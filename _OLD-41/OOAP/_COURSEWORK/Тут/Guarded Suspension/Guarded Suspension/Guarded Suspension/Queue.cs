using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using System.Threading;

namespace Guarded_Suspension
{
    /// <summary>
    /// A queue class that handles a attempt to remove an object
    /// from an empty queue by waiting for another thread to put
    /// an object in the queue.
    /// </summary>
    public class PatientQueue
    {
        private ArrayList data;
        public int Lenght { get { return data.Count; } }
        /// <summary>
        /// Конструктор створює обєкт <c>PatientQueue</c>.
        /// </summary>
        public PatientQueue()
        {
            data = new ArrayList();
        }
        /// <summary>
        /// Параметризований конструктор 
        /// створює обєкт <c>PatientQueue</c>.
        /// </summary>
        /// <param name="initialCapacity">
        /// Ініціалізація пропускної здатності внутрішньої структури даних для черги.
        /// </param>
        public PatientQueue(int initialCapacity)
        {
            data = new ArrayList(initialCapacity);
        }
        /// <summary>
        /// Поміщає обєкт в кінець черги
        /// </summary>
        /// <param name="obj">
        /// Обєкт для розміщення в черзі
        /// </param>
        public void Push(object obj)
        {
            lock (data)
            {
                data.Add(obj);
                Monitor.Pulse(data);
            }
        }
        /// <summary>
        /// Дістає та видаляє обєкт з початку черги 
        /// </summary>
        /// <returns>
        /// Повертає видобутий з черги обєкт
        /// </returns>
        /// <remarks>
        /// Якщо черга порожня даний метод чекає поки інший 
        /// потік помістить обєкт в чергу і 
        /// після цього повертає цей обєкт
        /// </remarks>
        public object Pull()
        {
            lock (data)
            {
                while (data.Count == 0)
                {
                    Monitor.Wait(data);
                }
            }
            object obj = data[0];
            data.RemoveAt(0);
            return obj;
        }
    } 
}
