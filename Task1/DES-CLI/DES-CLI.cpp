// g++ -g3 -ggdb -O0 -DDEBUG -I/usr/include/cryptopp Driver.cpp -o Driver.exe -lcryptopp -lpthread
// g++ -g -O2 -DNDEBUG -I/usr/include/cryptopp Driver.cpp -o Driver.exe -lcryptopp -lpthread
#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
#include <chrono>


// Vietnamese utf-8
#ifdef _WIN32
#include <windows.h>
#endif
#include <locale>
#include <cctype>
#include <codecvt>

#include <string>
using std::string;

#include <cstdlib>
using std::exit;

#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include "cryptopp/cryptlib.h"
using CryptoPP::Exception;

#include "cryptopp/hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

#include "cryptopp/base64.h"
using CryptoPP::Base64Encoder;
using CryptoPP::Base64Decoder;


#include "cryptopp/filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;
using CryptoPP::ArraySink;
using CryptoPP::ArraySource;

#include "cryptopp/modes.h"
using CryptoPP::ECB_Mode;
using CryptoPP::CBC_Mode;
using CryptoPP::OFB_Mode;
using CryptoPP::CTR_Mode; 
using CryptoPP::CFB_Mode;
using CryptoPP::CTR_Mode;
#include "cryptopp/xts.h"
using CryptoPP::XTS;

#include "cryptopp/ccm.h"
using CryptoPP::CCM;

#include "cryptopp/gcm.h"
using CryptoPP::GCM;

#include "cryptopp/des.h"
using CryptoPP::DES;

#include "cryptopp/aes.h"
using CryptoPP::AES;

#include "cryptopp/ccm.h"
using CryptoPP::CBC_Mode;

#include "cryptopp/files.h"
using CryptoPP::FileSink;
using CryptoPP::FileSource;

#include "cryptopp/secblock.h"
using CryptoPP::SecByteBlock;

#include "assert.h"

std::wstring StringToWString(const string& str) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(str);
}

string WStringToString(const std::wstring& wstr) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wstr);
}

