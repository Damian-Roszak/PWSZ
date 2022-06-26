using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Lista6zad3
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            int min = 0;
            int max = 0;
            int ile = 0;

            int.TryParse(TextBox1.Text, out ile);
            int.TryParse(TextBox2.Text, out min);
            int.TryParse(TextBox3.Text, out max);
            if (min > max)
            {
                Label1.Text = "max musi być większy o min";
                return;
            }
            if (max - min < 100 || ile < 1)
            {
                Label1.Text = "zakres musi wynosić min 100";
                return;
            }

            string url;
            url = $"WebForm2.aspx?min={min}&max={max}&ile={ile}";
            Response.Redirect(url);
        }
    }
}