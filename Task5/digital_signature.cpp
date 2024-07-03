#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/sha.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <chrono>

extern "C" {
    bool generateKeys(const char* keyType, const char* curveOrKeySize, const char* publicKeyPath, const char* privateKeyPath);
    bool sign(const char* privateKeyPath, const char* messagePath, const char* signaturePath, const char* algorithm);
    bool verifySignature(const char* publicKeyPath, const char* messagePath, const char* signaturePath, const char* algorithm);
}

int getCurveNID(const char* curve) {
    if (std::strcmp(curve, "prime256v1") == 0) return NID_X9_62_prime256v1;
    if (std::strcmp(curve, "secp384r1") == 0) return NID_secp384r1;
    if (std::strcmp(curve, "secp521r1") == 0) return NID_secp521r1;
    if (std::strcmp(curve, "secp224r1") == 0) return NID_secp224r1;
    if (std::strcmp(curve, "secp256k1") == 0) return NID_secp256k1;
    if (std::strcmp(curve, "brainpoolP256r1") == 0) return NID_brainpoolP256r1;
    if (std::strcmp(curve, "brainpoolP384r1") == 0) return NID_brainpoolP384r1;
    if (std::strcmp(curve, "brainpoolP512r1") == 0) return NID_brainpoolP512r1;
    if (std::strcmp(curve, "secp192r1") == 0) return NID_X9_62_prime192v1;
    if (std::strcmp(curve, "sect233k1") == 0) return NID_sect233k1;
    return 0; // Invalid curve
}


bool generateKeys(const char* keyType, const char* curveOrKeySize, const char* publicKeyPath, const char* privateKeyPath) {
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    EVP_PKEY* pkey = nullptr;
    EVP_PKEY_CTX* pctx = nullptr;

    if (std::strcmp(keyType, "ECDSA") == 0) {
        int curveNID = getCurveNID(curveOrKeySize);
        if (curveNID == 0) {
            std::cerr << "Invalid curve. Supported curves: prime256v1, secp384r1, secp521r1, secp224r1, secp256k1, brainpoolP256r1, brainpoolP384r1, brainpoolP512r1, secp192r1, sect233k1" << std::endl;
            return false;
        }
        pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_EC, NULL);
        if (!pctx || EVP_PKEY_keygen_init(pctx) <= 0 || EVP_PKEY_CTX_set_ec_paramgen_curve_nid(pctx, curveNID) <= 0) {
            std::cerr << "Error initializing ECDSA key generation context." << std::endl;
            return false;
        }
    } else if (std::strcmp(keyType, "RSAPSS") == 0) {
        int keySize = std::stoi(curveOrKeySize);
        if (keySize < 2048 || keySize > 8192 || keySize % 1024 != 0) {
            std::cerr << "Invalid key size. Supported sizes: 2048, 3072, 4096, 5120, 6144, 7168, 8192" << std::endl;
            return false;
        }
        pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);
        if (!pctx || EVP_PKEY_keygen_init(pctx) <= 0 || EVP_PKEY_CTX_set_rsa_keygen_bits(pctx, keySize) <= 0) {
            std::cerr << "Error initializing RSAPSS key generation context." << std::endl;
            return false;
        }
    } else {
        std::cerr << "Invalid key type. Supported types: ECDSA, RSAPSS" << std::endl;
        return false;
    }

    if (EVP_PKEY_keygen(pctx, &pkey) <= 0) {
        std::cerr << "Error generating keys." << std::endl;
        EVP_PKEY_CTX_free(pctx);
        return false;
    }

    // Save private key
    BIO* privateKeyBio = BIO_new_file(privateKeyPath, "w+");
    PEM_write_bio_PrivateKey(privateKeyBio, pkey, NULL, NULL, 0, NULL, NULL);
    BIO_free(privateKeyBio);

    // Save public key
    BIO* publicKeyBio = BIO_new_file(publicKeyPath, "w+");
    PEM_write_bio_PUBKEY(publicKeyBio, pkey);
    BIO_free(publicKeyBio);

    EVP_PKEY_free(pkey);
    EVP_PKEY_CTX_free(pctx);
    EVP_cleanup();
    ERR_free_strings();
    return true;
}

