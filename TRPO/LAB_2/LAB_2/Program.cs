

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


using System.Collections;

namespace Vehicle
{
    class Program
    {
        static private void HeightMonitor(object sender, VehicleEventArgs e) // метод для обробки даної події
        {
            Console.WriteLine("\tWarning Message: Height is changing from {0} to {1}.", e.OldHeight, e.NewHeight);
        }
        static void Main()
        {

            Plane.heightTreshHold += HeightMonitor;//виклик подію heightTreshHold
            VehicleCollection vc = new VehicleCollection();
            vc.Print();
           
            Console.WriteLine();
           
            Console.Read();
        }
    }

    class VehicleCollection
    {
        SortedList sortedList = new SortedList();
        public VehicleCollection()
        {
            sortedList.Add(new Vehicle(100, 200, 1999), new Plane(7000, 100, 213, 12300, 900));
            sortedList.Add(new Vehicle(90, 6868, 232), new Ship(67, 546, 6456, 1232, "aaa"));
            sortedList.Add(new Vehicle(390, 6575, 1212), new Plane(6437, 444, 877, 323, 2323));
            sortedList.Add(new Vehicle(23, 44, 1899), new Ship(2367, 23, 333, 456, "vvv"));
            sortedList.Add(new Vehicle(545, 2090, 1899), new Ship(222, 126, 233, 878, "ccc"));
        }


        public void Print()
        {
            for (int i = 0; i < sortedList.Count; i++)
            {
                Console.WriteLine("\t{0}:", sortedList.GetByIndex(i));
            }
        }
    }

    

    class Vehicle : ICloneable, IComparable
    {

        public double price, speed, year;
        public Vehicle(double p, double s, double y)
        {
            price = p;
            speed = s;
            year = y;
        }

        object ICloneable.Clone()
        {
            return this.MemberwiseClone();
        }

        int IComparable.CompareTo(object ob)
        {
            Vehicle office = ob as Vehicle;
            if (office != null)
            {
                return this.price.CompareTo(office.price);
            }
            else throw new InvalidCastException();
        }
        public double Price()
        {
            return price;

        }

        public double Speed()
        {
            return speed;

        }

        public double Year_of_construction()
        {
            return year;

        }
        public override string ToString()
        {
            return String.Format("Vehicle: Speed = {0} , Price = {1} , Year = {2}", Speed(), Price(), Year_of_construction());
        }
    }


    public delegate void VehicleEventHandler(object sender, VehicleEventArgs vehicEvent); //sender відправник
    class Plane : Vehicle
    {
        public double Height { get; set; }
        public double NumberOfPassengers { get; set; }
        
        static public event VehicleEventHandler heightTreshHold; // оголош подію        handler обробник

        public Plane(double price, double speed, double year, double height, double numberOfPassengers) : base(price, speed, year)
        {
            this.Height = height;
            this.NumberOfPassengers = numberOfPassengers;
        }
        public override string ToString()
        {
            if (this.Height > 5000) MoreThanOneHundredHeightEvents(4500);
            return base.ToString() + String.Format(" Height = {0} , Number = {1}", Height, NumberOfPassengers);
        }

        protected  void MoreThanOneHundredHeightEvents(double newHeight) ///метод, що подія породжує
        {
            if (heightTreshHold != null)
            {
                heightTreshHold(this, new VehicleEventArgs(this.Height, newHeight));
                this.Height = newHeight;
            }

        }
    }

    class Ship : Vehicle
    {
        public double NumberOfPassengers { get; set; }
        public string DestinationPort { get; set; }
        public Ship(double price, double speed, double year_of_construction, double numberOfPassengers, string destinationPort)
            : base(price, speed, year_of_construction)
        {
            this.DestinationPort = destinationPort;
            this.NumberOfPassengers = numberOfPassengers;
        }
        public override string ToString()
        {
            return base.ToString() + String.Format("\tDestination = {0} , Number = {1}", DestinationPort, NumberOfPassengers);
        }
    }
}
