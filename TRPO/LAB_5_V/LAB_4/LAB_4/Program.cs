using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace oop14lan_new
{
    class Program
    {
        static void Main(string[] args)
        {

            ListOfSelling listOfSelling = new ListOfSelling();
            listOfSelling.Show();
            listOfSelling.Sort();
            listOfSelling.ShowDiscount();
            listOfSelling.GroupByDiscount();
            listOfSelling.Serialize("ss1");
            listOfSelling.Deserialized("ss1");
            Console.ReadLine();

        }
    }
}
