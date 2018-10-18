using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Vehicle
{
   public class VehicleEventArgs
    {
        public double OldHeight { set; get; }
        public double NewHeight { get; set; }
        public VehicleEventArgs(double oldHeight, double newHeight)
        {
            this.OldHeight = oldHeight;
            this.NewHeight = newHeight;
        }
    }
}
