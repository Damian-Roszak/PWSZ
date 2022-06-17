#include "Bib_Prog2_Lista_4_zad_2.hpp"

int main(){

char opcja;
int N;
vector<vector<int>> m1;
vector<vector<int>> m2;
vector<vector<int>> m3;

    cout << "\n+++++++++ Zad 2 +++++++++++ ";
      wczytaj_macierze(N, m1, m2);
do{

    cout << "\n+++++++++ Zad 2 MENU +++++++++++ ";
    
     
    cout << "\n1) Dodaj ";
    cout << "\n2) Odejmij ";
    cout << "\n3) Pomnóż ";
    cout << "\n4) Większa mniejsza ";
    cout << "\nk) Zakończ ";
    cout << "\nWybieram opcje: ";
    
            cin >> opcja;
     
   if(opcja!='k' && opcja!='K')
   {
 
        if(opcja=='1')
        {       
            m3 = opcja1(N, m1, m2);
            cout << "\n Wynik dodawania macierzy: ";
            poka_macierz(N, m3);
        }
       
        if(opcja=='2') 
        {
            m3 = opcja2(N, m1, m2);
            cout << "\n Wynik odejmowania macierzy: ";
            poka_macierz(N, m3);
        }
        
        if(opcja=='3')
        {
            m3 = opcja3(N, m1, m2);
            cout << "\n Wynik mnożenia macierzy: ";
            poka_macierz(N, m3);
        }
        
        if(opcja=='4')
        {            
            cout << "\n Wynik porównania macierzy: ";
            m3 = wieksza_mniejsza(N, m1, m2);
            poka_macierz(N, m3);
        }
        
   }


}while(opcja!='k' && opcja!='K');
cout << endl;
return 5;
}
