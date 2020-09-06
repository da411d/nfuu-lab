using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BuilderExample
{
    class Program
    {
        static void Main(string[] args)
        {
            var tripLaptop = new TripLaptopBulder();
            var gamingLaptop = new GamingLaptopBulder();
            var constructor=new Director();
            constructor.SetLaptopBuider(tripLaptop);
            constructor.ConstructLaptop(++Laptop.number);
            Laptop laptop = constructor.GetLaptop();
            Console.WriteLine(laptop.ToString());

            constructor.SetLaptopBuider(gamingLaptop);
            constructor.ConstructLaptop(++Laptop.number); ;
            laptop = constructor.GetLaptop();
            Console.WriteLine(laptop.ToString());
        }
    }
   

}
