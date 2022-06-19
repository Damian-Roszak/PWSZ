using System;
class opmat
{
    class Klient 
    {
        int pin;
        int nrKlienta;
        double stan;
        public void setPIN(int p) { pin = p; }
        public int getPIN() { return pin; }
        public void setStan(double s) { stan = s; }
        public double getStan() { return stan; }
        public void setNrKlienta(int p) { nrKlienta = p; }
        public int getNrKlienta() { return nrKlienta; }
    };
    class Bankomat
    {
        int dychy, dwudziestki, pięćdziesiątki, stówy, dwusetki, pięćsetki;

        public Bankomat()
        {
            var rand = new Random();
            dychy = rand.Next(200);
            dwudziestki = rand.Next(200);
            pięćdziesiątki = rand.Next(200);
            stówy = rand.Next(200);
            dwusetki = rand.Next(200);
            pięćsetki = rand.Next(200);

            Console.WriteLine("=========== BANKOMAT STAN BANKNOTÓW ==============");
            Console.WriteLine("500: "+ pięćsetki);
            Console.WriteLine("200: " + dwusetki);
            Console.WriteLine("100: " + stówy);
            Console.WriteLine("50: " + pięćdziesiątki);
            Console.WriteLine("20: " + dwudziestki);
            Console.WriteLine("10: " + dychy);
            Console.WriteLine("=========== BANKOMAT STAN BANKNOTÓW ==============");

        }
        public bool login(Klient klient)
        {
            int pin;
            bool ret = false;
            Console.Write("Podaj PIN: ");
            pin = int.Parse(Console.ReadLine());
            if (pin == klient.getPIN())
            {
                ret = true;
                menu(klient);
            }
          
         return ret;
        }
        void saldo(Klient klient)
        {
            Console.WriteLine("Stan Twojego konta wynosi: {0}", klient.getStan().ToString("C"));
        }
        void wypłata(Klient klient)
        {
            int kwota, ile;
            int ile10, ile20, ile50, ile100, ile200, ile500;
            Console.Write("Jaką kwotę chcesz wypłacić?: ");
            kwota = int.Parse(Console.ReadLine());
            Console.Write(" \n");
            if (kwota % 10 == 0)
            {
                if (kwota <= klient.getStan())
                {
                    ile = kwota;
                    ile500 = ile / 500;
                    if (ile500 <= pięćsetki)
                    {
                        Console.WriteLine("Wypłacam {0} pięćsetek.", ile500);
                        pięćsetki -= ile500;
                        ile -= 500 * ile500;
                    }

                    ile200 = ile / 200;
                    if (ile200 <= dwusetki)
                    {
                        Console.WriteLine("Wypłacam {0} dwusetek.", ile200);
                        dwusetki -= ile200;
                        ile -= 200 * ile200;
                    }

                    ile100 = ile / 100;
                    if (ile100 <= stówy)
                    {
                        Console.WriteLine("Wypłacam {0} setek.", ile100);
                        stówy -= ile100;
                        ile -= 100 * ile100;
                    }

                    ile50 = ile / 50;
                    if (ile50 <= pięćdziesiątki)
                    {
                        Console.WriteLine("Wypłacam {0} pięćdziesiątek.", ile50);
                        pięćdziesiątki -= ile50;
                        ile -= 50 * ile50;
                    }

                    ile20 = ile / 20;
                    if (ile20 <= dwudziestki)
                    {
                        Console.WriteLine("Wypłacam {0} dwudziestek.", ile20);
                        dwudziestki -= ile20;
                        ile -= 20 * ile20;
                    }

                    ile10 = ile / 10;
                    if (ile10 <= dychy)
                    {
                        Console.WriteLine("Wypłacam {0} dziesiątek.", ile10);
                        dychy -= ile10;
                        ile -= 10 * ile10;
                    }
                    //int suma = ile10 * 10 + ile20 * 20 + ile50 * 50 + ile100 * 100 + ile200 * 200 + ile500 * 500;
                    //if (suma == kwota)
                    klient.setStan(klient.getStan() - kwota);
                    Console.Write("\n Obecny stan konta: {0}", klient.getStan().ToString("C"));
                }
                else
                    Console.Write("BŁĄD: Brak wystarczających środków na koncie!");
            }
            else
                Console.Write("BŁĄD: Podana kwota zawiera bilon!");
        }
        void zmienPIN(Klient klient)
        {
            int nowy;
            Console.Write("Podaj nowy PIN: ");
            nowy = int.Parse(Console.ReadLine());
            klient.setPIN(nowy);
            Console.Write("Twój nowy PIN to: " + klient.getPIN());
        }
        void wpłać(Klient klient)
        {
            int ile;
            Console.Write("Jaką kwotę chcesz wpłacić?: ");
            ile = int.Parse(Console.ReadLine());
            if (ile % 10 == 0)
                klient.setStan(klient.getStan() + ile);
            else
                Console.Write("BŁĄD: Podana kwota zawiera bilon!");
        }
        public void menu(Klient klient)
        {
            char opcja = 'a';
            while (opcja != '0')
            {
                Console.WriteLine("\n");
                Console.WriteLine("1.Wypłać gotówkę");
                Console.WriteLine("2.Zmień PIN");
                Console.WriteLine("3.Wpłać gotówkę");
                Console.WriteLine("4.Sprawdź saldo");
                Console.WriteLine("0.Zakończ");
                Console.Write("Podaj nr opcji: ");
                opcja = char.Parse(Console.ReadLine());
                switch (opcja)
                {
                    case '1':
                        wypłata(klient);
                        break;
                    case '2':
                        zmienPIN(klient);
                        break;
                    case '3':
                        wpłać(klient);
                        break;
                    case '4':
                        saldo(klient);
                        break;
                    case '0':
                        break;
                }
            }
        }
    };
    static void Main()
    {

        Klient[] bd = new Klient[3];
        
                bd[0] = new Klient();
                bd[0].setPIN(1234);
                bd[0].setStan(1000.04);
                bd[0].setNrKlienta(11);

                bd[1] = new Klient();        
                bd[1].setPIN(1111);
                bd[1].setStan(1111.11);
                bd[1].setNrKlienta(22);
            
                bd[2] = new Klient();
                bd[2].setPIN(2222);
                bd[2].setStan(2222.22);
                bd[2].setNrKlienta(33);

        Bankomat atm = new Bankomat();
        bool logon = false;
        int nrKarty=11;
        /*
        Console.Write("Podaj nr karty: ");
        nrKarty = int.Parse(Console.ReadLine());
        */

        for (int i = 0; i < 3; i++)
            if (nrKarty == bd[i].getNrKlienta())
                logon = atm.login(bd[i]);
       
        if (logon == false) Console.Write("Błędny PIN");
        
    }
}
