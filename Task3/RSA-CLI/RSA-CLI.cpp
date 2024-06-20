#include "cryptopp/rsa.h"
#include "cryptopp/base64.h"
#include "cryptopp/hex.h"
#include "cryptopp/integer.h"
#include "cryptopp/sha.h"
#include "cryptopp/osrng.h"
#include "cryptopp/cryptlib.h"
#include "cryptopp/queue.h"
#include "cryptopp/files.h"
#include "cryptopp/filters.h"

#include <stdexcept>
#include <string>
#include <exception>
#include <iostream>
#include <chrono>
#include <fstream>

using namespace CryptoPP;
using namespace std;
using namespace std::chrono;

void Save(const string& filename, const BufferedTransformation& bt);
void SavePrivateKey(const string& filename, const PrivateKey& key);
void SavePublicKey(const string& filename, const PublicKey& key);
void SaveBase64(const string& filename, const BufferedTransformation& bt);
void SaveBase64PrivateKey(const string& filename, const PrivateKey& key);
void SaveBase64PublicKey(const string& filename, const PublicKey& key);
void SaveHex(const string& filename, const BufferedTransformation& bt);
void SaveHexPrivateKey(const string& filename, const PrivateKey& key);
void SaveHexPublicKey(const string& filename, const PublicKey& key);
void Load(const string& filename, BufferedTransformation& bt);
void LoadPrivateKey(const string& filename, PrivateKey& key);
void LoadPublicKey(const string& filename, PublicKey& key);
void LoadBase64(const string& filename, BufferedTransformation& bt);
void LoadBase64PrivateKey(const string& filename, PrivateKey& key);
void LoadBase64PublicKey(const string& filename, PublicKey& key);
void LoadHex(const string& filename, BufferedTransformation& bt);
void LoadHexPrivateKey(const string& filename, PrivateKey& key);
void LoadHexPublicKey(const string& filename, PublicKey& key);

void GenerateAndSaveRSAKeys(int keySize, const char* format, const char* privateKeyFile, const char* publicKeyFile) {
    string strFormat(format);
    string strPrivateKeyFile(privateKeyFile);
    string strPublicKeyFile(publicKeyFile);

    AutoSeededRandomPool rnd;
    RSA::PrivateKey rsaPrivate;
    rsaPrivate.GenerateRandomWithKeySize(rnd, keySize);
    RSA::PublicKey rsaPublic(rsaPrivate);

    if (strFormat == "DER") {
        SavePrivateKey(strPrivateKeyFile, rsaPrivate);
        SavePublicKey(strPublicKeyFile, rsaPublic);
    } else if (strFormat == "Base64") {
        SaveBase64PrivateKey(strPrivateKeyFile, rsaPrivate);
        SaveBase64PublicKey(strPublicKeyFile, rsaPublic);
    } else if (strFormat == "Hex") {
        SaveHexPrivateKey(strPrivateKeyFile, rsaPrivate);
        SaveHexPublicKey(strPublicKeyFile, rsaPublic);
    } else {
        cerr << "Unsupported format. Please choose 'DER', 'Base64' or 'Hex' ";
        exit(1);
    }

    Integer modul1 = rsaPrivate.GetModulus();
    Integer prime1 = rsaPrivate.GetPrime1();
    Integer prime2 = rsaPrivate.GetPrime2();
    Integer SK = rsaPrivate.GetPrivateExponent();
    Integer PK = rsaPublic.GetPublicExponent();
    Integer modul2 = rsaPublic.GetModulus();

    cout << "Public modulus (from secret key) =" << modul1 << endl;
    cout << "\nPublic modulus (from public key) =" << modul2 << endl;
    cout << "\nSecret exponent d=" << SK << endl;
    cout << "\nPrime number p=" << std::hex << prime1 << std::dec << endl;
    cout << "\nPrime number q=" << prime2 << endl;
    cout << "\nPublic exponent e=" << PK << endl;

    RSA::PrivateKey r1, r2;
    r1.GenerateRandomWithKeySize(rnd, 3072);

    SavePrivateKey("rsa-roundtrip.key", r1);
    LoadPrivateKey("rsa-roundtrip.key", r2);

    r1.Validate(rnd, 3);
    r2.Validate(rnd, 3);

    if (r1.GetModulus() != r2.GetModulus() ||
        r1.GetPublicExponent() != r2.GetPublicExponent() ||
        r1.GetPrivateExponent() != r2.GetPrivateExponent()) {
        throw runtime_error("key data did not round trip");
    }

    cout << "Successfully generated and saved RSA keys" << endl;
}

