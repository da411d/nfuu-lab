using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using System.Threading;

namespace StockExchangeDraft
{

    public partial class StockExchange : Form
    {
        public StockExchange()
        {
            InitializeComponent();
        }

        object locker = new object();
        //creating the objects
        private static int count = 0;
        private static double bullAndBearCheck = 0;
        private static Company apple = new Company("Apple", "aapl", 123, 1);
        private static Company microsoft = new Company("Microsoft", "msft", 1234, 1);
        private static PlayerRand player1 = new PlayerRand("Broker1", 10000);
        private static PlayerStrat player2 = new PlayerStrat("Broker2", 10000);
        private static EventCrash crash = new EventCrash("Crash", 0.99, "Stock Market Crash happened on day ");
        private static EventDelisting delisting = new EventDelisting();
        private static EventBullAndBear bullAndBear = new EventBullAndBear(0.04);


        //creating the lists
        private static Dictionary<string, Company> dictCompanies = new Dictionary<string, Company>();
        private static List<Player> lstPlayers = new List<Player>();

        public static int Count { get => count; set => count = value; }
        public static double BullAndBearCheck { get => bullAndBearCheck; set => bullAndBearCheck = value; }
        public static Company Apple { get => apple; set => apple = value; }
        public static Company Microsoft { get => microsoft; set => microsoft = value; }
        public static PlayerRand Player1 { get => player1; set => player1 = value; }
        public static PlayerStrat Player2 { get => player2; set => player2 = value; }
        public static EventCrash Crash { get => crash; set => crash = value; }
        public static EventDelisting Delisting { get => delisting; set => delisting = value; }
        public static EventBullAndBear BullAndBear { get => bullAndBear; set => bullAndBear = value; }
        public static List<Player> LstPlayers { get => lstPlayers; set => lstPlayers = value; }
        public static Dictionary<string, Company> DictCompanies { get => dictCompanies; set => dictCompanies = value; }


        //Changes label's color
        public static void SetColorPositivity(ListViewItem.ListViewSubItem label, double checkNumber)
        {
            if (checkNumber > 0) label.ForeColor = Color.Green;
            if (checkNumber < 0) label.ForeColor = Color.Red;
            if (checkNumber == 0) label.ForeColor = Color.Blue;
        }

        public static void SetColorPositivity(Label label, double checkNumber)
        {
            if (checkNumber > 0) label.ForeColor = Color.Green;
            if (checkNumber < 0) label.ForeColor = Color.Red;
            if (checkNumber == 0) label.ForeColor = Color.Blue;
        }


        private static void CompaniesListViewInitialize(Dictionary<string, Company> dictCompanies, ListView stocksListView)
        {
            foreach (KeyValuePair<string, Company> item in dictCompanies)
            {
                Company company = item.Value;
                ListViewItem listViewItem = new ListViewItem(company.CompanySymbol, 0);
                listViewItem.SubItems.Add(company.CompanyName);
                listViewItem.SubItems.Add(company.StockValue.ToString());
                listViewItem.SubItems.Add(company.DailyChangePercentage.ToString());
                listViewItem.SubItems.Add(company.DailyChangeUsd.ToString());
                listViewItem.SubItems.Add(company.ChangeSinceStart.ToString());

                //this property enables setting different colors for subitems
                listViewItem.UseItemStyleForSubItems = false;

                stocksListView.Items.Add(listViewItem);
                company.ListViewItemCompany = listViewItem;
            }
        }

        private static void CompaniesListViewDelisting(Company company, ListBox listBoxEvents)
        {
            ListViewItem listViewItem = company.ListViewItemCompany;
            if(company.CompanyDelisted)
            {
                listBoxEvents.Items.Add(company.CompanyName + Delisting.EventMessageBoxText);

                listViewItem.SubItems[1].Text = "Delisted";
                listViewItem.SubItems[1].ForeColor = Color.Red;

                for (int i = 2; i <= 5; i++)
                {
                    listViewItem.SubItems[i].Text = "---";
                    listViewItem.SubItems[i].ForeColor = Color.Red;
                }
            }
        }

