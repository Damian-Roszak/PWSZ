using System;
using System.Text;

namespace Zad2
{
    class Program
    {
        
        public enum Heks
        {
            A = 10, B = 11, C = 12, D = 13, E = 14, F = 15
        }
        public static string BinToOct(string binarna)
        {
            if (string.IsNullOrEmpty(binarna))
                return binarna;

            StringBuilder result = new StringBuilder(binarna.Length / 3 + 1);
        
        string bajt;
            int mod4Len = binarna.Length % 3;
            if (mod4Len != 0)
            {
                binarna = binarna.PadLeft(((binarna.Length / 3) + 1) * 3, '0');
               // Console.WriteLine("bajt OCT " + binarna);
            }

            for (int i = 0; i < binarna.Length; i += 3)
            {
                bajt = binarna.Substring(i, 3);
                result.AppendFormat("{0:X1}", Convert.ToByte(bajt, 2));
               // Console.WriteLine("bajt OCT " + bajt);
            }

            return result.ToString();
        }

        static int BinToDec(string input)
        {
            char[] tablica = input.ToCharArray();
            Array.Reverse(tablica);
            int sum = 0;

            for (int i = 0; i < tablica.Length; i++)
            {
                if (tablica[i] == '1')
                {
                    if (i == 0)
                    {
                        sum += 1;
                    }
                    else
                    {
                        sum += (int)Math.Pow(2, i);
                    }
                }

            }

            return sum;
        }
        public static string DwoToHex(string binarna)
        {
            if (string.IsNullOrEmpty(binarna))
                return binarna;

            String result = "0x";// = new StringBuilder(binarna.Length / 8 + 1);
            int enumInt = 0;
            string bajt;
            
            Heks wynik = Heks.A;
            int mod4Len = binarna.Length % 8;
            if (mod4Len != 0)
            {
                binarna = binarna.PadLeft(((binarna.Length / 8) + 1) * 8, '0');
               // Console.WriteLine("bajt HEX " + binarna);
            }

            for (int i = 0; i < binarna.Length; i += 4)
            {
                bajt = binarna.Substring(i, 4);
                //result.AppendFormat("{0:X2}", Convert.ToByte(bajt, 2));

                if (bajt == "0000") enumInt = 0;
                else if (bajt == "0001") enumInt = 1;
                else if (bajt == "0010") enumInt = 2;
                else if (bajt == "0011") enumInt = 3;
                else if (bajt == "0100") enumInt = 4;
                else if (bajt == "0101") enumInt = 5;
                else if (bajt == "0110") enumInt = 6;
                else if (bajt == "0111") enumInt = 7;
                else if (bajt == "1000") enumInt = 8;
                else if (bajt == "1001") enumInt = 9;
                else if (bajt == "1010") enumInt = 10;
                else if (bajt == "1011") enumInt = 11;
                else if (bajt == "1100") enumInt = 12;
                else if (bajt == "1101") enumInt = 13;
                else if (bajt == "1110") enumInt = 14;
                else if (bajt == "1111") enumInt = 15;
                if (enumInt >= 10)
                {
                    wynik = (Heks)enumInt;
                 //   Console.WriteLine("wynik HEX " + wynik.ToString());
                    result += wynik.ToString();
                }
                else {
                  //  Console.WriteLine("bajt HEX " + bajt);
                    result += enumInt.ToString();
                }
                
            }
            return result.ToString();
        }

        public static string BinTo5(string bin)
        {
            if (string.IsNullOrEmpty(bin))
                return "pusto";
            if (bin == "0")
                return "0";
            
            int dec= BinToDec(bin);
            string  res = "";
            int mod;
            while(dec>0)
            {
                mod = dec % 5;
                dec /= 5;
                res += mod.ToString();
            }
            string wynik = "";
            for(int i= res.Length-1; i>=0; i--)
            {
                wynik += res[i];
            }

            return wynik;
        }

        static void Main(string[] args)
        {
            string x;
          //  Console.Write("Podaj liczbę BIN: ");
          //  x = Console.ReadLine();
            // Console.WriteLine("BinToDec: " + BinToDec(x));

            // Console.WriteLine("BinToOct: " + BinToOct(x));

            //  Console.WriteLine("DwoToHex: " + DwoToHex(x));

            //  Console.WriteLine("BinTo5: " + BinTo5(x));

             string[] l =
                 {
                     "1111010101","1001","1011","1100","1110","1101","1111","101010","0111010","10101010"
                 };
                 for (int i=0; i<l.Length; i++)
            {
                Console.WriteLine(" ========================== \n");
                Console.WriteLine("\n ====BinToDec====" + l[i]);
                Console.WriteLine("BinToDec: " + BinToDec(l[i]));

                Console.WriteLine("\n ====BinTo5====" + l[i]);
                Console.WriteLine("BinTo5: " + BinTo5(l[i]));
                Console.WriteLine(" ========================== \n");
            }

        }
    }
}