int main(int argc, char* argv[])
{
    #ifdef _WIN32
        // _setmode(_fileno(stdin), _O_U16TEXT);
        // _setmode(_fileno(stdout), _O_U16TEXT);
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #elif __linux__
        // setlocale(LC_ALL, "");
        std::locale::global(std::locale("C.utf8"));
    #endif
    
	AutoSeededRandomPool prng;
	string encoded;

    cout << "Select mode, enter mode's number (1.ECB, 2.CBC, 3.OFB, 4.CFB, 5.CTR): ";
    int mode;
    cin >> mode;

    if (mode < 1 || mode > 5)
    {
        cout << "Input is incorrect, please enter 1, 2, 3, 4, 5 for your task." << endl;
        exit(1);
    }

	cout << "\nWhat would you like to do?";
	cout << "\n1.DES Encryption.";
	cout << "\n2.DES Decryption.\n";
	int actions;
	cin >> actions;

    string plain, recovered;
    string cipher, cipherhex, cipherbase64;
    SecByteBlock key(DES::DEFAULT_KEYLENGTH);
	CryptoPP::byte iv[DES::BLOCKSIZE];

	switch (actions)
	{
		case 1:
		{
            cout << "\nChoose your key mode (1.Autogenerate, 2.Input your key, 3.Choose from file): \n";
            int keymode;
            cin >> keymode;

            switch (keymode)
            {
            case 1:
            {
                prng.GenerateBlock(key, key.size());
                StringSource(key, key.size(), true,
                            new StringSink(encoded)
                );
                StringSource(key, key.size(), true,
                        new FileSink("key.bin", true)
                );
                cout << "key (binary): " << encoded << endl;
                encoded.clear();

                StringSource(key, key.size(), true,
                        new HexEncoder(
                            new StringSink(encoded)
                        )
                );
                StringSource(key, key.size(), true,
                        new HexEncoder(new FileSink("key.hex", true))
                );
                cout << "key (hex): " << encoded << endl;
                encoded.clear();

                StringSource(key, key.size(), true,
                        new Base64Encoder(
                            new StringSink(encoded)
                        )
                );
                StringSource(key, key.size(), true,
                        new Base64Encoder(new FileSink("key.pem", true))
                );
                cout << "key (base64): " << encoded << endl;
                encoded.clear();

                if (mode != 1)
                {
                    prng.GenerateBlock(iv, sizeof(iv));
                    StringSource(iv, sizeof(iv), true,
                            new FileSink("iv.bin", true)
                    );
                    StringSource(iv, sizeof(iv), true,
                            new StringSink(encoded)
                    );
                    cout << "iv (binary): " << encoded << endl;
                    encoded.clear();

                    StringSource(iv, sizeof(iv), true,
                            new HexEncoder(
                                new StringSink(encoded)
                            )
                    );
                    StringSource(iv, sizeof(iv), true,
                            new HexEncoder(new FileSink("iv.hex", true))
                    );
                    cout << "iv (hex): " << encoded << endl;

                    encoded.clear();
                    StringSource(iv, sizeof(iv), true,
                            new Base64Encoder(
                                new StringSink(encoded)
                            )
                    );
                    StringSource(iv, sizeof(iv), true,
                            new Base64Encoder(new FileSink("iv.pem", true))
                    );
                    cout << "iv (base64): " << encoded << endl;
                }
                break;

            }
            case 2:
            {
                string keystring;
                cout << "Enter your key: ";
                cin.ignore();
                getline(cin, keystring);
                cout << "Enter your key format (1.Binary, 2.Hex, 3.Base64): ";
                int format;
                cin >> format;
                switch (format)
                {
                case 1: {
                    StringSource(keystring, true,
                            new ArraySink(key, key.size())
                    );
                    break;
                }
                case 2: {
                    StringSource(keystring, true,
                            new HexDecoder(
                                new ArraySink(key, key.size())
                            )
                    );
                    break;
                }
                case 3: {
                    StringSource(keystring, true,
                            new Base64Decoder(
                                new ArraySink(key, key.size())
                            )
                    );
                    break;
                }
                
                default:
                    {
                        cout << "Input is incorrect, please enter 1, 2 or 3 for your task." << endl;
                        exit(1);
                    }
                }

                if (mode != 1)
                {
                    cout << "Enter your iv: ";
                    cin.ignore();
                    getline(cin, keystring);
                    cout << "Enter your iv format (1.Binary, 2.Hex, 3.Base64): ";
                    cin >> format;
                    switch (format)
                    {
                    case 1: {
                        StringSource(keystring, true,
                                new ArraySink(iv, sizeof(iv))
                        );
                        break;
                    }
                    case 2: {
                        StringSource(keystring, true,
                                new HexDecoder(
                                    new ArraySink(iv, sizeof(iv))
                                )
                        );
                        break;
                    }
                    case 3: {
                        StringSource(keystring, true,
                                new Base64Decoder(
                                    new ArraySink(iv, sizeof(iv))
                                )
                        );
                        break;
                    }
                    default:
                        {
                            cout << "Input is incorrect, please enter 1, 2 or 3 for your task." << endl;
                            exit(1);
                        }
                    }
                    
                }
                break;
            }
            case 3:
            {
                char keyfile[100];
                char ivfile[100];

                cout << "Enter your key's file name: ";
                cin >> keyfile;
                cout << "Enter your key file's format (1.Binary, 2.Hex, 3.Base64): ";
                int format;
                cin >> format;
                switch (format)
                {
                case 1: {
                    FileSource(keyfile, true,
                            new ArraySink(key, key.size()), true
                    ); // FileSource
                    break;
                }
                case 2: {
                    FileSource(keyfile, true,
                            new HexDecoder(
                                new ArraySink(key, key.size())
                            ), true
                    ); // FileSource
                    break;
                }
                case 3: {
                    FileSource(keyfile, true,
                            new Base64Decoder(
                                new ArraySink(key, key.size())
                            ), true
                    ); // FileSource
                    break;
                }
                default:
                    {
                        cout << "Input is incorrect, please enter 1, 2 or 3 for your task." << endl;
                        exit(1);
                    }
                }
                if (mode != 1)
                {
                    cout << "Enter your iv's file name: ";
                    cin >> ivfile;
                    cout << "Enter your iv file's format (1.Binary, 2.Hex, 3.Base64): ";
                    cin >> format;
                    switch (format)
                    {
                    case 1: {
                        FileSource(ivfile, true,
                                new ArraySink(iv, sizeof(iv)), true
                        ); // FileSource
                        break;
                    }
                    case 2: {
                        FileSource(ivfile, true,
                                new HexDecoder(
                                    new ArraySink(iv, sizeof(iv))
                                ), true
                        ); // FileSource
                        break;
                    }
                    case 3: {
                        FileSource(ivfile, true,
                                new Base64Decoder(
                                    new ArraySink(iv, sizeof(iv))
                                ), true
                        ); // FileSource
                        break;
                    }
                    default:
                        {
                            cout << "Input is incorrect, please enter 1, 2 or 3 for your task." << endl;
                            exit(1);
                        }
                    }
                    
                }
                break;
            }
            
            default:
                {
                    cout << "Input is incorrect, please enter 1, 2 or 3 for your task." << endl;
                    exit(1);
                }
            }

            cout << "\nChoose your plaintext mode (1.Input your plaintext, 2.Choose from file): \n";
            int plainmode;
            cin >> plainmode;

            switch (plainmode)
            {
            case 1:
            {
                cout << "Enter your plain text: ";
                cin.ignore();
                getline(cin, plain);
                break;
            }
            case 2:
            {
                char plainfile[100];
                cout << "Enter your plain text's file name: ";
                cin >> plainfile;

                FileSource(plainfile, true,
                        new StringSink(plain), true
                ); // FileSource

                break;
            }
            
            default:
                {
                    cout << "Input is incorrect, please enter 1 or 2 for your task." << endl;
                    exit(1);
                }
            }
            long long total_duration = 0;
            const int iterations = 10000;
            
            string test;
            string p = plain;

            switch (mode)
            {
            case 1: {
                ECB_Mode<DES>::Encryption encryptor;
                encryptor.SetKey(key, key.size());
                StringSource(plain, true, 
                    new StreamTransformationFilter(encryptor,
                        new StringSink(cipher)
                    ) // StreamTransformationFilter
                ); // StringSource

                for (int i = 0; i < iterations; ++i) {
                    auto start = std::chrono::steady_clock::now();
                    StringSource(p, true, 
                         new StreamTransformationFilter(encryptor,
                             new StringSink(test)
                         ) // StreamTransformationFilter
                    ); // StringSource
                    auto end = std::chrono::steady_clock::now();
                    total_duration += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                    test.clear();
                }
                break;
            }
            case 2: {
                CBC_Mode<DES>::Encryption encryptor;
                encryptor.SetKeyWithIV(key, key.size(), iv);

                StringSource(plain, true, 
                    new StreamTransformationFilter(encryptor,
                        new StringSink(cipher)
                    ) // StreamTransformationFilter
                ); // StringSource

                 for (int i = 0; i < iterations; ++i) {
                     auto start = std::chrono::steady_clock::now();

                     StringSource(p, true, 
                         new StreamTransformationFilter(encryptor,
                             new StringSink(test)
                         ) // StreamTransformationFilter
                     ); // StringSource

                     auto end = std::chrono::steady_clock::now();
                     test.clear();
                     total_duration += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                 }

                break;
            }
            case 3: {
                OFB_Mode<DES>::Encryption encryptor;
                encryptor.SetKeyWithIV(key, key.size(), iv);
                StringSource(plain, true, 
                    new StreamTransformationFilter(encryptor,
                        new StringSink(cipher)
                    ) // StreamTransformationFilter
                ); // StringSource

                for (int i = 0; i < iterations; ++i) {
                    auto start = std::chrono::steady_clock::now();

                    StringSource(p, true, 
                        new StreamTransformationFilter(encryptor,
                            new StringSink(test)
                        ) // StreamTransformationFilter
                    ); // StringSource

                    auto end = std::chrono::steady_clock::now();
                    test.clear();
                    total_duration += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                }

                break;
            }
            case 4: {
                CFB_Mode<DES>::Encryption encryptor;
                encryptor.SetKeyWithIV(key, key.size(), iv);
                StringSource(plain, true, 
                    new StreamTransformationFilter(encryptor,
                        new StringSink(cipher)
                    ) // StreamTransformationFilter
                ); // StringSource

                for (int i = 0; i < iterations; ++i) {
                    auto start = std::chrono::steady_clock::now();

                    StringSource(p, true, 
                        new StreamTransformationFilter(encryptor,
                            new StringSink(test)
                        ) // StreamTransformationFilter
                    ); // StringSource

                    auto end = std::chrono::steady_clock::now();
                    test.clear();
                    total_duration += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                }

                break;
            }
            case 5: {
                CTR_Mode<DES>::Encryption encryptor;
                encryptor.SetKeyWithIV(key, key.size(), iv);
                StringSource(plain, true, 
                    new StreamTransformationFilter(encryptor,
                        new StringSink(cipher)
                    ) // StreamTransformationFilter
                ); // StringSource

                for (int i = 0; i < iterations; ++i) {
                    auto start = std::chrono::steady_clock::now();

                    StringSource(p, true, 
                        new StreamTransformationFilter(encryptor,
                            new StringSink(test)
                        ) // StreamTransformationFilter
                    ); // StringSource

                    auto end = std::chrono::steady_clock::now();
                    test.clear();
                    total_duration += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                }

                break;
            }
            
            default:
                {
                    cout << "Input is incorrect, please enter 1, 2, 3, 4, 5 for your task." << endl;
                    exit(1);
                }
            }

            StringSource(cipher, true,
                new FileSink("cipher.bin", true)
            );
            cout << "cipher text (bin): " << cipher << endl;
            StringSource(cipher, true,
                new HexEncoder(
                    new StringSink(cipherhex)
                )
            );
            cout << "cipher text (hex): " << cipherhex << endl;
            StringSource(cipherhex, true,
                new FileSink("cipher.hex", true)
            );

            StringSource(cipher, true,
                new Base64Encoder(
                    new StringSink(cipherbase64)
                )
            );
            cout << "cipher text (base64): " << cipherbase64 << endl;
            StringSource(cipherbase64, true,
                new FileSink("cipher.pem", true)
            );
            double average_duration = static_cast<double>(total_duration) / iterations;
            cout << "Average time taken for " << iterations << " iterations: " << average_duration << " microseconds" << std::endl;

			break;
		}
		case 2:
		{
            cout << "\nChoose your key mode (1.Autogenerate, 2.Input your key, 3.Choose from file): \n";
            int keymode;
            cin >> keymode;

            switch (keymode)
            {
            case 1:
            {
                prng.GenerateBlock(key, key.size());
                StringSource(key, key.size(), true,
                            new StringSink(encoded)
                );
                StringSource(key, key.size(), true,
                        new FileSink("key.bin", true)
                );
                cout << "key (binary): " << encoded << endl;
                encoded.clear();

                StringSource(key, key.size(), true,
                        new HexEncoder(
                            new StringSink(encoded)
                        )
                );
                StringSource(key, key.size(), true,
                        new HexEncoder(new FileSink("key.hex", true))
                );
                cout << "key (hex): " << encoded << endl;
                encoded.clear();

                StringSource(key, key.size(), true,
                        new Base64Encoder(
                            new StringSink(encoded)
                        )
                );
                StringSource(key, key.size(), true,
                        new Base64Encoder(new FileSink("key.pem", true))
                );
                cout << "key (base64): " << encoded << endl;
                encoded.clear();

                if (mode != 1)
                {
                    prng.GenerateBlock(iv, sizeof(iv));
                    StringSource(iv, sizeof(iv), true,
                            new FileSink("iv.bin", true)
                    );
                    StringSource(iv, sizeof(iv), true,
                            new StringSink(encoded)
                    );
                    cout << "iv (binary): " << encoded << endl;
                    encoded.clear();

                    StringSource(iv, sizeof(iv), true,
                            new HexEncoder(
                                new StringSink(encoded)
                            )
                    );
                    StringSource(iv, sizeof(iv), true,
                            new HexEncoder(new FileSink("iv.hex", true))
                    );
                    cout << "iv (hex): " << encoded << endl;

                    encoded.clear();
                    StringSource(iv, sizeof(iv), true,
                            new Base64Encoder(
                                new StringSink(encoded)
                            )
                    );
                    StringSource(iv, sizeof(iv), true,
                            new Base64Encoder(new FileSink("iv.pem", true))
                    );
                    cout << "iv (base64): " << encoded << endl;
                }
                break;

            }
            case 2:
            {
                string keystring;
                cout << "Enter your key format (1.Binary, 2.Hex, 3.Base64): ";
                int format;
                cin >> format;
                cout << "Enter your key: ";
                cin.ignore();
                getline(cin, keystring);

                switch (format)
                {
                case 1:
                    StringSource(keystring, true,
                            new ArraySink(key, key.size())
                    );
                    break;
                case 2:
                    StringSource(keystring, true,
                            new HexDecoder(
                                new ArraySink(key, key.size())
                            )
                    );
                    break;
                case 3:
                    StringSource(keystring, true,
                            new Base64Decoder(
                                new ArraySink(key, key.size())
                            )
                    );
                    break;
                default:
                    {
                        cout << "Input is incorrect, please enter 1, 2 or 3 for your task." << endl;
                        exit(1);
                    }
                }

                if (mode != 1)
                {
                    cout << "Enter your iv: ";
                    cin.ignore();
                    getline(cin, keystring);
                    cout << "Enter your iv format (1.Binary, 2.Hex, 3.Base64): ";
                    cin >> format;
                    switch (format)
                    {
                    case 1:
                        {StringSource(keystring, true,
                                new ArraySink(iv, sizeof(iv))
                        );
                        break;}
                    case 2:
                        {StringSource(keystring, true,
                                new HexDecoder(
                                    new ArraySink(iv, sizeof(iv))
                                )
                        );
                        break;}
                    case 3:
                        {StringSource(keystring, true,
                                new Base64Decoder(
                                    new ArraySink(iv, sizeof(iv))
                                )
                        );
                        break;}
                    default:
                        {
                            cout << "Input is incorrect, please enter 1, 2 or 3 for your task." << endl;
                            exit(1);
                        }
                    }
                }
                break;
            }
            case 3:
            {
                char keyfile[100];
                char ivfile[100];

                cout << "Enter your key's file name: ";
                cin >> keyfile;
                cout << "Enter your key file's format (1.Binary, 2.Hex, 3.Base64): ";
                int format;
                cin >> format;
                switch (format)
                {
                case 1: {
                    FileSource(keyfile, true,
                            new ArraySink(key, key.size()), true
                    ); // FileSource
                    break;
                }
                case 2: {
                    FileSource(keyfile, true,
                            new HexDecoder(
                                new ArraySink(key, key.size())
                            ), true
                    ); // FileSource
                    break;
                }
                case 3: {
                    FileSource(keyfile, true,
                            new Base64Decoder(
                                new ArraySink(key, key.size())
                            ), true
                    ); // FileSource
                    break;
                }
                default:
                    {
                        cout << "Input is incorrect, please enter 1, 2 or 3 for your task." << endl;
                        exit(1);
                    }
                }

                if (mode != 1)
                {
                    cout << "Enter your iv's file name: ";
                    cin >> ivfile;
                    cout << "Enter your iv file's format (1.Binary, 2.Hex, 3.Base64): ";
                    cin >> format;

                    switch (format)
                    {
                    case 1: {
                        FileSource(ivfile, true,
                                new ArraySink(iv, sizeof(iv)), true
                        ); // FileSource
                        break;
                    }
                    case 2: {
                        FileSource(ivfile, true,
                                new HexDecoder(
                                    new ArraySink(iv, sizeof(iv))
                                ), true
                        ); // FileSource
                        break;
                    }
                    case 3: {
                        FileSource(ivfile, true,
                                new Base64Decoder(
                                    new ArraySink(iv, sizeof(iv))
                                ), true
                        ); // FileSource
                        break;
                    }
                    default:
                        {
                            cout << "Input is incorrect, please enter 1, 2 or 3 for your task." << endl;
                            exit(1);
                        }
                    }
                }
                break;
            }
            default:
                {
                    cout << "Input is incorrect, please enter 1, 2 or 3 for your task." << endl;
                    exit(1);
                }
            }

            cout << "\nChoose your cipher mode (1.Input your cipher, 2.Choose from file): \n";
            int ciphermode;
            cin >> ciphermode;
            switch (ciphermode)
            {
            case 1: {
                cout << "Enter your cipher text: ";
                cin.ignore();
                getline(cin, cipher);
                break;
            }
            case 2: {
                char cipherfile[100];
                cout << "Enter your cipher text's file name: ";
                cin >> cipherfile;

                cout << "Enter your cipher text's format (1.Binary, 2.Hex, 3.Base64): ";
                int format;
                cin >> format;
                switch (format)
                {
                case 1: {
                    FileSource(cipherfile, true,
                            new StringSink(cipher), true
                    ); // FileSource
                    break;
                }
                case 2: {
                    FileSource(cipherfile, true,
                            new HexDecoder(
                                new StringSink(cipher)
                            ), true
                    ); // FileSource
                    break;
                }
                case 3: {
                    FileSource(cipherfile, true,
                            new Base64Decoder(
                                new StringSink(cipher)
                            ), true
                    ); // FileSource
                    break;
                }
                default:
                    {
                        cout << "Input is incorrect, please enter 1, 2 or 3 for your task." << endl;
                        exit(1);
                    }
                }

                break;
            }
            
            default:
                {
                    cout << "Input is incorrect, please enter 1 or 2 for your task." << endl;
                    exit(1);
                }
            }

            long long total_duration = 0;
            const int iterations = 10000;
            string test;
            string c = cipher;
            switch (mode)
            {
            case 1:
            {
                ECB_Mode<DES>::Decryption decryptor;
                decryptor.SetKey(key, key.size());
                StringSource s(cipher, true,
                    new StreamTransformationFilter(decryptor,
                        new StringSink(recovered)
                    ) // StreamTransformationFilter
                ); // StringSource

                for (int i = 0; i < iterations; ++i) {
                    auto start = std::chrono::steady_clock::now();

                    StringSource s(c, true,
                        new StreamTransformationFilter(decryptor,
                            new StringSink(test)
                        ) // StreamTransformationFilter
                    ); // StringSource

                    auto end = std::chrono::steady_clock::now();
                    test.clear();
                    total_duration += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                }

                break;
            }
            case 2:
           {
                CBC_Mode<DES>::Decryption decryptor;
                decryptor.SetKeyWithIV(key, key.size(), iv);

                StringSource s(cipher, true,
                    new StreamTransformationFilter(decryptor,
                        new StringSink(recovered)
                    ) // StreamTransformationFilter
                ); // StringSource

                for (int i = 0; i < iterations; ++i) {
                    
                     auto start = std::chrono::steady_clock::now();

                     StringSource s(c, true,
                         new StreamTransformationFilter(decryptor,
                             new StringSink(test)
                         ) // StreamTransformationFilter
                     ); // StringSource

                     auto end = std::chrono::steady_clock::now();
                     test.clear();
                     total_duration += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                 }

                break;
            }
            case 3: {
                OFB_Mode<DES>::Decryption decryptor;
                decryptor.SetKeyWithIV(key, key.size(), iv);
                StringSource s(cipher, true,
                    new StreamTransformationFilter(decryptor,
                        new StringSink(recovered)
                    ) // StreamTransformationFilter
                ); // StringSource

                for (int i = 0; i < iterations; ++i) {
                    auto start = std::chrono::steady_clock::now();

                    StringSource s(c, true,
                        new StreamTransformationFilter(decryptor,
                            new StringSink(test)
                        ) // StreamTransformationFilter
                    ); // StringSource

                    auto end = std::chrono::steady_clock::now();
                    test.clear();
                    total_duration += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                }

                break;
            }
            case 4: {
                CFB_Mode<DES>::Decryption decryptor;
                decryptor.SetKeyWithIV(key, key.size(), iv);
                StringSource s(cipher, true,
                    new StreamTransformationFilter(decryptor,
                        new StringSink(recovered)
                    ) // StreamTransformationFilter
                ); // StringSource

                for (int i = 0; i < iterations; ++i) {
                    auto start = std::chrono::steady_clock::now();

                    StringSource s(c, true,
                        new StreamTransformationFilter(decryptor,
                            new StringSink(test)
                        ) // StreamTransformationFilter
                    ); // StringSource

                    auto end = std::chrono::steady_clock::now();
                    test.clear();
                    total_duration += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                }

                break;
            }
            case 5: {
                CTR_Mode<DES>::Decryption decryptor;
                decryptor.SetKeyWithIV(key, key.size(), iv);
                StringSource s(cipher, true,
                    new StreamTransformationFilter(decryptor,
                        new StringSink(recovered)
                    ) // StreamTransformationFilter
                ); // StringSource

                for (int i = 0; i < iterations; ++i) {
                    auto start = std::chrono::steady_clock::now();

                    StringSource s(c, true,
                        new StreamTransformationFilter(decryptor,
                            new StringSink(test)
                        ) // StreamTransformationFilter
                    ); // StringSource

                    auto end = std::chrono::steady_clock::now();
                    test.clear();
                    total_duration += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                }

                break;
            }
            default: {
                cout << "Input is incorrect, please enter 1, 2, 3, 4, 5 for your task." << endl;
                exit(1);
            }
            }
            
            cout << "recovered text: " << recovered << endl;
            StringSource(recovered, true,
                new FileSink("recovered.txt", true)
            );

            double average_duration = static_cast<double>(total_duration) / iterations;
            std::cout << "Average time taken for " << iterations << " iterations: " << average_duration << " microseconds" << std::endl;
		break;
		}
		default: cout << "Input is incorrect, please enter 1 or 2 for your task." << endl;
	}
	return 0;
}

