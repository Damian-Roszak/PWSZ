#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string.h>

//#include <cstdio>
//#include <iomanip>

using namespace std;
typedef struct{
    int id;
    char imie[20];
    char nazwisko[20];
    int wiek;
    }tosoba;

int N;
tosoba inicjujTOsoba(int i);
void sortujTOsoba(tosoba T_tabOsoba[], int N);
void szukaj(tosoba T_tabOsoba[], int N);
void wyswietl(tosoba T_tabOsoba[], int N);
tosoba * usun(tosoba T_tabOsoba[], int N);

int main(){
srand(time(NULL));

cout << "\n Podaj N: ";
cin >> N;

tosoba *T_tabOsoba = new tosoba[N];

for (int i=0; i<N; i++){
    T_tabOsoba[i] = inicjujTOsoba(i);
}

cout << "\n\n T_tabOsoba[i]: ";
wyswietl( T_tabOsoba,  N);

szukaj( T_tabOsoba,  N);

sortujTOsoba( T_tabOsoba,  N);
cout << "\n\n T_tabOsoba[i] Po sortowaniu: ";
wyswietl( T_tabOsoba,  N);


T_tabOsoba = usun( T_tabOsoba,  N);
cout << "\n\n T_tabOsoba[i] Po usunięciu: ";
wyswietl( T_tabOsoba,  N+3);


delete[] T_tabOsoba;

cout << endl;
return 5;
}

// +++++++++++++++    FUNKCJE +++++++++++++++++

tosoba * usun(tosoba T_tabOsoba[], int N){

        tosoba *NewTab = new tosoba[N-1];
cout << "\n Podaj nazwisko do usunięcia: ";
string szukaneNazwisko;
cin >> szukaneNazwisko;

for (int i=0; i<N; i++){
    if (T_tabOsoba[i].nazwisko == szukaneNazwisko){
        tosoba tmp;
        for (int j=i; i<N-1; i++){
            tmp = T_tabOsoba[i];
            T_tabOsoba[i] = T_tabOsoba[i+1];
            T_tabOsoba[i+1] = tmp;
        }
        memcpy(NewTab, T_tabOsoba, (N-1)*sizeof(tosoba));
        delete[] T_tabOsoba;
        return NewTab;
    }
}
delete[] NewTab;
return T_tabOsoba;
}



void wyswietl(tosoba T_tabOsoba[], int N){
cout << "\n   id\t" << "imie\t" << "nazwisko " << " wiek\n";
for (int i=0; i<N; i++){
    cout << i+1 << ") " << T_tabOsoba[i].id << "\t " << T_tabOsoba[i].imie << "\t " << T_tabOsoba[i].nazwisko << " \t " << T_tabOsoba[i].wiek << "\n";
}
}


void szukaj(tosoba T_tabOsoba[], int N){

cout << "\n Podaj nazwisko do znalezienia: ";
string szukaneNazwisko;
cin >> szukaneNazwisko;

for (int i=0; i<N; i++){
    if (T_tabOsoba[i].nazwisko == szukaneNazwisko){
         cout << "znalezione:\n";
          cout << i+1 << ") " << T_tabOsoba[i].id << "\t " << T_tabOsoba[i].imie << "\t " << T_tabOsoba[i].nazwisko << " \t " << T_tabOsoba[i].wiek << "\n";
          break;
    }
}
}


void sortujTOsoba(tosoba T_tabOsoba[], int N){

tosoba tmp;
int licz=N; 
do{
    for(int i=0; i<N-1; i++)
    {
        //if ( T_tabOsoba[i].nazwisko > T_tabOsoba[i+1].nazwisko){
        if ( strcmp (T_tabOsoba[i].nazwisko , T_tabOsoba[i+1].nazwisko)>0){
            tmp = T_tabOsoba[i];
            T_tabOsoba[i] = T_tabOsoba[i+1];
            T_tabOsoba[i+1] = tmp;
        }
    }
licz--;
}while(licz>1);

}


tosoba inicjujTOsoba(int i){

tosoba *T_tabOsoba = new tosoba;
    T_tabOsoba->id = rand()%333;
    T_tabOsoba->imie[0] = rand()%26 + 65;
    T_tabOsoba->nazwisko[0] = rand()%26 + 65; 

    for (int im=1; im<5; im++){
     char *znak = new char (sizeof(char));
          *znak = rand()%26 + 97;
          strncat(T_tabOsoba->imie, znak, 1);         
    }
    for (int naz=1; naz<5; naz++){
      char *znak = new char (sizeof(char));
          *znak = rand()%26 + 97;
          strncat(T_tabOsoba->nazwisko, znak, 1); 
   }
   T_tabOsoba->wiek = rand()%333;
    std::cout << i+1 << ") " << T_tabOsoba->id << "\t " << T_tabOsoba->imie << "\t " << T_tabOsoba->nazwisko << " \t " << T_tabOsoba->wiek << "\n";

return *T_tabOsoba;
}
