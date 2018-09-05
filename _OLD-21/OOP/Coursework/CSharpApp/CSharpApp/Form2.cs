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
    public partial class Form2 : Form
    {
        Form1 _parentForm;
        BigIntArray bigIntArr;
        int selectionIndex;

        public Form2()
        {
            InitializeComponent();
            bigIntArr = new BigIntArray();
        }

        public Form2(BigIntArray bigIntArr)
        {
            InitializeComponent();
            this.bigIntArr = bigIntArr;
        }

        public Form2(Form1 form, BigIntArray bigIntArr)
        {
            InitializeComponent();
            _parentForm = form;
            this.bigIntArr = bigIntArr;
        }

        public Form2(Form1 form)
        {
            InitializeComponent();
            _parentForm = form;
            bigIntArr = new BigIntArray();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            bigIntsListView.FullRowSelect = true;
            bigIntsListView.GridLines = true;           
        }

      

        private void bigIntsListView_SelectedIndexChanged(object sender, EventArgs e)
        {

            if (bigIntsListView.SelectedIndices.Count > 0)
            {
                selectionIndex = bigIntsListView.SelectedIndices[0];
                BigInt number = bigIntArr.GetBigInts().ElementAt(selectionIndex);
                //_parentForm.Display.Text = number.ToString();
               //_parentForm.label1.Text = "";               
            }
            
        }

        private void bigIntsListView_DrawColumnHeader(object sender, DrawListViewColumnHeaderEventArgs e)
        {
            e.DrawDefault = true;
        }

        private void btnSum_Click(object sender, EventArgs e)
        {
            string str = "";
            str += "Сума всіх елементів масиву складає: " + bigIntArr.Sum();
            MessageBox.Show(str, "Сума елементів масиву");
        }

        private void btnDynamicBindingDemo_Click(object sender, EventArgs e)
        {
            BigInt a = new BigInt(_parentForm.output.Text, 10);
            BigInt b = bigIntArr.GetBigInts().ElementAt(selectionIndex);
            BigInt c = a + b; 
            MessageBox.Show("Сума двох елементів: " + a.ToString() + "+" + b.ToString() + "=" + c.ToString(), "Сума двох елементів");
        }

        public void UpdateData()
        {
            bigIntsListView.Items.Clear();

            int counterOfArraylist = bigIntArr.GetCount();
            string str;

            foreach (BigInt number in bigIntArr.GetBigInts())
            {
                str = number.ToString();
                ListViewItem li = new ListViewItem(str);
                li.UseItemStyleForSubItems = false;
                //li.SubItems[0].BackColor = Color.Aqua;
                bigIntsListView.Items.Add(li);
            }
        }

        public void AddNumber(BigInt _number)
        {
            bigIntArr.AddBigIntNumber(_number.ToString());
        }

        private void bigIntsListView_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Delete)
            {
                //MessageBox.Show("delete pressed");
                if (bigIntsListView.SelectedIndices.Count > 0)
                {
                    bigIntsListView.Items[selectionIndex].Remove();
                    bigIntArr.GetBigInts().RemoveAt(selectionIndex);
                    e.Handled = true;
                }
            }
        }

        private void textBoxCharIsDigit_KeyPress(object sender, KeyPressEventArgs e)
        {
            int isNumber = 0;
            e.Handled = !int.TryParse(e.KeyChar.ToString(), out isNumber);
        }

        private void textBoxFloatValue_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsControl(e.KeyChar) && !char.IsDigit(e.KeyChar)
                    && e.KeyChar != ',')
            {
                e.Handled = true;
            }
            // only allow one decimal point
            if (e.KeyChar == ','
                && (sender as TextBox).Text.IndexOf(',') > -1)
            {
                e.Handled = true;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            bigIntsListView.Items.Clear();
            bigIntArr.GetBigInts().Clear();
        }
    }
}

