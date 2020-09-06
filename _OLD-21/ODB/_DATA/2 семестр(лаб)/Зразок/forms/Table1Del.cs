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
    public partial class Table1Del : Form
    {
        public Table1Del()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Table1Del_Load(object sender, EventArgs e)
        {
            textBox1.Text = h.keyName + " = " + h.curVal0;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //формуємо запит на видалення з таблиці
            string sqlStr = "DELETE FROM Katalog WHERE " + textBox1.Text;

            if (MessageBox.Show("Ви впевнені, що хочете видалити запис", "Видалення",
                MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                using (MySqlConnection con = new MySqlConnection(h.conStr))
                {
                    MySqlCommand cmd = new MySqlCommand(sqlStr, con);

                    con.Open();              //Відкриваємо з'єднання
                    cmd.ExecuteNonQuery();   //Виконуємо команду cmd
                    con.Close();             //Закриваємо з'єднання
                }
            }
            this.Close();    //Закриваємо вікно

        }
    }
}
