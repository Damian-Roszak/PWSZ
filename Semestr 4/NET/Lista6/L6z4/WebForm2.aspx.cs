using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Reflection;
using Lista6zad4;

namespace Lista6zad4
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        /*[Serializable]
        public class Produkt
        {
            public string ile;
            public string dostawa;
            public string platnosc;
        }*/
        protected void Page_Load(object sender, EventArgs e)
        {
            /*if ((int)ViewState["zamówienia"] != 0)
            {
                string d = Request.QueryString["dostawa"];
                string p = Request.QueryString["płatność"];

                Label1.Text = Request.QueryString["ile"];
                Label1.Text += " " + d;
                Label1.Text += " " + p;
            }*/
           // string p = Context.Items["NP"].ToString();

           if(PreviousPage != null && PreviousPageViewState != null)//&& PreviousPageViewState != null
            {
                //Produkt p = new Produkt();
                //string p = PreviousPageViewState["NastProd"];
                // Type ty = Page.PreviousPage.GetType();
                // MethodInfo mi = ty.GetMethod("GetViewValue");
                // Produkt p = (Produkt)mi.Invoke(Page.PreviousPage, null);
                // Label1.Text += " " + p.ile;
                //  string d = Request.QueryString["dostawa"];
                //  string p = Request.QueryString["płatność"];
               //var sg = (int)PreviousPageViewState["ileProd1"];
               // Label1.Text = sg.ToString();
               // Label1.Text += " " + d;
               // Label1.Text += " " + p;
            }
                     
        }
        private StateBag PreviousPageViewState
        {
            get
            {
                StateBag retVal = null;
                if(PreviousPage != null)
                {
                    Object objPrePage = (Object)PreviousPage;
                    MethodInfo objMet = objPrePage.GetType().GetMethod("ReturnViewState");
                    return (StateBag)objMet.Invoke(objPrePage, null);
                }
                return retVal;
            }
        }
    }
}