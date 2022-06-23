using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace L4z2
{
    public class ZnajdźNextSzukaj
    {
        String szukajŁańcuch;
        String kierunek;
        bool dopasujZnaki;
        String treść;
        int pozycja;
        bool sukces;

        public string SzukajŁańcuch { get => szukajŁańcuch; set => szukajŁańcuch = value; }
        public string Kierunek { get => kierunek; set => kierunek = value; }
        public bool DopasujZnaki { get => dopasujZnaki; set => dopasujZnaki = value; }
        public string Treść { get => treść; set => treść = value; }
        public int Pozycja { get => pozycja; set => pozycja = value; }
        public bool Sukces { get => sukces; set => sukces = value; }
    }
}
