using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace LabWork5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            progressBar3.Visible = false;
            dataGridView1.Columns.Add("x", "x");
            dataGridView1.Columns.Add("f(x)", "f(x)");
            dataGridView1.Columns.Add("Condition", "Condition");
            dataGridView1.Columns[0].Width = 30;
            dataGridView1.Columns[1].Width = 80;
            dataGridView1.Columns[2].Width = 100;
        }
        private void button2_Click(object sender, EventArgs e)
        {
            dataGridView1.Rows.Clear();
            progressBar3.Value = 0;
            progressBar1.Value = 0;
            progressBar2.Value = 0;
            //timer1.Stop();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            try {
                progressBar3.Maximum = Convert.ToInt32(textBox1.Text);
                progressBar1.Maximum = 5;
                progressBar2.Maximum = Convert.ToInt32(textBox1.Text) - progressBar1.Maximum;
                timer1.Start();
            }
            catch(Exception ex) {
                MessageBox.Show(ex.Message);
            }
        }
        private void timer1_Tick(object sender, EventArgs e)
        {
            if (progressBar3.Value == progressBar3.Maximum)
            {
                timer1.Stop();
                MessageBox.Show("Completed");
            }
            else
            {
                progressBar3.Increment(1);
                Function calculation = new Function(progressBar3.Value);

                if (progressBar3.Value >=2)
                {
                    Thread thread = new Thread(calculation.FirstCalculate);
                    progressBar1.Increment(1);
                    thread.Start();
                    thread.Join();
                    String[] row = new string[] { progressBar1.Value.ToString(), Math.Round(calculation.Value, 3).ToString(), "First" };
                    dataGridView1.Rows.Add(row);
                }
                else
                {
                    Thread thread1 = new Thread(calculation.SecondCalculate);
                    progressBar2.Increment(1);
                    thread1.Start();
                    thread1.Join();
                    String[] row = new string[] { (progressBar2.Value + 5).ToString() , Math.Round(calculation.Value, 3).ToString(), "Second" };
                    dataGridView1.Rows.Add(row);
                }
            }
        }
    }
}
