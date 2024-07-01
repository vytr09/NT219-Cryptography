using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RSA
{
    public partial class RSA : Form
    {
        [DllImport("RSADLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "GenerateAndSaveRSAKeys")]
        public static extern void GenerateAndSaveRSAKeys(int keySize, string format, string privateKeyFile, string publicKeyFile);

        [DllImport("RSADLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "RSAencrypt")]
        public static extern void RSAencrypt(string format, string publicKeyFile, string PlaintextFile, string CiphertFile);

        [DllImport("RSADLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "RSAdecrypt")]
        public static extern void RSAdecrypt(string format, string privateKeyFile, string CiphertFile, string PlaintextFile);
        public RSA()
        {
            InitializeComponent();
        }

        private void genkeyBtn_Click(object sender, EventArgs e)
        {
            if (keysizeTxt.Text == "" || keyformatCbo.SelectedItem == null || genPubFileTxt.Text == "" || genPriFileTxt.Text == "")
            {
                MessageBox.Show("Please fill in all fields");
                return;
            }

            int keySize;
            if (!int.TryParse(keysizeTxt.Text, out keySize))
            {
                MessageBox.Show("Invalid key size");
                return;
            }

            string format = keyformatCbo.SelectedItem.ToString();
            string privateKeyFile = genPriFileTxt.Text;
            string publicKeyFile = genPubFileTxt.Text;

            GenerateAndSaveRSAKeys(keySize, format, privateKeyFile, publicKeyFile);

            string absolutePrivateKeyPath = Path.GetFullPath(privateKeyFile);
            string absolutePublicKeyPath = Path.GetFullPath(publicKeyFile);

            MessageBox.Show($"Keys generated successfully.\nPrivate Key Location: {absolutePrivateKeyPath}\nPublic Key Location: {absolutePublicKeyPath}");
        }

        private void encryptBtn_Click(object sender, EventArgs e)
        {
            if (pubKeyEncryptTxt.Text == "" || plainEncryptTxt.Text == "" || cipherEncrtptTxt.Text == "" || encryptformatCbo.SelectedItem == null)
            {
                MessageBox.Show("Please fill in all fields");
                return;
            }

            string format = encryptformatCbo.SelectedItem.ToString();
            string publicKeyFile = pubKeyEncryptTxt.Text;
            string PlaintextFile = plainEncryptTxt.Text;
            string CiphertFile = cipherEncrtptTxt.Text;
            RSAencrypt(format, publicKeyFile, PlaintextFile, CiphertFile);

            string absolutePlaintextPath = Path.GetFullPath(CiphertFile);
            MessageBox.Show($"Encryption successful.\nCiphertext Location: {absolutePlaintextPath}");
        }

        private void decryptBtn_Click(object sender, EventArgs e)
        {
            if (priKeyDecryptTxt.Text == "" || cipherDecryptTxt.Text == "" || recoveredDecryptTxt.Text == "" || decryptformatCbo.SelectedItem == null)
            {
                MessageBox.Show("Please fill in all fields");
                return;
            }

            string format = decryptformatCbo.SelectedItem.ToString();
            string privateKeyFile = priKeyDecryptTxt.Text;
            string CiphertFile = cipherDecryptTxt.Text;
            string PlaintextFile = recoveredDecryptTxt.Text;
            RSAdecrypt(format, privateKeyFile, CiphertFile, PlaintextFile);

            string absolutePlaintextPath = Path.GetFullPath(PlaintextFile);
            MessageBox.Show($"Decryption successful.\nRecovered Plaintext Location: {absolutePlaintextPath}");
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void keyformatCbo_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
