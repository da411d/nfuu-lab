namespace Builder
{
    partial class Form1
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.fromAddress = new System.Windows.Forms.TextBox();
            this.toAddress = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.displayMIME = new System.Windows.Forms.Button();
            this.fromValide = new System.Windows.Forms.Label();
            this.toValide = new System.Windows.Forms.Label();
            this.displayOtherFormat = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.richTextBox2 = new System.Windows.Forms.RichTextBox();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // fromAddress
            // 
            this.fromAddress.Location = new System.Drawing.Point(113, 28);
            this.fromAddress.Name = "fromAddress";
            this.fromAddress.Size = new System.Drawing.Size(139, 20);
            this.fromAddress.TabIndex = 0;
            this.fromAddress.TextChanged += new System.EventHandler(this.fromAddress_TextChanged);
            // 
            // toAddress
            // 
            this.toAddress.Location = new System.Drawing.Point(113, 54);
            this.toAddress.Name = "toAddress";
            this.toAddress.Size = new System.Drawing.Size(139, 20);
            this.toAddress.TabIndex = 1;
            this.toAddress.TextChanged += new System.EventHandler(this.toAddress_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(21, 28);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(64, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Відправник";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(21, 57);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(49, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Адресат";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(131, 87);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(105, 13);
            this.label3.TabIndex = 4;
            this.label3.Text = "Текс повідомлення";
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(24, 114);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.Size = new System.Drawing.Size(321, 112);
            this.richTextBox1.TabIndex = 5;
            this.richTextBox1.Text = "Суди слід вписати зміст вашого повідомлення!";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.displayMIME);
            this.groupBox1.Controls.Add(this.fromValide);
            this.groupBox1.Controls.Add(this.toValide);
            this.groupBox1.Controls.Add(this.fromAddress);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.richTextBox1);
            this.groupBox1.Controls.Add(this.toAddress);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(368, 280);
            this.groupBox1.TabIndex = 6;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Параметри повідомлення в форматі MIME ";
            // 
            // displayMIME
            // 
            this.displayMIME.Location = new System.Drawing.Point(91, 232);
            this.displayMIME.Name = "displayMIME";
            this.displayMIME.Size = new System.Drawing.Size(182, 31);
            this.displayMIME.TabIndex = 8;
            this.displayMIME.Text = "Переглянути повідомлення";
            this.displayMIME.UseVisualStyleBackColor = true;
            this.displayMIME.Click += new System.EventHandler(this.displayMIME_Click);
            // 
            // fromValide
            // 
            this.fromValide.AutoSize = true;
            this.fromValide.Location = new System.Drawing.Point(273, 31);
            this.fromValide.Name = "fromValide";
            this.fromValide.Size = new System.Drawing.Size(0, 13);
            this.fromValide.TabIndex = 7;
            // 
            // toValide
            // 
            this.toValide.AutoSize = true;
            this.toValide.Location = new System.Drawing.Point(273, 57);
            this.toValide.Name = "toValide";
            this.toValide.Size = new System.Drawing.Size(0, 13);
            this.toValide.TabIndex = 6;
            // 
            // displayOtherFormat
            // 
            this.displayOtherFormat.Location = new System.Drawing.Point(189, 29);
            this.displayOtherFormat.Name = "displayOtherFormat";
            this.displayOtherFormat.Size = new System.Drawing.Size(156, 31);
            this.displayOtherFormat.TabIndex = 7;
            this.displayOtherFormat.Text = "Перетворити";
            this.displayOtherFormat.UseVisualStyleBackColor = true;
            this.displayOtherFormat.Click += new System.EventHandler(this.displayOtherFormat_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.richTextBox2);
            this.groupBox2.Controls.Add(this.radioButton2);
            this.groupBox2.Controls.Add(this.radioButton1);
            this.groupBox2.Controls.Add(this.displayOtherFormat);
            this.groupBox2.Location = new System.Drawing.Point(12, 298);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(368, 218);
            this.groupBox2.TabIndex = 8;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Перетворити повідомлення до іншого формату";
            // 
            // richTextBox2
            // 
            this.richTextBox2.Location = new System.Drawing.Point(24, 66);
            this.richTextBox2.Name = "richTextBox2";
            this.richTextBox2.Size = new System.Drawing.Size(321, 137);
            this.richTextBox2.TabIndex = 10;
            this.richTextBox2.Text = "";
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(102, 36);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(61, 17);
            this.radioButton2.TabIndex = 9;
            this.radioButton2.TabStop = true;
            this.radioButton2.Text = "PROFS";
            this.radioButton2.UseVisualStyleBackColor = true;
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Checked = true;
            this.radioButton1.Location = new System.Drawing.Point(24, 36);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(51, 17);
            this.radioButton1.TabIndex = 8;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "MAPI";
            this.radioButton1.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(392, 523);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "MessageMenager";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TextBox fromAddress;
        private System.Windows.Forms.TextBox toAddress;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button displayOtherFormat;
        private System.Windows.Forms.Label fromValide;
        private System.Windows.Forms.Label toValide;
        private System.Windows.Forms.Button displayMIME;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.RichTextBox richTextBox2;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RadioButton radioButton1;
    }
}