bool sign(const char* privateKeyPath, const char* messagePath, const char* signaturePath, const char* algorithm) {
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    // Read the private key from file
    BIO* keyData = BIO_new_file(privateKeyPath, "r");
    EVP_PKEY* privateKey = PEM_read_bio_PrivateKey(keyData, NULL, NULL, NULL);
    BIO_free(keyData);
    if (!privateKey) {
        std::cerr << "Error reading private key." << std::endl;
        ERR_print_errors_fp(stderr);
        return false;
    }

    // Read input message (binary)
    std::ifstream messageFile(messagePath, std::ios::binary);
    std::vector<unsigned char> messageContents((std::istreambuf_iterator<char>(messageFile)), std::istreambuf_iterator<char>());
    messageFile.close();

    // Create a hash of the message
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(&messageContents[0], messageContents.size(), hash);

    // Sign the hash
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    if (std::strcmp(algorithm, "ECDSA") == 0) {
        EVP_DigestSignInit(ctx, NULL, EVP_sha256(), NULL, privateKey);
    } else if (std::strcmp(algorithm, "RSAPSS") == 0) {
        EVP_DigestSignInit(ctx, NULL, EVP_sha256(), NULL, privateKey);
        EVP_PKEY_CTX* pctx = EVP_MD_CTX_pkey_ctx(ctx);
        EVP_PKEY_CTX_set_rsa_padding(pctx, RSA_PKCS1_PSS_PADDING);
    } else {
        std::cerr << "Invalid algorithm. Supported algorithms: ECDSA, RSAPSS" << std::endl;
        EVP_MD_CTX_free(ctx);
        EVP_PKEY_free(privateKey);
        return false;
    }

    EVP_DigestSignUpdate(ctx, hash, SHA256_DIGEST_LENGTH);
    size_t signatureLen;
    EVP_DigestSignFinal(ctx, NULL, &signatureLen);
    std::vector<unsigned char> signature(signatureLen);
    EVP_DigestSignFinal(ctx, &signature[0], &signatureLen);

    // Write the signature to a file
    std::ofstream signatureFile(signaturePath, std::ios::binary);
    if (!signatureFile.is_open()) {
        std::cerr << "Error opening signature file." << std::endl;
        EVP_MD_CTX_free(ctx);
        EVP_PKEY_free(privateKey);
        return false;
    }
    signatureFile.write(reinterpret_cast<const char*>(&signature[0]), signatureLen);
    signatureFile.close();

    // Clean up
    EVP_MD_CTX_free(ctx);
    EVP_PKEY_free(privateKey);
    EVP_cleanup();
    ERR_free_strings();
    return true;
}

bool verifySignature(const char* publicKeyPath, const char* messagePath, const char* signaturePath, const char* algorithm) {
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    // Read the public key from file
    BIO* keyData = BIO_new_file(publicKeyPath, "r");
    EVP_PKEY* publicKey = PEM_read_bio_PUBKEY(keyData, NULL, NULL, NULL);
    BIO_free(keyData);
    if (!publicKey) {
        std::cerr << "Error reading public key." << std::endl;
        ERR_print_errors_fp(stderr);
        return false;
    }

    // Read input message (binary)
    std::ifstream messageFile(messagePath, std::ios::binary);
    std::vector<unsigned char> messageContents((std::istreambuf_iterator<char>(messageFile)), std::istreambuf_iterator<char>());
    messageFile.close();

    // Create a hash of the message
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(&messageContents[0], messageContents.size(), hash);

    // Read the signature
    std::ifstream signatureFile(signaturePath, std::ios::binary);
    std::vector<unsigned char> signature((std::istreambuf_iterator<char>(signatureFile)), std::istreambuf_iterator<char>());
    signatureFile.close();

    // Verify the signature
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    if (std::strcmp(algorithm, "ECDSA") == 0) {
        EVP_DigestVerifyInit(ctx, NULL, EVP_sha256(), NULL, publicKey);
    } else if (std::strcmp(algorithm, "RSAPSS") == 0) {
        EVP_DigestVerifyInit(ctx, NULL, EVP_sha256(), NULL, publicKey);
        EVP_PKEY_CTX* pctx = EVP_MD_CTX_pkey_ctx(ctx);
        EVP_PKEY_CTX_set_rsa_padding(pctx, RSA_PKCS1_PSS_PADDING);
    } else {
        std::cerr << "Invalid algorithm. Supported algorithms: ECDSA, RSAPSS" << std::endl;
        EVP_MD_CTX_free(ctx);
        EVP_PKEY_free(publicKey);
        return false;
    }

    EVP_DigestVerifyUpdate(ctx, hash, SHA256_DIGEST_LENGTH);
    int result = EVP_DigestVerifyFinal(ctx, &signature[0], signature.size());

    // Clean up
    EVP_MD_CTX_free(ctx);
    EVP_PKEY_free(publicKey);
    EVP_cleanup();
    ERR_free_strings();
    return result == 1;
}

