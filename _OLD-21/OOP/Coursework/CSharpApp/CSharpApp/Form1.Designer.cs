namespace BigIntNumbersCalculator
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
            this.selectAction = new System.Windows.Forms.ComboBox();
            this.output = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.inputA = new System.Windows.Forms.NumericUpDown();
            this.inputB = new System.Windows.Forms.NumericUpDown();
            this.add = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.inputA)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.inputB)).BeginInit();
            this.SuspendLayout();
            // 
            // selectAction
            // 
            this.selectAction.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.selectAction.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.selectAction.FormattingEnabled = true;
            this.selectAction.Items.AddRange(new object[] {
            "+",
            "-",
            "*",
            "/"});
            this.selectAction.Location = new System.Drawing.Point(12, 53);
            this.selectAction.Name = "selectAction";
            this.selectAction.Size = new System.Drawing.Size(576, 29);
            this.selectAction.TabIndex = 2;
            this.selectAction.Text = "+";
            this.selectAction.SelectedIndexChanged += new System.EventHandler(this.selectAction_SelectedIndexChanged);
            // 
            // output
            // 
            this.output.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.output.BackColor = System.Drawing.SystemColors.Window;
            this.output.Font = new System.Drawing.Font("Segoe UI", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.output.Location = new System.Drawing.Point(12, 180);
            this.output.Name = "output";
            this.output.ReadOnly = true;
            this.output.Size = new System.Drawing.Size(535, 35);
            this.output.TabIndex = 4;
            this.output.Text = "0";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(12, 153);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(96, 25);
            this.label1.TabIndex = 3;
            this.label1.Text = "Результат";
            // 
            // inputA
            // 
            this.inputA.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.inputA.Font = new System.Drawing.Font("Segoe UI", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.inputA.Location = new System.Drawing.Point(12, 12);
            this.inputA.Maximum = new decimal(new int[] {
            268435455,
            1042612833,
            542101086,
            0});
            this.inputA.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.inputA.Name = "inputA";
            this.inputA.Size = new System.Drawing.Size(576, 35);
            this.inputA.TabIndex = 1;
            this.inputA.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.inputA.ValueChanged += new System.EventHandler(this.inputA_ValueChanged);
            this.inputA.KeyUp += new System.Windows.Forms.KeyEventHandler(this.inputA_KeyUp);
            // 
            // inputB
            // 
            this.inputB.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.inputB.Font = new System.Drawing.Font("Segoe UI", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.inputB.Location = new System.Drawing.Point(12, 88);
            this.inputB.Maximum = new decimal(new int[] {
            268435455,
            1042612833,
            542101086,
            0});
            this.inputB.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.inputB.Name = "inputB";
            this.inputB.Size = new System.Drawing.Size(576, 35);
            this.inputB.TabIndex = 3;
            this.inputB.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.inputB.ValueChanged += new System.EventHandler(this.inputB_ValueChanged);
            this.inputB.KeyUp += new System.Windows.Forms.KeyEventHandler(this.inputB_KeyUp);
            // 
            // add
            // 
            this.add.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.add.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.add.Location = new System.Drawing.Point(553, 180);
            this.add.Name = "add";
            this.add.Size = new System.Drawing.Size(35, 35);
            this.add.TabIndex = 5;
            this.add.Text = "+";
            this.add.UseVisualStyleBackColor = true;
            this.add.Click += new System.EventHandler(this.add_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(600, 227);
            this.Controls.Add(this.add);
            this.Controls.Add(this.inputB);
            this.Controls.Add(this.inputA);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.selectAction);
            this.Controls.Add(this.output);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.ShowIcon = false;
            this.Text = "КАЛЬКУЛЯТОР";
            ((System.ComponentModel.ISupportInitialize)(this.inputA)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.inputB)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.ComboBox selectAction;
        public System.Windows.Forms.TextBox output;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown inputA;
        private System.Windows.Forms.NumericUpDown inputB;
        private System.Windows.Forms.Button add;
    }
}

