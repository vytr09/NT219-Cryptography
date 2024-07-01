using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DESAESGUI
{
    public partial class AES : Form
    {
        [DllImport("AESDLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "GenerateKeyAndIV")]
        public static extern void GenerateKeyAndIV(string format, string mode, string keyFile, string ivFile);

        [DllImport("AESDLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "EncryptData")]
        public static extern void EncryptData(string format, string mode, string keyFile, string ivFile, string inputFile, string outputFile);

        [DllImport("AESDLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "DecryptData")]
        public static extern void DecryptData(string format, string mode, string keyFile, string ivFile, string inputFile, string outputFile);
        public AES()
        {
            InitializeComponent();
        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void keyivFormatCbo_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void AESgenKeyIVTxt_Click(object sender, EventArgs e)
        {
            if (keyivFormatCbo.SelectedItem == null || genkeyModeCbo.SelectedItem == null || genkeyTxt.Text == "" || genivTxt.Text == "")
            {
                MessageBox.Show("Please enter all the required fields");
            }
            else
            {
                GenerateKeyAndIV(keyivFormatCbo.SelectedItem.ToString(), genkeyModeCbo.SelectedItem.ToString(), genkeyTxt.Text, genivTxt.Text);
                MessageBox.Show("Key and IV generated successfully");
            }
        }

        private void AESEncryptBtn_Click(object sender, EventArgs e)
        {
            if (encryptKeyTxt.Text == "" || encryptIVTxt.Text == "" || encryptPlainTxt.Text == "" || encryptCipherTxt.Text == "" || encryptFormatCbo.SelectedItem == null || encryptModeCbo.SelectedItem == null)
            {
                MessageBox.Show("Please enter all the required fields");
            }
            else
            {
                EncryptData(encryptFormatCbo.SelectedItem.ToString(), encryptModeCbo.SelectedItem.ToString(), encryptKeyTxt.Text, encryptIVTxt.Text, encryptPlainTxt.Text, encryptCipherTxt.Text);
                MessageBox.Show("Data encrypted successfully");
            }
        }

        private void decryptBtn_Click(object sender, EventArgs e)
        {
            if (decryptKeyTxt.Text == "" || decryptivTxt.Text == "" || decryptRecoverTxt.Text == "" || decryptCipherTxt.Text == "" || decryptFormatCbo.SelectedItem == null || decryptModeCbo.SelectedItem == null)
            {
                MessageBox.Show("Please enter all the required fields");
            }
            else
            {
                DecryptData(decryptFormatCbo.SelectedItem.ToString(), decryptModeCbo.SelectedItem.ToString(), decryptKeyTxt.Text, decryptivTxt.Text, decryptCipherTxt.Text, decryptRecoverTxt.Text);
                MessageBox.Show("Data decrypted successfully");
            }
        }
    }
}
