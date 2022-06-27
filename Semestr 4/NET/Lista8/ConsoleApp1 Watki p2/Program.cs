using System;
using System.Threading;

class WatekTestowy
{
    bool zrobione;
    static void Main()
    {
        WatekTestowy nazwa = new WatekTestowy();
        new Thread(nazwa.Uruchom).Start();
        nazwa.Uruchom();
        Console.ReadLine();
    }
    void Uruchom() 
    {
        Console.WriteLine("Piszę");
        if (!zrobione)
        {
            zrobione = true;
            Console.WriteLine("Zrobione");
        }
    }
}