        private static void CompaniesListViewUpdate(Dictionary<string, Company> dictCompanies, ListBox listBoxEvents)
        {
            if (dictCompanies.Count <= 0)
                return;

            foreach (KeyValuePair<string, Company> item in dictCompanies)
            {
                Company company = item.Value;
                ListViewItem listViewItem = company.ListViewItemCompany;

                if (company.CompanyDelisted)
                    continue;

                try
                {
                    //starting indexing with 1, because 0 is a company symbol
                    listViewItem.SubItems[1].Text = company.CompanyName;
                    listViewItem.SubItems[2].Text = company.StockValue.ToString();
                    listViewItem.SubItems[3].Text = company.DailyChangePercentage.ToString() + "%";
                    SetColorPositivity(listViewItem.SubItems[3], company.DailyChangePercentage);
                    listViewItem.SubItems[4].Text = company.DailyChangeUsd.ToString();
                    SetColorPositivity(listViewItem.SubItems[4], company.DailyChangeUsd);
                    listViewItem.SubItems[5].Text = company.ChangeSinceStart.ToString();
                    SetColorPositivity(listViewItem.SubItems[5], company.ChangeSinceStart);
                }
                catch (IndexOutOfRangeException e)
                {
                    throw new ArgumentOutOfRangeException("index parameter is out of range.", e);
                }
            }
        }

        private static void CompaniesListViewReset(ListView stocksListView)
        {
            foreach (ListViewItem listItem in stocksListView.Items)
            {
                stocksListView.Items.Remove(listItem);
            }
        }

        //updates columns for all existing companies in playersListView
        public static void PlayersListViewColumnsUpdate(Dictionary<string, Company> companies, ListView playersListView, List<Player> players)
        {
            foreach (KeyValuePair<string, Company> item in companies)
            {
                Company company = item.Value;

                bool columnExists = false;

                string companySharesText = company.CompanySymbol + " shares";

                //check if the column already exists in the listView
                foreach (ColumnHeader column in playersListView.Columns)
                {
                    if (column.Text == companySharesText)
                        columnExists = true;
                }

                //If there are is no column like that, we want to add one
                if (!columnExists)
                {
                    playersListView.Columns.Add(companySharesText, 80, HorizontalAlignment.Left);
                }
            }
        }

        public static void PlayersListViewAddSubItems(Player player, ListView playersListView)
        {
            if (player.ListViewItemPlayer == null)
                return;

            //fills the SubItems with "0" in order to make their count equal to columns count
            while(player.ListViewItemPlayer.SubItems.Count < playersListView.Columns.Count)
                player.ListViewItemPlayer.SubItems.Add("0");
        }

        private static void PlayersListViewDisplayBancrupcy(Player player, ListBox listBoxEvents)
        {
            if (player.PlayerBancrupt == true)
            {
                player.ListViewItemPlayer.SubItems[1].Text = "Player Bancrupt";
                listBoxEvents.Items.Add(player.PlayerName + " bancrupted");
            }
        }

        private static void PlayersListViewAddPlayer(Player player, ListView playersListView)
        {
            ListViewItem listViewItem = new ListViewItem(player.PlayerName, 0);
            listViewItem.SubItems.Add(player.PlayerBudget.ToString());
            listViewItem.SubItems.Add(player.PlayerBalance.ToString());

            //this property enables setting different colors for subitems
            listViewItem.UseItemStyleForSubItems = false;

            playersListView.Items.Add(listViewItem);
            player.ListViewItemPlayer = listViewItem;
        }

        private static void PlayersListViewUpdate(List<Player> players, ListBox listBoxEvents, Dictionary<string, Company> companies, ListView playersListView)
        {
            if (players.Count <= 0)
                return;

            //updates the columns of each company
            PlayersListViewColumnsUpdate(companies, playersListView, players);

            foreach (Player player in players)
            {
                if(player.ListViewItemPlayer == null || !playersListView.Items.Contains(player.ListViewItemPlayer))
                {
                    PlayersListViewAddPlayer(player, playersListView);
                }

                //adds the subitems for new columns, for each player
                PlayersListViewAddSubItems(player, playersListView);

                ListViewItem listViewItem = player.ListViewItemPlayer;

                if (player.PlayerBancrupt)
                    continue;

                try
                {
                    //starting indexing with 1, because 0 is a player name
                    listViewItem.SubItems[1].Text = player.PlayerBudget.ToString();
                    listViewItem.SubItems[2].Text = player.PlayerStocksValue.ToString();
                    listViewItem.SubItems[3].Text = player.PlayerBalance.ToString();

                    //updates the numbers of shares
                    for(int i = 3; i < playersListView.Columns.Count; i++)
                    {
                        string columnText = playersListView.Columns[i].Text;
                        string companySymbol = columnText.Substring(0, columnText.Length - 7);
                        if (player.PlayerStocks.ContainsKey(companySymbol))
                        {
                            listViewItem.SubItems[i].Text = player.PlayerStocks[companySymbol].NumberOfShares.ToString();
                        }
                    }
                }
                catch (IndexOutOfRangeException e)
                {
                    throw new ArgumentOutOfRangeException("index parameter is out of range.", e);
                }
            }
        }

