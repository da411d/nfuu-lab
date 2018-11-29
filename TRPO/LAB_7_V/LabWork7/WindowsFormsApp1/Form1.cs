using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using System.Runtime.Remoting.Messaging;
using System.Diagnostics;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        private Random rand = new Random();
        private int[] firstArray, secondArray;
        private int length;
        //Stopwatch stopWatch = new Stopwatch();
        //Stopwatch stopWatch1 = new Stopwatch();
        ManualResetEvent mre = new ManualResetEvent(false);

        public Form1()
        {
            InitializeComponent();
        }

        public string firstSumCalculation()
        {
            string str = String.Empty;
            int firstSum = -1;
            int i = 0;
            while (i < length)
            {
                if (firstSum % 5 == 0)
                    break;
                firstSum += firstArray[i];
                str += String.Format("{0}. {1}\r\n", i + 1, firstSum);
                i++;
            }
            mre.Set();
            return str;
        }

        public string secondSumCalculation()
        {
            string str = String.Empty;
            int secondSum = -1;
            int i = 0;
            while (i < length)
            {
                if (secondSum % 5 == 0)
                    break;
                secondSum += secondArray[i];
                str += String.Format("{0}. {1}\r\n", i + 1, secondSum);
                i++;
                //Thread.Sleep(100);
            }
            return str;
        }

        private void startButton_Click(object sender, EventArgs e)
        {
            label1.Text = String.Empty;
            label2.Text = String.Empty;
            //stopWatch.Reset();
            //stopWatch1.Reset();

            length = rand.Next(10, 20);
            firstArray = new int[length];
            secondArray = new int[length];
            for (int i = 0; i < length; i++)
            {
                firstArray[i] = rand.Next(1, 9);
                secondArray[i] = rand.Next(1, 9);
            }

            //stopWatch.Start();
            var action1 = new Func<string>(firstSumCalculation);
            IAsyncResult result1 = action1.BeginInvoke(null, null);
            textBox1.Text = action1.EndInvoke(result1);
            //stopWatch.Stop();

            //label1.Text = stopWatch.Elapsed.TotalMilliseconds.ToString() + " milliseconds";

            mre.WaitOne();

            //stopWatch1.Start();
            var action2 = new Func<string>(secondSumCalculation);
            IAsyncResult result2 = action2.BeginInvoke(null, null);
            textBox2.Text = action2.EndInvoke(result2);
            //stopWatch1.Stop();

            //label2.Text = stopWatch1.Elapsed.TotalMilliseconds.ToString() + " milliseconds";
        }
    }
}