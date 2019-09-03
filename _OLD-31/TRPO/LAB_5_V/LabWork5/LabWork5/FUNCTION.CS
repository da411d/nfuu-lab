using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LabWork5
{
    class Function
    {
        private double value;
        private int param;
        public double Value { get { return value; } set { this.value = value; } }
        public Function(int param)
        {
            this.param = param;
        }
        public void Calculate()
        {
            if (param >= 2)
            {
                this.Value = 0.6 * param;
            }
            else
                this.Value = (2 / (3 * param));
                 
        }
    }
}
