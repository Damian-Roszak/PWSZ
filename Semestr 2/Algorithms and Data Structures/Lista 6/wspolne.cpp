#include "wspolne.hpp"
#include <fstream>


 
void zapis(string nazwa_alg, int rozm, int czas)
{
 string sciezka = "sort.txt";
 
 fstream wsk_plik;
 wsk_plik.open(sciezka, ios::out | ios::app);

    if (wsk_plik.good())
        //cout << "\n otworzyć pliku: "; 
         wsk_plik << "\n" << nazwa_alg << "   \t  " << rozm  << "    \t " << czas;
        
    else
         cout << "\n Nie udało się otworzyć pliku: " << sciezka;

wsk_plik.close(); 
}

void poka_R(vector <double> t)
{
    cout << "\n Pokazuje vector double: ";
    for(unsigned int i=0; i<t.capacity(); i++)
    {
        cout << "\n t["<<i<<"]="<< t[i];
    }
}


void poka_C(const vector <int> &t)
{
    cout << "\n Pokazuje vector całkowite: ";
    for(unsigned int i=0; i<t.capacity(); i++)
    {
        cout << "\n t["<<i<<"]="<< t[i];
    }
}

