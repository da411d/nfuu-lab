using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;

namespace CompositePattern
{
    class NullIEnumerator: IEnumerator
    {
        public object Current { get { return null; } }
        public bool MoveNext()
        {
            return false;
        }
        public void Reset()
        {
            throw new ApplicationException();
        }
    }
}
