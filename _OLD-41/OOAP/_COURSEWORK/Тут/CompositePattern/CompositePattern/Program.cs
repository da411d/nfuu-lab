using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CompositePattern
{
    class Program
    {
        static void Main(string[] args)
        {
            MenuComponent pancakeHouseMenu = new Menu("PANCAKE HOUSE MENU","Breakfast");
            MenuComponent dinerMenu = new Menu("DINER MENU", "Lunch");
            MenuComponent cafeMenu = new Menu("CAFE MENU", "Dinner");
            MenuComponent dessertMenu = new Menu("DESSERT MENU","Dessert of course!");

            MenuComponent allMenus = new Menu("ALL MENUS", "All menus combined");
            allMenus.add(pancakeHouseMenu);
            allMenus.add(dinerMenu);
            allMenus.add(cafeMenu);

            dinerMenu.add(new MenuItem( "Pasta", 
                "Spaghetti with Marinara Sauce, and a slice of sourdough bread", 
                false, 32.56));
            dinerMenu.add(new MenuItem("PastaPretto",
                "Spaghetti with Marinara Sauce, and a slice of sourdough bread",
                false, 40.05));
            dinerMenu.add(dessertMenu);
            dessertMenu.add(new MenuItem("Apple Pie",
                "Apple pie with a flakey crust, topped with vanilla icecream",
                true,1.59));
            dessertMenu.add(new MenuItem("Tiramissu",
               "Apple pie with a flakey crust, topped with vanilla icecream",
               true, 1.59));

            Waitress waitress = new Waitress(allMenus);
            waitress.printMenu();
            waitress.printVegetarian();
            Console.Read();
        }


    }
}
