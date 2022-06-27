using System;

using System.Xml;

namespace ConsoleApplication1
{

    class Program
    {

        static void Main(string[] args)
        {

            // Inicjujemy obiekt System.XML.XmlTextReader. Musimy podać ścieżkę do pliku XML

            XmlTextReader xtr = new XmlTextReader("filmy.xml");

            // Po utworzeniu obiektu wskaźnik umieszczany jest przed pierwszą linią pliku.

            // Za każdym razem kiedy wywołujemy metodę Read() zwraca prawdę gdy pobierze fragment dokumentu a fałsz gdy się nie uda.

            // Fragment ten odpowiada jednemu węzłowi z struktury dokumentu.

            while (xtr.Read())
            {

                // Zwracamy typ węzła pod (NodeType) jego nazwę (Name) i wartość (Value)

                Console.WriteLine(xtr.NodeType.ToString() + ":" + xtr.Name + ":" + xtr.Value);

                // Sprawdzamy czy odczytany węzeł posiada atrybuty (Metoda HasAttributes())

                if (xtr.HasAttributes)
                {

                    // Zmienna AttributeCount to ilość atrybutów w węźle (o ile je posiada)

                    for (int i = 0; i < xtr.AttributeCount; i++)
                    {

                        // Tu następuje odwołanie się do atrybutów (MoveToAttribute(i)). Wartość i to indeks atrybutu

                        xtr.MoveToAttribute(i);

                        // Wyświetlamy Własności węzłów

                        Console.WriteLine(xtr.NodeType.ToString() + ":" + xtr.Name + ":" + xtr.Value);

                    }

                    // Powrót do aktualnego węzła

                    xtr.MoveToElement();

                }

            }

            Console.ReadKey();

        }

    }

}