//#include <iostream>
//#include <vector> 
#include "Bib_Prog2_Lista_4.hpp"

using namespace std;

int main(){

 srand(time(NULL));
 vector<int> zwracany2;
 vector<int> lol;
  
 
lol = wczytaj_ile_liczb();
    
zwracany2 = min_max(lol);
       
      
      cout << "\n min wynosi: " << zwracany2[0] << " na pozycji: " << zwracany2[1];
      cout << "\n max wynosi: " << zwracany2[2] << " na pozycji: " << zwracany2[3];
      cout << "\n średnia wynosi: " << srednia(lol);
      cout << "\n Jaką wartość chcesz odnaleść?: ";
   
           int wart;
           cin >> wart;
        poz_wart(lol, wart);
        
cout<<endl;
 return 5;
}

