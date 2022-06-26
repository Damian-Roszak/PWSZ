using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Lista6zad3
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            Random rnd = new Random();
            int min = 0;
            int max = 0;
            int ile = 0;
            int wylosowana;

            int.TryParse(Request.QueryString["min"], out min);
            int.TryParse(Request.QueryString["max"], out max);
            int.TryParse(Request.QueryString["ile"], out ile);

            Label2.Text = ""; //min.ToString();
            Label4.Text = ""; // max.ToString();
            Label6.Text = ""; // ile.ToString();

            int [] tab = new int[ile];
            Dictionary<int, int> elementy = new Dictionary<int, int>();
            Dictionary<int, int> powtórzenia = new Dictionary<int, int>();

            for (int i = 0; i < ile; i++)
            {
                wylosowana = rnd.Next(min, max + 1);
                tab[i] = wylosowana;
                if (elementy.ContainsValue(wylosowana) == false)
                {
                    elementy.Add(i, wylosowana);
                }
                else
                {
                    if (powtórzenia.ContainsValue(wylosowana) == false)
                        powtórzenia.Add(i, wylosowana);
                }
            }
            for (int i = 0; i < ile; i++)
            {                
                Label2.Text += tab[i] + ", ";
            }
            Dictionary<int, int>.ValueCollection valColElem = elementy.Values;
            foreach(int i in valColElem)
                Label4.Text += i.ToString() + ", ";

            Dictionary<int, int>.ValueCollection valColPowt = powtórzenia.Values;
            foreach (int j in valColPowt)
                Label6.Text += j.ToString() + ", ";

        }

    }
}
