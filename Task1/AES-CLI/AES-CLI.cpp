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
using CryptoPP::BufferedTransformation;
using CryptoPP::AuthenticatedSymmetricCipher;

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
using CryptoPP::AuthenticatedEncryptionFilter;
using CryptoPP::AuthenticatedDecryptionFilter;
using CryptoPP::ArraySink;
using CryptoPP::ArraySource;
using CryptoPP::Redirector;

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

#include "cryptopp/aes.h"
using CryptoPP::AES;

#include "cryptopp/files.h"
using CryptoPP::FileSink;
using CryptoPP::FileSource;

#include "cryptopp/secblock.h"
using CryptoPP::SecByteBlock;

#include "assert.h"

int main(int argc, char* argv[])
{
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #elif __linux__
        std::locale::global(std::locale("C.utf8"));
    #endif
    
	AutoSeededRandomPool prng;
	string encoded;

    cout << "Select mode, enter mode's number (1.ECB, 2.CBC, 3.OFB, 4.CFB, 5.CTR, 6.XTS, 7.CCM, 8.GCM): ";
    int mode;
    cin >> mode;
    int keysize, ivsize;

    if (mode < 1 || mode > 8)
    {
        cout << "Input is incorrect, please enter 1, 2, 3, 4, 5, 6, 7 or 8 for your task." << endl;
        exit(1);
    }
    else if (mode == 6)
    {
        keysize = 32;
        ivsize = 16;
    }
    else if (mode == 7)
    {
        cout << "Enter your iv size (7, 8, 9, 10, 11, 12, 13): ";
        cin >> ivsize;
        if (ivsize < 7 || ivsize > 13)
        {
            cout << "Input is incorrect, please enter 7, 8, 9, 10, 11, 12 or 13 for your task." << endl;
            exit(1);
        }
        keysize = AES::DEFAULT_KEYLENGTH;
    }
    else {
        keysize = AES::DEFAULT_KEYLENGTH;
        ivsize = AES::BLOCKSIZE;
    }
    
	cout << "\nWhat would you like to do?";
	cout << "\n1.AES Encryption.";
	cout << "\n2.AES Decryption.\n";
	int actions;
	cin >> actions;

    string plain, recovered;
    string cipher, cipherhex, cipherbase64;
    SecByteBlock key(keysize);
    SecByteBlock iv(ivsize);

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
                    prng.GenerateBlock(iv, iv.size());
                    StringSource(iv, iv.size(), true,
                            new FileSink("iv.bin", true)
                    );
                    StringSource(iv, iv.size(), true,
                            new StringSink(encoded)
                    );
                    cout << "iv (binary): " << encoded << endl;
                    encoded.clear();

                    StringSource(iv, iv.size(), true,
                            new HexEncoder(
                                new StringSink(encoded)
                            )
                    );
                    StringSource(iv, iv.size(), true,
                            new HexEncoder(new FileSink("iv.hex", true))
                    );
                    cout << "iv (hex): " << encoded << endl;

                    encoded.clear();
                    StringSource(iv, iv.size(), true,
                            new Base64Encoder(
                                new StringSink(encoded)
                            )
                    );
                    StringSource(iv, iv.size(), true,
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
                                new ArraySink(iv, iv.size())
                        );
                        break;
                    }
                    case 2: {
                        StringSource(keystring, true,
                                new HexDecoder(
                                    new ArraySink(iv, iv.size())
                                )
                        );
                        break;
                    }
                    case 3: {
                        StringSource(keystring, true,
                                new Base64Decoder(
                                    new ArraySink(iv, iv.size())
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
                                new ArraySink(iv, iv.size()), true
                        ); // FileSource
                        break;
                    }
                    case 2: {
                        FileSource(ivfile, true,
                                new HexDecoder(
                                    new ArraySink(iv, iv.size())
                                ), true
                        ); // FileSource
                        break;
                    }
                    case 3: {
                        FileSource(ivfile, true,
                                new Base64Decoder(
                                    new ArraySink(iv, iv.size())
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
                ECB_Mode<AES>::Encryption encryptor;
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
                    test.clear();
                    total_duration += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                }

                break;
            }
            case 2: {
                CBC_Mode<AES>::Encryption encryptor;
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
                OFB_Mode<AES>::Encryption encryptor;
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
                CFB_Mode<AES>::Encryption encryptor;
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
                CTR_Mode<AES>::Encryption encryptor;
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
            case 6: {
                XTS_Mode<AES>::Encryption encryptor;
                encryptor.SetKeyWithIV(key, key.size(), iv);
                StringSource(plain, true, 
                    new StreamTransformationFilter(encryptor,
                        new StringSink(cipher),
                        StreamTransformationFilter::NO_PADDING
                    ) // StreamTransformationFilter
                ); // StringSource

                for (int i = 0; i < iterations; ++i) {
                    auto start = std::chrono::steady_clock::now();

                    StringSource(p, true, 
                         new StreamTransformationFilter(encryptor,
                             new StringSink(test),
                             StreamTransformationFilter::NO_PADDING
                         ) // StreamTransformationFilter
                     ); // StringSource

                    auto end = std::chrono::steady_clock::now();
                    test.clear();
                    total_duration += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                }

                break;
            }
            case 7: {
                SecByteBlock key1 = key;
                SecByteBlock iv1 = iv;
                const int TAG_SIZE = 8;
                CCM<AES,TAG_SIZE>::Encryption encryptor;
                encryptor.SetKeyWithIV(key, key.size(), iv, iv.size());
                encryptor.SpecifyDataLengths(0, plain.size(), 0);
                StringSource ss1(plain, true, 
                    new AuthenticatedEncryptionFilter(encryptor,
                        new StringSink(cipher)
                    ) // AuthenticatedEncryptionFilter
                ); // StringSource

                for (int i = 0; i < iterations; ++i) {
                    CCM<AES,TAG_SIZE>::Encryption e;
                    e.SetKeyWithIV(key1, key1.size(), iv1, iv1.size());
                    e.SpecifyDataLengths(0, p.size(), 0);
                    auto start = std::chrono::steady_clock::now();

                    StringSource(p, true, 
                         new AuthenticatedEncryptionFilter(e,
                             new StringSink(test)
                         ) // AuthenticatedEncryptionFilter
                     ); // StringSource

                    auto end = std::chrono::steady_clock::now();
                    test.clear();
                    total_duration += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                }

                break;
            }
            case 8: {
                SecByteBlock key1 = key;
                SecByteBlock iv1 = iv;
                GCM<AES>::Encryption encryptor;
                encryptor.SetKeyWithIV(key, key.size(), iv, ivsize);
                StringSource(plain, true, 
                    new AuthenticatedEncryptionFilter(encryptor,
                        new StringSink(cipher), false, 12
                    ) // AuthenticatedEncryptionFilter
                ); // StringSource

                for (int i = 0; i < iterations; ++i) {
                    GCM<AES>::Encryption e;
                    e.SetKeyWithIV(key1, key1.size(), iv1, iv1.size());
                    auto start = std::chrono::steady_clock::now();

                    StringSource(p, true, 
                         new AuthenticatedEncryptionFilter(e,
                             new StringSink(test), false, 12
                         ) // AuthenticatedEncryptionFilter
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
                    prng.GenerateBlock(iv, iv.size());
                    StringSource(iv, iv.size(), true,
                            new FileSink("iv.bin", true)
                    );
                    StringSource(iv, iv.size(), true,
                            new StringSink(encoded)
                    );
                    cout << "iv (binary): " << encoded << endl;
                    encoded.clear();

                    StringSource(iv, iv.size(), true,
                            new HexEncoder(
                                new StringSink(encoded)
                            )
                    );
                    StringSource(iv, iv.size(), true,
                            new HexEncoder(new FileSink("iv.hex", true))
                    );
                    cout << "iv (hex): " << encoded << endl;

                    encoded.clear();
                    StringSource(iv, iv.size(), true,
                            new Base64Encoder(
                                new StringSink(encoded)
                            )
                    );
                    StringSource(iv, iv.size(), true,
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
                                new ArraySink(iv, iv.size())
                        );
                        break;}
                    case 2:
                        {StringSource(keystring, true,
                                new HexDecoder(
                                    new ArraySink(iv, iv.size())
                                )
                        );
                        break;}
                    case 3:
                        {StringSource(keystring, true,
                                new Base64Decoder(
                                    new ArraySink(iv, iv.size())
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
                                new ArraySink(iv, iv.size()), true
                        ); // FileSource
                        break;
                    }
                    case 2: {
                        FileSource(ivfile, true,
                                new HexDecoder(
                                    new ArraySink(iv, iv.size())
                                ), true
                        ); // FileSource
                        break;
                    }
                    case 3: {
                        FileSource(ivfile, true,
                                new Base64Decoder(
                                    new ArraySink(iv, iv.size())
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
                ECB_Mode<AES>::Decryption decryptor;
                decryptor.SetKey(key, key.size());
                StringSource s(cipher, true,
                    new StreamTransformationFilter(decryptor,
                        new StringSink(recovered)
                    ) // StreamTransformationFilter
                ); // StringSource

                for (int i = 0; i < iterations; ++i) {
                    auto start = std::chrono::steady_clock::now();

                    StringSource s1(c, true,
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
                CBC_Mode<AES>::Decryption decryptor;
                decryptor.SetKeyWithIV(key, key.size(), iv);

                StringSource s(cipher, true,
                    new StreamTransformationFilter(decryptor,
                        new StringSink(recovered)
                    ) // StreamTransformationFilter
                ); // StringSource

                for (int i = 0; i < iterations; ++i) {
                     auto start = std::chrono::steady_clock::now();

                     StringSource s1(c, true,
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
                OFB_Mode<AES>::Decryption decryptor;
                decryptor.SetKeyWithIV(key, key.size(), iv);
                StringSource s(cipher, true,
                    new StreamTransformationFilter(decryptor,
                        new StringSink(recovered)
                    ) // StreamTransformationFilter
                ); // StringSource

                for (int i = 0; i < iterations; ++i) {
                    auto start = std::chrono::steady_clock::now();

                    StringSource s1(c, true,
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
                CFB_Mode<AES>::Decryption decryptor;
                decryptor.SetKeyWithIV(key, key.size(), iv);
                StringSource s(cipher, true,
                    new StreamTransformationFilter(decryptor,
                        new StringSink(recovered)
                    ) // StreamTransformationFilter
                ); // StringSource

                for (int i = 0; i < iterations; ++i) {
                    auto start = std::chrono::steady_clock::now();

                    StringSource s1(c, true,
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
                CTR_Mode<AES>::Decryption decryptor;
                decryptor.SetKeyWithIV(key, key.size(), iv);
                StringSource s(cipher, true,
                    new StreamTransformationFilter(decryptor,
                        new StringSink(recovered)
                    ) // StreamTransformationFilter
                ); // StringSource

                for (int i = 0; i < iterations; ++i) {
                    auto start = std::chrono::steady_clock::now();

                    StringSource s1(c, true,
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
            case 6: {
                XTS_Mode<AES>::Decryption decryptor;
                decryptor.SetKeyWithIV(key, key.size(), iv);
                StringSource s(cipher, true,
                    new StreamTransformationFilter(decryptor,
                        new StringSink(recovered),
                        StreamTransformationFilter::NO_PADDING
                    ) // StreamTransformationFilter
                ); // StringSource

                for (int i = 0; i < iterations; ++i) {
                    auto start = std::chrono::steady_clock::now();

                    StringSource s1(c, true,
                        new StreamTransformationFilter(decryptor,
                            new StringSink(test),
                            StreamTransformationFilter::NO_PADDING
                        ) // StreamTransformationFilter
                    ); // StringSource

                    auto end = std::chrono::steady_clock::now();
                    test.clear();
                    total_duration += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                }

                break;
            }
            case 7: {
                SecByteBlock key1 = key;
                SecByteBlock iv1 = iv;

                const int TAG_SIZE = 8;
                CCM<AES,TAG_SIZE>::Decryption decryptor;
                decryptor.SetKeyWithIV(key, key.size(), iv, iv.size());
                decryptor.SpecifyDataLengths(0, cipher.size()-TAG_SIZE, 0);

                AuthenticatedDecryptionFilter df(decryptor,
                    new StringSink(recovered)
                ); // AuthenticatedDecryptionFilter

                // The StringSource dtor will be called immediately
                //  after construction below. This will cause the
                //  destruction of objects it owns. To stop the
                //  behavior so we can get the decoding result from
                //  the DecryptionFilter, we must use a redirector
                //  or manually Put(...) into the filter without
                //  using a StringSource.
                StringSource ss2( cipher, true,
                    new Redirector( df )
                ); // StringSource

                for (int i = 0; i < iterations; ++i) {
                    CCM<AES,TAG_SIZE>::Decryption d;
                    d.SetKeyWithIV(key1, key1.size(), iv1, iv1.size());
                    d.SpecifyDataLengths(0, c.size()-TAG_SIZE, 0);
                    auto start = std::chrono::steady_clock::now();

                    AuthenticatedDecryptionFilter df1(d,
                           new StringSink(test)
                       ); // AuthenticatedDecryptionFilter
                    StringSource ss3( c, true,
                           new Redirector( df1 )
                       ); // StringSource

                    auto end = std::chrono::steady_clock::now();
                    test.clear();
                    total_duration += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                }

                break;
            }
            case 8: {
                SecByteBlock key1 = key;
                SecByteBlock iv1 = iv;
                GCM<AES>::Decryption decryptor;
                decryptor.SetKeyWithIV(key, key.size(), iv, iv.size());
                AuthenticatedDecryptionFilter df( decryptor,
                    new StringSink( recovered ),
                    false, 12
                ); // AuthenticatedDecryptionFilter
                // The StringSource dtor will be called immediately
                //  after construction below. This will cause the
                //  destruction of objects it owns. To stop the
                //  behavior so we can get the decoding result from
                //  the DecryptionFilter, we must use a redirector
                //  or manually Put(...) into the filter without
                //  using a StringSource.
                StringSource ss2( cipher, true,
                    new Redirector( df /*, PASS_EVERYTHING */ )
                ); // StringSource

                for (int i = 0; i < iterations; ++i) {
                    GCM<AES>::Decryption d;
                    d.SetKeyWithIV(key1, key1.size(), iv1, iv1.size());

                    auto start = std::chrono::steady_clock::now();
                    AuthenticatedDecryptionFilter df1( d,
                         new StringSink( test ),
                         false, 12
                     ); // AuthenticatedDecryptionFilter
                    StringSource ss3( c, true,
                     new Redirector( df1 /*, PASS_EVERYTHING */ )
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

