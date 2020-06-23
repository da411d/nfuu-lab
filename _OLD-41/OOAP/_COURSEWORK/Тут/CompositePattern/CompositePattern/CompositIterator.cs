using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;

namespace CompositePattern
{
    class CompositEnumerator : IEnumerator
    {
        Stack stack = new Stack();
        public CompositEnumerator(IEnumerator enumerator)
        {
             stack.Push(enumerator);
        }
        public object Current 
        { 
            get 
            {
                if (MoveNext())
                {
                    IEnumerator enumerator = (IEnumerator)stack.Peek();
                    MenuComponent component = (MenuComponent)enumerator.Current;
                    if (component is Menu)
                    {
                        stack.Push(((Menu)component).CreateEnumerator());
                    }
                    return component;
                }
                else return null;
             }
         }          
        public bool MoveNext() 
        {
            if (stack.Count == 0)
                return false;
            else 
            {
                IEnumerator enumerator = (IEnumerator)stack.Peek();
                if (!enumerator.MoveNext())
                {
                    stack.Pop();
                    return MoveNext();
                }
                else return true;
            }
        }
        public void Reset() 
        {
            throw new ApplicationException();
        }
    }
}
