using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace StockExchangeDraft
{
    public class Company
    {
        private string companyName;
        private string companySymbol;
        private double stockValue;
        private double previousValue;
        private double changeSinceStart;
        private double begginingValue;
        private double dailyChangePercentage;
        private double dailyChangeUsd;
        private double stability;
        private double startingStability;
        private bool companyDelisted = false;
        private ListViewItem listViewItemCompany;

        public string CompanyName { get => companyName; set => companyName = value; }
        public string CompanySymbol { get => companySymbol; set => companySymbol = value; }
        public double StockValue { get => stockValue; set => stockValue = value; }
        public double PreviousValue { get => previousValue; set => previousValue = value; }
        public double ChangeSinceStart { get => changeSinceStart; set => changeSinceStart = value; }
        public double BegginingValue { get => begginingValue; set => begginingValue = value; }
        public double DailyChangePercentage { get => dailyChangePercentage; set => dailyChangePercentage = value; }
        public double DailyChangeUsd { get => dailyChangeUsd; set => dailyChangeUsd = value; }
        public double Stability { get => stability; set => stability = value; }
        public double StartingStability { get => startingStability; set => startingStability = value; }
        public bool CompanyDelisted { get => companyDelisted; set => companyDelisted = value; }
        public ListViewItem ListViewItemCompany { get => listViewItemCompany; set => listViewItemCompany = value; }

        public Company(string sname, string ssymbol, double svalue, double sstability)
        {
            CompanyName = sname;
            CompanySymbol = ssymbol;
            StockValue = svalue;
            BegginingValue = svalue;
            Stability = sstability;
            StartingStability = sstability;
        }

        public Company()
        {
        }

        public double GetStockValue()
        {
            return StockValue;
        }

        public void DailyChange(double value)
        {
            PreviousValue = StockValue;
            StockValue = Math.Round(StockValue + StockValue * value, 2);
            ChangeSinceStart = Math.Round(StockValue - BegginingValue, 2);
            DailyChangePercentage = Math.Round(((StockValue - PreviousValue) / PreviousValue) * 100, 4);
            DailyChangeUsd = Math.Round((StockValue - PreviousValue), 4);
        }

        public void CompanyReset()
        {
            CompanyDelisted = false;
            Stability = StartingStability;
            StockValue = BegginingValue;
            ChangeSinceStart = 0;
            DailyChangeUsd = 0;
            DailyChangePercentage = 0;
            PreviousValue = 0;
        }
    }
}
