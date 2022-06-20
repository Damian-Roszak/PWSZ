using System;

namespace Zad4
{
    class Program
    {
        static void Main(string[] args)
        {
            double a,b,c,x1,x2;
            Console.WriteLine("Podaj a=");
            a = Double.Parse(Console.ReadLine());

            Console.WriteLine("Podaj b=");
            b = Double.Parse(Console.ReadLine());

            Console.WriteLine("Podaj c=");
            c = Double.Parse(Console.ReadLine());

            if (a == 0) Console.WriteLine("To nie jest funkcja kwadratowa!!");
            else { 
                x1 = (b*b-4*a*c)/ 2 * a;
                x2 = (b * b + 4 * a * c) / 2 * a;

               // Console.WriteLine("Wynik: x1=" + x1 + "  x2=" + x2);
                Console.WriteLine(String.Format("WYNIK x1={0:0.##}  x2={1:0.##}", x1,x2));
            }

        }
    }
}
