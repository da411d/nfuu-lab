using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;

namespace CompositePattern
{
    class Waitress
    {
        MenuComponent allMenu;

        public Waitress(MenuComponent allMenu)
        {
            this.allMenu = allMenu;
        }
        public void printMenu()
        {
            allMenu.print();
        }
        public void printVegetarian()
        {
            Console.WriteLine("\nVEGETARIAN MENU\n");
            allMenu.printVegeterian();
        }
    }
}
