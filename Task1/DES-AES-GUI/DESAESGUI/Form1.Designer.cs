namespace DESAESGUI
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label2 = new System.Windows.Forms.Label();
            this.genkeyTxt = new System.Windows.Forms.TextBox();
            this.genivTxt = new System.Windows.Forms.TextBox();
            this.keyivFormatCbo = new System.Windows.Forms.ComboBox();
            this.DESgenKeyIVTxt = new System.Windows.Forms.Button();
            this.DESEncryptBtn = new System.Windows.Forms.Button();
            this.encryptFormatCbo = new System.Windows.Forms.ComboBox();
            this.encryptIVTxt = new System.Windows.Forms.TextBox();
            this.encryptKeyTxt = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.encryptPlainTxt = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.encryptCipherTxt = new System.Windows.Forms.TextBox();
            this.label12 = new System.Windows.Forms.Label();
            this.encryptModeCbo = new System.Windows.Forms.ComboBox();
            this.label13 = new System.Windows.Forms.Label();
            this.decryptModeCbo = new System.Windows.Forms.ComboBox();
            this.label14 = new System.Windows.Forms.Label();
            this.decryptRecoverTxt = new System.Windows.Forms.TextBox();
            this.label15 = new System.Windows.Forms.Label();
            this.decryptCipherTxt = new System.Windows.Forms.TextBox();
            this.label16 = new System.Windows.Forms.Label();
            this.label17 = new System.Windows.Forms.Label();
            this.label18 = new System.Windows.Forms.Label();
            this.decryptBtn = new System.Windows.Forms.Button();
            this.decryptFormatCbo = new System.Windows.Forms.ComboBox();
            this.decryptivTxt = new System.Windows.Forms.TextBox();
            this.decryptKeyTxt = new System.Windows.Forms.TextBox();
            this.label19 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label2.Location = new System.Drawing.Point(22, 28);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(255, 25);
            this.label2.TabIndex = 1;
            this.label2.Text = "Generate DES key and iv";
            // 
            // genkeyTxt
            // 
            this.genkeyTxt.Location = new System.Drawing.Point(27, 87);
            this.genkeyTxt.Name = "genkeyTxt";
            this.genkeyTxt.Size = new System.Drawing.Size(138, 22);
            this.genkeyTxt.TabIndex = 2;
            // 
            // genivTxt
            // 
            this.genivTxt.Location = new System.Drawing.Point(187, 87);
            this.genivTxt.Name = "genivTxt";
            this.genivTxt.Size = new System.Drawing.Size(138, 22);
            this.genivTxt.TabIndex = 3;
            // 
            // keyivFormatCbo
            // 
            this.keyivFormatCbo.FormattingEnabled = true;
            this.keyivFormatCbo.Items.AddRange(new object[] {
            "DER",
            "Base64",
            "Hex"});
            this.keyivFormatCbo.Location = new System.Drawing.Point(352, 85);
            this.keyivFormatCbo.Name = "keyivFormatCbo";
            this.keyivFormatCbo.Size = new System.Drawing.Size(121, 24);
            this.keyivFormatCbo.TabIndex = 4;
            // 
            // DESgenKeyIVTxt
            // 
            this.DESgenKeyIVTxt.Location = new System.Drawing.Point(498, 80);
            this.DESgenKeyIVTxt.Name = "DESgenKeyIVTxt";
            this.DESgenKeyIVTxt.Size = new System.Drawing.Size(109, 33);
            this.DESgenKeyIVTxt.TabIndex = 5;
            this.DESgenKeyIVTxt.Text = "Generate";
            this.DESgenKeyIVTxt.UseVisualStyleBackColor = true;
            this.DESgenKeyIVTxt.Click += new System.EventHandler(this.genKeyIVTxt_Click);
            // 
            // DESEncryptBtn
            // 
            this.DESEncryptBtn.Location = new System.Drawing.Point(260, 260);
            this.DESEncryptBtn.Name = "DESEncryptBtn";
            this.DESEncryptBtn.Size = new System.Drawing.Size(109, 33);
            this.DESEncryptBtn.TabIndex = 10;
            this.DESEncryptBtn.Text = "Encrypt";
            this.DESEncryptBtn.UseVisualStyleBackColor = true;
            this.DESEncryptBtn.Click += new System.EventHandler(this.DESEncryptBtn_Click);
            // 
            // encryptFormatCbo
            // 
            this.encryptFormatCbo.FormattingEnabled = true;
            this.encryptFormatCbo.Items.AddRange(new object[] {
            "DER",
            "Base64",
            "Hex"});
            this.encryptFormatCbo.Location = new System.Drawing.Point(37, 269);
            this.encryptFormatCbo.Name = "encryptFormatCbo";
            this.encryptFormatCbo.Size = new System.Drawing.Size(121, 24);
            this.encryptFormatCbo.TabIndex = 9;
            this.encryptFormatCbo.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // encryptIVTxt
            // 
            this.encryptIVTxt.Location = new System.Drawing.Point(187, 219);
            this.encryptIVTxt.Name = "encryptIVTxt";
            this.encryptIVTxt.Size = new System.Drawing.Size(138, 22);
            this.encryptIVTxt.TabIndex = 8;
            // 
            // encryptKeyTxt
            // 
            this.encryptKeyTxt.Location = new System.Drawing.Point(37, 219);
            this.encryptKeyTxt.Name = "encryptKeyTxt";
            this.encryptKeyTxt.Size = new System.Drawing.Size(138, 22);
            this.encryptKeyTxt.TabIndex = 7;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label3.Location = new System.Drawing.Point(33, 165);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(164, 25);
            this.label3.TabIndex = 6;
            this.label3.Text = "DES Encryption";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(24, 68);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(55, 16);
            this.label4.TabIndex = 11;
            this.label4.Text = "Key File";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(184, 68);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(44, 16);
            this.label5.TabIndex = 12;
            this.label5.Text = "IV File";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(349, 68);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(49, 16);
            this.label6.TabIndex = 13;
            this.label6.Text = "Format";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(34, 252);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(49, 16);
            this.label7.TabIndex = 16;
            this.label7.Text = "Format";
            this.label7.Click += new System.EventHandler(this.label7_Click);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(184, 200);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(44, 16);
            this.label8.TabIndex = 15;
            this.label8.Text = "IV File";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(34, 200);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(55, 16);
            this.label9.TabIndex = 14;
            this.label9.Text = "Key File";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(332, 200);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(82, 16);
            this.label10.TabIndex = 18;
            this.label10.Text = "Plaintext File";
            // 
            // encryptPlainTxt
            // 
            this.encryptPlainTxt.Location = new System.Drawing.Point(335, 219);
            this.encryptPlainTxt.Name = "encryptPlainTxt";
            this.encryptPlainTxt.Size = new System.Drawing.Size(138, 22);
            this.encryptPlainTxt.TabIndex = 17;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(477, 200);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(71, 16);
            this.label11.TabIndex = 20;
            this.label11.Text = "Cipher File";
            // 
            // encryptCipherTxt
            // 
            this.encryptCipherTxt.Location = new System.Drawing.Point(480, 219);
            this.encryptCipherTxt.Name = "encryptCipherTxt";
            this.encryptCipherTxt.Size = new System.Drawing.Size(138, 22);
            this.encryptCipherTxt.TabIndex = 19;
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(163, 252);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(42, 16);
            this.label12.TabIndex = 22;
            this.label12.Text = "Mode";
            // 
            // encryptModeCbo
            // 
            this.encryptModeCbo.FormattingEnabled = true;
            this.encryptModeCbo.Items.AddRange(new object[] {
            "ECB",
            "CBC",
            "OFB",
            "CFB",
            "CTR"});
            this.encryptModeCbo.Location = new System.Drawing.Point(166, 269);
            this.encryptModeCbo.Name = "encryptModeCbo";
            this.encryptModeCbo.Size = new System.Drawing.Size(88, 24);
            this.encryptModeCbo.TabIndex = 21;
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(163, 447);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(42, 16);
            this.label13.TabIndex = 36;
            this.label13.Text = "Mode";
            // 
            // decryptModeCbo
            // 
            this.decryptModeCbo.FormattingEnabled = true;
            this.decryptModeCbo.Items.AddRange(new object[] {
            "ECB",
            "CBC",
            "OFB",
            "CFB",
            "CTR"});
            this.decryptModeCbo.Location = new System.Drawing.Point(166, 464);
            this.decryptModeCbo.Name = "decryptModeCbo";
            this.decryptModeCbo.Size = new System.Drawing.Size(88, 24);
            this.decryptModeCbo.TabIndex = 35;
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(477, 389);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(84, 16);
            this.label14.TabIndex = 34;
            this.label14.Text = "Recover File";
            // 
            // decryptRecoverTxt
            // 
            this.decryptRecoverTxt.Location = new System.Drawing.Point(480, 408);
            this.decryptRecoverTxt.Name = "decryptRecoverTxt";
            this.decryptRecoverTxt.Size = new System.Drawing.Size(138, 22);
            this.decryptRecoverTxt.TabIndex = 33;
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(332, 389);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(71, 16);
            this.label15.TabIndex = 32;
            this.label15.Text = "Cipher File";
            // 
            // decryptCipherTxt
            // 
            this.decryptCipherTxt.Location = new System.Drawing.Point(335, 408);
            this.decryptCipherTxt.Name = "decryptCipherTxt";
            this.decryptCipherTxt.Size = new System.Drawing.Size(138, 22);
            this.decryptCipherTxt.TabIndex = 31;
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(34, 447);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(49, 16);
            this.label16.TabIndex = 30;
            this.label16.Text = "Format";
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Location = new System.Drawing.Point(184, 389);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(44, 16);
            this.label17.TabIndex = 29;
            this.label17.Text = "IV File";
            // 
            // label18
            // 
            this.label18.AutoSize = true;
            this.label18.Location = new System.Drawing.Point(34, 389);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(55, 16);
            this.label18.TabIndex = 28;
            this.label18.Text = "Key File";
            // 
            // decryptBtn
            // 
            this.decryptBtn.Location = new System.Drawing.Point(260, 455);
            this.decryptBtn.Name = "decryptBtn";
            this.decryptBtn.Size = new System.Drawing.Size(109, 33);
            this.decryptBtn.TabIndex = 27;
            this.decryptBtn.Text = "Decrypt";
            this.decryptBtn.UseVisualStyleBackColor = true;
            this.decryptBtn.Click += new System.EventHandler(this.decryptBtn_Click);
            // 
            // decryptFormatCbo
            // 
            this.decryptFormatCbo.FormattingEnabled = true;
            this.decryptFormatCbo.Items.AddRange(new object[] {
            "DER",
            "Base64",
            "Hex"});
            this.decryptFormatCbo.Location = new System.Drawing.Point(37, 464);
            this.decryptFormatCbo.Name = "decryptFormatCbo";
            this.decryptFormatCbo.Size = new System.Drawing.Size(121, 24);
            this.decryptFormatCbo.TabIndex = 26;
            // 
            // decryptivTxt
            // 
            this.decryptivTxt.Location = new System.Drawing.Point(187, 408);
            this.decryptivTxt.Name = "decryptivTxt";
            this.decryptivTxt.Size = new System.Drawing.Size(138, 22);
            this.decryptivTxt.TabIndex = 25;
            // 
            // decryptKeyTxt
            // 
            this.decryptKeyTxt.Location = new System.Drawing.Point(37, 408);
            this.decryptKeyTxt.Name = "decryptKeyTxt";
            this.decryptKeyTxt.Size = new System.Drawing.Size(138, 22);
            this.decryptKeyTxt.TabIndex = 24;
            // 
            // label19
            // 
            this.label19.AutoSize = true;
            this.label19.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label19.Location = new System.Drawing.Point(32, 352);
            this.label19.Name = "label19";
            this.label19.Size = new System.Drawing.Size(165, 25);
            this.label19.TabIndex = 23;
            this.label19.Text = "DES Decryption";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(677, 547);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.decryptModeCbo);
            this.Controls.Add(this.label14);
            this.Controls.Add(this.decryptRecoverTxt);
            this.Controls.Add(this.label15);
            this.Controls.Add(this.decryptCipherTxt);
            this.Controls.Add(this.label16);
            this.Controls.Add(this.label17);
            this.Controls.Add(this.label18);
            this.Controls.Add(this.decryptBtn);
            this.Controls.Add(this.decryptFormatCbo);
            this.Controls.Add(this.decryptivTxt);
            this.Controls.Add(this.decryptKeyTxt);
            this.Controls.Add(this.label19);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.encryptModeCbo);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.encryptCipherTxt);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.encryptPlainTxt);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.DESEncryptBtn);
            this.Controls.Add(this.encryptFormatCbo);
            this.Controls.Add(this.encryptIVTxt);
            this.Controls.Add(this.encryptKeyTxt);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.DESgenKeyIVTxt);
            this.Controls.Add(this.keyivFormatCbo);
            this.Controls.Add(this.genivTxt);
            this.Controls.Add(this.genkeyTxt);
            this.Controls.Add(this.label2);
            this.Name = "Form1";
            this.Text = "DES";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox genkeyTxt;
        private System.Windows.Forms.TextBox genivTxt;
        private System.Windows.Forms.ComboBox keyivFormatCbo;
        private System.Windows.Forms.Button DESgenKeyIVTxt;
        private System.Windows.Forms.Button DESEncryptBtn;
        private System.Windows.Forms.ComboBox encryptFormatCbo;
        private System.Windows.Forms.TextBox encryptIVTxt;
        private System.Windows.Forms.TextBox encryptKeyTxt;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox encryptPlainTxt;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.TextBox encryptCipherTxt;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.ComboBox encryptModeCbo;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.ComboBox decryptModeCbo;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.TextBox decryptRecoverTxt;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.TextBox decryptCipherTxt;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.Label label17;
        private System.Windows.Forms.Label label18;
        private System.Windows.Forms.Button decryptBtn;
        private System.Windows.Forms.ComboBox decryptFormatCbo;
        private System.Windows.Forms.TextBox decryptivTxt;
        private System.Windows.Forms.TextBox decryptKeyTxt;
        private System.Windows.Forms.Label label19;
    }
}

