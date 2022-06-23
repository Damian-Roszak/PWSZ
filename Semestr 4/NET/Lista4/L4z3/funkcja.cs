using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace L4z3
{
    internal class funkcja
    {
        public decimal A { get; set; }
        public decimal B { get; set; }

        public decimal[] liniowa(in int length)
        {
            decimal[] tab = new decimal[length];
            for (int i = 0; i < length; i++)
                tab[i] = i * A + B;

            return tab;
        }
        public decimal[] parabola(in int length)
        {
            decimal[] tab = new decimal[length];
            for (int i = 0; i < length; i++)
                tab[i] = i * i * A ;

            return tab;
        }
        public object this[string propertyName]
        {
            get { return this.GetType().GetProperty(propertyName).GetValue(this, null); }
            set { this.GetType().GetProperty(propertyName).SetValue(this, value, null); }
        }
    }
}
