using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace StockExchangeDraftV0._0._1
{
    
    public partial class StcokExchange : Form
    {



        public StcokExchange()
        {
            InitializeComponent();
            

       
        }
        int i = 0;
        Stock Wig20 = new Stock("Wig20", 123);
        Stock mWig40 = new Stock("mWig40", 1234);
        Player Player1 = new Player("Andrzej", 100000);
       

        List<Stock> lststocks = new List<Stock>();
         
        
        public void colorpositivity(Label label, double checkNumber)
        {
            if (checkNumber > 0) label.ForeColor = Color.Green;
            if (checkNumber < 0) label.ForeColor = Color.Red;
            if (checkNumber == 0) label.ForeColor = Color.Blue;
        }
        
        
        private static readonly Random getrandom = new Random();

        public static double GetRandomNumber(double max, double min)
        { Random random = new Random(Guid.NewGuid().GetHashCode());

            return random.NextDouble() * (max - min) + min;
        }

        private void buttonExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void buttonShowStocks_Click(object sender, EventArgs e)
        {
            panelStockValues.Visible = true;
            labelStockValue1.Text = Wig20.stockValue.ToString();
            labelStockName1.Text = Wig20.stockName;
            labelStockValue2.Text = mWig40.stockValue.ToString();
            labelStockName2.Text = mWig40.stockName;
            lststocks.Add(Wig20);
            lststocks.Add(mWig40);
            
        }
       
        

        private void buttonBack_Click(object sender, EventArgs e)
        {
            panelStockValues.Visible = false;


        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            i++;

            double change;
            foreach (Stock stock in lststocks)
            {
                change=GetRandomNumber(0.05, -0.05);
                stock.DailyChange(change);


            }
            labelStockValue1.Text = Wig20.stockValue.ToString();
            labelPercentageChangeDaily1.Text = Wig20.dailyChangePercentage.ToString()+"%";
            colorpositivity(labelPercentageChangeDaily1, Wig20.dailyChangePercentage);
            labelChangeSinceStart1.Text = Wig20.changeSinceStart.ToString();
            colorpositivity(labelChangeSinceStart1, Wig20.changeSinceStart);
            labelDailyChange1.Text = Wig20.dailyChange.ToString();
            colorpositivity(labelDailyChange1, Wig20.dailyChange);
            labelStockValue2.Text = mWig40.stockValue.ToString();
            labelPercentageChangeDaily2.Text = mWig40.dailyChangePercentage.ToString() + "%";
            colorpositivity(labelPercentageChangeDaily2, mWig40.dailyChangePercentage);
            labelChangeSinceStart2.Text = mWig40.changeSinceStart.ToString();
            colorpositivity(labelChangeSinceStart2, mWig40.changeSinceStart);
            labelDailyChange2.Text = mWig40.dailyChange.ToString();
            colorpositivity(labelDailyChange2, mWig40.dailyChange);
            Player1.PlayerBuyAndSell(lststocks,i);
            labelPlayer1Budget.Text = Player1.playerBudget.ToString();
            labelmWig40Player1Amn.Text = Player1.playerStocks[1].ToString();
            labelWig20Playe1Amn.Text = Player1.playerStocks[0].ToString();
            labelPlayerDiff.Text = Player1.playerDifference.ToString();
            colorpositivity(labelPlayerDiff, Player1.playerDifference);
            labelStocksValuePlayer1.Text = Player1.playerStocksValue.ToString();

            labeldayn.Text = i.ToString();


        }

        private void buttonStartTimer_Click(object sender, EventArgs e)
        {
            timer1.Start();
        }

        private void buttonStopTimer_Click(object sender, EventArgs e)
        {
            timer1.Stop();
           
        }

        private void labelSinceStart_Click(object sender, EventArgs e)
        {

        }

        private void label_Click(object sender, EventArgs e)
        {

        }

       

       

        private void labelPlayer1_Click(object sender, EventArgs e)
        {
            panelPlayer1.Visible = true;
            labelPlayer1Budget.Text = Player1.playerBudget.ToString();
            labelmWig40Player1Amn.Text = Player1.playerStocks[1].ToString();
            labelWig20Playe1Amn.Text = Player1.playerStocks[0].ToString();

            labelStocksValuePlayer1.Text = Player1.playerStocksValue.ToString();
        }

        private void buttonClosePlayer1_Click(object sender, EventArgs e)
        {
            panelPlayer1.Visible = false;
        }

        private void labelDay_Click(object sender, EventArgs e)
        {

        }

        
    }

    public class Stock
    {
        public string stockName;
        public double stockValue;
        public double previousValue;
        public double changeSinceStart;
        private double begginingValue;
        public double dailyChangePercentage;
        public double dailyChange;
        public Stock(string sname, double svalue)
        {
            this.stockName = sname;
            this.stockValue = svalue;
            this.begginingValue = svalue;
        }
        public double GetStockValue()
           {
            return stockValue;
            }
        public void DailyChange(double value)

        {
            
            previousValue = stockValue;
            stockValue = Math.Round(stockValue + stockValue * value, 2);
            changeSinceStart = Math.Round(stockValue - begginingValue, 2);
            dailyChangePercentage = Math.Round(((stockValue - previousValue) / previousValue) * 100, 4);
            dailyChange = Math.Round((stockValue - previousValue), 4);
        }

        
    }
    public class Player
    {
        public string playerName;
        public double playerBudget;
        public int[] playerStocks = new int[2] { 0, 0 };
        public double playerStocksValue;
        public double[] playerStockBuyValue = new double[2] { 0, 0 };
        public double playerDifference;
        public Player(string pname, double pbudget)
        {
            this.playerName = pname;
            this.playerBudget = pbudget;
            this.playerStocksValue = 0;
            
        }
        public void PlayerBuyAndSell(List<Stock> lst, int i)
        {

            if (i % 3 == 0)
            {
                int z = playerStocks[0];
                playerBudget += z * lst[0].stockValue;
                playerStocksValue = 0;
                playerStocks[0] -= z;
                int f = 5;
                playerBudget -= f * lst[1].stockValue;
                playerStocksValue += f*lst[1].stockValue;
                playerStocks[1] += f;
            }
            if(i%3 == 1)
            {
                int z = playerStocks[1];
                playerBudget += z * lst[1].stockValue;
                playerStocksValue = 0;
                playerStocks[1] -= z;
                int f = 5;
                playerBudget -= f * lst[0].stockValue;
                playerStocksValue += f*lst[0].stockValue;
                playerStocks[0] += f;
            }


            playerDifference = Math.Round(playerBudget + playerStocksValue - 100000, 2);
            playerBudget = Math.Round(playerBudget, 2);
            playerStocksValue = Math.Round(playerStocksValue, 2);
           
        }
       

        
    }
}
