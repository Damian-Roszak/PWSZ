using System;
class opmat
{
    static void Main()
    {

        double value, power;
        Console.Write("Podaj liczbę do pierwiastkowania: ");
        value = Double.Parse(Console.ReadLine());
        Console.WriteLine(" ");

        Console.Write("Podaj stopień pierwiastka: ");
        power = Double.Parse(Console.ReadLine());
        Console.WriteLine(" ");

        Console.WriteLine($"{value}^{1/power} = {(long)Math.Pow(value, (1 / power)):N0} (0x{(long)Math.Pow(value, (1 / power)):X})");

    }
}