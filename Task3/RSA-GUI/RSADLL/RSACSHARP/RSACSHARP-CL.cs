using System;
using System.Runtime.InteropServices;

[DllImport("RSADLL.dll", CallingConvention = CallingConvention.Cdecl, Charset = CharSet.Unicode, EntryPoint = "GenerateAndSaveRSAKeys")]
public static extern void GenerateAndSaveRSAKeys(int keySize, const char* format, const char* privateKeyFile, const char* publicKeyFile);

[DllImport("RSADLL.dll", CallingConvention = CallingConvention.Cdecl, Charset = CharSet.Unicode, EntryPoint = "RSAencrypt")]
public static extern void RSAencrypt(const char* format, const char* publicKeyFile, const char* PlaintextFile, const char* CiphertFile);

[DllImport("RSADLL.dll", CallingConvention = CallingConvention.Cdecl, Charset = CharSet.Unicode, EntryPoint = "RSAdecrypt")]
public static extern void RSAdecrypt(const char* format, const char* secretKeyFile, const char* ciphertFile, const char* PlaintextFile);

class Program
{
    static void Main(string[] args)
    {
        if (Environment.OSVersion.Platform == PlatformID.Win32NT)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;
            Console.InputEncoding = System.Text.Encoding.UTF8;
        }
    }
}
