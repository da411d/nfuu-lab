using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;

namespace CompositePattern
{
    class Menu : MenuComponent
    {
        IEnumerator enumerator = null;
        ArrayList menuItems = new ArrayList();
        string name;
        string description;
        public Menu(string arg1, string arg2)
        {
            name = arg1;
            description = arg2;
        }
        public override IEnumerator CreateEnumerator()
        {
            if (enumerator == null)
                enumerator = new CompositEnumerator(menuItems.GetEnumerator());
            return enumerator;
        }
        public override void add(MenuComponent menuComponent)
        {
            menuItems.Add(menuComponent);
        }
        public override void remove(MenuComponent menuComponent)
        {
            menuItems.Remove(menuComponent);
        }
        public override MenuComponent GetChild(int i)
        {
            return (MenuComponent)menuItems[i];
        }
        public override string getName()
        {
            return name;
        }
        public override string getDescription()
        {
            return description;
        }
        public override void print()
        {
            Console.Write("\n "+getName());
            Console.Write(", "+ getDescription());
            Console.WriteLine("\n----------------------------------------------");
            enumerator = menuItems.GetEnumerator();
            while (enumerator.MoveNext())
            {
                MenuComponent component = (MenuComponent)enumerator.Current;
                component.print();
            }
        }
        public override void printVegeterian()
        {
            enumerator = menuItems.GetEnumerator();
            while (enumerator.MoveNext())
            {
                MenuComponent component = (MenuComponent)enumerator.Current;
                if (component.IsVegetarian())
                    component.printVegeterian();
            }
        }

        public override IEnumerator GetEnumerator()
        {
            enumerator= new CompositEnumerator(menuItems.GetEnumerator());
            return enumerator;
        }
        public override bool IsVegetarian()
        {
            enumerator = menuItems.GetEnumerator();
            bool flag = false;
            while (enumerator.MoveNext())
            {
                MenuComponent component = (MenuComponent)enumerator.Current;
                if (component.IsVegetarian())
                {
                    flag = true;
                    break;
                }
            }
            return flag;
        }
        
       
    }
}
