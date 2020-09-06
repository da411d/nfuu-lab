//****************************************************
//Приклад використання шаблону проектування "Декоратор"
//****************************************************
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DecoratorExample
{
    /// <summary>
    ///Клас автомобіля
    /// </summary>
    class Car
    {
        protected String BrandName { get; set; }
        public Car(String brand) 
        { 
            BrandName = brand; 
        }
        public Car() { }
        public virtual void Go()
        {
            Console.WriteLine("I'm a {0} and I'm on my way...", BrandName);
        }
    }
    /// <summary>
    /// Загальна реалізація декоратора
    /// </summary>
    abstract class DecoratorCar : Car
    {
        protected Car DecoratedCar { get; set; }
        public DecoratorCar(Car decoratedCar)
        {
            DecoratedCar = decoratedCar;
        }
        public override void Go()
        {
            DecoratedCar.Go();
        }
    }
    /// <summary>
    /// Декоратор для конкретної реалізації
    /// </summary>
    class AmbulanceCar : DecoratorCar
    {
        public AmbulanceCar(Car decoratedCar)
            : base(decoratedCar)
        {
        }
        public override void Go()
        {
            base.Go();
            Console.WriteLine("... beep-beep-beeeeeep ...");
        }
    }

    class ArmorCar : DecoratorCar
    {
        public String Gun { get; set; }
        
        public ArmorCar(Car decoratedCar, String gun)
            : base(decoratedCar)
        {
            Gun = gun;
        }
        public override void Go()
        {
            base.Go();
            Console.WriteLine("... Я злобний водій і у мене є зброя ...{0}", Gun);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            var doctorsDream = new AmbulanceCar(new Car("Mercedes"));
            doctorsDream.Go();

            var DangerousCar = new ArmorCar(new Car("Mercedes"), "револьвер");
            DangerousCar.Go();
        }
    }
}
