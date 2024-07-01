namespace GUI
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
            this.hashBtn = new System.Windows.Forms.Button();
            this.hashTxt = new System.Windows.Forms.TextBox();
            this.fileInputBtn = new System.Windows.Forms.Button();
            this.algoCbo = new System.Windows.Forms.ComboBox();
            this.digestLengthTxt = new System.Windows.Forms.TextBox();
            this.resultTxt = new System.Windows.Forms.RichTextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.saveOutputBtn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // hashBtn
            // 
            this.hashBtn.Location = new System.Drawing.Point(636, 126);
            this.hashBtn.Name = "hashBtn";
            this.hashBtn.Size = new System.Drawing.Size(109, 30);
            this.hashBtn.TabIndex = 0;
            this.hashBtn.Text = "Hash";
            this.hashBtn.UseVisualStyleBackColor = true;
            this.hashBtn.Click += new System.EventHandler(this.hashBtn_Click);
            // 
            // hashTxt
            // 
            this.hashTxt.Location = new System.Drawing.Point(34, 48);
            this.hashTxt.Name = "hashTxt";
            this.hashTxt.Size = new System.Drawing.Size(586, 22);
            this.hashTxt.TabIndex = 1;
            // 
            // fileInputBtn
            // 
            this.fileInputBtn.Location = new System.Drawing.Point(636, 48);
            this.fileInputBtn.Name = "fileInputBtn";
            this.fileInputBtn.Size = new System.Drawing.Size(109, 30);
            this.fileInputBtn.TabIndex = 2;
            this.fileInputBtn.Text = "Choose file";
            this.fileInputBtn.UseVisualStyleBackColor = true;
            this.fileInputBtn.Click += new System.EventHandler(this.fileInputBtn_Click);
            // 
            // algoCbo
            // 
            this.algoCbo.FormattingEnabled = true;
            this.algoCbo.Items.AddRange(new object[] {
            "sha224",
            "sha256",
            "sha384",
            "sha512",
            "sha3_224",
            "sha3_256",
            "sha3_384",
            "sha3_512",
            "shake128",
            "shake256"});
            this.algoCbo.Location = new System.Drawing.Point(34, 126);
            this.algoCbo.Name = "algoCbo";
            this.algoCbo.Size = new System.Drawing.Size(163, 24);
            this.algoCbo.TabIndex = 3;
            this.algoCbo.SelectedIndexChanged += new System.EventHandler(this.algoCbo_SelectedIndexChanged);
            // 
            // digestLengthTxt
            // 
            this.digestLengthTxt.Enabled = false;
            this.digestLengthTxt.Location = new System.Drawing.Point(222, 126);
            this.digestLengthTxt.Name = "digestLengthTxt";
            this.digestLengthTxt.Size = new System.Drawing.Size(398, 22);
            this.digestLengthTxt.TabIndex = 4;
            // 
            // resultTxt
            // 
            this.resultTxt.Location = new System.Drawing.Point(34, 171);
            this.resultTxt.Name = "resultTxt";
            this.resultTxt.Size = new System.Drawing.Size(711, 243);
            this.resultTxt.TabIndex = 5;
            this.resultTxt.Text = "";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label1.Location = new System.Drawing.Point(34, 19);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(193, 18);
            this.label1.TabIndex = 6;
            this.label1.Text = "Input or choose from file";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label2.Location = new System.Drawing.Point(34, 97);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(142, 18);
            this.label2.TabIndex = 7;
            this.label2.Text = "Choose algorithm";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label3.Location = new System.Drawing.Point(219, 97);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(397, 18);
            this.label3.TabIndex = 8;
            this.label3.Text = "For shake128 and shake256: Choose Digest Length";
            // 
            // saveOutputBtn
            // 
            this.saveOutputBtn.Location = new System.Drawing.Point(636, 430);
            this.saveOutputBtn.Name = "saveOutputBtn";
            this.saveOutputBtn.Size = new System.Drawing.Size(109, 30);
            this.saveOutputBtn.TabIndex = 9;
            this.saveOutputBtn.Text = "Save Output";
            this.saveOutputBtn.UseVisualStyleBackColor = true;
            this.saveOutputBtn.Click += new System.EventHandler(this.saveOutputBtn_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(800, 482);
            this.Controls.Add(this.saveOutputBtn);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.resultTxt);
            this.Controls.Add(this.digestLengthTxt);
            this.Controls.Add(this.algoCbo);
            this.Controls.Add(this.fileInputBtn);
            this.Controls.Add(this.hashTxt);
            this.Controls.Add(this.hashBtn);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button hashBtn;
        private System.Windows.Forms.TextBox hashTxt;
        private System.Windows.Forms.Button fileInputBtn;
        private System.Windows.Forms.ComboBox algoCbo;
        private System.Windows.Forms.TextBox digestLengthTxt;
        private System.Windows.Forms.RichTextBox resultTxt;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button saveOutputBtn;
    }
}

