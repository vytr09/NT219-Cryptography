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
    public partial class Form1 : Form
    {
        [DllImport("DESDLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "GenerateDESKey")]
        public static extern void GenerateDESKey(string keyFile, string ivFile, string format);

        [DllImport("DESDLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "DESEncrypt")]
        public static extern void DESEncrypt(string keyFile, string ivFile, string plaintextFile, string cipherFile, string format, string mode);

        [DllImport("DESDLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "DESDecrypt")]
        public static extern void DESDecrypt(string keyFile, string ivFile, string cipherFile, string plaintextFile, string format, string mode);
        public Form1()
        {
            InitializeComponent();
        }

        private void genKeyIVTxt_Click(object sender, EventArgs e)
        {
            if (genkeyTxt.Text == "" || genivTxt.Text == "" || keyivFormatCbo.SelectedItem == null)
            {
                MessageBox.Show("Please enter the key and IV file names");
            }
            else
            {
                GenerateDESKey(genkeyTxt.Text, genivTxt.Text, keyivFormatCbo.SelectedItem.ToString());
                MessageBox.Show("Key and IV generated successfully");
            }
        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void DESEncryptBtn_Click(object sender, EventArgs e)
        {
            if (encryptKeyTxt.Text == "" || encryptIVTxt.Text == "" || encryptPlainTxt.Text == "" || encryptCipherTxt.Text == "" || encryptFormatCbo.SelectedItem == null || encryptModeCbo.SelectedItem == null)
            {
                MessageBox.Show("Please enter all the required fields");
            }
            else
            {
                DESEncrypt(encryptKeyTxt.Text, encryptIVTxt.Text, encryptPlainTxt.Text, encryptCipherTxt.Text, encryptFormatCbo.SelectedItem.ToString(), encryptModeCbo.SelectedItem.ToString());
                MessageBox.Show("Encryption successful");
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void decryptBtn_Click(object sender, EventArgs e)
        {
            if (decryptKeyTxt.Text == "" || decryptivTxt.Text == "" || decryptCipherTxt.Text == "" || decryptRecoverTxt.Text == "" || decryptFormatCbo.SelectedItem == null || decryptModeCbo.SelectedItem == null)
            {
                MessageBox.Show("Please enter all the required fields");
            }
            else
            {
                DESDecrypt(decryptKeyTxt.Text,decryptivTxt.Text,decryptCipherTxt.Text,decryptRecoverTxt.Text,decryptFormatCbo.SelectedItem.ToString(),decryptModeCbo.SelectedItem.ToString());
                MessageBox.Show("Decryption successful");
            }
        }
    }
}
