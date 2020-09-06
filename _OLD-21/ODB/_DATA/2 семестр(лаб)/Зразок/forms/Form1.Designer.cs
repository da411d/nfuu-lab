namespace forms
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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.tablesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tabl1ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tabl2ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tabl3ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.zvedToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.адмініструванняToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.калькуляторToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.проПрограмуToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tabControlToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tablesToolStripMenuItem,
            this.адмініструванняToolStripMenuItem,
            this.калькуляторToolStripMenuItem,
            this.проПрограмуToolStripMenuItem,
            this.tabControlToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(568, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // tablesToolStripMenuItem
            // 
            this.tablesToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tabl1ToolStripMenuItem,
            this.tabl2ToolStripMenuItem,
            this.tabl3ToolStripMenuItem,
            this.zvedToolStripMenuItem});
            this.tablesToolStripMenuItem.Name = "tablesToolStripMenuItem";
            this.tablesToolStripMenuItem.Size = new System.Drawing.Size(74, 20);
            this.tablesToolStripMenuItem.Text = "Таблиці БД";
            // 
            // tabl1ToolStripMenuItem
            // 
            this.tabl1ToolStripMenuItem.Name = "tabl1ToolStripMenuItem";
            this.tabl1ToolStripMenuItem.Size = new System.Drawing.Size(109, 22);
            this.tabl1ToolStripMenuItem.Text = "tabl1";
            this.tabl1ToolStripMenuItem.Click += new System.EventHandler(this.tabl1ToolStripMenuItem_Click);
            // 
            // tabl2ToolStripMenuItem
            // 
            this.tabl2ToolStripMenuItem.Name = "tabl2ToolStripMenuItem";
            this.tabl2ToolStripMenuItem.Size = new System.Drawing.Size(109, 22);
            this.tabl2ToolStripMenuItem.Text = "tabl2";
            this.tabl2ToolStripMenuItem.Click += new System.EventHandler(this.tabl2ToolStripMenuItem_Click);
            // 
            // tabl3ToolStripMenuItem
            // 
            this.tabl3ToolStripMenuItem.Name = "tabl3ToolStripMenuItem";
            this.tabl3ToolStripMenuItem.Size = new System.Drawing.Size(109, 22);
            this.tabl3ToolStripMenuItem.Text = "tabl3";
            this.tabl3ToolStripMenuItem.Click += new System.EventHandler(this.tabl3ToolStripMenuItem_Click);
            // 
            // zvedToolStripMenuItem
            // 
            this.zvedToolStripMenuItem.Name = "zvedToolStripMenuItem";
            this.zvedToolStripMenuItem.Size = new System.Drawing.Size(109, 22);
            this.zvedToolStripMenuItem.Text = "zved";
            this.zvedToolStripMenuItem.Click += new System.EventHandler(this.zvedToolStripMenuItem_Click);
            // 
            // адмініструванняToolStripMenuItem
            // 
            this.адмініструванняToolStripMenuItem.Name = "адмініструванняToolStripMenuItem";
            this.адмініструванняToolStripMenuItem.Size = new System.Drawing.Size(102, 20);
            this.адмініструванняToolStripMenuItem.Text = "Адміністрування";
            // 
            // калькуляторToolStripMenuItem
            // 
            this.калькуляторToolStripMenuItem.Name = "калькуляторToolStripMenuItem";
            this.калькуляторToolStripMenuItem.Size = new System.Drawing.Size(86, 20);
            this.калькуляторToolStripMenuItem.Text = "Калькулятор";
            this.калькуляторToolStripMenuItem.Click += new System.EventHandler(this.калькуляторToolStripMenuItem_Click);
            // 
            // проПрограмуToolStripMenuItem
            // 
            this.проПрограмуToolStripMenuItem.Name = "проПрограмуToolStripMenuItem";
            this.проПрограмуToolStripMenuItem.Size = new System.Drawing.Size(88, 20);
            this.проПрограмуToolStripMenuItem.Text = "Про програму";
            this.проПрограмуToolStripMenuItem.Click += new System.EventHandler(this.проПрограмуToolStripMenuItem_Click);
            // 
            // tabControlToolStripMenuItem
            // 
            this.tabControlToolStripMenuItem.Name = "tabControlToolStripMenuItem";
            this.tabControlToolStripMenuItem.Size = new System.Drawing.Size(72, 20);
            this.tabControlToolStripMenuItem.Text = "TabControl";
            this.tabControlToolStripMenuItem.Click += new System.EventHandler(this.tabControlToolStripMenuItem_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(568, 273);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "myBD";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem tablesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem tabl1ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem tabl2ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem tabl3ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem калькуляторToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem проПрограмуToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem zvedToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem адмініструванняToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem tabControlToolStripMenuItem;
    }
}

