using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StockExchangeDraft
{
    public class EventDelisting : Event
    {

        public EventDelisting()
        {
            EventName = "delisting";

            EventMessageBoxText = " has been delisted";
        }

        //Event checking for stock Delisting
        public static bool eventCheckDelisting(Company stock, int i, double checkValue)
        {
            if (checkValue > stock.Stability)
            {
                stock.Stability = 0;
                return true;
            }

            return false;
        }

    }
}
