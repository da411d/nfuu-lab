using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace forms
{
    public partial class TabControlForm : Form
    {
        public TabControlForm()
        {
            InitializeComponent();
        }

        private void TabControlForm_Load(object sender, EventArgs e)
        {
            h.bs1 = new BindingSource();
            h.bs1.DataSource = h.myfunDT("select * from Katalog");
            dataGridView1.DataSource = h.bs1;
        }

        private void TabControlForm_Click(object sender, EventArgs e)
        {
            string d = tabControl1.TabPages[tabControl1.SelectedIndex].Text;
            MessageBox.Show("d="+d);
        }

        private void TabControlForm_MouseClick(object sender, MouseEventArgs e)
        {
            string d = tabControl1.TabPages[tabControl1.SelectedIndex].Text;
            MessageBox.Show("d=" + d);
        }

        private void TabControlForm_MouseEnter(object sender, EventArgs e)
        {
           // string d = tabControl1.TabPages[tabControl1.SelectedIndex].Text; 
           // MessageBox.Show("d=" + d);
        }

        private void tabControl1_Selecting(object sender, TabControlCancelEventArgs e)
        {
            string d = tabControl1.TabPages[tabControl1.SelectedIndex].Text;
            MessageBox.Show("d=" + d);
        }
    }
}
