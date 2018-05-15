using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BigIntNumbersCalculator
{
    public class String
    {
        protected char[] data; // вказівник на початок рядка
        protected int capacity;  // розмір рядка

        public String()
        {

        }

        public String(int cap)
        {
            capacity = cap;
            data = new char[capacity];
        }

        String(char[] _data)
        {
            this.capacity = _data.Length;
            this.data = _data;
        }

        String(string _data)
        {
            capacity = _data.Length;
            this.data = _data.ToCharArray();
        }

        String(String source)
        {
            this.capacity = source.capacity;
            this.data = source.data;
        }

        ~String()
        {
        }

        /* Set method */
        public void setString(char[] _data)
        {
            this.data = _data;
        }

        /* Get methods */
        char[] getString()
        {
            return data;
        }


        // Overload + operator to add two Box objects.
        public static String operator +(String a, String b)
        {
            String c = new String();
            c.data = a.getString().Concat(b.getString()).ToArray();
            return c;
        }

        public static String operator -(String a, String b)
        {
            String c = new String();
            return c;
        }

        public static bool operator *(String a, String b)
        {
            return false;
        }

        public virtual string print()
        {
            string s = "Рядок символів: " + getString();
            return s;
        }

        public override string ToString()
        {
            return "Рядок символів: " + data;
        }

        public /*override*/ void Input()
        {
            Console.WriteLine("Будь-ласка, введіть РЯДОК СИМВОЛІВ");
            data = Console.ReadLine().ToCharArray();
        }


    }
}
