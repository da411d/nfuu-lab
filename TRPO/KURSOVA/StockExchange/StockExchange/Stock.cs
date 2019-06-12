using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StockExchangeDraft
{
    public class Stock
    {
        private Company company;
        private Player player;
        private double numberOfShares = 0;

        //Value increase since being bought. Being used for strategy reasons.
        private double valueIncrease = 0;

        public Stock(Company company, Player player)
        {
            Company = company;
            Player = player;
            NumberOfShares = 0;
            ValueIncrease = 0;
        }
        public Stock(Company company, Player player, double numberOfShares)
        {
            Company = company;
            Player = player;
            NumberOfShares = numberOfShares;
            ValueIncrease = 0;
        }

        public Company Company { get => company; set => company = value; }
        public Player Player { get => player; set => player = value; }
        public double NumberOfShares { get => numberOfShares; set => numberOfShares = value; }
        public double ValueIncrease { get => valueIncrease; set => valueIncrease = value; }
    }
}
