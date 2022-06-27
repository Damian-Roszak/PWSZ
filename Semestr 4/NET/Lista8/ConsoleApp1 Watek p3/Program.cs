using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace MyThread
{
    class Program
    {
        static bool zrobione;
        static object kłódka = new object();
        static void Main(string[] args)
        {
            new Thread(Uruchom).Start();
            Uruchom();
            Console.Read();
        }

        static void Uruchom()
        {
            lock (kłódka)
            {
                if (!zrobione)
                {
                    Console.WriteLine("Zrobione");
                    zrobione = true;
                }
            }
        }
    }
}