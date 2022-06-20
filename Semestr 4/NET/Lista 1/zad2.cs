using System;

namespace Zad2
{
    class Program
    {
        static void Main(string[] args)
        {
            string x;
             Console.Write("Podaj palindrom: ");
             x = Console.ReadLine();
            int czek = 0;

            for (int i = 0; i < x.Length; i++)
            {
                if (x[i] == x[x.Length - i - 1]) continue;
                else {
                    Console.WriteLine("wyraz 1: " + x + " to nie palindrom");
                    czek++;
                    break;
                }
            }
            if (czek==0) Console.WriteLine("SUKCES wyraz 1: "+x+ " to palindrom");
            
        }
    }
}
