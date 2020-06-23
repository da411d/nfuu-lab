using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Builder
{
    class PROFSMsg: OutboundMessageIF
    {
        public String Message { get; set; }//текст повідомлення
        public String Receiver { get; set; }//електронна адреса одержувача
        public String Sender { get; set; }//електронна адреса відправника
        public override string ToString()
        {
            string str = "Receiver: ";
            str += Receiver + System.Environment.NewLine;
            str += "____________________________________" + System.Environment.NewLine;
            str += "Sender: ";
            str += Sender + System.Environment.NewLine;
            str += "____________________________________" + System.Environment.NewLine;
            str += Message + System.Environment.NewLine;
            str += "____________________________________";
            return str;
        }
    }
}
