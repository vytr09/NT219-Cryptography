#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cryptopp/osrng.h>
#include <cryptopp/cryptlib.h>
#include <cryptopp/modes.h>
#include <cryptopp/aes.h>
#include <cryptopp/ccm.h>
#include <cryptopp/gcm.h>
#include <cryptopp/xts.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>
#include <cryptopp/base64.h>
#include <cryptopp/files.h>
#include <cryptopp/secblock.h>

using namespace std;
using namespace CryptoPP;

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

extern "C" {

    DLL_EXPORT void GenerateKeyAndIV(const char* format, const char* mode, const char* keyFile, const char* ivFile) {
        try {
            SecByteBlock key, iv;
            size_t keySize = AES::DEFAULT_KEYLENGTH;
            size_t ivSize = AES::BLOCKSIZE;

            if (string(mode) == "XTS") {
                keySize *= 2; // Double the key size for XTS mode
            }

            AutoSeededRandomPool prng;
            key = SecByteBlock(keySize);
            prng.GenerateBlock(key, key.size());
            iv = SecByteBlock(ivSize);
            prng.GenerateBlock(iv, iv.size());

            if (string(format) == "Hex") {
                HexEncoder encoder(new FileSink(keyFile));
                encoder.Put(key, key.size());
                encoder.MessageEnd();

                HexEncoder ivEncoder(new FileSink(ivFile));
                ivEncoder.Put(iv, iv.size());
                ivEncoder.MessageEnd();
            }
            else if (string(format) == "Base64") {
                Base64Encoder encoder(new FileSink(keyFile));
                encoder.Put(key, key.size());
                encoder.MessageEnd();

                Base64Encoder ivEncoder(new FileSink(ivFile));
                ivEncoder.Put(iv, iv.size());
                ivEncoder.MessageEnd();
            }
            else {
                FileSink keyFileSink(keyFile, true);
                keyFileSink.Put(key, key.size());

                FileSink ivFileSink(ivFile, true);
                ivFileSink.Put(iv, iv.size());
            }
        }
        catch (const std::exception& e) {
            cerr << "Error in GenerateKeyAndIV: " << e.what() << endl;
        }
    }

    DLL_EXPORT void EncryptData(const char* format, const char* mode, const char* keyFile, const char* ivFile, const char* inputFile, const char* outputFile) {
        try {
            SecByteBlock key, iv;
            size_t keySize = AES::DEFAULT_KEYLENGTH;

            if (string(mode) == "XTS") {
                keySize *= 2; // Double the key size for XTS mode
            }
            key = SecByteBlock(keySize);
            iv = SecByteBlock(AES::BLOCKSIZE);

            if (string(format) == "Hex") {
                FileSource keySource(keyFile, true, new HexDecoder(new ArraySink(key, key.size())));
                FileSource ivSource(ivFile, true, new HexDecoder(new ArraySink(iv, iv.size())));
            }
            else if (string(format) == "Base64") {
                FileSource keySource(keyFile, true, new Base64Decoder(new ArraySink(key, key.size())));
                FileSource ivSource(ivFile, true, new Base64Decoder(new ArraySink(iv, iv.size())));
            }
            else {
                FileSource keySource(keyFile, true, new ArraySink(key, key.size()));
                FileSource ivSource(ivFile, true, new ArraySink(iv, iv.size()));
            }

            string plaintext;
            FileSource(inputFile, true, new StringSink(plaintext));

            string ciphertext;
            if (string(mode) == "ECB") {
                ECB_Mode<AES>::Encryption e;
                e.SetKey(key, key.size());
                StringSource ss(plaintext, true, new StreamTransformationFilter(e, new StringSink(ciphertext)));
            }
            else if (string(mode) == "CBC") {
                CBC_Mode<AES>::Encryption e;
                e.SetKeyWithIV(key, key.size(), iv, iv.size());
                StringSource ss(plaintext, true, new StreamTransformationFilter(e, new StringSink(ciphertext)));
            }
            else if (string(mode) == "CFB") {
                CFB_Mode<AES>::Encryption e;
                e.SetKeyWithIV(key, key.size(), iv, iv.size());
                StringSource ss(plaintext, true, new StreamTransformationFilter(e, new StringSink(ciphertext)));
            }
            else if (string(mode) == "OFB") {
                OFB_Mode<AES>::Encryption e;
                e.SetKeyWithIV(key, key.size(), iv, iv.size());
                StringSource ss(plaintext, true, new StreamTransformationFilter(e, new StringSink(ciphertext)));
            }
            else if (string(mode) == "CTR") {
                CTR_Mode<AES>::Encryption e;
                e.SetKeyWithIV(key, key.size(), iv, iv.size());
                StringSource ss(plaintext, true, new StreamTransformationFilter(e, new StringSink(ciphertext)));
            }
            else if (string(mode) == "GCM") {
                GCM<AES>::Encryption e;
                e.SetKeyWithIV(key, key.size(), iv, iv.size());
                StringSource ss(plaintext, true, new AuthenticatedEncryptionFilter(e, new StringSink(ciphertext)));
            }
            else if (string(mode) == "CCM") {
                CCM<AES, 16>::Encryption e;
                e.SetKeyWithIV(key, key.size(), iv, iv.size());
                StringSource ss(plaintext, true, new AuthenticatedEncryptionFilter(e, new StringSink(ciphertext)));
            }
            else if (string(mode) == "XTS") {
                XTS_Mode<AES>::Encryption e;
                e.SetKeyWithIV(key, key.size(), iv, iv.size());
                StringSource ss(plaintext, true, new StreamTransformationFilter(e, new StringSink(ciphertext)));
            }
            else {
                throw runtime_error("Unsupported mode");
            }

            FileSink file(outputFile);
            file.Put(reinterpret_cast<const CryptoPP::byte*>(ciphertext.data()), ciphertext.size());
        }
        catch (const std::exception& e) {
            cerr << "Error in EncryptData: " << e.what() << endl;
        }
    }

    DLL_EXPORT void DecryptData(const char* format, const char* mode, const char* keyFile, const char* ivFile, const char* inputFile, const char* outputFile) {
        try {
            SecByteBlock key, iv;
            size_t keySize = AES::DEFAULT_KEYLENGTH;

            if (string(mode) == "XTS") {
                keySize *= 2; // Double the key size for XTS mode
            }
            key = SecByteBlock(keySize);
            iv = SecByteBlock(AES::BLOCKSIZE);

            if (string(format) == "Hex") {
                FileSource keySource(keyFile, true, new HexDecoder(new ArraySink(key, key.size())));
                FileSource ivSource(ivFile, true, new HexDecoder(new ArraySink(iv, iv.size())));
            }
            else if (string(format) == "Base64") {
                FileSource keySource(keyFile, true, new Base64Decoder(new ArraySink(key, key.size())));
                FileSource ivSource(ivFile, true, new Base64Decoder(new ArraySink(iv, iv.size())));
            }
            else {
                FileSource keySource(keyFile, true, new ArraySink(key, key.size()));
                FileSource ivSource(ivFile, true, new ArraySink(iv, iv.size()));
            }

            string ciphertext;
            FileSource(inputFile, true, new StringSink(ciphertext));

            string plaintext;
            if (string(mode) == "ECB") {
                ECB_Mode<AES>::Decryption d;
                d.SetKey(key, key.size());
                StringSource ss(ciphertext, true, new StreamTransformationFilter(d, new StringSink(plaintext)));
            }
            else if (string(mode) == "CBC") {
                CBC_Mode<AES>::Decryption d;
                d.SetKeyWithIV(key, key.size(), iv, iv.size());
                StringSource ss(ciphertext, true, new StreamTransformationFilter(d, new StringSink(plaintext)));
            }
            else if (string(mode) == "CFB") {
                CFB_Mode<AES>::Decryption d;
                d.SetKeyWithIV(key, key.size(), iv, iv.size());
                StringSource ss(ciphertext, true, new StreamTransformationFilter(d, new StringSink(plaintext)));
            }
            else if (string(mode) == "OFB") {
                OFB_Mode<AES>::Decryption d;
                d.SetKeyWithIV(key, key.size(), iv, iv.size());
                StringSource ss(ciphertext, true, new StreamTransformationFilter(d, new StringSink(plaintext)));
            }
            else if (string(mode) == "CTR") {
                CTR_Mode<AES>::Decryption d;
                d.SetKeyWithIV(key, key.size(), iv, iv.size());
                StringSource ss(ciphertext, true, new StreamTransformationFilter(d, new StringSink(plaintext)));
            }
            else if (string(mode) == "GCM") {
                GCM<AES>::Decryption d;
                d.SetKeyWithIV(key, key.size(), iv, iv.size());
                StringSource ss(ciphertext, true, new AuthenticatedDecryptionFilter(d, new StringSink(plaintext)));
            }
            else if (string(mode) == "CCM") {
                CCM<AES, 16>::Decryption d;
                d.SetKeyWithIV(key, key.size(), iv, iv.size());
                StringSource ss(ciphertext, true, new AuthenticatedDecryptionFilter(d, new StringSink(plaintext)));
            }
            else if (string(mode) == "XTS") {
                XTS_Mode<AES>::Decryption d;
                d.SetKeyWithIV(key, key.size(), iv, iv.size());
                StringSource ss(ciphertext, true, new StreamTransformationFilter(d, new StringSink(plaintext)));
            }
            else {
                throw runtime_error("Unsupported mode");
            }

            FileSink file(outputFile);
            file.Put(reinterpret_cast<const CryptoPP::byte*>(plaintext.data()), plaintext.size());
        }
        catch (const std::exception& e) {
            cerr << "Error in DecryptData: " << e.what() << endl;
        }
    }

}

