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

namespace DigitalSignature
{
    public partial class Form1 : Form
    {
        // Importing generateKeys function
        [DllImport("digital_signature.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "generateKeys")]
        private static extern bool GenerateKeys(string keyType, string curveOrKeySize, string publicKeyPath, string privateKeyPath);

        // Importing sign function
        [DllImport("digital_signature.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "sign")]
        private static extern bool Sign(string privateKeyPath, string messagePath, string signaturePath, string algorithm);

        // Importing verifySignature function
        [DllImport("digital_signature.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "verifySignature")]
        private static extern bool VerifySignature(string publicKeyPath, string messagePath, string signaturePath, string algorithm);

        public Form1()
        {
            InitializeComponent();
        }

        private void genkeyBtn_Click(object sender, EventArgs e)
        {
            string keyType = algoBox.SelectedItem?.ToString();
            if (string.IsNullOrEmpty(keyType))
            {
                MessageBox.Show("Please select an algorithm.", "Input Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            string curveOrKeySize = keyType == "ECDSA" ? curveBox.SelectedItem?.ToString() : keysizeTxt.Text;
            if (string.IsNullOrEmpty(curveOrKeySize))
            {
                MessageBox.Show("Please select a curve or enter a key size.", "Input Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            string publicKeyPath = pubkeyTxt.Text;
            string privateKeyPath = prikeyTxt.Text;
            if (string.IsNullOrEmpty(publicKeyPath) || string.IsNullOrEmpty(privateKeyPath))
            {
                MessageBox.Show("Please enter paths for both public and private keys.", "Input Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            try
            {
                bool result = GenerateKeys(keyType, curveOrKeySize, publicKeyPath, privateKeyPath);
                MessageBox.Show(result ? "Keys generated successfully!" : "Failed to generate keys.");
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Error generating keys: {ex.Message}", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void signBtn_Click(object sender, EventArgs e)
        {
            string privateKeyPath = signPriketTxt.Text;
            string messagePath = signMessageTxt.Text;
            string signaturePath = signSignatureTxt.Text;
            string algorithm = algoBox.SelectedItem?.ToString();

            if (string.IsNullOrEmpty(privateKeyPath) || string.IsNullOrEmpty(messagePath) || string.IsNullOrEmpty(signaturePath) || string.IsNullOrEmpty(algorithm))
            {
                MessageBox.Show("Please fill in all the fields for signing.", "Input Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            try
            {
                bool result = Sign(privateKeyPath, messagePath, signaturePath, algorithm);
                MessageBox.Show(result ? "Message signed successfully!" : "Failed to sign message.");
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Error signing message: {ex.Message}", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void verifyBtn_Click(object sender, EventArgs e)
        {
            string publicKeyPath = verPubkeyTxt.Text;
            string messagePath = verMessageTxt.Text;
            string signaturePath = verSignatureTxt.Text;
            string algorithm = algoBox.SelectedItem?.ToString();

            if (string.IsNullOrEmpty(publicKeyPath) || string.IsNullOrEmpty(messagePath) || string.IsNullOrEmpty(signaturePath) || string.IsNullOrEmpty(algorithm))
            {
                MessageBox.Show("Please fill in all the fields for verifying the signature.", "Input Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            try
            {
                bool result = VerifySignature(publicKeyPath, messagePath, signaturePath, algorithm);
                MessageBox.Show(result ? "Signature verified successfully!" : "Failed to verify signature.");
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Error verifying signature: {ex.Message}", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void algoBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (algoBox.SelectedItem.ToString() == "ECDSA")
            {
                curveBox.Enabled = true;
                keysizeTxt.Enabled = false;
            }
            else
            {
                curveBox.Enabled = false;
                keysizeTxt.Enabled = true;
            }

            genkeyBtn.Enabled = true;
            signBtn.Enabled = true;
            verifyBtn.Enabled = true;
        }
    }
}
