using System;
class opmat
{
    static void Main()
    {
        int n;
        Console.Write("Podaj liczbę: ");
        n = int.Parse(Console.ReadLine());
        Console.WriteLine(" ");
        double ulamek, calk, kwadr, pierw;
        kwadr = 8 * n + 1;
        pierw = Math.Sqrt(kwadr);
        calk = Math.Truncate(pierw);
        ulamek = pierw - calk;
        if (ulamek == 0)
        {
            Console.WriteLine("WYNIK: liczba="+ n + " jest trójkątna");
        }
        else {
            Console.WriteLine("liczba=" + n + " NIE jest trójkątna");
        }
        
        
    }
}