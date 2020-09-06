using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using MySql.Data.MySqlClient;
using System.IO;

namespace forms
{
    public partial class Table1 : Form
    {
        public Table1()
        {
            InitializeComponent();
        }

        private void Table1_Load(object sender, EventArgs e)
        {
            h.bs1 = new BindingSource();
            h.bs1.DataSource = h.myfunDT("SELECT * FROM Katalog");
            bindingNavigator1.BindingSource = h.bs1;
            dataGridView1.DataSource = h.bs1; 

        }

        private void dataGridView1_CellEnter(object sender, DataGridViewCellEventArgs e)
        {
            int rIndx = dataGridView1.CurrentCell.RowIndex;
            if (rIndx < dataGridView1.RowCount - 1)
            {
                byte[] a = (byte[])dataGridView1.Rows[rIndx].Cells[6].Value;
                MemoryStream memImage = new MemoryStream(a);
                pictureBox1.Image = Image.FromStream(memImage);
                memImage.Close();
            }
            else
            {
                pictureBox1.Image = null; //при виході за межі записів
            }

        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {

            h.curVal0 = dataGridView1[0, dataGridView1.CurrentRow.Index].Value.ToString();
            h.keyName = dataGridView1.Columns[0].Name;

            Table1Del f13 = new Table1Del();
            f13.ShowDialog();

            dataGridView1.Update();
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            Table1Add f12 = new Table1Add();
            f12.ShowDialog();

            dataGridView1.Update();
        }
    }
    

}

