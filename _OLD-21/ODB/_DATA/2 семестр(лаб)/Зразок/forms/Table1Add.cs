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
    public partial class Table1Add : Form
    {
        public Table1Add()
        {
            InitializeComponent();
        }

        private void Table1Add_Load(object sender, EventArgs e)
        {
            h.pathToFoto = Application.StartupPath + @"\" + "img247.jpg";
            pictureBox1.Image = Image.FromFile(h.pathToFoto);

        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            // кнопка вибрати зображення
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            openFileDialog1.Title = "Виберіть файл";
            openFileDialog1.Filter = "img files (*.jpg)|*.jpg|bmp file (*.bmp)|*.bmp|All files (*.*)|*.*";
            openFileDialog1.InitialDirectory = Application.StartupPath;
            if (openFileDialog1.ShowDialog() != DialogResult.OK) return;
            {
                h.pathToFoto = openFileDialog1.FileName;
                pictureBox1.Image = Image.FromFile(h.pathToFoto);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            using (MySqlConnection con = new MySqlConnection(h.conStr))
            {
                //читаємо дані з форми FormAddRecordToTable
                string tb1 = textBox1.Text;
                string tb2 = textBox2.Text;
                string tb3 = textBox3.Text;
                string tb4 = textBox4.Text;
                string tb5 = textBox5.Text;
                string tb6 = textBox6.Text;

                string strFileName = h.pathToFoto;
                FileStream fs = new FileStream(strFileName, FileMode.Open, FileAccess.Read);
                int FileSize = (Int32)fs.Length;
                byte[] rawData = new byte[FileSize];
                fs.Read(rawData, 0, FileSize);
                fs.Close();

                //формуємо команду на додавання запису
                string sql = "INSERT INTO Katalog  (IPk,  NameK, AvtorK," +
                             " KilkK, RikVydK, VydavnK, FotoK, FotoPath)" +
                             " VALUES (@TK1,  @TK2,  @TK3, @TK4,  @TK5, " +
                             " @TK6, @File, @FileName) ";

                MySqlCommand cmd = new MySqlCommand(sql, con);

                //Додаємо параметри у колекцію класу Command 
                cmd.Parameters.AddWithValue("@TK1", tb1);
                cmd.Parameters.AddWithValue("@TK2", tb2);
                cmd.Parameters.AddWithValue("@TK3", tb3);
                cmd.Parameters.AddWithValue("@TK4", tb4);
                cmd.Parameters.AddWithValue("@TK5", tb5);
                cmd.Parameters.AddWithValue("@TK6", tb6);

                cmd.Parameters.AddWithValue("@FileName", strFileName);
                cmd.Parameters.AddWithValue("@File", rawData);

                con.Open();                   //Відкриваємо з'єднання
                cmd.ExecuteNonQuery();        //Виконуємо команду cmd
                con.Close();                  //Закриваємо з'єднання

                MessageBox.Show("Додавання запису пройшло вдало");
            }
            this.Close();                      //Закриваємо вікно
        }






    }
}
