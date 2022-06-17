#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string.h>

typedef struct{
    int id;
    char imie[20];
    char nazwisko[20];
    int wiek;
    }tosoba;

int N;
tosoba inicjujTOsoba(int i);

int main(){
using namespace std;
srand(time(NULL));


cout << "\n Podaj N: ";
cin >> N;

tosoba *T_tabOsoba = new tosoba[N];

for (int i=0; i<N; i++){
    T_tabOsoba[i] = inicjujTOsoba(i);
}

cout << "\n\n T_tabOsoba[i]: ";
cout << "\n   id\t" << "imie\t" << "nazwisko " << " wiek\n";
for (int i=0; i<N; i++){
    cout << i << ") " << T_tabOsoba[i].id << "\t " << T_tabOsoba[i].imie << "\t " << T_tabOsoba[i].nazwisko << " \t " << T_tabOsoba[i].wiek << "\n";
}


delete[] T_tabOsoba;

cout << endl;
return 5;
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
