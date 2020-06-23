using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;

namespace CompositePattern
{
    class MenuItem : MenuComponent
    {
        string name;
        string description;
        bool isVegetarian;
        double price;
        public MenuItem(string arg1, string arg2, bool arg3, double arg4)
        {
            name = arg1;
            description = arg2;
            isVegetarian = arg3;
            price = arg4;
        }
        public override string getName() { return name; }
        public override string getDescription() { return description; }
        public override bool IsVegetarian() { return isVegetarian; }
        public override double getPrice(){return price;}

        public override void print()
        {
            Console.Write(" " + getName());
            if (isVegetarian) Console.Write(" (вегетерiанська страва)");
            Console.WriteLine(", " + getPrice());
            Console.WriteLine("    - - - " + getDescription());
        }
        public override void printVegeterian()
        {
            if (isVegetarian)
            {
                Console.Write(" " + getName());
                Console.Write(" (вегетерiанська страва)");
                Console.WriteLine(", " + getPrice());
                Console.WriteLine("    - - - " + getDescription());
            }
        }
        public override IEnumerator CreateEnumerator()
        { 
            return new NullIEnumerator();
        }
    }
}
