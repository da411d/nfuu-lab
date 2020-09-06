using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CoffeeShop
{
    abstract class CondimentDecorator: Beverage
    {
        public Beverage beverage;
        public abstract override String GetDescription();
        public abstract override double Cost();

        public override string ToString()
        {
            return GetDescription()+": "+Cost()+ "$";
        }
    }

    class Mocha : CondimentDecorator
    {     
        public Mocha(Beverage beverage)
        {
            this.beverage = beverage;
        }
        public override string GetDescription()
        {
            return beverage.GetDescription() + ", Mocha";
        }
        public override double Cost()
        {
            return (beverage.Cost() + 0.25);
        }
    }

    class Milk : CondimentDecorator
    {
        public Milk(Beverage beverage)
        {
            this.beverage = beverage;
        }
        public override string GetDescription()
        {
            return beverage.GetDescription() + ", Milk";
        }
        public override double Cost()
        {
            return (beverage.Cost() + 0.10);
        }
    }

    class Whip : CondimentDecorator
    {
        public Whip(Beverage beverage)
        {
            this.beverage = beverage;
        }
        public override string GetDescription()
        {
            return beverage.GetDescription() + ", Whip";
        }
        public override double Cost()
        {
            return (beverage.Cost() + 0.15);
        }
    }
}
