using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StockExchangeDraft
{
    public class EventBullAndBear : Event
    {
        private double bullAndBearDaysLeft = 0;
        public double BullAndBearDaysLeft { get => bullAndBearDaysLeft; set => bullAndBearDaysLeft = value; }

        public EventBullAndBear(double rrate)
        {
            EventOccuranceRate = rrate;
            EventName = "BullAndBear";
        }
        public double eventCheckBullAndBear(double check, double daysRolled)
        {
            switch (Math.Sign(BullAndBearDaysLeft))
            {
                case -1:
                    BullAndBearDaysLeft++;
                    break;
                case 0:
                    if (check < EventOccuranceRate) BullAndBearDaysLeft = daysRolled;
                    if (check > (1 - EventOccuranceRate)) BullAndBearDaysLeft = -daysRolled;
                    break;
                case 1:
                    BullAndBearDaysLeft--;
                    break;
            }
            return Math.Sign(BullAndBearDaysLeft);
        }
    }
}
