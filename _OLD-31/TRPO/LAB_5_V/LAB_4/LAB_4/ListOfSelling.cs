using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;

namespace oop14lan_new
{
    [Serializable]
    class ListOfSelling
    {
        BinaryFormatter formatter;
        List<Seller> seller = new List<Seller>();
        /// <summary>
        /// Конструктор для створення Generic колекції типу Seller
        /// </summary>
        public ListOfSelling()
        {
            seller.Add(new Seller("Хамець I.", "порошок для випiчки ", 15, 11, ""));
            seller.Add(new Seller("Хамець А.", "машинне масло       ", 166, 2, ""));
            seller.Add(new Seller("Кочiрко Т.", "папiр туалетний    ", 4, 8, ""));
            seller.Add(new Seller("Крецул М.", "зошит              ", 10, 6, ""));
            seller.Add(new Seller("Рочняк А.", "олiвець             ", 5, 12, ""));
            seller.Add(new Seller("Лопадчак I.", "рушник            ", 82, 2, ""));
            seller.Add(new Seller("Процах М.", "папiр для друку     ", 100, 1, ""));
            seller.Add(new Seller("Iванюк С.", "пудинг ванiльний    ", 14, 1, ""));
        }

       
        public void Show()
        {
            for (int i = 0; i < seller.Count; i++)
            {
                Console.WriteLine(seller[i].Info());
            }
            Console.WriteLine("\n\n");

        }
       
        public void Sort()
        {
            seller.Sort();
            this.Show();
        }
       
        public void ShowDiscount()
        {
            for (int i = 0; i < seller.Count; i++)
            {
                if (seller[i].Amount >= 2 && seller[i].Amount <= 5)
                { seller[i].Discount ="Знижка 3%";}
                else if (seller[i].Amount >= 5 && seller[i].Amount <= 10)
                { seller[i].Discount = "Знижка 5%"; }
                else if (seller[i].Amount >= 10 )
                { seller[i].Discount = "Знижка 7%"; }
            }
            this.Show();
        }
        
        public void GroupByDiscount()
        {
            for (int i = 0; i < seller.Count; i++)
            {
                if (seller[i].Discount == "Знижка 3%" || seller[i].Discount == "Знижка 5%" || seller[i].Discount == "Знижка 7%")
                {
                    
                    Console.WriteLine(seller[i].Client);
                }
            }
           
        }
       
        #region Серіалізація
        public void Serialize(string path)
        {
            formatter = new BinaryFormatter();
            using (FileStream filestream = new FileStream(path, FileMode.OpenOrCreate))
            {
                formatter.Serialize(filestream, seller);
                Console.WriteLine("Колекцiя Серiалiзована");
            }
        }
        public List<Seller> Deserialized(string path)
        {
            formatter = new BinaryFormatter();
            using (FileStream filestream = new FileStream(path, FileMode.OpenOrCreate))
            {
                List<Seller> deserializeList = (List<Seller>)formatter.Deserialize(filestream);
                Console.WriteLine("Колекцiя Десерiалiзована");
                
                return deserializeList;
            }

        }
        #endregion

    }
}
