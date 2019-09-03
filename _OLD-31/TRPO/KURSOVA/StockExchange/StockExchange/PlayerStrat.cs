using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace StockExchangeDraft
{
    public class PlayerStrat : Player
    {
        private double stockCheckValue;
        private string stockSymbol;
        public PlayerStrat(string pname, double pbudget)
        {
            PlayerName = pname;
            PlayerBudget = pbudget;
            PlayerStartingBudget = pbudget;
        }

        public double StockCheckValue { get => stockCheckValue; set => stockCheckValue = value; }
        public string StockSymbol { get => stockSymbol; set => stockSymbol = value; }

        public override void PlayerBuyAndSell(Dictionary<string, Company> companies, int i, int rand)
        {
            int c = 0;
            string check = this.PlayerStocks.First().Key;
            double max = 100, amn;
            if (PlayerStocksValue == 0)
            {
                foreach (KeyValuePair<String, Company> companyKeyVal in companies)
                {
                    Company company = companyKeyVal.Value;
                    string companyKey = companyKeyVal.Key;

                    if (company.CompanyDelisted != true)
                    {
                        double dailyChangePercentage = company.DailyChangePercentage;
                        PlayerStocks[companyKey].ValueIncrease = dailyChangePercentage;
                        if (c == 0) max = dailyChangePercentage;
                        else if (dailyChangePercentage < max)
                        {
                            max = dailyChangePercentage;
                            check = companyKey;
                        }
                    }

                    c++;
                }

                if (companies[check].CompanyDelisted != true)
                {
                    amn = Math.Floor(PlayerBudget / companies[check].StockValue);
                    PlayerBudget -= amn * companies[check].StockValue;
                    PlayerStocks[check].NumberOfShares = amn;
                    StockCheckValue = companies[check].StockValue;
                    StockSymbol = check;
                    PlayerStocksValue = amn * companies[check].StockValue;
                }
            }
            else
            {
                if (companies[StockSymbol].StockValue > StockCheckValue)
                {
                    PlayerBudget += PlayerStocks[StockSymbol].NumberOfShares * companies[StockSymbol].StockValue;
                    PlayerStocks[StockSymbol].NumberOfShares = 0;
                    PlayerStocksValue = 0;
                }
            }
            //Buying and selling pattern for strat player, that buys stock with biggest decrease/smallest increase in value, then waiting for bought stock value to be higher than when stock was bought
            PlayerBalance = Math.Round(PlayerBudget + PlayerStocksValue - PlayerStartingBudget, 2);
            PlayerBudget = Math.Round(PlayerBudget, 2);
            PlayerStocksValue = Math.Round(PlayerStocksValue, 2);

            //Value update + bancrupcy check
            if ((PlayerBudget + PlayerStocksValue) < 0.1 * PlayerStartingBudget) PlayerBancrupt = true;

        }
    }
}