        private static void PlayersListViewReset(ListView listView)
        {
            foreach (ListViewItem listItem in listView.Items)
            {
                listView.Items.Remove(listItem);
            }

            //removes the "numbers of shares" columns
            for(int i = 3; i < listView.Columns.Count; i++)
            {
                listView.Columns[i].Dispose();
            }
        }

        private static readonly Random getRandom = new Random();

        public static double GetRandomNumber(double min, double max)
        {
            Random random = new Random(Guid.NewGuid().GetHashCode());
            return random.NextDouble() * (max - min) + min;
        }
        //Random number generator
        private void buttonExit_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void buttonShowStocks_Click(object sender, EventArgs e)
        {
            panelStockValues.Visible = true;

            if (!DictCompanies.ContainsKey("aapl"))
                DictCompanies.Add("aapl", Apple);

            if(!DictCompanies.ContainsKey("msft"))
                DictCompanies.Add("msft", Microsoft);

            CompaniesListViewReset(companiesListView);
            CompaniesListViewInitialize(DictCompanies, companiesListView);

            LstPlayers.Add(Player1);
            LstPlayers.Add(Player2);

            PlayersListViewUpdate(LstPlayers, listBoxEvents, DictCompanies, playersListView);
        }      

        private void buttonBack_Click(object sender, EventArgs e)
        {
            panelStockValues.Visible = false;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            int threadId = Thread.CurrentThread.ManagedThreadId;

            lock (locker)
            {
                Count++;

                //We want to be sure, that every player has every company's stocks. Even if it's number of shares is 0. (temporary)
                Player.FillPlayerStocksWithCompanies(DictCompanies, lstPlayers);

                //multiplepurpose check value for daily changes cycle
                int i = 0;

                //Floor and Ceiling for Stock value changes
                double floor = -0.05, ceiling = 0.05;

                double change;



                //Bear and Bull Markets
                BullAndBearCheck = BullAndBear.eventCheckBullAndBear(GetRandomNumber(0, 1), Math.Round(GetRandomNumber(5, 15)));
                switch (BullAndBearCheck)
                {
                    case -1:
                        floor = -0.08; ceiling = 0;
                        listBoxEvents.Items.Add("Day " + Count.ToString() + "(Bear Market)");
                        break;
                    case 0:
                        floor = -0.05; ceiling = 0.05;
                        listBoxEvents.Items.Add("Day " + Count.ToString());
                        break;
                    case 1:
                        floor = 0; ceiling = 0.08;
                        listBoxEvents.Items.Add("Day " + Count.ToString() + "(Bull Market)");
                        break;
                }

                //Crash check + Floor and Ceiling changes if crash happens
                if (BullAndBearCheck != 1)
                    if (Crash.eventCheckCrash(GetRandomNumber(0, 1)) == 1)
                    {
                        floor = -0.2;
                        ceiling = -0.05;
                        listBoxEvents.Items.Add(Crash.EventMessageBoxText + Count.ToString());
                        foreach (KeyValuePair<string, Company> company in DictCompanies) company.Value.Stability -= 0.01;

                    }

                foreach (KeyValuePair<string, Company> item in DictCompanies)
                {
                    Company company = item.Value;
                    if (company.CompanyDelisted != true)
                    {
                        EventDelisting.eventCheckDelisting(company, Count, GetRandomNumber(0, 1));
                        if (company.Stability == 0)
                        {
                            foreach (Player player in LstPlayers)
                            {
                                player.PlayerStocksValue -= (company.StockValue * player.PlayerStocks[company.CompanySymbol].NumberOfShares);
                                player.PlayerStocks[company.CompanySymbol].NumberOfShares = 0;
                            }

                            company.CompanyDelisted = true;
                            company.StockValue = 0;
                            company.StockValue = 0;

                            CompaniesListViewDelisting(company, listBoxEvents);
                        }
                    }

                    if (company.CompanyDelisted != true)
                    {
                        //stock values + labels + value of stock owned by players changes
                        change = GetRandomNumber(floor, ceiling);
                        company.DailyChange(change);

                        foreach (Player player in LstPlayers)
                        {
                            try
                            {
                                player.PlayerStocksValue += player.PlayerStocks[item.Key].NumberOfShares * company.DailyChangeUsd;
                            }
                            catch (KeyNotFoundException ex)
                            {
                                throw new ArgumentException("Key Not Found", "company.Key", ex);
                            }
                        }
                    }
                }

                CompaniesListViewUpdate(DictCompanies, listBoxEvents);

                i = 0;

                foreach (Player player in LstPlayers)
                {
                    if (player.PlayerBancrupt != true)
                    {
                        //player buying and selling stocks + displaying it
                        player.PlayerBuyAndSell(DictCompanies, Count, Convert.ToInt32(GetRandomNumber(1, 15)));

                        if (player.PlayerBancrupt)
                            PlayersListViewDisplayBancrupcy(player, listBoxEvents);

                        PlayersListViewUpdate(LstPlayers, listBoxEvents, DictCompanies, playersListView);
                    }
                    i++;
                }


                i = 0;
                labeldayn.Text = Count.ToString();
                //simulation ending conditions
                foreach (KeyValuePair<string, Company> company in DictCompanies)
                    if (company.Value.CompanyDelisted != true) i = 1;

                if (i == 0)
                {
                    timer1.Stop();
                    listBoxEvents.Items.Add("Simulation ended by delisting of all stocks");
                }
                i = 0;
                foreach (Player player in LstPlayers) if (player.PlayerName != "Player bancrupt") i = 1;
                if (i == 0)
                {
                    timer1.Stop();
                    listBoxEvents.Items.Add("Simulation ended by bancrupcy of all players");
                }
                if (Count == 100)
                {
                    timer1.Stop();
                    listBoxEvents.Items.Add("Simulation ended by reaching 100 days");
                }
            }
        }

