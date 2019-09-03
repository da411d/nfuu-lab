using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StockExchangeDraft
{
    public class EventCrash : Event
    {
        public EventCrash(string rname, double rrate, string etext)
        {
            EventName = rname;
            EventOccuranceRate = rrate;
            EventMessageBoxText = etext;
        }

        //Event checking for Market Crash
        public int eventCheckCrash(double checkValue)
        {
            if (checkValue > EventOccuranceRate) return 1;
            else return 0;
        }
    }

}
