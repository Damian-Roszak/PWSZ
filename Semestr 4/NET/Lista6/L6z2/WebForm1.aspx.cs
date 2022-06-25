using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Lista6zad2
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        double n, m;
        protected void Page_Load(object sender, EventArgs e)
        {
            ViewState["n1"] = TextBox1.Text;
            ViewState["n2"] = TextBox2.Text;
        }

        protected void BtnPlus_Click(object sender, EventArgs e)
        {
            fun();
            Label1.Text = (n + m).ToString();
        }

        protected void BtnMinus_Click(object sender, EventArgs e)
        {
            fun();
            Label1.Text = (n - m).ToString();
        }

        protected void BtnMn_Click(object sender, EventArgs e)
        {
            fun();
            Label1.Text = (n * m).ToString();
        }

        protected void BtnDiv_Click(object sender, EventArgs e)
        {
            fun();
            Label1.Text = (n / m).ToString();
        }

        protected void BtnPot_Click(object sender, EventArgs e)
        {
            fun();
            Label1.Text = (Math.Pow(n,m)).ToString();
        }

        protected void BtnPier_Click(object sender, EventArgs e)
        {
            fun();
            Label1.Width = 20 *
                (("√Liczba 1=").Length + (Math.Sqrt(n)).ToString().Length 
                + ("√Liczba 2=").Length + (Math.Sqrt(m)).ToString().Length);
            Label1.Text = "√Liczba 1=" + (Math.Sqrt(n)).ToString();
            Label1.Text += "<br />";
            Label1.Text += "√Liczba 2=" + (Math.Sqrt(m)).ToString();
        }

        protected void BtnModulo_Click(object sender, EventArgs e)
        {
            fun();
            Label1.Text = (n % m).ToString();
        }

        protected void BtnSin_Click(object sender, EventArgs e)
        {
            fun();
            double sn = Math.Sin(n);
            double sm = Math.Sin(m);
            Label1.Width = 20 *
                (("Sin Liczba 1=").Length + sn.ToString().Length + ("Sin Liczba 2=").Length + sm.ToString().Length);
            Label1.Text = "Sin Liczba 1=" + sn.ToString();
            Label1.Text += "<br />";
            Label1.Text += "Sin Liczba 2=" + sm.ToString();
        }

        private void fun()
        {
            n = Convert.ToDouble(ViewState["n1"]);
            m = Convert.ToDouble(ViewState["n2"]);
        }

    }
}
    
