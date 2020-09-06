using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Genetic
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        public bool stackmaxtrue(Stack<int> max) {
            bool boolmax = false;
            int max1=max.Pop();
            int max2=max.Pop();
            if (max1>max2)boolmax=true;
            else boolmax=false;
            max.Push(max2);
            max.Push(max1);
            return boolmax;
    }
        public int[] ryletka(string[,] mass)//Рулетка повертає робить селекцію с секторів
        {
            Random n = new Random();
            double summass = 0;
            int[] ranmas = new int[6];

            int rand;
            for (int j = 0; j < 6; j++)
            {
                rand = n.Next(1, 100);
                for (int i = 0; i < 6; i++)
                {
                    summass += Convert.ToDouble(mass[i, 3]);

                    if (rand > summass)
                    {
                        continue;
                    }
                    else
                    {
                        ranmas[j] = i;
                        summass = 0;
                        break;
                    }
                }
            }
            return ranmas;
        }

        public int znmax(int maxmass, string[,] mass, int indx)
        {
            int a = 0;
            for (int i = 0; i < 6; i++)
            {
                if (Convert.ToInt32(mass[i, indx]) == maxmass)
                {
                    a = Convert.ToInt32(mass[i, 0]);
                }
            }
            return a;
        }
        public int max(string[,] mass, int z) //повертає максимальне значення функцій з даного покоління
        {
            int max = 0;
            for (int i = 0; i < 6; i++)
            {
                if (Convert.ToInt32(mass[i, z]) > max)
                {
                    max = Convert.ToInt32(mass[i, z]);
                }
                else continue;
            }
            return max;
        }
        public double myfun(string a)// Обчислення значення функції
        {
            double x = Convert.ToInt64(a);
            double y = 0.47, z = -1.32;
            double res = Convert.ToInt64(x + y - z);
            return res;
        }
        public string toTwo(long a)
        {
            string b;
            string b1 = null;
            while (a != 1)
            {

                b1 += Convert.ToString(a % 2);
                a = Convert.ToInt32(a / 2);
            }
            b1 = b1 + "1";
            char[] arr = b1.ToCharArray();
            Array.Reverse(arr);
            b = new string(arr);
            while (b.Length != 10)
            {
                b = "0" + b;
            }
            return b;
        }
        public int toTen(long a)
        {
            int b = 0;
            string b1 = Convert.ToString(a);
            char[] arr = b1.ToCharArray();
            Array.Reverse(arr);
            for (int i = 0; i < arr.Length; i++)
            {
                if (Convert.ToInt32(arr[i]) == 48)
                {
                    b += Convert.ToInt32(0 * Math.Pow(2, i));
                }
                else
                {
                    b += Convert.ToInt32(1 * Math.Pow(2, i));
                }
            }


            return b;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            listBox2.Items.Clear();
            Stack<int> funmax = new Stack<int>();
            funmax.Push(0);
            
            int a = 1023;
            double sum = 0;
            Random n = new Random();
            string[,] rand = new string[6, 4];

           
            //
            for (int i = 0; i < 6; i++)
            {

                rand[i, 0] = Convert.ToString(n.Next(1, a));//значення аргумента
                rand[i, 1] = toTwo(Convert.ToInt64(rand[i, 0]));//значення в двійковій 
                rand[i, 2] = Convert.ToString(myfun(rand[i, 0]));// значення ф-ї
                sum += Convert.ToDouble(rand[i, 2]);//загальна пристосованість покоління Сума всіх значень ф-й

            }
            do
            {
                double sum1 = 0;
                double prystosov = 0;
                for (int i = 0; i < 6; i++)
                {
                    prystosov = (Convert.ToInt64(rand[i, 2]));//значення фунції
                    prystosov = (prystosov * 100 / sum);//пристосованість даного екземпляра

                    rand[i, 3] = Convert.ToString(prystosov);

                    sum1 += prystosov; //сума всіх пристосованостей к покоління
                }

                int maxmass = max(rand, 2);//знайшли максимальне значення фй з даного покоління 
                funmax.Push(maxmass);//вставили в стек
            
                int maxzn = znmax(maxmass, rand, 2);//знайшли таке значення x яке дає максимальне значення фії
                int maxten = toTen(1111111111);//1023
                if (maxzn == maxten)
                {
                    this.Close();
                }
       
            
                int[] massindx = new int[6];
                massindx = ryletka(rand);//відбулася селекція  тих обєктів
                string[,] parents = new string[3, 3];
                string[,] children = new string[6, 3];
                MyRandom r = new MyRandom(0, 6);//рандомится точка розриву
                Random q = new Random();
                int indxpar;

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        indxpar = r.Next();
                        parents[i, j] = rand[massindx[indxpar], 1];
                    }
                    parents[i, 2] = Convert.ToString(q.Next(3, 8));
                }
                string s1, s2, s3, s4;
                int li4 = 0;
                for (int j = 0; j < 3; j++)
                {
                    s1 = parents[j, 0].Substring(Convert.ToInt32(parents[j, 2]));  //last value
                    s2 = parents[j, 0].Substring(0, Convert.ToInt32(parents[j, 2]));  //second value
                    s3 = parents[j, 1].Substring(Convert.ToInt32(parents[j, 2]));  //last value
                    s4 = parents[j, 1].Substring(0, Convert.ToInt32(parents[j, 2]));  //second value

                    children[li4, 1] = s1 + s4; //вібдувається склеювання двох частин різних батьків з покоління
                    li4++;
                    children[li4, 1] = s2 + s3;
                    li4++;
                }
                listBox1.Items.Add("       Parents:");
                for (int i = 0; i < 6; i++)//добавлення для дітей значення в десятковій і значення функції
                {
                    int zzz =  (toTen(Convert.ToInt64(children[i, 1])));
                    children[i, 0] = Convert.ToString(zzz);
                    children[i, 2] = Convert.ToString(myfun(children[i, 0]));
                    listBox1.Items.Add("      "+"{"+rand[i,0]+"}  "+rand[i,2]+"  [ "+ rand[i,1]+" ]"+"\t");
                }

                maxmass = max(children,2);
                funmax.Push(maxmass);

                listBox2.Items.Add("        Children:");
                for (int i = 0; i < 6; i++)
                {
                    listBox2.Items.Add("     "+"{" + children[i, 0] + "}  " + children[i, 2] + "  [ " + children[i, 1] + " ]"+"\t");
                }
                for (int i = 0; i < 6; i++)//замінюємо батьків на дітей і йдемо по другому колу
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (j == 0 || j==1 || j==2) {
                            rand[i, j] = children[i, j];
                            children[i, j] = null;

                        }
                        if (j == 3)
                        {
                            rand[i, j] = null;
                        }
                    }
                }
            } while(stackmaxtrue(funmax));

            int aa=funmax.Pop();
            tb_znfun.Text = Convert.ToString(funmax.Pop());
        }
    }
}
