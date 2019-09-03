using System;
using System.Threading.Tasks;

namespace LAB_14
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] graph = {
                //1   2   3   4   5   6   7   8
                { 0,  6,  0,  0,  0,  0,  0,  0 }, // 1
                { 6,  0,  11, 14, 0,  0,  0,  0 }, // 2
                { 0,  11, 0,  0,  3,  0,  0,  0 }, // 3
                { 0,  14, 0,  0,  0,  0,  6,  0 }, // 4
                { 0,  0,  3,  0,  0,  0,  16, 6 }, // 5
                { 0,  0,  0,  0,  0,  0,  0,  8 }, // 6
                { 0,  0,  0,  6,  16, 0,  0,  13}, // 7
                { 0,  0,  0,  0,  6,  8,  13, 0 }, // 8
            };

            Prim(graph);

            Console.ReadKey();
        }

        public static void Prim(int[,] graph)
        {
            int verticesCount = graph.GetLength(1);
            int[] parent = new int[verticesCount];
            int[] key = new int[verticesCount];
            bool[] mstSet = new bool[verticesCount];

            for (int i = 0; i < verticesCount; ++i)
            {
                key[i] = int.MaxValue;
                mstSet[i] = false;
            }

            key[0] = 0;
            parent[0] = -1;

            Parallel.For(0, verticesCount - 1, count => {
                int u = MinKey(key, mstSet, verticesCount);
                mstSet[u] = true;

                for (int v = 0; v < verticesCount; ++v)
                {
                    if (Convert.ToBoolean(graph[u, v]) && mstSet[v] == false && graph[u, v] < key[v])
                    {
                        parent[v] = u;
                        key[v] = graph[u, v];
                    }
                }
            });

            Print(parent, graph, verticesCount);
        }

        private static int MinKey(int[] key, bool[] set, int verticesCount)
        {
            int min = int.MaxValue, minIndex = 0;

            for (int v = 0; v < verticesCount; ++v)
            {
                if (set[v] == false && key[v] < min)
                {
                    min = key[v];
                    minIndex = v;
                }
            }
            return minIndex;
        }

        private static void Print(int[] parent, int[,] graph, int verticesCount)
        {
            int weight = 0;
            Console.WriteLine("Edge     Weight");
            for (int i = 1; i < verticesCount; ++i)
            {
                Console.WriteLine("{0} - {1}    {2}", parent[i], i, graph[i, parent[i]]);
                weight += graph[i, parent[i]];
            }
            Console.WriteLine("Weight: " + weight);
        }
    }
}