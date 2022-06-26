using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;

namespace Lista6zad4
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        [Serializable]
        public class Produkt
        {
            public string ile { get; set; }
            public string dostawa { get; set; }
            public string platnosc { get; set; }
        }
        int stan1;
        int stan2;
        int stan3;
        int stan4;
        int stan5;
        int stan6;
        protected void Page_Load(object sender, EventArgs e)
        {
            Random rnd = new Random();
            if (ViewState["ileProd1"] == "?" || Label37.Text == "?")
            {
                ViewState["zamówienia"] = 0;
                inf.Text += "Załadowana";
                stan1 = rnd.Next(2, 55); stan2 = rnd.Next(2, 55); stan3 = rnd.Next(2, 55);
                stan4 = rnd.Next(2, 55); stan5 = rnd.Next(2, 55); stan6 = rnd.Next(2, 55);

                Label37.Text = stan1.ToString(); Label38.Text = stan2.ToString(); Label39.Text = stan3.ToString();
                Label40.Text = stan4.ToString(); Label41.Text = stan5.ToString(); Label42.Text = stan6.ToString();

                ViewState["produkt1Ile"] = stan1;
                ViewState["produkt2Ile"] = stan2;
                ViewState["produkt3Ile"] = stan3;
                ViewState["produkt4Ile"] = stan4;
                ViewState["produkt5Ile"] = stan5;
                ViewState["produkt6Ile"] = stan6;
            }
            //stan1 = rnd.Next(2, 55);
            stan1 = (int)ViewState["produkt1Ile"];
            stan2 = (int)ViewState["produkt2Ile"];
            stan3 = (int)ViewState["produkt3Ile"];
            stan4 = (int)ViewState["produkt4Ile"];
            stan5 = (int)ViewState["produkt5Ile"];
            stan6 = (int)ViewState["produkt6Ile"];
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            int stanBox;
            int.TryParse(TextBox1.Text, out stanBox);
            if (stan1 < stanBox)
            {
                stanBox = stan1;
            }

            Session["Data"] += "<br />Produkt 1:<br /> ilość= " + stanBox.ToString() + " "
                + "<br />rodzaj dostawy: " + DropDownList1.SelectedItem.ToString()
                + "<br /> sposób płatności: " + DropDownList7.SelectedItem.ToString()
                + "<br /> stary stan magazynowy: " + stan1
                + "<br /> nowy stan magazynowy: " + (stan1 - stanBox)
                + "<br />";


            string url;
            //{Server.UrlEncode(TextBox1.Text)}
            url = "WebForm2.aspx?ile=" + ViewState["NastProd"]
              // + "&dostawa=" + DropDownList1.SelectedValue.ToString()
              //+ "&płatność=" + DropDownList7.SelectedValue.ToString()
              ;
             //Response.Redirect("WebForm2.aspx");
            //Server.Transfer("WebForm2.aspx");
        }
        protected void TextBox1_TextChanged(object sender, EventArgs e)
        {
            int stanBox;
            int.TryParse(TextBox1.Text, out stanBox);
            if (stan1 < stanBox)
            {
                TextBox1.Text = stan1.ToString();
            }
        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            int stanBox2;
            int.TryParse(TextBox2.Text, out stanBox2);
            if (stan2 < stanBox2)
            {
                stanBox2 = stan2;
            }
            inf.Text = stan2.ToString();
                Session["Data"] += "<br />Produkt 2:<br /> ilość= " + TextBox2.Text + " "
                + "<br />rodzaj dostawy: " + DropDownList2.SelectedItem.ToString()
                + "<br /> sposób płatności: " + DropDownList8.SelectedItem.ToString()
                + "<br /> stary stan magazynowy: " + stan2
                + "<br /> nowy stan magazynowy: " + (stan2 - stanBox2)
                + "<br />";
        }

        protected void Button3_Click(object sender, EventArgs e)
        {

            int stanBox;
            int.TryParse(TextBox3.Text, out stanBox);
            if (stan3 < stanBox)
            {
                stanBox = stan3;
            }

            Session["Data"] += "<br />Produkt 3:<br /> ilość= " + stanBox.ToString() + " "
            + "<br />rodzaj dostawy: " + DropDownList3.SelectedItem.ToString()
            + "<br /> sposób płatności: " + DropDownList9.SelectedItem.ToString()
                + "<br /> stary stan magazynowy: " + stan3
            + "<br /> nowy stan magazynowy: " + (stan3 - stanBox)
            + "<br />";
        }

        protected void Button7_Click(object sender, EventArgs e)
        {
            Response.Redirect("WebForm2.aspx");
        }

        protected void Button4_Click(object sender, EventArgs e)
        {
            int stanBox;
            int.TryParse(TextBox4.Text, out stanBox);
            if (stan4 < stanBox)
            {
                stanBox = stan4;
            }

            Session["Data"] += "<br />Produkt 4:<br /> ilość= " + stanBox.ToString() + " "
            + "<br />rodzaj dostawy: " + DropDownList4.SelectedItem.ToString()
            + "<br /> sposób płatności: " + DropDownList10.SelectedItem.ToString()
                + "<br /> stary stan magazynowy: " + stan4
            + "<br /> nowy stan magazynowy: " + (stan4 - stanBox)
            + "<br />";
        }

        protected void TextBox4_TextChanged(object sender, EventArgs e)
        {

        }

        protected void Button5_Click(object sender, EventArgs e)
        {
            int stanBox;
            int.TryParse(TextBox5.Text, out stanBox);
            if (stan5 < stanBox)
            {
                stanBox = stan5;
            }

            Session["Data"] += "<br />Produkt 5:<br /> ilość= " + stanBox.ToString() + " "
                + "<br />rodzaj dostawy: " + DropDownList5.SelectedItem.ToString()
                + "<br /> sposób płatności: " + DropDownList11.SelectedItem.ToString()
                + "<br /> stary stan magazynowy: " + stan5
                + "<br /> nowy stan magazynowy: " + (stan5 - stanBox)
                + "<br />";
        }

        protected void TextBox2_TextChanged(object sender, EventArgs e)
        {
            int stanBox;
            int.TryParse(TextBox2.Text, out stanBox);
            if (stan2 < stanBox)
            {
                TextBox2.Text = stan2.ToString();
            }
        }

        protected void Button6_Click(object sender, EventArgs e)
        {
            int stanBox;
            int.TryParse(TextBox6.Text, out stanBox);
            if (stan6 < stanBox)
            {
                stanBox = stan6;
            }

            Session["Data"] += "<br />Produkt 6:<br /> ilość= " + stanBox.ToString() + " "
                + "<br />rodzaj dostawy: " + DropDownList6.SelectedItem.ToString()
                + "<br /> sposób płatności: " + DropDownList12.SelectedItem.ToString()
                + "<br /> stary stan magazynowy: " + stan6
                + "<br /> nowy stan magazynowy: " + (stan6 - stanBox)
                + "<br />";
        }
    }
}
