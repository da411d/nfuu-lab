using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Genetic
{
    public class MyRandom
    {
        private int[] _shuffled;
        private int _index;
        private readonly int _start;

        public int Count { get; set; }

        public MyRandom(int start, int end)
        {
            Count = end - start;
            Random r = new Random();
            _shuffled = Enumerable.Range(start, Count).OrderBy(x => r.Next()).ToArray();
            _start = start;
        }
        public int Next()
        {
            if (_index == _shuffled.Length)
            {
                _index = 0;
            }
            return _shuffled[_index++];
        }

        public void Shuffle()
        {
            Random r = new Random();
            _shuffled = Enumerable.Range(_start, Count).OrderBy(x => r.Next()).ToArray();
        }
    }
}
