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

namespace GUI
{
    public partial class Form1 : Form
    {
        // Import the hashData function from the DLL
        [DllImport("Hash_dll.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "hashData")]
        private static extern IntPtr hashData(string data, string algorithm, int digestLength = 0);
        public Form1()
        {
            InitializeComponent();
        }

        private void hashBtn_Click(object sender, EventArgs e)
        {
            try
            {
                // Check if input text is provided
                if (string.IsNullOrEmpty(hashTxt.Text))
                {
                    MessageBox.Show("Please enter the text to hash.", "Input Required", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }

                // Check if an algorithm is selected
                if (algoCbo.SelectedItem == null)
                {
                    MessageBox.Show("Please select an algorithm.", "Algorithm Required", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }

                string input = hashTxt.Text;
                string algorithm = algoCbo.SelectedItem.ToString();

                // Check if digest length is required for the selected algorithm
                int digestLength = 0;
                if ((algorithm == "shake128" || algorithm == "shake256"))
                {
                    if (string.IsNullOrEmpty(digestLengthTxt.Text) || !int.TryParse(digestLengthTxt.Text, out digestLength))
                    {
                        MessageBox.Show("Please enter a valid digest length for the selected SHAKE algorithm.", "Digest Length Required", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                        return;
                    }
                }

                // Call the hashData function
                IntPtr resultPtr = hashData(input, algorithm, digestLength);
                string result = Marshal.PtrToStringAnsi(resultPtr);

                // Display the result
                resultTxt.Text = result;
                MessageBox.Show($"Hash result: {result}");
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Error: {ex.Message}");
            }
        }

        private void fileInputBtn_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
            openFileDialog.InitialDirectory = AppDomain.CurrentDomain.BaseDirectory;
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    string filePath = openFileDialog.FileName;
                    string fileContent = System.IO.File.ReadAllText(filePath);
                    hashTxt.Text = fileContent;
                }
                catch (Exception ex)
                {
                    MessageBox.Show($"Error: {ex.Message}");
                }
            }
        }

        private void algoCbo_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (algoCbo.SelectedItem.ToString() == "shake128" || algoCbo.SelectedItem.ToString() == "shake256")
            {
                digestLengthTxt.Enabled = true;
            }
            else
            {
                digestLengthTxt.Enabled = false;
            }
        }

        private void saveOutputBtn_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
            saveFileDialog.InitialDirectory = AppDomain.CurrentDomain.BaseDirectory;
            saveFileDialog.Title = "Save Hash Output";

            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    string filePath = saveFileDialog.FileName;
                    System.IO.File.WriteAllText(filePath, resultTxt.Text);
                    MessageBox.Show($"File saved successfully to {filePath}");
                }
                catch (Exception ex)
                {
                    MessageBox.Show($"Error: {ex.Message}");
                }
            }
        }
    }
}
