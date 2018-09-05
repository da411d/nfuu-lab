using System;
using System.Windows.Forms;

namespace BigIntNumbersCalculator
{
    public partial class Form1 : Form
    {
        BigIntArray bigIntArr;
        Form2 form2;

        public Form1()
        {
            InitializeComponent();
            bigIntArr = new BigIntArray();
            form2 = new Form2(this, bigIntArr);
        }

        private void calculate()
        {
            if (inputA.Text.Length == 0 || inputB.Text.Length == 0) return;
            BigInt a = new BigInt(inputA.Text);
            BigInt b = new BigInt(inputB.Text);
            BigInt c;
            string action = selectAction.Text;
            switch (action)
            {
                case "+":
                    c = a + b;
                    break;
                case "-":
                    c = a - b;
                    break;
                case "*":
                    c = a * b;
                    break;
                case "/":
                    c = a / b;
                    break;
                default:
                    c = new BigInt("0");
                    break;
            }
            output.Text = c.ToString();
        }
        

        private void inputA_ValueChanged(object sender, EventArgs e)
        {
            calculate();
        }

        private void selectAction_SelectedIndexChanged(object sender, EventArgs e)
        {
            calculate();
        }

        private void inputB_ValueChanged(object sender, EventArgs e)
        {
            calculate();
        }

        private void inputA_KeyUp(object sender, KeyEventArgs e)
        {
            calculate();
        }

        private void inputB_KeyUp(object sender, KeyEventArgs e)
        {
            calculate();
        }

        private void add_Click(object sender, EventArgs e)
        {
            BigInt n = new BigInt(output.Text);
            bigIntArr.AddBigIntNumber(n.ToString());

            form2.UpdateData();
            form2.Show();
            form2.Top = this.Top;
            form2.Left = this.Left + this.Width;
        }
    }
}
