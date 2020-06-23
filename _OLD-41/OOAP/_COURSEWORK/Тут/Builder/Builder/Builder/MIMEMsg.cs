using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Builder
{
    class MIMEMsg
    {
        public String Message { get; set; }//текст повідомлення в форматі MIME
        public int Lenght { get { return Message.Length; } }
        public MIMEMsg(string arg1, string arg2, string arg3)
        {
            Message =arg1+"/ "+arg2+"/ "+System.Environment.NewLine+arg3;
        }
        public override string ToString()
        {
            return Message;
        }
    }
}
