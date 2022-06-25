using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using System.ComponentModel;
using System.Drawing;

namespace Lista6zad1
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        protected System.Web.UI.HtmlControls.HtmlGenericControl Div1;
        protected void Page_Load(object sender, EventArgs e)
        {
            string cz = Request.QueryString["czcionka"];
            int rozm;
            int.TryParse(Request.QueryString["rozmiar"], out rozm);
            string kolorZhtml = Request.QueryString["kolor"];

            Color kolor = ColorTranslator.FromHtml(kolorZhtml);

            string pogrub = Request.QueryString["pogrubienie"];
            string pochyl = Request.QueryString["pochylenie"];
            string podkre = Request.QueryString["podkreślenie"];
            
            Label1.Text = Request.QueryString["imie"];
                Label1.Font.Name = cz;
                Label1.ForeColor = kolor;
                Label1.Font.Size = rozm;
                Label1.Font.Bold = Convert.ToBoolean(pogrub);
                Label1.Font.Italic = Convert.ToBoolean(pochyl);
                Label1.Font.Underline = Convert.ToBoolean(podkre);
                
                
            Label2.Text = Request.QueryString["nazwisko"];
            Label2.Font.Name = cz;
            Label2.ForeColor = kolor;
            Label2.Font.Size = rozm;
            Label2.Font.Bold = Convert.ToBoolean(pogrub);
            Label2.Font.Italic = Convert.ToBoolean(pochyl);
            Label2.Font.Underline = Convert.ToBoolean(podkre);


            Label3.Text = Request.QueryString["wiek"];
            Label3.Font.Name = cz;
            Label3.ForeColor = kolor;
            Label3.Font.Size = rozm;
            Label3.Font.Bold = Convert.ToBoolean(pogrub);
            Label3.Font.Italic = Convert.ToBoolean(pochyl);
            Label3.Font.Underline = Convert.ToBoolean(podkre);


            Label4.Text = Request.QueryString["pesel"];
            Label4.Font.Name = cz;
            Label4.ForeColor = kolor;
            Label4.Font.Size = rozm;
            Label4.Font.Bold = Convert.ToBoolean(pogrub);
            Label4.Font.Italic = Convert.ToBoolean(pochyl);
            Label4.Font.Underline = Convert.ToBoolean(podkre);


            Label5.Text = Request.QueryString["kraj"];
            Label5.Font.Name = cz;
            Label5.ForeColor = kolor;
            Label5.Font.Size = rozm;
            Label5.Font.Bold = Convert.ToBoolean(pogrub);
            Label5.Font.Italic = Convert.ToBoolean(pochyl);
            Label5.Font.Underline = Convert.ToBoolean(podkre);


            Label6.Text = Request.QueryString["miasto"];
            Label6.Font.Name = cz;
            Label6.ForeColor = kolor;
            Label6.Font.Size = rozm;
            Label6.Font.Bold = Convert.ToBoolean(pogrub);
            Label6.Font.Italic = Convert.ToBoolean(pochyl);
            Label6.Font.Underline = Convert.ToBoolean(podkre);


            Label7.Text = Request.QueryString["ulica"];
            Label7.Font.Name = cz;
            Label7.ForeColor = kolor;
            Label7.Font.Size = rozm;
            Label7.Font.Bold = Convert.ToBoolean(pogrub);
            Label7.Font.Italic = Convert.ToBoolean(pochyl);
            Label7.Font.Underline = Convert.ToBoolean(podkre);


            Label8.Text = Request.QueryString["nr"];
            Label8.Font.Name = cz;
            Label8.ForeColor = kolor;
            Label8.Font.Size = rozm;
            Label8.Font.Bold = Convert.ToBoolean(pogrub);
            Label8.Font.Italic = Convert.ToBoolean(pochyl);
            Label8.Font.Underline = Convert.ToBoolean(podkre);
        }
    }
}