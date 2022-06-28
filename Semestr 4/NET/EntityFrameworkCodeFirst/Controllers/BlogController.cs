using EntityFrameworkCodeFirst.Context;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace EntityFrameworkCodeFirst.Controllers
{
    public class BlogController : Controller
    {
        BlogContext db = new BlogContext();
        // GET: Blog
        public ActionResult Index()
        {
            return View(db.Blog.ToList());
        }
    }
}