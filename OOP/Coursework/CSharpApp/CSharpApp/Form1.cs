using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BigIntNumbersCalculator
{
    public partial class Form1 : Form
    {
        BigIntArray bigIntArr;
        BigInt a, b;
        int operation;
        bool sign = true;
        Form2 frm2;

        public Form1()
        {
            InitializeComponent();
            label1.Text = "";
            btnC.ForeColor = Color.Red;
            btnAND.ForeColor = Color.Red;
            btnAdd.ForeColor = Color.Red;
            btnSub.ForeColor = Color.Red;
            btnMul.ForeColor = Color.Red;
            btnDiv.ForeColor = Color.Red;
            btnSign.ForeColor = Color.Red;
            btnEqu.ForeColor = Color.Red;
            btnReminder.ForeColor = Color.Red;
            btnSqrt.ForeColor = Color.Red;
            btnAND.ForeColor = Color.Indigo;
            btnOR.ForeColor = Color.Indigo;
            btnXOR.ForeColor = Color.Indigo;
            btnNOT.ForeColor = Color.Indigo;
            btn0.ForeColor = Color.Blue;
            btn1.ForeColor = Color.Blue;
            btn2.ForeColor = Color.Blue;
            btn3.ForeColor = Color.Blue;
            btn4.ForeColor = Color.Blue;
            btn5.ForeColor = Color.Blue;
            btn6.ForeColor = Color.Blue;
            btn7.ForeColor = Color.Blue;
            btn8.ForeColor = Color.Blue;
            btn9.ForeColor = Color.Blue;
            bigIntArr = new BigIntArray();           
        }

        private void calculate()
        {
            switch (operation)
            {
                case 1:
                    b = a + new BigInt(Display.Text, 10);
                    Display.Text = b.ToString();
                    break;
                case 2:
                    b = a - new BigInt(Display.Text, 10);
                    Display.Text = b.ToString();
                    break;
                case 3:
                    b = a * new BigInt(Display.Text, 10);
                    Display.Text = b.ToString();
                    break;
                case 4:
                    b = a / new BigInt(Display.Text, 10);
                    Display.Text = b.ToString();
                    break;
                case 5:
                    b = a % new BigInt(Display.Text, 10);
                    Display.Text = b.ToString();
                    break;
                case 6:
                    b = a & new BigInt(Display.Text, 10);
                    Display.Text = b.ToString();
                    break;
                case 7:
                    b = a | new BigInt(Display.Text, 10);
                    Display.Text = b.ToString();
                    break;
                case 8:
                    b = a ^ new BigInt(Display.Text, 10);
                    Display.Text = b.ToString();
                    break;
                case 9:
                    bool result = a < new BigInt(Display.Text, 10);
                    if (result) Display.Text = "TRUE";
                    else Display.Text = "FALSE";
                    break;
                case 10:
                    if (a > new BigInt(Display.Text, 10)) Display.Text = "TRUE";
                    else Display.Text = "FALSE";
                    break;
                default:
                    break;
            }
        }

        private void btn0_Click(object sender, EventArgs e)
        {
            if (Display.Text != "0")
            Display.Text = Display.Text + 0;
        }

        private void btn1_Click(object sender, EventArgs e)
        {
            if (Display.Text == "0") Display.Text = "";
            Display.Text = Display.Text + 1;
        }

        private void btn2_Click(object sender, EventArgs e)
        {
            if (Display.Text == "0") Display.Text = "";
            Display.Text = Display.Text + 2;
        }

        private void btn3_Click(object sender, EventArgs e)
        {
            if (Display.Text == "0") Display.Text = "";
            Display.Text = Display.Text + 3;
        }

        private void btn4_Click(object sender, EventArgs e)
        {
            if (Display.Text == "0") Display.Text = "";
            Display.Text = Display.Text + 4;
        }

        private void btn5_Click(object sender, EventArgs e)
        {
            if (Display.Text == "0") Display.Text = "";
            Display.Text = Display.Text + 5;
        }

        private void btn6_Click(object sender, EventArgs e)
        {
            if (Display.Text == "0") Display.Text = "";
            Display.Text = Display.Text + 6;
        }

        private void btn7_Click(object sender, EventArgs e)
        {
            if (Display.Text == "0") Display.Text = "";
            Display.Text = Display.Text + 7;
        }

        private void btn8_Click(object sender, EventArgs e)
        {
            if (Display.Text == "0") Display.Text = "";
            Display.Text = Display.Text + 8;
        }

        private void btn9_Click(object sender, EventArgs e)
        {
            if (Display.Text == "0") Display.Text = "";
            Display.Text = Display.Text + 9;
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            a = new BigInt(Display.Text, 10);
            Display.Clear();
            operation = 1;
            label1.Text = a.ToString() + "+";
            sign = true;
        }

        private void btnSub_Click(object sender, EventArgs e)
        {
            a = new BigInt(Display.Text, 10);
            Display.Clear();
            operation = 2;
            label1.Text = a.ToString() + "-";
            sign = true;
        }
        private void btnMul_Click(object sender, EventArgs e)
        {
            a = new BigInt(Display.Text, 10);
            Display.Clear();
            operation = 3;
            label1.Text = a.ToString() + "*";
            sign = true;
        }

        private void btnDiv_Click(object sender, EventArgs e)
        {

            a = new BigInt(Display.Text, 10);
            Display.Clear();
            operation = 4;
            label1.Text = a.ToString() + "/";
            sign = true;
        }

        private void btnReminder_Click(object sender, EventArgs e)
        {
            a = new BigInt(Display.Text, 10);
            Display.Clear();
            operation = 5;
            label1.Text = a.ToString() + "%";
            sign = true;
        }

        private void btnAND_Click(object sender, EventArgs e)
        {
            a = new BigInt(Display.Text, 10);
            Display.Clear();
            operation = 6;
            label1.Text = a.ToString() + "&&";
            sign = true;
        }

        private void btnOR_Click(object sender, EventArgs e)
        {
            a = new BigInt(Display.Text, 10);
            Display.Clear();
            operation = 7;
            label1.Text = a.ToString() + "|";
            sign = true;
        }

        private void btnXOR_Click(object sender, EventArgs e)
        {
            a = new BigInt(Display.Text, 10);
            Display.Clear();
            operation = 8;
            label1.Text = a.ToString() + "^";
            sign = true;
        }

        private void btnNOT_Click(object sender, EventArgs e)
        {
            a = new BigInt(Display.Text, 10);
            b = ~a;
            Display.Clear();
            Display.Text = b.ToString();
            label1.Text = a.ToString() + "~";
            sign = true;
        }

        private void btnLess_Click(object sender, EventArgs e)
        {
            a = new BigInt(Display.Text, 10);
            Display.Clear();
            operation = 9;
            label1.Text = a.ToString() + "<";
            sign = true;
        }

        private void btnGreater_Click(object sender, EventArgs e)
        {
            a = new BigInt(Display.Text, 10);
            Display.Clear();
            operation = 10;
            label1.Text = a.ToString() + ">";
            sign = true;
        }

        private void btnEqu_Click(object sender, EventArgs e)
        {

            calculate();
            label1.Text = "";
        }

        private void btnC_Click(object sender, EventArgs e)
        {
            Display.Text = "0";
            label1.Text = "";
        }

        private void btnBackspace_Click(object sender, EventArgs e)
        {
            int length = Display.Text.Length - 1;
            string text = Display.Text;
            Display.Clear();
            for (int i = 0; i < length; i++)
            {
                Display.Text = Display.Text + text[i];
            }
        }

        private void btnSign_Click(object sender, EventArgs e)
        {
            if (sign == true)
            {
                Display.Text = "-" + Display.Text;
                sign = false;
            }
            else if (sign == false)
            {
                Display.Text = Display.Text.Replace("-","");
                sign = true;
            }
        }

        private void btnSqrt_Click(object sender, EventArgs e)
        {
            b = new BigInt(Display.Text, 10);            
            Display.Text = b.sqrt().ToString();
        }

        private void btnMR_Click(object sender, EventArgs e)
        {

            frm2 = new Form2(this, bigIntArr);
            frm2.UpdateData();            
            frm2.Show();
        }

        private void btnMS_Click(object sender, EventArgs e)
        {
            BigInt n = new BigInt(Display.Text, 10);
            bigIntArr.AddBigIntNumber(n.ToString());
            //frm2.AddNumber(n);            
        }  

        private void textBoxCharIsDigit_KeyPress(object sender, KeyPressEventArgs e)
        {
            int isNumber = 0;
            e.Handled = !int.TryParse(e.KeyChar.ToString(), out isNumber);
        }

        private void btnMC_Click(object sender, EventArgs e)
        {
          bigIntArr.GetBigInts().Clear();
        }

        private void btnMplus_Click(object sender, EventArgs e)
        {
            a = new BigInt(Display.Text, 10);
            Display.Clear();
            operation = 1;
            label1.Text = a.ToString() + "+";
            sign = true;
            frm2 = new Form2(this, bigIntArr);
            frm2.UpdateData();
            frm2.Show();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            char currentKey = (char)e.KeyCode;
            if (char.IsDigit(currentKey))
                if (Display.Text == "0") Display.Text = "";            
            e.Handled = true;
        }
    }
}
