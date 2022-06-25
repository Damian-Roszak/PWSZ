using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Lista6zad1
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string name = TextBox1.Text;
            string url;
            //{Server.UrlEncode(TextBox1.Text)}
            url = "WebForm2.aspx?imie=" + TextBox1.Text
              + "&nazwisko=" + TextBox2.Text
              + "&wiek=" + TextBox3.Text
              + "&pesel=" + TextBox4.Text
              + "&kraj=" + TextBox5.Text
              + "&miasto=" + TextBox6.Text
              + "&ulica=" + TextBox7.Text
              + "&nr=" + TextBox8.Text
              + "&czcionka=" + DropDownList1.SelectedValue.ToString()
              + "&kolor=" + DropDownList2.SelectedValue.ToString()
              + "&rozmiar=" + TextBox9.Text
              + "&pogrubienie=" + CheckBox1.Checked
              + "&pochylenie=" + CheckBox2.Checked
              + "&podkreślenie=" + CheckBox3.Checked
              ;
           // url = $"WebForm2.aspx?imie={name}";
            Response.Redirect(url);
        }
    }
}
