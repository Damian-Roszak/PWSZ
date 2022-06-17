#include "Bib_L5.hpp"










int main()
{

  
  char koniec;
  int tryb, wymiar, stopienTrudnosci;
  
  vector< vector<char> > t;
    
        
  do
  {
    menuGlowne();
    wczytajTryb(tryb);
    
    menuWymiar();
    wczytajWymiar(wymiar);
    
    if(t.empty())
        inicjuj_plansze(t, wymiar);
    else
    {
        t.clear();
        inicjuj_plansze(t, wymiar);
    }
    
    if (tryb == 1)
    {
        graj(t, wymiar);
    }
    
    if (tryb == 2)
    {
        menuStopienTrudnosci();
        wczytajStopienTrudnosci(stopienTrudnosci);
        graj_VS_CPU(t, wymiar, stopienTrudnosci);
    }
    
    if (tryb == 3)
    {
        menuStopienTrudnosci();
        wczytajStopienTrudnosci(stopienTrudnosci);
        CPU_VS_CPU(t, wymiar, stopienTrudnosci);
    }
   
    
    
    cout << "\nJeszcze raz ? (T = TAK) : ";
    cin >> koniec;
    cout << "\n";
  } while((koniec == 'T') || (koniec == 't'));
  
return 5;
}
