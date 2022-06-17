#include "Bib_Prog2_Lista_4.hpp"

 

vector<int> wczytaj_ile_liczb(){
 
        vector<int> zwracany;

    int rozm = rand()%23;
    int liczba;
    for (int i=0; i<rozm; i++)
    { 
        liczba = rand()%320;
        if(czy_byla(liczba,zwracany, zwracany.size() )==false)
        {
            zwracany.push_back(liczba);
        }
        else 
            i--;
    }
    pokaz(zwracany);
 
/*
        int ile_liczb, liczba;  
      cout << "\n Podaj ile liczb chcesz wczytać: ";
      cin >> ile_liczb;  
   
     for (int i=0; i<ile_liczb; i++)
     { 
        cout << "\n Podaj liczbę "<< i <<"-tą: ";
        cin >> liczba;  
        if(czy_byla(liczba,zwracany, zwracany.size() )==false)
        {
            zwracany.push_back(liczba);
        }
        else 
            i--;
     }   
   */
return zwracany;
}

bool czy_byla( int iLiczba, vector<int> wek, int ile )
{
    if( ile <= 0 )
         return false;   
    
    for(int i = 0; i < ile; i++)
    {
        if( wek[i] == iLiczba )
             return true;
    }   
    return false;
}

void pokaz(vector<int> lol){
    
    for(unsigned int i = 0; i < lol.size(); i++){
          cout<<"vec["<<i<<"]="<<lol[i]<<endl;
     }
}

vector<int> min_max(vector<int> param){

    vector<int> zwrot;
     zwrot.push_back(param.front());
     zwrot.push_back(0); 
        zwrot.push_back(param.front());
        zwrot.push_back(0); 
        
    for (unsigned int i = 1; i < param.size(); i++){
        if(zwrot[0] > param[i]) {
               zwrot[0] = param[i];
               zwrot[1] = i;
        }
        if(zwrot[2] < param[i]){
                 zwrot[2] = param[i];
               zwrot[3] = i;
        }
    }
return zwrot;
}


double srednia(vector<int> lol){
    double sr = 0;
    
    for(unsigned int i = 0; i < lol.size(); i++){
          sr += lol[i];
     }

return sr/lol.size();
}

int poz_wart(vector<int> lol, int w){

    int p, flaga = 0; //rand()%23
    //cout<<"\n Podaj wartość której pozycje chcesz poznać: ";
    //cin >> p;
     for(unsigned int i = 0; i < lol.size(); i++){
          if(lol[i] == w) {
            p=i;
            flaga++;
          }
     }
     
     if(flaga==0){
                 cout << "\n Brak podanej wartości w zbiorze. " << endl; 
                 return -1;
                 }   
     else 
        cout << "Pozycja wartości: "<< w << " to: "<< p << endl;
return p;
}

