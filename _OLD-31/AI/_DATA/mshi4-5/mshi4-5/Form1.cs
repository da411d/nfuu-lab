using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace mshi4_5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            // int sum=0;
            const int kilk = 6;
            int[,] a = new int[kilk, kilk]
           {   
             {0,1,0,0,0,1},
             {1,0,0,0,0,0},
             {1,0,0,1,0,0},
             {0,0,1,0,1,0},
             {0,0,0,1,0,0},
             {1,0,0,0,0,0}
      
           };
            int b = Convert.ToInt32(Math.Sqrt(a.Length));

            int[,] aCopy;
            aCopy = a;
            int[,] z = new int[b, 2];
            //z[0, 0] = 1;





            dataGridView1.RowCount = b;
            dataGridView1.ColumnCount = b;

            for (int i = 0; i < b; i++)
            {
                for (int j = 0; j < b; j++)
                {
                    dataGridView1.Rows[i].Cells[j].Value = a[j, i];
                }
            }
            //ширина
            int k = 1;
            int p = Convert.ToInt32(textBox1.Text);
            z[p - 1, 1] = 100500;

            for (int i = p - 1; i < kilk; i = k)
            {

                for (int j = 0; j < kilk; j++)
                {
                    aCopy[j, i] = 0;
                    if (aCopy[i, j] == 1)
                    {
                        textBox1.Text += "," + (j + 1);
                        k = j;
                        /*
                        z[d, 0] = j;
                        z[d, 1] = i;
                        d++;*/
                        z[j, 0] = j;
                        z[j, 1] = i;
                        break;
                    }

                    if (j == 5)////////////
                    {
                        k = z[i, 1];
                    }
                }

            }
            //глибина
            int[] arr = new int[kilk];
            int[,] y = new int[kilk, kilk]
            
           {
             {0,1,0,0,0,1},
             {1,0,0,0,0,0},
             {1,0,0,1,0,0},
             {0,0,1,0,1,0},
             {0,0,0,1,0,0},
             {1,0,0,0,0,0}
           };
            p = 1;
            int v = 0;
            k = Convert.ToInt32(textBox2.Text) - 1;
            arr[0] = k;
            for (int i = k; i < kilk; i = k)
            {
                for (int j = 0; j < kilk; j++)
                {
                    if (y[i, j] == 1)
                    {
                        arr[p] = j;
                        p++;
                        y[j, i] = 0;
                    };
                    if (j == 5)///////////
                    {
                        if (arr[5] == 0)/////////
                        {
                            k = arr[v + 1];
                            v++;
                        }
                        else goto R;

                    }
                }
            }
        R: int rr;
            textBox2.Text = "";
            for (int i = 0; i < kilk; i++)
            {
                rr = arr[i] + 1;
                textBox2.Text += rr + ",";
            }
        }
    }
}
