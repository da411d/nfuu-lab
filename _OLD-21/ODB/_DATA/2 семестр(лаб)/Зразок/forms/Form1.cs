using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using MySql.Data.MySqlClient;

namespace forms
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            h.conStr = "server=172.16.2.250; CharacterSet = cp1251;" +
                 "user=BIBLIO; database=BIBLIO; password=111;";
        }

        private void tabl1ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Table1 f1 = new Table1();
            f1.ShowDialog();
        }

        private void tabl2ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Table2 f2 = new Table2();
            f2.ShowDialog();
        }

        private void tabl3ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Table3 f3 = new Table3();
            f3.ShowDialog();
        }
        
        private void zvedToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Table4 f4 = new Table4();
            f4.ShowDialog();
        }

        private void калькуляторToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("С А М О С Т І Й Н О ! ! !");
        }

        private void проПрограмуToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("С А М О С Т І Й Н О ! ! !");
        }

        private void tabControlToolStripMenuItem_Click(object sender, EventArgs e)
        {
            TabControlForm f1 = new TabControlForm();
            f1.ShowDialog();
        }

    }
    static class h
    {
        public static BindingSource bs1 { get; set; }
        public static string conStr { get; set; }

        public static string curVal0 { get; set; }
        public static string keyName { get; set; }
        public static string pathToFoto { get; set; }
        public static DataTable myfunDT(string sqlStr)
        {
            DataTable dt = new DataTable();
            using (MySqlConnection con = new MySqlConnection(h.conStr))
            {
                MySqlCommand com = new MySqlCommand(sqlStr, con);
                try
                {
                    con.Open();
                    using (MySqlDataReader dr = com.ExecuteReader())
                    {
                        if (dr.HasRows)
                        {
                            dt.Load(dr);
                        }
                    }
                    con.Close();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
            return dt;
        }
    } 


}
