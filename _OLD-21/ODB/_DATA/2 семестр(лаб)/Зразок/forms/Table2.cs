﻿using System;
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
    public partial class Table2 : Form
    {
        public Table2()
        {
            InitializeComponent();
        }

        private void Table2_Load(object sender, EventArgs e)
        {
            h.bs1 = new BindingSource();
            h.bs1.DataSource = h.myfunDT("SELECT * FROM Osoba");
            bindingNavigator1.BindingSource = h.bs1;
            dataGridView1.DataSource = h.bs1; 
        }
    }
}