void RSAencrypt(const char* format, const char* publicKeyFile, const char* PlaintextFile, const char* CipherFile) {
    AutoSeededRandomPool rng;
    string strFormat(format);
    string strPublicKeyFile(publicKeyFile);

    RSA::PublicKey publicKey;

    if (strFormat == "DER") {
        LoadPublicKey(strPublicKeyFile, publicKey);
    } else if (strFormat == "Base64") {
        LoadBase64PublicKey(strPublicKeyFile, publicKey);
    } else if (strFormat == "Hex") {
        LoadHexPublicKey(strPublicKeyFile, publicKey);
    } else {
        cerr << "Unsupported format. Please choose 'DER', 'Base64' or 'Hex' ";
        exit(1);
    }

    string plain;
    FileSource fs(PlaintextFile, true, new StringSink(plain));

    // Clear the output file before writing
    std::ofstream ofs(CipherFile, std::ios::out | std::ios::trunc);
    ofs.close();

    RSAES_OAEP_SHA_Encryptor e(publicKey);

    StringSource ss(plain, true,
        new PK_EncryptorFilter(rng, e,
            new FileSink(CipherFile, true)
        )
    );
}

void RSAdecrypt(const char* format, const char* privateKeyFile, const char* CipherFile, const char* PlaintextFile) {
    string strFormat(format);
    string strSecretKeyFile(privateKeyFile);

    RSA::PrivateKey PrivateKey;

    if (strFormat == "DER") {
        LoadPrivateKey(strSecretKeyFile, PrivateKey);
    } else if (strFormat == "Base64") {
        LoadBase64PrivateKey(strSecretKeyFile, PrivateKey);
    } else if (strFormat == "Hex") {
        LoadHexPrivateKey(strSecretKeyFile, PrivateKey);
    } else {
        cerr << "Unsupported format. Please choose 'DER', 'Base64' or 'Hex' ";
        exit(1);
    }

    AutoSeededRandomPool rng;

    RSAES_OAEP_SHA_Decryptor d(PrivateKey);
    string cipher;
    FileSource fs(CipherFile, true, new StringSink(cipher));

    // Clear the output file before writing
    std::ofstream ofs(PlaintextFile, std::ios::out | std::ios::trunc);
    ofs.close();

    StringSource ss2(cipher, true,
        new PK_DecryptorFilter(rng, d,
            new FileSink(PlaintextFile, true)
        )
    );
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    if (argc < 2) {
        cerr << "Usage: \n"
            << argv[0] << " genkey <keysize> <format> <privatekeyFile> <publicKeyFile>" << endl
            << argv[0] << " encrypt <format> <publickeyFile> <plainTextFile> <cipherFile>" << endl
            << argv[0] << " decrypt <format> <privatekeyFile> <cipherFile> <plainTextFile>" << endl;
        exit(1);
    }

    string mode = argv[1];

    if (mode == "genkey" && argc == 6) {
        int keySize = std::stoi(argv[2]);
        GenerateAndSaveRSAKeys(keySize, argv[3], argv[4], argv[5]);
    } else if (mode == "encrypt" && argc == 6) {
        RSAencrypt(argv[2], argv[3], argv[4], argv[5]);
    } else if (mode == "decrypt" && argc == 6) {
        RSAdecrypt(argv[2], argv[3], argv[4], argv[5]);
    } else if (mode == "test" && argc == 6) {
        string format = argv[2];
        string publicKeyFile = argv[3];
        string privateKeyFile = argv[4];
        string plainTextFile = argv[5];

        const char* cipherFile = "cipher.txt";
        const char* decryptedFile = "decrypted.txt";

        high_resolution_clock::time_point start, end;
        double encryptTime = 0.0, decryptTime = 0.0;

        for (int i = 0; i < 10000; ++i) {
            start = high_resolution_clock::now();
            RSAencrypt(format.c_str(), publicKeyFile.c_str(), plainTextFile.c_str(), cipherFile);
            end = high_resolution_clock::now();
            encryptTime += duration_cast<duration<double>>(end - start).count();

            start = high_resolution_clock::now();
            RSAdecrypt(format.c_str(), privateKeyFile.c_str(), cipherFile, decryptedFile);
            end = high_resolution_clock::now();
            decryptTime += duration_cast<duration<double>>(end - start).count();
        }

        cout << "Average encryption time: " << (encryptTime / 10000.0) << " seconds" << endl;
        cout << "Average decryption time: " << (decryptTime / 10000.0) << " seconds" << endl;
    } else {
        cerr << "Invalid arguments." << endl;
        exit(1);
    }

    return 0;
}

