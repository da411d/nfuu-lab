using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;

namespace CompositePattern
{
    abstract class MenuComponent
    {
        public virtual void add(MenuComponent menuComponent)
        {
            throw new ApplicationException("Даний метод не підтримується!");
        }
        public virtual void remove(MenuComponent menuComponent)
        {
            throw new ApplicationException("Даний метод не підтримується!");
        }
        public virtual MenuComponent GetChild(int i)
        {
            throw new ApplicationException("Даний метод не підтримується!");
        }
        public virtual string getName()
        {
            throw new ApplicationException("Даний метод не підтримується!");
        }
        public virtual string getDescription()
        {
            throw new ApplicationException("Даний метод не підтримується!");
        }
        public virtual double getPrice()
        {
            throw new ApplicationException("Даний метод не підтримується!");
        }
        public abstract bool IsVegetarian();
        //{
        //    throw new ApplicationException("Даний метод не підтримується!");
        //    //return false;
        //}        
        public abstract void print();
        public abstract void printVegeterian();
        public virtual IEnumerator GetEnumerator() { return null; }
        public abstract IEnumerator CreateEnumerator();

    }
}