double measureSigningPerformance(const char* privateKeyPath, const char* messagePath, const char* signaturePath, const char* algorithm, int iterations) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        sign(privateKeyPath, messagePath, signaturePath, algorithm);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count() / iterations;
}

double measureVerificationPerformance(const char* publicKeyPath, const char* messagePath, const char* signaturePath, const char* algorithm, int iterations) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        verifySignature(publicKeyPath, messagePath, signaturePath, algorithm);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count() / iterations;
}

void reportPerformance(const std::string& keyType, const char* publicKeyPath, const char* privateKeyPath, const char* messagePath, const char* signaturePath, int iterations) {
    double avgSignTime = measureSigningPerformance(privateKeyPath, messagePath, signaturePath, keyType.c_str(), iterations);
    double avgVerifyTime = measureVerificationPerformance(publicKeyPath, messagePath, signaturePath, keyType.c_str(), iterations);
    std::cout << "Average time for signing with " << keyType << " over " << iterations << " iterations: " << avgSignTime << " seconds" << std::endl;
    std::cout << "Average time for verifying with " << keyType << " over " << iterations << " iterations: " << avgVerifyTime << " seconds" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [generate|sign|verify|report] <other parameters>" << std::endl;
        return 1;
    }

    std::string mode(argv[1]);
    if (mode == "generate") {
        if (argc != 6) {
            std::cerr << "Usage: " << argv[0] << " generate <ECDSA|RSAPSS> <curve or key size> <public key file> <private key file>" << std::endl;
            return 1;
        }

        if (generateKeys(argv[2], argv[3], argv[4], argv[5])) {
            std::cout << "Keys generated successfully." << std::endl;
        } else {
            std::cout << "Failed to generate keys." << std::endl;
        }
    } else if (mode == "sign") {
        if (argc != 6) {
            std::cerr << "Usage: " << argv[0] << " sign <private key file> <message file> <signature file> <ECDSA|RSAPSS>" << std::endl;
            return 1;
        }

        if (sign(argv[2], argv[3], argv[4], argv[5])) {
            std::cout << "Message signed successfully." << std::endl;
        } else {
            std::cout << "Failed to sign message." << std::endl;
        }
    } else if (mode == "verify") {
        if (argc != 6) {
            std::cerr << "Usage: " << argv[0] << " verify <public key file> <message file> <signature file> <ECDSA|RSAPSS>" << std::endl;
            return 1;
        }

        if (verifySignature(argv[2], argv[3], argv[4], argv[5])) {
            std::cout << "Message verified successfully." << std::endl;
        } else {
            std::cout << "Failed to verify message." << std::endl;
        }
    } else if (mode == "report") {
        if (argc != 8) {
            std::cerr << "Usage: " << argv[0] << " report <ECDSA|RSAPSS> <public key file> <private key file> <message file> <signature file> <iterations>" << std::endl;
            return 1;
        }

        std::string keyType(argv[2]);
        std::string publicKeyPath(argv[3]);
        std::string privateKeyPath(argv[4]);
        std::string messagePath(argv[5]);
        std::string signaturePath(argv[6]);
        int iterations = std::stoi(argv[7]);

        reportPerformance(keyType, publicKeyPath.c_str(), privateKeyPath.c_str(), messagePath.c_str(), signaturePath.c_str(), iterations);
    } else {
        std::cerr << "Invalid mode, please choose 'generate', 'sign', 'verify', or 'report'." << std::endl;
        return 1;
    }

    return 0;
}
