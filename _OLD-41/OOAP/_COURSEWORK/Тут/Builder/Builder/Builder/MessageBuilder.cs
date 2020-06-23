using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Builder
{
    abstract class MessageBuilder
    {
        //перетворений обєкт повідомлення
        public OutboundMessageIF messageObject { get; set; }
       
        //отримати обєкт будівельника
        public static MessageBuilder GetInstance(String format)
        {
            MessageBuilder builder = null;
            if (format.Equals("MAPI"))
                builder = new MAPIBuilder();
            else if (format.Equals("PROFS"))
                builder = new PROFSBuilder();
            return builder;
        }
        //абстрактні методи для побудови обєкту повідомлення
        public abstract void From(string Value);
        public abstract void To(string Value);
        public abstract void PlainText(string Value);
    }
    class MAPIBuilder : MessageBuilder
    {
        public MAPIBuilder()
        {
            messageObject = new MAPIMsg();
        }
        public override void From(string msg)
        {
            messageObject.Sender = msg;
        }
        public override void To(string msg)
        {
            messageObject.Receiver = msg;
        }
        public override void PlainText(string msg)
        {
            messageObject.Message = msg;
        }
    }
    class PROFSBuilder : MessageBuilder
    {
        public PROFSBuilder()
        {
            messageObject = new PROFSMsg();
        }
        public override void From(string msg)
        {
            messageObject.Sender =msg;
        }
        public override void To(string msg)
        {
            messageObject.Receiver = msg;
        }
        public override void PlainText(string msg)
        {
            messageObject.Message = msg;
        }
    }
}
