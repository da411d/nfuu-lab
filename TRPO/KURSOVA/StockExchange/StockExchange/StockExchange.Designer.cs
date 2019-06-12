namespace StockExchangeDraft
{
    partial class StockExchange
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
            this.components = new System.ComponentModel.Container();
            this.buttonExit = new System.Windows.Forms.Button();
            this.buttonShowStocks = new System.Windows.Forms.Button();
            this.panelMenu = new System.Windows.Forms.Panel();
            this.panelStockValues = new System.Windows.Forms.Panel();
            this.labelPlayers = new System.Windows.Forms.Label();
            this.labelCompanies = new System.Windows.Forms.Label();
            this.playersListView = new System.Windows.Forms.ListView();
            this.columnPlayerName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnPlayerBudget = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnPlayerStocksValue = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnPlayerBalance = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.companiesListView = new System.Windows.Forms.ListView();
            this.columnSymbol = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnCompanyName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnStockValue = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnDailyChangePercentage = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnDailyChange = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnChangeSinceStart = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.buttonReset = new System.Windows.Forms.Button();
            this.listBoxEvents = new System.Windows.Forms.ListBox();
            this.labeldayn = new System.Windows.Forms.Label();
            this.labelDay = new System.Windows.Forms.Label();
            this.buttonStopTimer = new System.Windows.Forms.Button();
            this.buttonStartTimer = new System.Windows.Forms.Button();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.panelMenu.SuspendLayout();
            this.panelStockValues.SuspendLayout();
            this.SuspendLayout();
            // 
            // buttonExit
            // 
            this.buttonExit.Location = new System.Drawing.Point(340, 332);
            this.buttonExit.Name = "buttonExit";
            this.buttonExit.Size = new System.Drawing.Size(75, 23);
            this.buttonExit.TabIndex = 0;
            this.buttonExit.Text = "Exit";
            this.buttonExit.UseVisualStyleBackColor = true;
            this.buttonExit.Click += new System.EventHandler(this.buttonExit_Click);
            // 
            // buttonShowStocks
            // 
            this.buttonShowStocks.Location = new System.Drawing.Point(324, 138);
            this.buttonShowStocks.Name = "buttonShowStocks";
            this.buttonShowStocks.Size = new System.Drawing.Size(119, 23);
            this.buttonShowStocks.TabIndex = 1;
            this.buttonShowStocks.Text = "Show Stocks";
            this.buttonShowStocks.UseVisualStyleBackColor = true;
            this.buttonShowStocks.Click += new System.EventHandler(this.buttonShowStocks_Click);
            // 
            // panelMenu
            // 
            this.panelMenu.Controls.Add(this.buttonShowStocks);
            this.panelMenu.Controls.Add(this.buttonExit);
            this.panelMenu.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelMenu.Location = new System.Drawing.Point(0, 0);
            this.panelMenu.Name = "panelMenu";
            this.panelMenu.Size = new System.Drawing.Size(807, 345);
            this.panelMenu.TabIndex = 2;
            // 
            // panelStockValues
            // 
            this.panelStockValues.Controls.Add(this.labelPlayers);
            this.panelStockValues.Controls.Add(this.labelCompanies);
            this.panelStockValues.Controls.Add(this.playersListView);
            this.panelStockValues.Controls.Add(this.companiesListView);
            this.panelStockValues.Controls.Add(this.buttonReset);
            this.panelStockValues.Controls.Add(this.listBoxEvents);
            this.panelStockValues.Controls.Add(this.labeldayn);
            this.panelStockValues.Controls.Add(this.labelDay);
            this.panelStockValues.Controls.Add(this.buttonStopTimer);
            this.panelStockValues.Controls.Add(this.buttonStartTimer);
            this.panelStockValues.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelStockValues.Location = new System.Drawing.Point(0, 0);
            this.panelStockValues.Name = "panelStockValues";
            this.panelStockValues.Size = new System.Drawing.Size(807, 345);
            this.panelStockValues.TabIndex = 2;
            this.panelStockValues.Visible = false;
            // 
            // labelPlayers
            // 
            this.labelPlayers.AutoSize = true;
            this.labelPlayers.Location = new System.Drawing.Point(14, 176);
            this.labelPlayers.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.labelPlayers.Name = "labelPlayers";
            this.labelPlayers.Size = new System.Drawing.Size(41, 13);
            this.labelPlayers.TabIndex = 28;
            this.labelPlayers.Text = "Players";
            // 
            // labelCompanies
            // 
            this.labelCompanies.AutoSize = true;
            this.labelCompanies.Location = new System.Drawing.Point(14, 15);
            this.labelCompanies.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.labelCompanies.Name = "labelCompanies";
            this.labelCompanies.Size = new System.Drawing.Size(59, 13);
            this.labelCompanies.TabIndex = 27;
            this.labelCompanies.Text = "Companies";
            // 
            // playersListView
            // 
            this.playersListView.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnPlayerName,
            this.columnPlayerBudget,
            this.columnPlayerStocksValue,
            this.columnPlayerBalance});
            this.playersListView.Location = new System.Drawing.Point(11, 193);
            this.playersListView.Margin = new System.Windows.Forms.Padding(2);
            this.playersListView.Name = "playersListView";
            this.playersListView.Size = new System.Drawing.Size(565, 116);
            this.playersListView.TabIndex = 26;
            this.playersListView.UseCompatibleStateImageBehavior = false;
            this.playersListView.View = System.Windows.Forms.View.Details;
            // 
            // columnPlayerName
            // 
            this.columnPlayerName.Text = "Player Name";
            this.columnPlayerName.Width = 98;
            // 
            // columnPlayerBudget
            // 
            this.columnPlayerBudget.Text = "Budget";
            // 
            // columnPlayerStocksValue
            // 
            this.columnPlayerStocksValue.Text = "Stocks Value";
            this.columnPlayerStocksValue.Width = 95;
            // 
            // columnPlayerBalance
            // 
            this.columnPlayerBalance.Text = "Balance";
            this.columnPlayerBalance.Width = 64;
            // 
            // companiesListView
            // 
            this.companiesListView.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnSymbol,
            this.columnCompanyName,
            this.columnStockValue,
            this.columnDailyChangePercentage,
            this.columnDailyChange,
            this.columnChangeSinceStart});
            this.companiesListView.Location = new System.Drawing.Point(11, 32);
            this.companiesListView.Margin = new System.Windows.Forms.Padding(2);
            this.companiesListView.Name = "companiesListView";
            this.companiesListView.Size = new System.Drawing.Size(563, 123);
            this.companiesListView.TabIndex = 25;
            this.companiesListView.UseCompatibleStateImageBehavior = false;
            this.companiesListView.View = System.Windows.Forms.View.Details;
            // 
            // columnSymbol
            // 
            this.columnSymbol.Text = "Symbol";
            this.columnSymbol.Width = 58;
            // 
            // columnCompanyName
            // 
            this.columnCompanyName.Text = "Company Name";
            this.columnCompanyName.Width = 139;
            // 
            // columnStockValue
            // 
            this.columnStockValue.Text = "Stock Value";
            this.columnStockValue.Width = 89;
            // 
            // columnDailyChangePercentage
            // 
            this.columnDailyChangePercentage.Text = "Daily Change %";
            this.columnDailyChangePercentage.Width = 119;
            // 
            // columnDailyChange
            // 
            this.columnDailyChange.Text = "Daily Change";
            this.columnDailyChange.Width = 96;
            // 
            // columnChangeSinceStart
            // 
            this.columnChangeSinceStart.Text = "Change Since Start";
            this.columnChangeSinceStart.Width = 135;
            // 
            // buttonReset
            // 
            this.buttonReset.Location = new System.Drawing.Point(11, 314);
            this.buttonReset.Name = "buttonReset";
            this.buttonReset.Size = new System.Drawing.Size(80, 23);
            this.buttonReset.TabIndex = 23;
            this.buttonReset.Text = "Reset";
            this.buttonReset.UseVisualStyleBackColor = true;
            this.buttonReset.Click += new System.EventHandler(this.buttonReset_Click);
            // 
            // listBoxEvents
            // 
            this.listBoxEvents.FormattingEnabled = true;
            this.listBoxEvents.Location = new System.Drawing.Point(593, 32);
            this.listBoxEvents.Name = "listBoxEvents";
            this.listBoxEvents.Size = new System.Drawing.Size(185, 277);
            this.listBoxEvents.TabIndex = 22;
            // 
            // labeldayn
            // 
            this.labeldayn.AutoSize = true;
            this.labeldayn.Location = new System.Drawing.Point(616, 11);
            this.labeldayn.Name = "labeldayn";
            this.labeldayn.Size = new System.Drawing.Size(13, 13);
            this.labeldayn.TabIndex = 7;
            this.labeldayn.Text = "0";
            // 
            // labelDay
            // 
            this.labelDay.AutoSize = true;
            this.labelDay.Location = new System.Drawing.Point(591, 11);
            this.labelDay.Name = "labelDay";
            this.labelDay.Size = new System.Drawing.Size(29, 13);
            this.labelDay.TabIndex = 3;
            this.labelDay.Text = "Day:";
            // 
            // buttonStopTimer
            // 
            this.buttonStopTimer.Location = new System.Drawing.Point(183, 314);
            this.buttonStopTimer.Name = "buttonStopTimer";
            this.buttonStopTimer.Size = new System.Drawing.Size(80, 23);
            this.buttonStopTimer.TabIndex = 6;
            this.buttonStopTimer.Text = "Stop";
            this.buttonStopTimer.UseVisualStyleBackColor = true;
            this.buttonStopTimer.Click += new System.EventHandler(this.buttonStopTimer_Click);
            // 
            // buttonStartTimer
            // 
            this.buttonStartTimer.Location = new System.Drawing.Point(97, 314);
            this.buttonStartTimer.Name = "buttonStartTimer";
            this.buttonStartTimer.Size = new System.Drawing.Size(80, 23);
            this.buttonStartTimer.TabIndex = 5;
            this.buttonStartTimer.Text = "Start";
            this.buttonStartTimer.UseVisualStyleBackColor = true;
            this.buttonStartTimer.Click += new System.EventHandler(this.buttonStartTimer_Click);
            // 
            // timer1
            // 
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // StockExchange
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(807, 345);
            this.Controls.Add(this.panelStockValues);
            this.Controls.Add(this.panelMenu);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "StockExchange";
            this.Text = "Stock";
            this.panelMenu.ResumeLayout(false);
            this.panelStockValues.ResumeLayout(false);
            this.panelStockValues.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonExit;
        private System.Windows.Forms.Button buttonShowStocks;
        private System.Windows.Forms.Panel panelMenu;
        private System.Windows.Forms.Panel panelStockValues;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button buttonStartTimer;
        private System.Windows.Forms.Button buttonStopTimer;
        private System.Windows.Forms.Label labeldayn;
        private System.Windows.Forms.Label labelDay;
        private System.Windows.Forms.ListBox listBoxEvents;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.Button buttonReset;
        private System.Windows.Forms.ListView companiesListView;
        private System.Windows.Forms.ColumnHeader columnSymbol;
        private System.Windows.Forms.ColumnHeader columnCompanyName;
        private System.Windows.Forms.ColumnHeader columnStockValue;
        private System.Windows.Forms.ColumnHeader columnDailyChangePercentage;
        private System.Windows.Forms.ColumnHeader columnDailyChange;
        private System.Windows.Forms.ColumnHeader columnChangeSinceStart;
        private System.Windows.Forms.ListView playersListView;
        private System.Windows.Forms.ColumnHeader columnPlayerName;
        private System.Windows.Forms.ColumnHeader columnPlayerBudget;
        private System.Windows.Forms.ColumnHeader columnPlayerStocksValue;
        private System.Windows.Forms.ColumnHeader columnPlayerBalance;
        private System.Windows.Forms.Label labelPlayers;
        private System.Windows.Forms.Label labelCompanies;
    }
}

