using System;

namespace LAB03marzec
{
    class Program
    {
        static void Main(string[] args)
        {
            int x;
            Console.Write("Podaj liczbę : ");
            x = int.Parse(Console.ReadLine());

            int n=0, i;

            for ( i = 1; i <= x; i++)
            {
                if(x%i==0) n++;
            }
            if (n==2)
                Console.WriteLine("Liczba "+x+" jest liczbą pierwszą.");
            else
                Console.WriteLine("to nie " + x + " liczba pierwsza.");
        }
    }
}
