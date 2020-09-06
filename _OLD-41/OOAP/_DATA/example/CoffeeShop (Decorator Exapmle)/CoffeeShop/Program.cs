using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CoffeeShop
{
    class Program
    {
        static void Main(string[] args)
        {  
            FacadeCoffeeMaker coffeeMaker = new FacadeCoffeeMaker();
            //вибрати напій
            coffeeMaker.ChooseBeverage();
            //вибрати додаток
            coffeeMaker.ChooseCondiment();
            //роздрукувати чек
            coffeeMaker.PrintReceipt();
        }
    }
   

}
