using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Builder
{
    class MAPIMsg: OutboundMessageIF
    {
        public String Message { get; set; }//текст повідомлення
        public String Receiver { get; set; }//електронна адреса одержувача
        public String Sender { get; set; }//електронна адреса відправника
       
        public override string ToString()
        {
            string str = "Повідомлення адресовано до: ";
            str += Receiver + System.Environment.NewLine;
            str += "*****************************************";
            str += Message + System.Environment.NewLine;
            str += "*****************************************";
            str += System.Environment.NewLine;
            str += "Повідомлення було надіслано від: ";
            str += Sender;
            return str;
        }
    }
}
