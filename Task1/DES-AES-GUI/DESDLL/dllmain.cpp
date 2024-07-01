// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#ifndef DLL_EXPORT 
#ifdef _WIN32 
#define DLL_EXPORT __declspec(dllexport) 
#else 
#define DLL_EXPORT
#endif 
#endif 

// Declare functions with extern "C" to prevent name mangling in C++ 

extern "C" {
    DLL_EXPORT void GenerateDESKey(const char* keyFile, const char* ivFile, const char* format);
    DLL_EXPORT void DESEncrypt(const char* keyFile, const char* ivFile, const char* plaintextFile, const char* cipherFile, const char* format, const char* mode);
    DLL_EXPORT void DESDecrypt(const char* keyFile, const char* ivFile, const char* cipherFile, const char* plaintextFile, const char* format, const char* mode);
}
#include "cryptopp/des.h"
#include "cryptopp/modes.h"
#include "cryptopp/osrng.h"
#include "cryptopp/filters.h"
#include "cryptopp/files.h"
#include "cryptopp/hex.h"
#include "cryptopp/base64.h"

#include <iostream>
#include <fstream>
#include <string>
#include <memory>

using namespace CryptoPP;
using namespace std;

void GenerateKeyIV(SecByteBlock& key, SecByteBlock& iv, size_t keySize, size_t ivSize) {
    AutoSeededRandomPool prng;
    key = SecByteBlock(keySize);
    prng.GenerateBlock(key, key.size());
    iv = SecByteBlock(ivSize);
    prng.GenerateBlock(iv, iv.size());
}

void SaveKeyIV(const string& filename, const SecByteBlock& data, const string& format) {
    ByteQueue queue;
    queue.Put(data, data.size());

    if (format == "Hex") {
        HexEncoder encoder(new FileSink(filename.c_str()));
        queue.CopyTo(encoder);
        encoder.MessageEnd();
    }
    else if (format == "Base64") {
        Base64Encoder encoder(new FileSink(filename.c_str()));
        queue.CopyTo(encoder);
        encoder.MessageEnd();
    }
    else {
        FileSink file(filename.c_str());
        queue.CopyTo(file);
        file.MessageEnd();
    }
}

void LoadKeyIV(const string& filename, SecByteBlock& data, const string& format) {
    ByteQueue queue;
    if (format == "Hex") {
        FileSource file(filename.c_str(), true, new HexDecoder);
        file.TransferTo(queue);
    }
    else if (format == "Base64") {
        FileSource file(filename.c_str(), true, new Base64Decoder);
        file.TransferTo(queue);
    }
    else {
        FileSource file(filename.c_str(), true);
        file.TransferTo(queue);
    }
    queue.MessageEnd();

    data.resize(queue.MaxRetrievable());
    queue.Get(data, data.size());
}

void EncryptDecrypt(const SecByteBlock& key, const SecByteBlock& iv, const string& input, string& output, const string& mode, bool isEncrypt) {
    unique_ptr<StreamTransformation> cipher;
    if (mode == "ECB") {
        if (isEncrypt) {
            cipher.reset(new ECB_Mode<DES>::Encryption(key, key.size()));
        }
        else {
            cipher.reset(new ECB_Mode<DES>::Decryption(key, key.size()));
        }
    }
    else if (mode == "CBC") {
        if (isEncrypt) {
            cipher.reset(new CBC_Mode<DES>::Encryption(key, key.size(), iv));
        }
        else {
            cipher.reset(new CBC_Mode<DES>::Decryption(key, key.size(), iv));
        }
    }
    else if (mode == "OFB") {
        if (isEncrypt) {
            cipher.reset(new OFB_Mode<DES>::Encryption(key, key.size(), iv));
        }
        else {
            cipher.reset(new OFB_Mode<DES>::Decryption(key, key.size(), iv));
        }
    }
    else if (mode == "CFB") {
        if (isEncrypt) {
            cipher.reset(new CFB_Mode<DES>::Encryption(key, key.size(), iv));
        }
        else {
            cipher.reset(new CFB_Mode<DES>::Decryption(key, key.size(), iv));
        }
    }
    else if (mode == "CTR") {
        if (isEncrypt) {
            cipher.reset(new CTR_Mode<DES>::Encryption(key, key.size(), iv));
        }
        else {
            cipher.reset(new CTR_Mode<DES>::Decryption(key, key.size(), iv));
        }
    }
    else {
        throw runtime_error("Unsupported mode");
    }

    StringSource ss(input, true, new StreamTransformationFilter(*cipher, new StringSink(output)));
}

extern "C" {
    DLL_EXPORT void GenerateDESKey(const char* keyFile, const char* ivFile, const char* format) {
        SecByteBlock key(DES::DEFAULT_KEYLENGTH);
        SecByteBlock iv(DES::BLOCKSIZE);
        GenerateKeyIV(key, iv, DES::DEFAULT_KEYLENGTH, DES::BLOCKSIZE);
        SaveKeyIV(keyFile, key, format);
        SaveKeyIV(ivFile, iv, format);
    }

    DLL_EXPORT void DESEncrypt(const char* keyFile, const char* ivFile, const char* plaintextFile, const char* cipherFile, const char* format, const char* mode) {
        SecByteBlock key(DES::DEFAULT_KEYLENGTH);
        SecByteBlock iv(DES::BLOCKSIZE);
        LoadKeyIV(keyFile, key, format);
        if (string(mode) != "ECB") {
            LoadKeyIV(ivFile, iv, format);
        }

        string plaintext;
        FileSource fs(plaintextFile, true, new StringSink(plaintext));

        string ciphertext;
        EncryptDecrypt(key, iv, plaintext, ciphertext, mode, true);

        StringSource ss(ciphertext, true, new FileSink(cipherFile));
    }

    DLL_EXPORT void DESDecrypt(const char* keyFile, const char* ivFile, const char* cipherFile, const char* plaintextFile, const char* format, const char* mode) {
        SecByteBlock key(DES::DEFAULT_KEYLENGTH);
        SecByteBlock iv(DES::BLOCKSIZE);
        LoadKeyIV(keyFile, key, format);
        if (string(mode) != "ECB") {
            LoadKeyIV(ivFile, iv, format);
        }

        string ciphertext;
        FileSource fs(cipherFile, true, new StringSink(ciphertext));

        string plaintext;
        EncryptDecrypt(key, iv, ciphertext, plaintext, mode, false);

        StringSource ss(plaintext, true, new FileSink(plaintextFile));
    }
}
