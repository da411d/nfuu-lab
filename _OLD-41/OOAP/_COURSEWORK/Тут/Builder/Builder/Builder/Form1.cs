using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Text.RegularExpressions;

namespace Builder
{
    public partial class Form1 : Form
    {
        MIMEMsg MIMEMessage;                 //повідомлення в MIME форматі
        MIMEParser parser;                   //обєкт, який проводить перетворення форматів
        OutboundMessageIF otherFormatMessage;//повідомлення в іншому форматі
        bool validAddress1 = false;          //валідність  адреси відправника
        bool validAddress2 = false;          //валідність адреси одержувача

        public Form1()
        {
            InitializeComponent();
        }

        //створення та відображення повідомлення в MIME форматі
        private void displayMIME_Click(object sender, EventArgs e)
        {
            if (validAddress1 && validAddress2)
            {  
                MIMEMessage = new MIMEMsg(fromAddress.Text, toAddress.Text, richTextBox1.Text);
                richTextBox1.Clear();
                richTextBox1.Text = MIMEMessage.Message;
            }
            else MessageBox.Show("Введіть коректні електронні адреси!",
                                 "Некоректні електронні адреси!",MessageBoxButtons.OK,
                                 MessageBoxIcon.Warning);
        }

        //перетворення повідомлення до іншого формату та відображення
        private void displayOtherFormat_Click(object sender, EventArgs e)
        {
            if (MIMEMessage != null)
            {
                parser = new MIMEParser(MIMEMessage);
                string format = "";
                //визначення формату перетворення
                if (radioButton1.Checked == true)
                    format = "MAPI";
                else if (radioButton2.Checked == true)
                    format = "PROFS";
                //виконання перетворення
                otherFormatMessage = parser.parse(format);
                richTextBox2.Text = otherFormatMessage.ToString();
            }
            else
                MessageBox.Show("Повідомлення для перетворення відсутнє!"+
                                System.Environment.NewLine+" Створіть повідомлення!",
                                "Відсутній об'єкт MIME!",MessageBoxButtons.OK,MessageBoxIcon.Warning);
        }
        //Перевірка електронної адреси на допустимість
        public bool IsValidEmail(string email)
        {
            string pattern = @"^[-a-zA-Z0-9][-.a-zA-Z0-9]*@[-.a-zA-Z0-9]+(\.[-.a-zA-Z0-9]+)*\.
                    (com|edu|info|gov|int|mil|net|org|biz|name|museum|coop|aero|pro|tv|[a-zA-Z]{2})$";
            Regex check = new Regex(pattern,RegexOptions.IgnorePatternWhitespace);
            bool valid = false;
            if (string.IsNullOrEmpty(email))
            {
                valid = false;
            }
            else
            {
                valid = check.IsMatch(email);
            }
            return valid;
        }
        //Вивід позначки про валідність дреси
        void ShowAddressStatus(TextBox box, Label ValideLabel, ref bool valid)
        {
            string address = box.Text;
            valid = IsValidEmail(address);
            if (valid)
            {
                ValideLabel.ForeColor = Color.Blue;
                ValideLabel.Text = valid.ToString();     
            }
            else
            {
                ValideLabel.ForeColor = Color.Red;
                ValideLabel.Text = valid.ToString();
            }
        }
        private void toAddress_TextChanged(object sender, EventArgs e)
        {
            ShowAddressStatus(toAddress, toValide,ref validAddress2);
        }
        private void fromAddress_TextChanged(object sender, EventArgs e)
        {
            ShowAddressStatus(fromAddress, fromValide, ref validAddress1);
        }    
    }
}
