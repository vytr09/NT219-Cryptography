#include <cryptopp/sha.h>
#include <cryptopp/sha3.h>
#include <cryptopp/shake.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace CryptoPP;

// Function to hash data using different algorithms
std::string hashDataInternal(const std::string& data, const std::string& algorithm, int digestLength = 0) {
    std::string digest;
    HexEncoder encoder(new StringSink(digest));

    try {
        if (algorithm == "sha224") {
            SHA224 hash;
            StringSource(data, true, new HashFilter(hash, new Redirector(encoder)));
        } else if (algorithm == "sha256") {
            SHA256 hash;
            StringSource(data, true, new HashFilter(hash, new Redirector(encoder)));
        } else if (algorithm == "sha384") {
            SHA384 hash;
            StringSource(data, true, new HashFilter(hash, new Redirector(encoder)));
        } else if (algorithm == "sha512") {
            SHA512 hash;
            StringSource(data, true, new HashFilter(hash, new Redirector(encoder)));
        } else if (algorithm == "sha3_224") {
            SHA3_224 hash;
            StringSource(data, true, new HashFilter(hash, new Redirector(encoder)));
        } else if (algorithm == "sha3_256") {
            SHA3_256 hash;
            StringSource(data, true, new HashFilter(hash, new Redirector(encoder)));
        } else if (algorithm == "sha3_384") {
            SHA3_384 hash;
            StringSource(data, true, new HashFilter(hash, new Redirector(encoder)));
        } else if (algorithm == "sha3_512") {
            SHA3_512 hash;
            StringSource(data, true, new HashFilter(hash, new Redirector(encoder)));
        } else if (algorithm == "shake128") {
            if (digestLength <= 0) throw std::invalid_argument("digestLength is required for shake128");
            SHAKE128 hash(digestLength);
            StringSource(data, true, new HashFilter(hash, new Redirector(encoder)));
        } else if (algorithm == "shake256") {
            if (digestLength <= 0) throw std::invalid_argument("digestLength is required for shake256");
            SHAKE256 hash(digestLength);
            StringSource(data, true, new HashFilter(hash, new Redirector(encoder)));
        } else {
            throw std::invalid_argument("Unsupported algorithm");
        }
    } catch (const Exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return "";
    }

    return digest;
}

// Function to read file content
std::string readFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Error: File not found");
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// Exported function for DLL
#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

extern "C" {
    DLL_EXPORT const char* hashData(const char* data, const char* algorithm, int digestLength = 0) {
        static std::string result;
        result = hashDataInternal(std::string(data), std::string(algorithm), digestLength);
        return result.c_str();
    }
}

// Main function for testing
int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <input> <algorithm> [--file] [--digest_length <length>] [--output <file>]" << std::endl;
        return 1;
    }

    std::string input = argv[1];
    std::string algorithm = argv[2];
    bool isFile = false;
    int digestLength = 0;
    std::string outputFile;

    for (int i = 3; i < argc; ++i) {
        if (std::string(argv[i]) == "--file") {
            isFile = true;
        } else if (std::string(argv[i]) == "--digest_length" && i + 1 < argc) {
            digestLength = std::stoi(argv[++i]);
        } else if (std::string(argv[i]) == "--output" && i + 1 < argc) {
            outputFile = argv[++i];
        }
    }

    std::string data;
    try {
        data = isFile ? readFile(input) : input;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::string result = hashDataInternal(data, algorithm, digestLength);
    if (result.empty()) {
        return 1;
    }

    if (!outputFile.empty()) {
        std::ofstream outFile(outputFile);
        outFile << result;
    } else {
        std::cout << "Hash result: " << result << std::endl;
    }

    return 0;
}
