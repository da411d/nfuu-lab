using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BuilderExample
{
    /// <summary>
    /// Клас ноутбука
    /// </summary>
    class Laptop
    {
        public static int number = 0;
        public Laptop(int param)
        {

            PersonalNumber = param;
        }
        public int PersonalNumber { get; set; }
        public string MinitorResolution { get; set; }
        public string Processor { get; set; }
        public string Memory { get; set; }
        public string HDD { get; set; }
        public string Battery { get; set; }
        public override string ToString()
        {
            return "Laptop " + PersonalNumber + ": " + MinitorResolution + ", " + Processor + ", " + Battery + ", " + Memory + ", " + HDD + ", ";
        }
    }
    /// <summary>
    /// Абстрактний будывельник
    /// </summary>
    abstract class LaptopBuilder
    {
        protected Laptop Laptop { get; private set; }
        public void CreateNewLaptop(int number)
        {
            Laptop = new Laptop(number);
        }
        public Laptop GetMyLaptop()
        {
            return Laptop;
        }
        public abstract void SetMonitorResolution();
        public abstract void SetProcessor();
        public abstract void SetMemory();
        public abstract void SetHDD();
        public abstract void SetBattery();
    }
    /// <summary>
    /// Конкретна реалізація будівельника
    /// </summary>
    class GamingLaptopBulder : LaptopBuilder
    {
        public override void SetMonitorResolution()
        {
            Laptop.MinitorResolution = "1900x1200";
        }
        public override void SetProcessor()
        {
            Laptop.Processor = "Core 2 Duo, 3.2 GHz";
        }
        public override void SetMemory()
        {
            Laptop.Memory = "6144 Mb";
        }
        public override void SetHDD()
        {
            Laptop.HDD = "500 Gb";
        }
        public override void SetBattery()
        {
            Laptop.Battery = "6 lbs";
        }
    }
    /// <summary>
    /// Реалізація будівельника ноутбуків для подорожей
    /// </summary>
    class TripLaptopBulder : LaptopBuilder
    {
        public override void SetMonitorResolution()
        {
            Laptop.MinitorResolution = "1200x800";
        }
        public override void SetProcessor()
        {
            Laptop.Processor = "Core 2 Duo, 1.2 GHz";
        }
        public override void SetMemory()
        {
            Laptop.Memory = "3000 Mb";
        }
        public override void SetHDD()
        {
            Laptop.HDD = "200 Gb";
        }
        public override void SetBattery()
        {
            Laptop.Battery = "12 lbs";
        }
    }
    /// <summary>
    /// Директор, який приймає замрвлення та створює конкретний ноутбук
    /// </summary>
    class Director
    {
        private LaptopBuilder laptopBuilder;
        public void SetLaptopBuider(LaptopBuilder IBuilder)
        {
            laptopBuilder = IBuilder;
        }
        public Laptop GetLaptop()
        {
            return laptopBuilder.GetMyLaptop();
        }
        public void ConstructLaptop(int number)
        {
            laptopBuilder.CreateNewLaptop(number);
            laptopBuilder.SetBattery();
            laptopBuilder.SetHDD();
            laptopBuilder.SetMemory();
            laptopBuilder.SetMonitorResolution();
            laptopBuilder.SetProcessor();
        }
    }
}