void SavePrivateKey(const string& filename, const PrivateKey& key) {
    ByteQueue queue;
    key.Save(queue);
    Save(filename, queue);
}

void SavePublicKey(const string& filename, const PublicKey& key) {
    ByteQueue queue;
    key.Save(queue);
    Save(filename, queue);
}

void Save(const string& filename, const BufferedTransformation& bt) {
    FileSink file(filename.c_str());
    bt.CopyTo(file);
    file.MessageEnd();
}

void SaveBase64PrivateKey(const string& filename, const PrivateKey& key) {
    ByteQueue queue;
    key.Save(queue);
    SaveBase64(filename, queue);
}

void SaveBase64PublicKey(const string& filename, const PublicKey& key) {
    ByteQueue queue;
    key.Save(queue);
    SaveBase64(filename, queue);
}

void SaveBase64(const string& filename, const BufferedTransformation& bt) {
    Base64Encoder encoder;
    bt.CopyTo(encoder);
    encoder.MessageEnd();
    Save(filename, encoder);
}

void SaveHexPrivateKey(const string& filename, const PrivateKey& key) {
    ByteQueue queue;
    key.Save(queue);
    SaveHex(filename, queue);
}

void SaveHexPublicKey(const string& filename, const PublicKey& key) {
    ByteQueue queue;
    key.Save(queue);
    SaveHex(filename, queue);
}

void SaveHex(const string& filename, const BufferedTransformation& bt) {
    HexEncoder encoder;
    bt.CopyTo(encoder);
    encoder.MessageEnd();
    Save(filename, encoder);
}

void LoadPrivateKey(const string& filename, PrivateKey& key) {
    ByteQueue queue;
    Load(filename, queue);
    key.Load(queue);
}

void LoadPublicKey(const string& filename, PublicKey& key) {
    ByteQueue queue;
    Load(filename, queue);
    key.Load(queue);
}

void Load(const string& filename, BufferedTransformation& bt) {
    FileSource file(filename.c_str(), true);
    file.TransferTo(bt);
    bt.MessageEnd();
}

void LoadBase64PrivateKey(const string& filename, PrivateKey& key) {
    FileSource file(filename.c_str(), true, new Base64Decoder);
    ByteQueue queue;
    file.TransferTo(queue);
    queue.MessageEnd();
    key.Load(queue);
    AutoSeededRandomPool prng;
    if (!key.Validate(prng, 3)) {
        throw runtime_error("Failed to validate RSA private key");
    }
}

void LoadBase64PublicKey(const string& filename, PublicKey& key) {
    ByteQueue queue;
    LoadBase64(filename, queue);
    key.Load(queue);
    AutoSeededRandomPool prng;
    if (!key.Validate(prng, 3)) {
        throw runtime_error("Failed to validate RSA public key");
    }
}

void LoadBase64(const string& filename, BufferedTransformation& bt) {
    FileSource file(filename.c_str(), true, new Base64Decoder);
    file.TransferTo(bt);
    bt.MessageEnd();
}

void LoadHexPrivateKey(const string& filename, PrivateKey& key) {
    FileSource file(filename.c_str(), true, new HexDecoder);
    ByteQueue queue;
    file.TransferTo(queue);
    queue.MessageEnd();
    key.Load(queue);
    AutoSeededRandomPool prng;
    if (!key.Validate(prng, 3)) {
        throw runtime_error("Failed to validate RSA private key");
    }
}

void LoadHexPublicKey(const string& filename, PublicKey& key) {
    ByteQueue queue;
    LoadHex(filename, queue);
    key.Load(queue);
    AutoSeededRandomPool prng;
    if (!key.Validate(prng, 3)) {
        throw runtime_error("Failed to validate RSA public key");
    }
}

void LoadHex(const string& filename, BufferedTransformation& bt) {
    FileSource file(filename.c_str(), true, new HexDecoder);
    file.TransferTo(bt);
    bt.MessageEnd();
}
