namespace DESAESGUI
{
    partial class AES
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
            this.label12 = new System.Windows.Forms.Label();
            this.encryptModeCbo = new System.Windows.Forms.ComboBox();
            this.label11 = new System.Windows.Forms.Label();
            this.encryptCipherTxt = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.encryptPlainTxt = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.AESEncryptBtn = new System.Windows.Forms.Button();
            this.encryptFormatCbo = new System.Windows.Forms.ComboBox();
            this.encryptIVTxt = new System.Windows.Forms.TextBox();
            this.encryptKeyTxt = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.AESgenKeyIVTxt = new System.Windows.Forms.Button();
            this.keyivFormatCbo = new System.Windows.Forms.ComboBox();
            this.genivTxt = new System.Windows.Forms.TextBox();
            this.genkeyTxt = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.genkeyModeCbo = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(243, 441);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(42, 16);
            this.label13.TabIndex = 72;
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
            "CTR",
            "CCM",
            "GCM",
            "XTS"});
            this.decryptModeCbo.Location = new System.Drawing.Point(246, 458);
            this.decryptModeCbo.Name = "decryptModeCbo";
            this.decryptModeCbo.Size = new System.Drawing.Size(88, 24);
            this.decryptModeCbo.TabIndex = 71;
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(557, 383);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(84, 16);
            this.label14.TabIndex = 70;
            this.label14.Text = "Recover File";
            // 
            // decryptRecoverTxt
            // 
            this.decryptRecoverTxt.Location = new System.Drawing.Point(560, 402);
            this.decryptRecoverTxt.Name = "decryptRecoverTxt";
            this.decryptRecoverTxt.Size = new System.Drawing.Size(138, 22);
            this.decryptRecoverTxt.TabIndex = 69;
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(412, 383);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(71, 16);
            this.label15.TabIndex = 68;
            this.label15.Text = "Cipher File";
            // 
            // decryptCipherTxt
            // 
            this.decryptCipherTxt.Location = new System.Drawing.Point(415, 402);
            this.decryptCipherTxt.Name = "decryptCipherTxt";
            this.decryptCipherTxt.Size = new System.Drawing.Size(138, 22);
            this.decryptCipherTxt.TabIndex = 67;
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(114, 441);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(49, 16);
            this.label16.TabIndex = 66;
            this.label16.Text = "Format";
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Location = new System.Drawing.Point(264, 383);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(44, 16);
            this.label17.TabIndex = 65;
            this.label17.Text = "IV File";
            // 
            // label18
            // 
            this.label18.AutoSize = true;
            this.label18.Location = new System.Drawing.Point(114, 383);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(55, 16);
            this.label18.TabIndex = 64;
            this.label18.Text = "Key File";
            // 
            // decryptBtn
            // 
            this.decryptBtn.Location = new System.Drawing.Point(340, 453);
            this.decryptBtn.Name = "decryptBtn";
            this.decryptBtn.Size = new System.Drawing.Size(109, 33);
            this.decryptBtn.TabIndex = 63;
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
            this.decryptFormatCbo.Location = new System.Drawing.Point(117, 458);
            this.decryptFormatCbo.Name = "decryptFormatCbo";
            this.decryptFormatCbo.Size = new System.Drawing.Size(121, 24);
            this.decryptFormatCbo.TabIndex = 62;
            // 
            // decryptivTxt
            // 
            this.decryptivTxt.Location = new System.Drawing.Point(267, 402);
            this.decryptivTxt.Name = "decryptivTxt";
            this.decryptivTxt.Size = new System.Drawing.Size(138, 22);
            this.decryptivTxt.TabIndex = 61;
            // 
            // decryptKeyTxt
            // 
            this.decryptKeyTxt.Location = new System.Drawing.Point(117, 402);
            this.decryptKeyTxt.Name = "decryptKeyTxt";
            this.decryptKeyTxt.Size = new System.Drawing.Size(138, 22);
            this.decryptKeyTxt.TabIndex = 60;
            // 
            // label19
            // 
            this.label19.AutoSize = true;
            this.label19.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label19.Location = new System.Drawing.Point(112, 346);
            this.label19.Name = "label19";
            this.label19.Size = new System.Drawing.Size(165, 25);
            this.label19.TabIndex = 59;
            this.label19.Text = "AES Decryption";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(243, 246);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(42, 16);
            this.label12.TabIndex = 58;
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
            "CTR",
            "CCM",
            "GCM",
            "XTS"});
            this.encryptModeCbo.Location = new System.Drawing.Point(246, 263);
            this.encryptModeCbo.Name = "encryptModeCbo";
            this.encryptModeCbo.Size = new System.Drawing.Size(88, 24);
            this.encryptModeCbo.TabIndex = 57;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(557, 194);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(71, 16);
            this.label11.TabIndex = 56;
            this.label11.Text = "Cipher File";
            // 
            // encryptCipherTxt
            // 
            this.encryptCipherTxt.Location = new System.Drawing.Point(560, 213);
            this.encryptCipherTxt.Name = "encryptCipherTxt";
            this.encryptCipherTxt.Size = new System.Drawing.Size(138, 22);
            this.encryptCipherTxt.TabIndex = 55;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(412, 194);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(82, 16);
            this.label10.TabIndex = 54;
            this.label10.Text = "Plaintext File";
            // 
            // encryptPlainTxt
            // 
            this.encryptPlainTxt.Location = new System.Drawing.Point(415, 213);
            this.encryptPlainTxt.Name = "encryptPlainTxt";
            this.encryptPlainTxt.Size = new System.Drawing.Size(138, 22);
            this.encryptPlainTxt.TabIndex = 53;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(114, 246);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(49, 16);
            this.label7.TabIndex = 52;
            this.label7.Text = "Format";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(264, 194);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(44, 16);
            this.label8.TabIndex = 51;
            this.label8.Text = "IV File";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(114, 194);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(55, 16);
            this.label9.TabIndex = 50;
            this.label9.Text = "Key File";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(114, 62);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(49, 16);
            this.label6.TabIndex = 49;
            this.label6.Text = "Format";
            this.label6.Click += new System.EventHandler(this.label6_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(518, 66);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(44, 16);
            this.label5.TabIndex = 48;
            this.label5.Text = "IV File";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(358, 66);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(55, 16);
            this.label4.TabIndex = 47;
            this.label4.Text = "Key File";
            // 
            // AESEncryptBtn
            // 
            this.AESEncryptBtn.Location = new System.Drawing.Point(340, 258);
            this.AESEncryptBtn.Name = "AESEncryptBtn";
            this.AESEncryptBtn.Size = new System.Drawing.Size(109, 33);
            this.AESEncryptBtn.TabIndex = 46;
            this.AESEncryptBtn.Text = "Encrypt";
            this.AESEncryptBtn.UseVisualStyleBackColor = true;
            this.AESEncryptBtn.Click += new System.EventHandler(this.AESEncryptBtn_Click);
            // 
            // encryptFormatCbo
            // 
            this.encryptFormatCbo.FormattingEnabled = true;
            this.encryptFormatCbo.Items.AddRange(new object[] {
            "DER",
            "Base64",
            "Hex"});
            this.encryptFormatCbo.Location = new System.Drawing.Point(117, 263);
            this.encryptFormatCbo.Name = "encryptFormatCbo";
            this.encryptFormatCbo.Size = new System.Drawing.Size(121, 24);
            this.encryptFormatCbo.TabIndex = 45;
            // 
            // encryptIVTxt
            // 
            this.encryptIVTxt.Location = new System.Drawing.Point(267, 213);
            this.encryptIVTxt.Name = "encryptIVTxt";
            this.encryptIVTxt.Size = new System.Drawing.Size(138, 22);
            this.encryptIVTxt.TabIndex = 44;
            // 
            // encryptKeyTxt
            // 
            this.encryptKeyTxt.Location = new System.Drawing.Point(117, 213);
            this.encryptKeyTxt.Name = "encryptKeyTxt";
            this.encryptKeyTxt.Size = new System.Drawing.Size(138, 22);
            this.encryptKeyTxt.TabIndex = 43;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label3.Location = new System.Drawing.Point(113, 159);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(164, 25);
            this.label3.TabIndex = 42;
            this.label3.Text = "AES Encryption";
            // 
            // AESgenKeyIVTxt
            // 
            this.AESgenKeyIVTxt.Location = new System.Drawing.Point(550, 113);
            this.AESgenKeyIVTxt.Name = "AESgenKeyIVTxt";
            this.AESgenKeyIVTxt.Size = new System.Drawing.Size(109, 33);
            this.AESgenKeyIVTxt.TabIndex = 41;
            this.AESgenKeyIVTxt.Text = "Generate";
            this.AESgenKeyIVTxt.UseVisualStyleBackColor = true;
            this.AESgenKeyIVTxt.Click += new System.EventHandler(this.AESgenKeyIVTxt_Click);
            // 
            // keyivFormatCbo
            // 
            this.keyivFormatCbo.FormattingEnabled = true;
            this.keyivFormatCbo.Items.AddRange(new object[] {
            "DER",
            "Base64",
            "Hex"});
            this.keyivFormatCbo.Location = new System.Drawing.Point(117, 79);
            this.keyivFormatCbo.Name = "keyivFormatCbo";
            this.keyivFormatCbo.Size = new System.Drawing.Size(121, 24);
            this.keyivFormatCbo.TabIndex = 40;
            this.keyivFormatCbo.SelectedIndexChanged += new System.EventHandler(this.keyivFormatCbo_SelectedIndexChanged);
            // 
            // genivTxt
            // 
            this.genivTxt.Location = new System.Drawing.Point(521, 85);
            this.genivTxt.Name = "genivTxt";
            this.genivTxt.Size = new System.Drawing.Size(138, 22);
            this.genivTxt.TabIndex = 39;
            // 
            // genkeyTxt
            // 
            this.genkeyTxt.Location = new System.Drawing.Point(361, 85);
            this.genkeyTxt.Name = "genkeyTxt";
            this.genkeyTxt.Size = new System.Drawing.Size(138, 22);
            this.genkeyTxt.TabIndex = 38;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label2.Location = new System.Drawing.Point(112, 23);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(255, 25);
            this.label2.TabIndex = 37;
            this.label2.Text = "Generate AES key and iv";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(254, 62);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(42, 16);
            this.label1.TabIndex = 74;
            this.label1.Text = "Mode";
            // 
            // genkeyModeCbo
            // 
            this.genkeyModeCbo.FormattingEnabled = true;
            this.genkeyModeCbo.Items.AddRange(new object[] {
            "ECB",
            "CBC",
            "OFB",
            "CFB",
            "CTR",
            "CCM",
            "GCM",
            "XTS"});
            this.genkeyModeCbo.Location = new System.Drawing.Point(257, 79);
            this.genkeyModeCbo.Name = "genkeyModeCbo";
            this.genkeyModeCbo.Size = new System.Drawing.Size(88, 24);
            this.genkeyModeCbo.TabIndex = 73;
            // 
            // AES
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 504);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.genkeyModeCbo);
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
            this.Controls.Add(this.AESEncryptBtn);
            this.Controls.Add(this.encryptFormatCbo);
            this.Controls.Add(this.encryptIVTxt);
            this.Controls.Add(this.encryptKeyTxt);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.AESgenKeyIVTxt);
            this.Controls.Add(this.keyivFormatCbo);
            this.Controls.Add(this.genivTxt);
            this.Controls.Add(this.genkeyTxt);
            this.Controls.Add(this.label2);
            this.Name = "AES";
            this.Text = "AES";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

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
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.ComboBox encryptModeCbo;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.TextBox encryptCipherTxt;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox encryptPlainTxt;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button AESEncryptBtn;
        private System.Windows.Forms.ComboBox encryptFormatCbo;
        private System.Windows.Forms.TextBox encryptIVTxt;
        private System.Windows.Forms.TextBox encryptKeyTxt;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button AESgenKeyIVTxt;
        private System.Windows.Forms.ComboBox keyivFormatCbo;
        private System.Windows.Forms.TextBox genivTxt;
        private System.Windows.Forms.TextBox genkeyTxt;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox genkeyModeCbo;
    }
}