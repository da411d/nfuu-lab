using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Builder
{
    class MIMEParser
    {
        public MIMEMsg objectToParse { get; set; }   
        public MessageBuilder builder { get; set; }
        
        public MIMEParser(MIMEMsg ob)
        {
            objectToParse = ob;
        }
        public OutboundMessageIF parse(string format)
        {
            builder = MessageBuilder.GetInstance(format);
            string []param=objectToParse.Message.Split('/');
            builder.From(param[0]);
            builder.To(param[1]);
            builder.PlainText(param[2]);
            return builder.messageObject;
        }
    }
}
