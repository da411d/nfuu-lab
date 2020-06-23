/*
 * Варіант 2
 * Розробити програму-робота, яка б паралельно опрацьовувало
 * інформацію двох сторінок товару будь-якого інтернет магазину. 
 * Для реалізації застосувати Invoke.
 */

using System;
using System.Drawing;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;
using xNet.Net;

namespace LAB_5
{
    public partial class Form1 : Form
    {
        public static string sourcePageA;
        public static string sourcePageB;
        public Form1()
        {
            InitializeComponent();

            const int MAX_PAGES = 8;

            Parallel.Invoke(
                 () =>
                 {
                     using (var RequestA = new HttpRequest())
                     {
                         for (int i = 0; i < MAX_PAGES / 2; i += 1)
                         {
                             sourcePageA += RequestA.Get(String.Format("https://rat.in.ua/shop/page/{0}/", i)).ToText();
                         }
                     }
                 },
                 () =>
                 {
                     using (var RequestB = new HttpRequest())
                     {
                         for (int i = MAX_PAGES / 2; i < MAX_PAGES; i += 1)
                         {
                             sourcePageB += RequestB.Get(String.Format("https://rat.in.ua/shop/page/{0}/", i)).ToText();
                         }
                     }
                 }
               );

            string sourcePage = sourcePageA + sourcePageB;
            var pattern = @"<img width=""200"" height=""200"" src='[^']+' data-src=""([^""]+)"" class=""lazyload attachment-woocommerce_thumbnail size-woocommerce_thumbnail"" [^>]*><h2 class=""woocommerce-loop-product__title"">([^<]+)<\/h2> <span class=""price""><span class=""woocommerce-Price-amount amount"">([0-9.]+)&nbsp;<span class=""woocommerce-Price-currencySymbol"">₴<\/span><\/span><\/span>";
            MatchCollection matches = Regex.Matches(sourcePage, pattern);

            dataGridView1.RowCount = matches.Count;
            int index = 0;
            foreach (Match match in matches)
            {
                dataGridView1.Rows[index].Cells[0].Value = LoadImage(match.Groups[1].ToString());
                dataGridView1.Rows[index].Cells[1].Value = match.Groups[2];
                dataGridView1.Rows[index].Cells[2].Value = match.Groups[3] + "UAH";
                index++;
            }
        }

        // Source: https://stackoverflow.com/a/6152390/5698975
        private Image LoadImage(string url)
        {
            System.Net.WebRequest request = System.Net.WebRequest.Create(url);
            System.Net.WebResponse response = request.GetResponse();
            System.IO.Stream responseStream = response.GetResponseStream();
            Bitmap bmp = new Bitmap(responseStream);
            responseStream.Dispose();
            return bmp;
        }
    }
}