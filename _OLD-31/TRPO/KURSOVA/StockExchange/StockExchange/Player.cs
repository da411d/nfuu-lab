using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace StockExchangeDraft
{
    abstract public class Player
    {
        private string playerName;
        private double playerBudget;
        private Dictionary<string, Stock> playerStocks = new Dictionary<string, Stock>();
        private double playerStocksValue = 0;
        private double playerBalance;
        private double playerStartingBudget;
        private bool playerBancrupt = false;
        private ListViewItem listViewItemPlayer;

        public string PlayerName { get => playerName; set => playerName = value; }
        public double PlayerBudget { get => playerBudget; set => playerBudget = value; }
        public double PlayerStocksValue { get => playerStocksValue; set => playerStocksValue = value; }
        public double PlayerBalance { get => playerBalance; set => playerBalance = value; }
        public double PlayerStartingBudget { get => playerStartingBudget; set => playerStartingBudget = value; }
        public bool PlayerBancrupt { get => playerBancrupt; set => playerBancrupt = value; }
        internal Dictionary<string, Stock> PlayerStocks { get => playerStocks; set => playerStocks = value; }
        public ListViewItem ListViewItemPlayer { get => listViewItemPlayer; set => listViewItemPlayer = value; }

        abstract public void PlayerBuyAndSell(Dictionary<string, Company> companies, int i, int rand);
        public void PlayerReset()
        {
            PlayerBudget = PlayerStartingBudget;
            PlayerStocksValue = 0;

            foreach (KeyValuePair<string, Stock> stock in PlayerStocks)
                stock.Value.NumberOfShares = 0;

            foreach (KeyValuePair<string, Stock> stock in PlayerStocks)
                stock.Value.ValueIncrease = 0;

            PlayerBalance = 0;
            PlayerBancrupt = false;
        }
        public static void FillPlayerStocksWithCompanies(Dictionary<string, Company> companies, List<Player> players)
        {
            foreach (Player player in players)
                foreach(KeyValuePair<string, Company> company in companies)
                {
                    if(!player.playerStocks.ContainsKey(company.Key))
                        player.playerStocks.Add(company.Key, new Stock(company.Value, player));
                }
        }
    }
}
