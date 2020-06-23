using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Builder
{
    interface OutboundMessageIF
    {
        String Message { get; set; }//текст повідомлення
        String Receiver { get; set; }//електронна адреса одержувача
        String Sender { get; set; }//електронна адреса відправника
    }
}
