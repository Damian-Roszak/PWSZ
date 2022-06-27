using System;
using System.Linq;
using System.Xml;
using System.Xml.Linq;

namespace ConsoleApplication1
{

    class Program
    {

        static void Main(string[] args)
        {
            string filename = @"C:\Users\Damian\Documents\NET\ConsoleApp1 Lista 8\osoby.xml";
            XmlTextWriter xtw = new XmlTextWriter(filename, System.Text.Encoding.UTF8);
            xtw.Formatting = Formatting.Indented;
            xtw.WriteStartDocument();
            xtw.WriteComment("Autor: Damian Roszak");
            xtw.WriteComment("Tworzę plik XML używając C#");

            xtw.WriteStartElement("Osoby");
            for (int i = 0; i < 500; i++)
            {
                xtw.WriteStartElement("Osoba");
                xtw.WriteElementString("id", i.ToString());

                xtw.WriteElementString("Imie", GenerujImie());
                xtw.WriteElementString("Nazwisko", GenerujNazwisko());

                xtw.WriteElementString("Wiek", GenerujWiek());

                xtw.WriteEndElement();
            }
            xtw.WriteEndElement();
            xtw.WriteEndDocument();
            xtw.Flush();
            xtw.Close();


            Sortuj(filename);
        }
        static void Sortuj(string FName)
        {
            XElement root = XElement.Load(FName);
            var orderedtabs = root.Elements("Osoba")
                .OrderBy(xtab => (int)xtab.Element("Wiek"))
                .ToArray();
            root.RemoveAll();
            foreach (XElement tab in orderedtabs)
                root.Add(tab);
            root.Save(@"C:\Users\Damian\Documents\NET\ConsoleApp1 Lista 8\posortowany.txt");
        }
        static string GenerujImie()
        {
            Random rnd = new Random();
            string[] Tab = { "Damian", "Piotr", "Marian", "Łukasz", "Dawid", "Daniel", "Dariusz", "Edward","Tadeusz"
            ,"Marianna", "Eustacha", "Halina", "Leukadia"};
            string Wynik = Tab[rnd.Next(Tab.Length)];
            return Wynik;
        }
        static string GenerujNazwisko()
        {
            Random rnd = new Random();
            string[] Tab = { "Skiba", "Pliszka", "Kowalski", "Nowak", "Zegar", "Żagań", "Warszawa", "Sobieski", "Jagiełło"
                    ,"Roszak", "Stalone", "BradPit", "Washington" };   
            string Wynik = Tab[rnd.Next(Tab.Length)];
            return Wynik;
        }
        static string GenerujWiek()
        {
            Random rnd = new Random();
            int tmp = rnd.Next(150);
            string Wynik = tmp.ToString();
            return Wynik;
        }
    }

}