        private void buttonStartTimer_Click(object sender, EventArgs e)
        {
            timer1.Start();

            PlayerRand broker1 = new PlayerRand("Broker1", 10000);
            PlayerStrat broker2 = new PlayerStrat("Broker2", 10000);

            Thread playerThread1 = new Thread(() => {
                broker1.PlayerBuyAndSell(new Dictionary<string, Company>(), 0, Convert.ToInt32(GetRandomNumber(1, 15)));
               });
            playerThread1.IsBackground = true;

            Thread playerThread2 = new Thread(() => {
                broker2.PlayerBuyAndSell(new Dictionary<string, Company>(), 0, Convert.ToInt32(GetRandomNumber(1, 15)));
            });
            playerThread2.IsBackground = true;
        }

        private void buttonStopTimer_Click(object sender, EventArgs e)
        {
            timer1.Stop();
        }

        private void buttonReset_Click(object sender, EventArgs e)
        {
            foreach (Player player in LstPlayers)
                player.PlayerReset();

            PlayersListViewUpdate(LstPlayers, listBoxEvents, DictCompanies, playersListView);

            foreach (KeyValuePair<string, Company> company in DictCompanies)
            {
                company.Value.CompanyReset();
            }

            if (!DictCompanies.ContainsKey("aapl"))
                DictCompanies.Add("aapl", Apple);

            if (!DictCompanies.ContainsKey("msft"))
                DictCompanies.Add("msft", Microsoft);

            CompaniesListViewReset(companiesListView);
            CompaniesListViewInitialize(DictCompanies, companiesListView);

            Count = 0;
            timer1.Stop();
            labeldayn.Text = "0";
            listBoxEvents.Items.Clear();
            BullAndBear.BullAndBearDaysLeft = 0;

        }
    }
}
