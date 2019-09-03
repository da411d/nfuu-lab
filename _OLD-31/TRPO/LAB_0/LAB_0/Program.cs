using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LAB_0
{
    class Program
    {
        static void Main()
        {
            Vehicle[] vehicle = new Vehicle[10];
            for (int i = 0; i < vehicle.Length; i++)
            {
                if (i % 2 == 0)
                {
                    vehicle[i] = new Plane(i, 1000 - i, 10 + i, i + 45, i * 10);
                }
                else
                {
                    vehicle[i] = new Ship(i + 30, 2000 - i, 10 * i, 50 * i, "New port");
                }
            }
            Console.WriteLine("Масив обєктiв пiсля створення:\n");
            Render(vehicle);

            Array.Sort(vehicle);
            Console.WriteLine("\nМасив обєктiв пiсля сортування:\n");
            Render(vehicle);

            Vehicle[] vehicleClone = vehicle.Clone() as Vehicle[];
            Console.WriteLine("\nМасив обєктiв клонiв:\n");
            Render(vehicleClone);

            Console.Read();
        }
        static void Render(Vehicle[] vehicle)
        {
            for (int i = 0; i < vehicle.Length; i++)
            {
                Console.WriteLine(vehicle[i].GetType().Name
                + "\tprice: " + vehicle[i].price);
            }
        }

    }


    class Vehicle : IVechicle, ICloneable, IComparable
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
            else
            {
                throw new InvalidCastException();
            }
        }

        double IVechicle.Price()
        {
            return price;

        }

        double IVechicle.Speed()
        {
            return speed;
        }

        double IVechicle.Year()
        {
            return year;
        }
    }

    class Plane : Vehicle
    {
        public double Height { get; set; }
        public double NumberOfPassengers { get; set; }
        public Plane(double price, double speed, double year_of_construction, double height, double numberOfPassengers)
            : base(price, speed, year_of_construction)
        {
            this.Height = height;
            this.NumberOfPassengers = numberOfPassengers;
        }

    }

    class Ship : Vehicle
    {
        public double NumberOfPassengers { get; set; }
        public string DestinationPort { get; set; }
        public Ship(double price, double speed, double year, double numberOfPassengers, string destinationPort) : base(price, speed, year)
        {
            this.DestinationPort = destinationPort;
            this.NumberOfPassengers = numberOfPassengers;
        }
    }


    interface IVechicle
    {
        double Price();
        double Speed();
        double Year();
    }

}