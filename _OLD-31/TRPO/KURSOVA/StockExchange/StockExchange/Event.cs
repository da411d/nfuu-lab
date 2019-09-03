using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StockExchangeDraft
{
    public abstract class Event
    {
        private string eventName;
        private double eventOccuranceRate;
        private string eventMessageBoxText;

        public string EventName { get => eventName; set => eventName = value; }
        public double EventOccuranceRate { get => eventOccuranceRate; set => eventOccuranceRate = value; }
        public string EventMessageBoxText { get => eventMessageBoxText; set => eventMessageBoxText = value; }
    }
}
