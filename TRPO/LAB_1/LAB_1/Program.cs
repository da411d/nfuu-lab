using System;
using System.Collections.Generic;
using System.Collections;

namespace Vehicle
{
    class Program
    {
        static void Main()
        {
            VehicleCollection vc = new VehicleCollection();
            vc.Print();
            Console.WriteLine();
            VehiclCollectionGeneric vcg = new VehiclCollectionGeneric();
            vcg.Print();
            Console.Read();
        }
    }

    class VehicleCollection
    {
        SortedList sortedList = new SortedList();
        public VehicleCollection()
        {
            sortedList.Add(new Vehicle(100, 200, 1999), new Plane(7000, 100, 213, 123, 900));
            sortedList.Add(new Vehicle(90, 2090, 1899), new Ship(67, 546, 6456, 456, "aaa"));
            sortedList.Add(new Vehicle(390, 2090, 1899), new Plane(6437, 546, 6456, 456, 2323));
            sortedList.Add(new Vehicle(23, 2090, 1899), new Ship(2367, 546, 6456, 456, "aaa"));
            sortedList.Add(new Vehicle(545, 2090, 1899), new Ship(567667, 546, 6456, 456, "aaa"));
        }

        public void Print()
        {
            for (int i = 0; i < sortedList.Count; i++)
            {
                Console.WriteLine("\t{0}:", sortedList.GetByIndex(i));
            }
        }
    }

    class VehiclCollectionGeneric
    {
        SortedList<Vehicle, Vehicle> sortedListGeneric = new SortedList<Vehicle, Vehicle>();
        public VehiclCollectionGeneric()
        {
            sortedListGeneric.Add(new Plane(6000, 1500, 6213, 9123, 900), new Ship(167, 546, 4456, 856, "BBaa"));
            sortedListGeneric.Add(new Plane(4678, 4567, 657, 23223, 567), new Ship(765, 324, 876, 3232, "CCCC"));
        }

        public void Print()
        {
            foreach (KeyValuePair<Vehicle, Vehicle> kvp in sortedListGeneric)
            {
                Console.WriteLine("key: {0}, value: {1}", kvp.Key, kvp.Value);
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

    class Plane : Vehicle
    {
        public double Height { get; set; }
        public double NumberOfPassengers { get; set; }
        public Plane(double price, double speed, double year, double height, double numberOfPassengers)
            : base(price, speed, year)
        {
            this.Height = height;
            this.NumberOfPassengers = numberOfPassengers;
        }
        public override string ToString()
        {
            return base.ToString() + String.Format(" PHeight = {0} , Number = {1}", Height, NumberOfPassengers);
        }

    }

    class Ship : Vehicle
    {
        public double NumberOfPassengers { get; set; }
        public string DestinationPort { get; set; }
        public Ship(double price, double speed, double year, double numberOfPassengers, string destinationPort)
            : base(price, speed, year)
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


