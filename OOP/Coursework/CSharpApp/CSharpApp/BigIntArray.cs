using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace BigIntNumbersCalculator
{
    public class BigIntArray : IEnumerable, IEnumerator
    {
        private List<BigInt> BigInts;
        private int Count = 0;
        private int index = -1;

        public BigIntArray() //Конструктор без параметрів
        {
            BigInts = new List<BigInt>();
        }
        public BigIntArray(int nCount) //Конструктор з параметром
        {
            BigInts = new List<BigInt>();
            Count = nCount;
        }
        // Реалізуємо інтерфйес IEnumerable
        public IEnumerator GetEnumerator()
        {
            foreach (BigInt number in BigInts)
            {
                yield return number;
            }
        }

        // Реалізуємо інтерфйес IEnumerator
        public bool MoveNext()
        {
            if (index == BigInts.Count() - 1)
            {
                Reset();
                return false;
            }

            index++;
            return true;
        }

        public void Reset()
        {
            index = -1;
        }

        public object Current
        {
            get
            {
                return BigInts.ElementAt(index);
            }
        }

        public void Input() //Метод для вводу даних
        {
            for (int i = 0; i < Count; i++)
            {
                Console.WriteLine("Запис #{0}", i + 1);
                BigInt number = new BigInt();
                //BigInt.Input();
                BigInts.Add(number);
            }
        }
        void Show() //Метод для виведення даних
        {
        }
        ~BigIntArray()  //Деструктор
        { }
        public List<BigInt> GetBigInts() //Повертає вказівник на елемент масиву
        {
            return BigInts;
        }

        // Public methods.
        public void AddBigIntNumber(string _number)
        {
            BigInts.Add(new BigInt(_number, 10));
        }

        public int GetCount() // Метод для читання поля  - кількість елементів масиву
        {
            return BigInts.Count;
        }
        public BigInt Sum()
        {
            BigInt sum = new BigInt();
            for (int i = 0; i < BigInts.Count; i++)
               sum = sum + BigInts[i];
            return sum;
        }

    }
}
