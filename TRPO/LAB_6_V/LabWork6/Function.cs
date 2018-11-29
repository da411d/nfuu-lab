using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LabWork5
{
    public class Function
    {
        private double value;
        private double x;

        public double Value
        {
            get { return this.value; }
        }
        public Function(double x)
        {
            this.x = x;
        }
        public void FirstCalculate()
        {
            this.value = 0.6 * x;
        }
        public void SecondCalculate()
        {
            this.value = 2/(3*x);
        }
    }
}
