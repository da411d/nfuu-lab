using System;
using System.Collections.Generic;


namespace StockExchangeDraft
{
    public class PlayerRand : Player
    {
        public PlayerRand(string pname, double pbudget)
        {
            PlayerName = pname;
            PlayerBudget = pbudget;
            PlayerStartingBudget = pbudget;
        }
        public override void PlayerBuyAndSell(Dictionary<string, Company> companies, int i, int rand)
        {
            int c = 0;

            //WIP Random pattern for buying stocks 
            foreach (KeyValuePair<string, Company> companyKeyVal in companies)
            {
                Company company = companyKeyVal.Value;
                string companyKey = companyKeyVal.Key;

                if (i % 2 == 0 && company.CompanyDelisted != true && (rand * company.StockValue < PlayerBudget))
                {
                    PlayerBudget -= rand * company.StockValue;
                    PlayerStocks[companyKey].ValueIncrease += rand;
                    PlayerStocksValue += rand * company.StockValue;
                    PlayerStocks[companyKey].ValueIncrease = 1;
                }


                if (i % 2 == 1 && company.CompanyDelisted != true)
                {
                    PlayerBudget += PlayerStocks[companyKey].ValueIncrease * company.StockValue;
                    PlayerStocksValue -= PlayerStocks[companyKey].ValueIncrease * company.StockValue;
                    PlayerStocks[companyKey].ValueIncrease = 0;
                    PlayerStocks[companyKey].NumberOfShares = 0;
                }
                c++;

            }

            //Value update + bancrupcy check
            PlayerBalance = Math.Round(PlayerBudget + PlayerStocksValue - PlayerStartingBudget, 2);
            PlayerBudget = Math.Round(PlayerBudget, 2);
            PlayerStocksValue = Math.Round(PlayerStocksValue, 2);
            if ((PlayerBudget + PlayerStocksValue) < 0.1 * PlayerStartingBudget) PlayerBancrupt = true;
        }
    }
}
