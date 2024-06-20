#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <codecvt>
#include <locale>
#include <chrono>
#include <stdexcept>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef WIN32_LEAN_AND_MEAN
#endif

#include "CBC.h"

using namespace std;
using namespace std::chrono;

std::string vectorUint8ToString(const std::vector<uint8_t> &data)
{
    return std::string(data.begin(), data.end());
}

std::vector<uint8_t> stringToVectorUint8(const std::string &str)
{
    return std::vector<uint8_t>(str.begin(), str.end());
}

std::vector<uint8_t> hexToBytes(const std::string &hexString)
{
    std::vector<uint8_t> bytes;

    for (size_t i = 0; i < hexString.length(); i += 2)
    {
        std::string byteString = hexString.substr(i, 2);
        uint8_t byte = static_cast<uint8_t>(std::stoul(byteString, nullptr, 16));
        bytes.push_back(byte);
    }

    return bytes;
}

std::vector<uint8_t> readBinaryFile(const std::string &filePath)
{
    std::ifstream file(filePath, std::ios::binary);
    if (!file)
    {
        throw std::runtime_error("Could not open file: " + filePath);
    }

    // Determine the file size
    file.seekg(0, std::ios::end);
    size_t fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // Read the entire file into a vector<uint8_t>
    std::vector<uint8_t> buffer(fileSize);
    file.read(reinterpret_cast<char*>(buffer.data()), fileSize);

    if (!file)
    {
        throw std::runtime_error("Error reading file: " + filePath);
    }

    return buffer;
}

void writeBytesToFile(const std::string &filePath, const std::vector<uint8_t> &data)
{
    std::ofstream file(filePath, std::ios::binary);
    if (!file)
    {
        throw std::runtime_error("Could not open file for writing: " + filePath);
    }
    file.write(reinterpret_cast<const char *>(data.data()), data.size());
}

int main()
{
#ifdef __linux__
    std::locale::global(std::locale("C.UTF-8"));
#endif

#ifdef _WIN32
    // Set console code page to UTF-8 on Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    cout << "AES-CBC - 128 bit key for Encryption and Decryption " << endl;
    
    int key_length = 128;
    std::string key128 = "ED54379125433C056EADD3EF3E6061E2"; // 128
    cout << "Enter the key (Hex) - 128 bit: ";
    cin >> key128;
    std::vector<uint8_t> key_hex_128(key128.begin(), key128.end());
    std::vector<uint8_t> key_bytes_128 = hexToBytes(key128);

    std::string iv = "4513FFE50CBB04629E52A5FB53D70F66"; // 128
    cout << "Enter the IV (Hex) - 128 bit: ";
    cin >> iv;
    std::vector<uint8_t> iv_hex(iv.begin(), iv.end());
    std::vector<uint8_t> iv_bytes = hexToBytes(iv);

    CBC cbc_mode(iv_bytes, key_bytes_128, key_length);

    int choice;
    cout << "Enter 1 to encrypt and 2 to decrypt:\n>>Enter your number:  ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        int inputChoice;
        cout << "Enter 1 to input plaintext manually or 2 to read from file:\n>>Enter your number:  ";
        cin >> inputChoice;
        std::string plaintext;

        if (inputChoice == 1)
        {
            cout << "Enter the plaintext: ";
            cin.ignore();
            getline(cin, plaintext);
        }
        else if (inputChoice == 2)
        {
            cout << "Enter the file path: ";
            std::string filePath;
            cin >> filePath;

            try
            {
                plaintext = vectorUint8ToString(readBinaryFile(filePath));
            }
            catch (const std::runtime_error &e)
            {
                cerr << e.what() << endl;
                return 1;
            }
        }
        else
        {
            cerr << "Invalid choice" << endl;
            return 1;
        }

        std::vector<uint8_t> plaintext_bytes = stringToVectorUint8(plaintext);

        // Timer and iteration for encryption
        auto startEncrypt = high_resolution_clock::now();
        for (int i = 0; i < 10000; ++i)
        {
            std::vector<uint8_t> ciphertext = cbc_mode.cbc_encrypt(plaintext_bytes);
        }
        auto endEncrypt = high_resolution_clock::now();
        auto durationEncrypt = duration_cast<microseconds>(endEncrypt - startEncrypt).count();
        double avgEncryptTime = static_cast<double>(durationEncrypt) / 10000;
        std::cout << "Average encryption time per iteration: " << avgEncryptTime << " microseconds" << std::endl;

        std::vector<uint8_t> ciphertext = cbc_mode.cbc_encrypt(plaintext_bytes);

        // Save ciphertext to file
        std::string ciphertextFilePath = "encrypted_output.bin";
        try
        {
            writeBytesToFile(ciphertextFilePath, ciphertext);
            cout << "Ciphertext saved to: " << ciphertextFilePath << endl;
        }
        catch (const std::runtime_error &e)
        {
            cerr << e.what() << endl;
            return 1;
        }

        std::cout << std::dec << std::endl;
        break;
    }
    case 2:
    {
        int inputChoice;
        cout << "Enter 1 to input ciphertext manually or 2 to read from file:\n>>Enter your number:  ";
        cin >> inputChoice;
        std::string ciphertext;

        if (inputChoice == 1)
        {
            cout << "Enter the ciphertext: ";
            cin.ignore();
            getline(cin, ciphertext);
        }
        else if (inputChoice == 2)
        {
            cout << "Enter the file path: ";
            std::string filePath;
            cin >> filePath;

            try
            {
                ciphertext = vectorUint8ToString(readBinaryFile(filePath));
            }
            catch (const std::runtime_error &e)
            {
                cerr << e.what() << endl;
                return 1;
            }
        }
        else
        {
            cerr << "Invalid choice" << endl;
            return 1;
        }

        std::vector<uint8_t> ciphertext_bytes;

        // Convert ciphertext from string to bytes
        try
        {
            ciphertext_bytes = stringToVectorUint8(ciphertext);
        }
        catch (const std::invalid_argument &e)
        {
            cerr << "Invalid format in ciphertext: " << e.what() << endl;
            return 1;
        }

        // Timer and iteration for decryption
        auto startDecrypt = high_resolution_clock::now();
        for (int i = 0; i < 10000; ++i)
        {
            std::vector<uint8_t> decrypted_bytes = cbc_mode.cbc_decrypt(ciphertext_bytes);
        }
        auto endDecrypt = high_resolution_clock::now();
        auto durationDecrypt = duration_cast<microseconds>(endDecrypt - startDecrypt).count();
        double avgDecryptTime = static_cast<double>(durationDecrypt) / 10000;
        std::cout << "Average decryption time per iteration: " << avgDecryptTime << " microseconds" << std::endl;

        std::vector<uint8_t> decrypted_bytes = cbc_mode.cbc_decrypt(ciphertext_bytes);
        
        // Save decrypted bytes to file
        std::string decryptedTextFilePath = "decrypted_output.text";
        try
        {
            writeBytesToFile(decryptedTextFilePath, decrypted_bytes);
            cout << "Decrypted text saved to: " << decryptedTextFilePath << endl;
        }
        catch (const std::runtime_error &e)
        {
            cerr << e.what() << endl;
            return 1;
        }

        std::string decrypted_text(decrypted_bytes.begin(), decrypted_bytes.end());
        break;
    }
    default:
        cerr << "Invalid choice" << endl;
        return 1;
    }

    return 0;
}
