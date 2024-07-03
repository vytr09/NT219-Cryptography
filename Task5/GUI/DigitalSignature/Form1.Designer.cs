namespace DigitalSignature
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
            this.label1 = new System.Windows.Forms.Label();
            this.algoBox = new System.Windows.Forms.ComboBox();
            this.curveBox = new System.Windows.Forms.ComboBox();
            this.keysizeTxt = new System.Windows.Forms.TextBox();
            this.pubkeyTxt = new System.Windows.Forms.TextBox();
            this.prikeyTxt = new System.Windows.Forms.TextBox();
            this.genkeyBtn = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.signPriketTxt = new System.Windows.Forms.TextBox();
            this.signMessageTxt = new System.Windows.Forms.TextBox();
            this.signSignatureTxt = new System.Windows.Forms.TextBox();
            this.signBtn = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.verSignatureTxt = new System.Windows.Forms.TextBox();
            this.verMessageTxt = new System.Windows.Forms.TextBox();
            this.verPubkeyTxt = new System.Windows.Forms.TextBox();
            this.verifyBtn = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label1.Location = new System.Drawing.Point(12, 88);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(133, 22);
            this.label1.TabIndex = 0;
            this.label1.Text = "Generate Key";
            // 
            // algoBox
            // 
            this.algoBox.FormattingEnabled = true;
            this.algoBox.Items.AddRange(new object[] {
            "RSAPSS",
            "ECDSA"});
            this.algoBox.Location = new System.Drawing.Point(15, 43);
            this.algoBox.Name = "algoBox";
            this.algoBox.Size = new System.Drawing.Size(121, 24);
            this.algoBox.TabIndex = 1;
            this.algoBox.SelectedIndexChanged += new System.EventHandler(this.algoBox_SelectedIndexChanged);
            // 
            // curveBox
            // 
            this.curveBox.Enabled = false;
            this.curveBox.FormattingEnabled = true;
            this.curveBox.Items.AddRange(new object[] {
            "prime256v1",
            "secp384r1",
            "secp521r1",
            "secp224r1",
            "secp256k1",
            "brainpoolP256r1",
            "brainpoolP384r1",
            "brainpoolP512r1",
            "secp192r1",
            "sect233k1"});
            this.curveBox.Location = new System.Drawing.Point(15, 144);
            this.curveBox.Name = "curveBox";
            this.curveBox.Size = new System.Drawing.Size(121, 24);
            this.curveBox.TabIndex = 2;
            // 
            // keysizeTxt
            // 
            this.keysizeTxt.Enabled = false;
            this.keysizeTxt.Location = new System.Drawing.Point(165, 146);
            this.keysizeTxt.Name = "keysizeTxt";
            this.keysizeTxt.Size = new System.Drawing.Size(120, 22);
            this.keysizeTxt.TabIndex = 3;
            // 
            // pubkeyTxt
            // 
            this.pubkeyTxt.Location = new System.Drawing.Point(328, 145);
            this.pubkeyTxt.Name = "pubkeyTxt";
            this.pubkeyTxt.Size = new System.Drawing.Size(219, 22);
            this.pubkeyTxt.TabIndex = 4;
            // 
            // prikeyTxt
            // 
            this.prikeyTxt.Location = new System.Drawing.Point(580, 145);
            this.prikeyTxt.Name = "prikeyTxt";
            this.prikeyTxt.Size = new System.Drawing.Size(219, 22);
            this.prikeyTxt.TabIndex = 5;
            // 
            // genkeyBtn
            // 
            this.genkeyBtn.Enabled = false;
            this.genkeyBtn.Location = new System.Drawing.Point(675, 187);
            this.genkeyBtn.Name = "genkeyBtn";
            this.genkeyBtn.Size = new System.Drawing.Size(124, 36);
            this.genkeyBtn.TabIndex = 6;
            this.genkeyBtn.Text = "Generate";
            this.genkeyBtn.UseVisualStyleBackColor = true;
            this.genkeyBtn.Click += new System.EventHandler(this.genkeyBtn_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label2.Location = new System.Drawing.Point(12, 228);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(135, 22);
            this.label2.TabIndex = 7;
            this.label2.Text = "Sign message";
            // 
            // signPriketTxt
            // 
            this.signPriketTxt.Location = new System.Drawing.Point(15, 283);
            this.signPriketTxt.Name = "signPriketTxt";
            this.signPriketTxt.Size = new System.Drawing.Size(219, 22);
            this.signPriketTxt.TabIndex = 8;
            // 
            // signMessageTxt
            // 
            this.signMessageTxt.Location = new System.Drawing.Point(296, 283);
            this.signMessageTxt.Name = "signMessageTxt";
            this.signMessageTxt.Size = new System.Drawing.Size(219, 22);
            this.signMessageTxt.TabIndex = 9;
            // 
            // signSignatureTxt
            // 
            this.signSignatureTxt.Location = new System.Drawing.Point(580, 283);
            this.signSignatureTxt.Name = "signSignatureTxt";
            this.signSignatureTxt.Size = new System.Drawing.Size(219, 22);
            this.signSignatureTxt.TabIndex = 10;
            // 
            // signBtn
            // 
            this.signBtn.Enabled = false;
            this.signBtn.Location = new System.Drawing.Point(675, 327);
            this.signBtn.Name = "signBtn";
            this.signBtn.Size = new System.Drawing.Size(124, 36);
            this.signBtn.TabIndex = 11;
            this.signBtn.Text = "Sign";
            this.signBtn.UseVisualStyleBackColor = true;
            this.signBtn.Click += new System.EventHandler(this.signBtn_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label3.Location = new System.Drawing.Point(12, 378);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(147, 22);
            this.label3.TabIndex = 12;
            this.label3.Text = "Verify message";
            // 
            // verSignatureTxt
            // 
            this.verSignatureTxt.Location = new System.Drawing.Point(580, 431);
            this.verSignatureTxt.Name = "verSignatureTxt";
            this.verSignatureTxt.Size = new System.Drawing.Size(219, 22);
            this.verSignatureTxt.TabIndex = 15;
            // 
            // verMessageTxt
            // 
            this.verMessageTxt.Location = new System.Drawing.Point(296, 431);
            this.verMessageTxt.Name = "verMessageTxt";
            this.verMessageTxt.Size = new System.Drawing.Size(219, 22);
            this.verMessageTxt.TabIndex = 14;
            // 
            // verPubkeyTxt
            // 
            this.verPubkeyTxt.Location = new System.Drawing.Point(15, 431);
            this.verPubkeyTxt.Name = "verPubkeyTxt";
            this.verPubkeyTxt.Size = new System.Drawing.Size(219, 22);
            this.verPubkeyTxt.TabIndex = 13;
            // 
            // verifyBtn
            // 
            this.verifyBtn.Enabled = false;
            this.verifyBtn.Location = new System.Drawing.Point(675, 475);
            this.verifyBtn.Name = "verifyBtn";
            this.verifyBtn.Size = new System.Drawing.Size(124, 36);
            this.verifyBtn.TabIndex = 16;
            this.verifyBtn.Text = "Verify";
            this.verifyBtn.UseVisualStyleBackColor = true;
            this.verifyBtn.Click += new System.EventHandler(this.verifyBtn_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label4.Location = new System.Drawing.Point(12, 9);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(176, 22);
            this.label4.TabIndex = 17;
            this.label4.Text = "Choose algorithms";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label5.Location = new System.Drawing.Point(12, 121);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(52, 18);
            this.label5.TabIndex = 18;
            this.label5.Text = "Curve";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label6.Location = new System.Drawing.Point(162, 121);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(72, 18);
            this.label6.TabIndex = 19;
            this.label6.Text = "Key size";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label7.Location = new System.Drawing.Point(325, 121);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(112, 18);
            this.label7.TabIndex = 20;
            this.label7.Text = "Public key file";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label8.Location = new System.Drawing.Point(577, 121);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(118, 18);
            this.label8.TabIndex = 21;
            this.label8.Text = "Private key file";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label9.Location = new System.Drawing.Point(12, 260);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(118, 18);
            this.label9.TabIndex = 22;
            this.label9.Text = "Private key file";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label10.Location = new System.Drawing.Point(293, 260);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(103, 18);
            this.label10.TabIndex = 23;
            this.label10.Text = "Message file";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label11.Location = new System.Drawing.Point(577, 260);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(106, 18);
            this.label11.TabIndex = 24;
            this.label11.Text = "Signature file";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label12.Location = new System.Drawing.Point(577, 408);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(106, 18);
            this.label12.TabIndex = 27;
            this.label12.Text = "Signature file";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label13.Location = new System.Drawing.Point(293, 408);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(103, 18);
            this.label13.TabIndex = 26;
            this.label13.Text = "Message file";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label14.Location = new System.Drawing.Point(12, 408);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(112, 18);
            this.label14.TabIndex = 25;
            this.label14.Text = "Public key file";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(837, 536);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.label14);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.verifyBtn);
            this.Controls.Add(this.verSignatureTxt);
            this.Controls.Add(this.verMessageTxt);
            this.Controls.Add(this.verPubkeyTxt);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.signBtn);
            this.Controls.Add(this.signSignatureTxt);
            this.Controls.Add(this.signMessageTxt);
            this.Controls.Add(this.signPriketTxt);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.genkeyBtn);
            this.Controls.Add(this.prikeyTxt);
            this.Controls.Add(this.pubkeyTxt);
            this.Controls.Add(this.keysizeTxt);
            this.Controls.Add(this.curveBox);
            this.Controls.Add(this.algoBox);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox algoBox;
        private System.Windows.Forms.ComboBox curveBox;
        private System.Windows.Forms.TextBox keysizeTxt;
        private System.Windows.Forms.TextBox pubkeyTxt;
        private System.Windows.Forms.TextBox prikeyTxt;
        private System.Windows.Forms.Button genkeyBtn;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox signPriketTxt;
        private System.Windows.Forms.TextBox signMessageTxt;
        private System.Windows.Forms.TextBox signSignatureTxt;
        private System.Windows.Forms.Button signBtn;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox verSignatureTxt;
        private System.Windows.Forms.TextBox verMessageTxt;
        private System.Windows.Forms.TextBox verPubkeyTxt;
        private System.Windows.Forms.Button verifyBtn;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label14;
    }
}

