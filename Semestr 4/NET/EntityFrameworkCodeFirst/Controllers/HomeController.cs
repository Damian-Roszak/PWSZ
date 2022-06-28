using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace EntityFrameworkCodeFirst.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult About()
        {
            ViewBag.Message = "Dziennik ocen stuentów.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "PWSZ.NYSA.PL";

            return View();
        }
    }
}