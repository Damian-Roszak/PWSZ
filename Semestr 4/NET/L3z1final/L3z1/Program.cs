using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace L3z1
{
    internal static class Program
    {
        public class Automobil
        {
            public string pole;
            public void setPole(string p)
            {
                pole = p;
            }
            public string metoda()
            {
                return pole;
            }
        }
        /// <summary>
        /// Główny punkt wejścia dla aplikacji.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Automobil brum = new Automobil();
            brum.setPole("autko");
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());

            
        }
    }
}
