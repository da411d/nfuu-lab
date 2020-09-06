using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CoffeeShop
{
    /// <summary>
    /// Фасад для роботи з системою приготування кави
    /// </summary>
    class FacadeCoffeeMaker
    {
        public Beverage beverage;
        /// <summary>
        /// Обираємо напій
        /// </summary>
        public void ChooseBeverage()
        {
            Console.Clear();
            Console.WriteLine("Оберiть напiй: \n 1-Espresso\n 2-HouseBlend\n 3-DarkRoast\n 4-Decaf\n iнше -Exit");
            int choose = Convert.ToInt32(Console.ReadLine());
            switch (choose)
            {
                case 1: { beverage = new Espresso(); break; }
                case 2: { beverage = new HouseBlend(); break; }
                case 3: { beverage = new DarkRoast(); break; }
                case 4: { beverage = new Decaf(); break; }
                default: break;
            }
        }
        /// <summary>
        /// Обираємо додатки
        /// </summary>
        public void ChooseCondiment()
        {
            if (beverage != null)
            {
                bool flag = true;
                while (flag)
                {
                    Console.Clear();
                    Console.WriteLine("Оберiть додаток:\n 1-Молоко\n 2-Шоколад\n 3-Вершки \n iнше -Exit");
                    int choose = Convert.ToInt32(Console.ReadLine());
                    switch (choose)
                    {
                        case 1: { AddMilk(); break; }
                        case 2: { AddMocha(); break; }
                        case 3: { AddWhip(); break; }
                    }
                    Console.Clear();
                    Console.WriteLine("Бажаєте до кави ще щось?\n 1 - так \n все iнше - нi");
                    string temp = Console.ReadLine();
                    if (temp != "1") flag = false;
                }
            }
        }
        /// <summary>
        /// Додаємо молоко
        /// </summary>
        public void AddMilk()
        {
            beverage = new Milk(beverage);
        }
        /// <summary>
        /// Додаємо шоколад
        /// </summary>
        public void AddMocha()
        {
            beverage = new Mocha(beverage);
        }
        /// <summary>
        /// Додаємо вершки
        /// </summary>
        public void AddWhip()
        {
            beverage = new Whip(beverage);
        }
        /// <summary>
        /// Роздрук чеку
        /// </summary>
        public void PrintReceipt()
        {
            if (beverage != null)
            {
                Console.Clear();
                Console.WriteLine("\n\nВаш рахунок: ");
                Console.WriteLine(beverage.ToString());
                Console.WriteLine("Дякуємо за покупку! Приходьте ще:)\n\n");
            }
            else
            {
                Console.Clear();
                Console.WriteLine("Бувай! Можливо iншим разом:)\n\n");
            }
        }
    }
}
