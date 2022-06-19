using System;
using System.Collections.Generic;

namespace Zad1
{
    public class Liczby
    {
       public int value, absValue;
       public string parity;

        public Liczby(int l) {
            value = l;
            absMet();
            parityMet();

        }
        public void absMet() {
            absValue = Math.Abs(value);
        }
        public void parityMet()
        {
            if (value % 2 == 0) parity = "Parzysta";
            else parity = "Nieparzysta";
        }

        public static implicit operator int(Liczby d) => d.value;
        public static explicit operator Liczby(int b) => new Liczby(b);

        public override string ToString() => $"wartość: {value} W. Bezwzględna: {absValue} parzystość: {parity}";
    }
    public class LiczbyComparer : IEqualityComparer<Liczby>
    {
        public bool Equals(Liczby x, Liczby y)
        {
            if (x.value == y.value)
                return true;
            else return false;
        }

        public int GetHashCode(Liczby obj)
        {
            return obj.value.GetHashCode();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            HashSet<Liczby> setLiczby = new HashSet<Liczby>(new LiczbyComparer());
            int n, m;
            Console.Write("Podaj n: ");
            n = int.Parse(Console.ReadLine());

            Random rnd = new Random();

            for (int i=0; i<n; i++)
            {
                m = rnd.Next(-100, 101);
                Console.Write("Wynik: {0,3} ", m);
                setLiczby.Add(new Liczby (m));
            }
            Console.WriteLine("\n odczyt");

            foreach (Liczby i in setLiczby)
            {
                Console.Write("\n odczyt {0,3}", i.ToString());
                
            }
        }
    }
}
