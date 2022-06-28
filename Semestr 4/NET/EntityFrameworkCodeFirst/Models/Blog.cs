using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace EntityFrameworkCodeFirst.Models
{
    public class Blog
    {
        public int BlogId { get; set;}
        public string Name { get; set; }
        public List<Post> Posts { get; set; }
    }
    
}