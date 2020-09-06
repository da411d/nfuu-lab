using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CoffeeShop
{
    /// <summary>
    /// Абстактний напій
    /// </summary>
    abstract class Beverage
    {
        String description = "Unknown Beverage";

        public String Description  {set { description = value; }}
        public virtual String GetDescription()
        {
            return description;
        }
        public abstract double Cost();
        public override string ToString()
        {
            return GetDescription() + ": " + Cost()+"$";
        }
    }
    class Espresso : Beverage
    {
        public Espresso()
        {
            Description = "Espresso";
        }
        public override double Cost()
        {
            return .88;
        }
    }
    class HouseBlend : Beverage
    {
        public HouseBlend()
        {
            Description = "HouseBlend";
        }
        public override double Cost()
        {
            return .92;
        }
    }
    class DarkRoast : Beverage
    {
        public DarkRoast()
        {
            Description = "DarkRoast";
        }
        public override double Cost()
        {
            return 1.01;
        }
    }
    class Decaf : Beverage
    {
        public Decaf()
        {
            Description = "Decaf";
        }
        public override double Cost()
        {
            return 1.10;
        }
    }
}
