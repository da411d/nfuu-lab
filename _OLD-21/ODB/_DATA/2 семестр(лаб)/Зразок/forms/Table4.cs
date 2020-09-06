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
    public partial class Table4 : Form
    {
        public Table4()
        {
            InitializeComponent();
        }

        private void Table4_Load(object sender, EventArgs e)
        {
            h.bs1 = new BindingSource();
            h.bs1.DataSource = h.myfunDT("SELECT * FROM Osoba inner join Katalog inner join Formuljar");
            dataGridView1.DataSource = h.bs1;
            h.bs1.Sort = dataGridView1.Columns[0].Name;
        }
    }
}
