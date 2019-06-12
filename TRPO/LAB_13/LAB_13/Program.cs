using System;
using System.Threading.Tasks;
using System.Diagnostics;

namespace LAB_13
{
    class Program
    {
        static int[] arr;

        static void Main(string[] args)
        {
            Stopwatch sw = new Stopwatch();
            arr = new int[16] { 25, 37, 49, 34, 63, 48, 6, 4, -11, 47, 4, 12, 6, 18, 3, 25 };
            sw.Start();
            OddEvenSort(arr);
            sw.Stop();
            PrintMass(arr);

            Console.WriteLine("\n\nTime: " + sw.Elapsed.TotalMilliseconds);
            Console.ReadKey();
        }

        public static void OddEvenSort(int[] mass)
        {
            int n = mass.Length;
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 1)
                {
                    Parallel.For(0, n / 2, (j) => {
                        if (2 * j + 1 < n)
                        {
                            CompareAndSwap(ref mass[2 * j], ref mass[2 * j + 1]);
                        }
                    });
                }
                else
                {
                    Parallel.For(0, n / 2, (j) => {
                        if (2 * j + 2 < n)
                        {
                            CompareAndSwap(ref mass[2 * j + 1], ref mass[2 * j + 2]);
                        }
                    });
                }
            }
        }

        public static void CompareAndSwap(ref int a, ref int b)
        {
            if (a > b)
            {
                int temp = a;
                a = b;
                b = temp;
            }
        }

        public static void PrintMass(int[] mass)
        {
            foreach (var el in mass)
            {
                Console.Write(String.Format("{0} ", el));
            }
        }
    }
}
