namespace RSA
{
    partial class RSA
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
            this.keysizeTxt = new System.Windows.Forms.TextBox();
            this.genPriFileTxt = new System.Windows.Forms.TextBox();
            this.genPubFileTxt = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.genkeyBtn = new System.Windows.Forms.Button();
            this.keyformatCbo = new System.Windows.Forms.ComboBox();
            this.label6 = new System.Windows.Forms.Label();
            this.encryptBtn = new System.Windows.Forms.Button();
            this.encryptformatCbo = new System.Windows.Forms.ComboBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.plainEncryptTxt = new System.Windows.Forms.TextBox();
            this.pubKeyEncryptTxt = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.cipherEncrtptTxt = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.recoveredDecryptTxt = new System.Windows.Forms.TextBox();
            this.label13 = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.cipherDecryptTxt = new System.Windows.Forms.TextBox();
            this.priKeyDecryptTxt = new System.Windows.Forms.TextBox();
            this.decryptformatCbo = new System.Windows.Forms.ComboBox();
            this.label15 = new System.Windows.Forms.Label();
            this.decryptBtn = new System.Windows.Forms.Button();
            this.label16 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // keysizeTxt
            // 
            this.keysizeTxt.Location = new System.Drawing.Point(147, 69);
            this.keysizeTxt.Name = "keysizeTxt";
            this.keysizeTxt.Size = new System.Drawing.Size(88, 22);
            this.keysizeTxt.TabIndex = 0;
            // 
            // genPriFileTxt
            // 
            this.genPriFileTxt.Location = new System.Drawing.Point(256, 69);
            this.genPriFileTxt.Name = "genPriFileTxt";
            this.genPriFileTxt.Size = new System.Drawing.Size(172, 22);
            this.genPriFileTxt.TabIndex = 2;
            // 
            // genPubFileTxt
            // 
            this.genPubFileTxt.Location = new System.Drawing.Point(458, 69);
            this.genPubFileTxt.Name = "genPubFileTxt";
            this.genPubFileTxt.Size = new System.Drawing.Size(172, 22);
            this.genPubFileTxt.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label1.Location = new System.Drawing.Point(13, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(202, 25);
            this.label1.TabIndex = 4;
            this.label1.Text = "Generate RSA keys";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(143, 50);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(59, 16);
            this.label2.TabIndex = 5;
            this.label2.Text = "Key Size";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(20, 48);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(49, 16);
            this.label3.TabIndex = 6;
            this.label3.Text = "Format";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(252, 50);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(97, 16);
            this.label4.TabIndex = 7;
            this.label4.Text = "PrivateKey File";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(455, 50);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(92, 16);
            this.label5.TabIndex = 8;
            this.label5.Text = "PublicKey File";
            // 
            // genkeyBtn
            // 
            this.genkeyBtn.Location = new System.Drawing.Point(647, 52);
            this.genkeyBtn.Name = "genkeyBtn";
            this.genkeyBtn.Size = new System.Drawing.Size(141, 41);
            this.genkeyBtn.TabIndex = 9;
            this.genkeyBtn.Text = "Generate RSA Keys";
            this.genkeyBtn.UseVisualStyleBackColor = true;
            this.genkeyBtn.Click += new System.EventHandler(this.genkeyBtn_Click);
            // 
            // keyformatCbo
            // 
            this.keyformatCbo.FormattingEnabled = true;
            this.keyformatCbo.Items.AddRange(new object[] {
            "DER",
            "Base64",
            "Hex"});
            this.keyformatCbo.Location = new System.Drawing.Point(23, 67);
            this.keyformatCbo.Name = "keyformatCbo";
            this.keyformatCbo.Size = new System.Drawing.Size(106, 24);
            this.keyformatCbo.TabIndex = 10;
            this.keyformatCbo.SelectedIndexChanged += new System.EventHandler(this.keyformatCbo_SelectedIndexChanged);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label6.Location = new System.Drawing.Point(13, 152);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(164, 25);
            this.label6.TabIndex = 11;
            this.label6.Text = "RSA Encryption";
            // 
            // encryptBtn
            // 
            this.encryptBtn.Location = new System.Drawing.Point(647, 196);
            this.encryptBtn.Name = "encryptBtn";
            this.encryptBtn.Size = new System.Drawing.Size(141, 41);
            this.encryptBtn.TabIndex = 12;
            this.encryptBtn.Text = "RSA Encrypt";
            this.encryptBtn.UseVisualStyleBackColor = true;
            this.encryptBtn.Click += new System.EventHandler(this.encryptBtn_Click);
            // 
            // encryptformatCbo
            // 
            this.encryptformatCbo.FormattingEnabled = true;
            this.encryptformatCbo.Items.AddRange(new object[] {
            "DER",
            "Base64",
            "Hex"});
            this.encryptformatCbo.Location = new System.Drawing.Point(23, 213);
            this.encryptformatCbo.Name = "encryptformatCbo";
            this.encryptformatCbo.Size = new System.Drawing.Size(106, 24);
            this.encryptformatCbo.TabIndex = 14;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(20, 194);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(49, 16);
            this.label7.TabIndex = 13;
            this.label7.Text = "Format";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(313, 196);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(82, 16);
            this.label8.TabIndex = 18;
            this.label8.Text = "Plaintext File";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(143, 196);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(92, 16);
            this.label9.TabIndex = 17;
            this.label9.Text = "PublicKey File";
            // 
            // plainEncryptTxt
            // 
            this.plainEncryptTxt.Location = new System.Drawing.Point(316, 215);
            this.plainEncryptTxt.Name = "plainEncryptTxt";
            this.plainEncryptTxt.Size = new System.Drawing.Size(150, 22);
            this.plainEncryptTxt.TabIndex = 16;
            // 
            // pubKeyEncryptTxt
            // 
            this.pubKeyEncryptTxt.Location = new System.Drawing.Point(147, 215);
            this.pubKeyEncryptTxt.Name = "pubKeyEncryptTxt";
            this.pubKeyEncryptTxt.Size = new System.Drawing.Size(150, 22);
            this.pubKeyEncryptTxt.TabIndex = 15;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(477, 196);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(91, 16);
            this.label10.TabIndex = 20;
            this.label10.Text = "Ciphertext File";
            // 
            // cipherEncrtptTxt
            // 
            this.cipherEncrtptTxt.Location = new System.Drawing.Point(480, 215);
            this.cipherEncrtptTxt.Name = "cipherEncrtptTxt";
            this.cipherEncrtptTxt.Size = new System.Drawing.Size(150, 22);
            this.cipherEncrtptTxt.TabIndex = 19;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label11.Location = new System.Drawing.Point(13, 296);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(165, 25);
            this.label11.TabIndex = 21;
            this.label11.Text = "RSA Decryption";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(477, 338);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(100, 16);
            this.label12.TabIndex = 30;
            this.label12.Text = "Recovered File";
            // 
            // recoveredDecryptTxt
            // 
            this.recoveredDecryptTxt.Location = new System.Drawing.Point(480, 357);
            this.recoveredDecryptTxt.Name = "recoveredDecryptTxt";
            this.recoveredDecryptTxt.Size = new System.Drawing.Size(150, 22);
            this.recoveredDecryptTxt.TabIndex = 29;
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(313, 338);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(91, 16);
            this.label13.TabIndex = 28;
            this.label13.Text = "Ciphertext File";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(143, 338);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(97, 16);
            this.label14.TabIndex = 27;
            this.label14.Text = "PrivateKey File";
            // 
            // cipherDecryptTxt
            // 
            this.cipherDecryptTxt.Location = new System.Drawing.Point(316, 357);
            this.cipherDecryptTxt.Name = "cipherDecryptTxt";
            this.cipherDecryptTxt.Size = new System.Drawing.Size(150, 22);
            this.cipherDecryptTxt.TabIndex = 26;
            // 
            // priKeyDecryptTxt
            // 
            this.priKeyDecryptTxt.Location = new System.Drawing.Point(147, 357);
            this.priKeyDecryptTxt.Name = "priKeyDecryptTxt";
            this.priKeyDecryptTxt.Size = new System.Drawing.Size(150, 22);
            this.priKeyDecryptTxt.TabIndex = 25;
            // 
            // decryptformatCbo
            // 
            this.decryptformatCbo.FormattingEnabled = true;
            this.decryptformatCbo.Items.AddRange(new object[] {
            "DER",
            "Base64",
            "Hex"});
            this.decryptformatCbo.Location = new System.Drawing.Point(23, 355);
            this.decryptformatCbo.Name = "decryptformatCbo";
            this.decryptformatCbo.Size = new System.Drawing.Size(106, 24);
            this.decryptformatCbo.TabIndex = 24;
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(20, 336);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(49, 16);
            this.label15.TabIndex = 23;
            this.label15.Text = "Format";
            // 
            // decryptBtn
            // 
            this.decryptBtn.Location = new System.Drawing.Point(647, 338);
            this.decryptBtn.Name = "decryptBtn";
            this.decryptBtn.Size = new System.Drawing.Size(141, 41);
            this.decryptBtn.TabIndex = 22;
            this.decryptBtn.Text = "RSA Decrypt";
            this.decryptBtn.UseVisualStyleBackColor = true;
            this.decryptBtn.Click += new System.EventHandler(this.decryptBtn_Click);
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label16.Location = new System.Drawing.Point(141, 416);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(497, 25);
            this.label16.TabIndex = 31;
            this.label16.Text = "NT219.O21.ANTT.2 - 22521709 Trần Thị Thúy Vy\r\n";
            // 
            // RSA
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label16);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.recoveredDecryptTxt);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.label14);
            this.Controls.Add(this.cipherDecryptTxt);
            this.Controls.Add(this.priKeyDecryptTxt);
            this.Controls.Add(this.decryptformatCbo);
            this.Controls.Add(this.label15);
            this.Controls.Add(this.decryptBtn);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.cipherEncrtptTxt);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.plainEncryptTxt);
            this.Controls.Add(this.pubKeyEncryptTxt);
            this.Controls.Add(this.encryptformatCbo);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.encryptBtn);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.keyformatCbo);
            this.Controls.Add(this.genkeyBtn);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.genPubFileTxt);
            this.Controls.Add(this.genPriFileTxt);
            this.Controls.Add(this.keysizeTxt);
            this.Name = "RSA";
            this.Text = "RSA";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox keysizeTxt;
        private System.Windows.Forms.TextBox genPriFileTxt;
        private System.Windows.Forms.TextBox genPubFileTxt;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button genkeyBtn;
        private System.Windows.Forms.ComboBox keyformatCbo;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button encryptBtn;
        private System.Windows.Forms.ComboBox encryptformatCbo;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox plainEncryptTxt;
        private System.Windows.Forms.TextBox pubKeyEncryptTxt;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox cipherEncrtptTxt;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.TextBox recoveredDecryptTxt;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.TextBox cipherDecryptTxt;
        private System.Windows.Forms.TextBox priKeyDecryptTxt;
        private System.Windows.Forms.ComboBox decryptformatCbo;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.Button decryptBtn;
        private System.Windows.Forms.Label label16;
    }
}

