using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace oop14lan_new
{
     [Serializable]
    class Seller : IComparable
    {
        private string client;
        private string product_name;
        private int cost; 
        private int amount;
        private string discount;
        #region Властивості
        
        public string Client
        {
            set { client = value; }
            get { return client; }
        }
        
        public string Product_name
        {
            set { product_name = value; }
            get { return product_name; }
        }
        
        public int Cost
        {
            set
            {
                try
                {
                    if (value > 0  ) cost = value;
                    else throw new Exception("Invalid cost");
                }
                catch (Exception ex) { Console.WriteLine(ex.Message); }
            }
            get { return cost; }
        }
        
        public int Amount
        {
            set
            {
                try
                {
                    if (value > 0) amount = value;
                    else throw new Exception("Invalid cost");
                }
                catch (Exception ex) { Console.WriteLine(ex.Message); }
                
            }
            get { return amount; }
        }

        public string Discount
        {
            set { discount = value; }
            get { return discount; }
        }
        #endregion
        #region Конструктори
        
        public Seller(string client, string product_name, int cost, int amount, string discount)
        {
            this.Client = client;
            this.Product_name = product_name;
            try { if (cost <= 0 && amount <= 0) throw new Exception("Cost and amount  must be over than 0 "); }
            catch (Exception ex) { Console.WriteLine(ex.Message); }
            this.Cost = cost;
            this.Amount = amount;
            this.Discount = discount;
            

        }
        public Seller(string client, string product_name, int cost) : this(client, product_name, cost, 1, "Знижка не надається") { }
       
        #endregion
        #region Методи
        
        int IComparable.CompareTo(object obj)
        {
            Seller seller = obj as Seller;
            if (seller != null)
            {
                return this.Amount.CompareTo(seller.Amount);
            }
            else throw new InvalidCastException();
        }
      
        public string Info()
        {
            return String.Format(Client + "\t" + Product_name + "\t" + Cost + "\t" + Amount+ "\t"+Discount );
        }
        #endregion

    }
}
