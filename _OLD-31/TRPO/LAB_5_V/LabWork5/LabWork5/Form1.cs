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

namespace LabWork5
{
    public partial class Form1 : Form
    {
        private Thread thread;
        public Form1()
        {
            InitializeComponent();
            dataGridView1.Columns.Add("x", "x");
            dataGridView1.Columns.Add("f(x)", "f(x)");
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (progressBar1.Value == progressBar1.Maximum)
            {
                timer1.Stop();
                MessageBox.Show("Completed");
            }

            else
            {
                progressBar1.Increment(1);
                Function func = new Function(progressBar1.Value);
                thread = new Thread(new ThreadStart(func.Calculate));
                thread.Start();
                thread.Join();
                string[] row = new string[] {
                    progressBar1.Value.ToString(), Math.Round(func.Value, 3).ToString() };
                dataGridView1.Rows.Add(row);

                label1.Text = (progressBar1.Value).ToString();
            }
        }
        
        private void start_Click(object sender, EventArgs e)
        {
            progressBar1.Maximum = Int32.Parse(textBox1.Text);
            timer1.Start();
        }

        private void Reset_Click(object sender, EventArgs e)
        {
            dataGridView1.Rows.Clear();
            progressBar1.Value = 0;
        }
    }
}
