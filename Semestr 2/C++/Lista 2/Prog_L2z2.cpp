#include<iostream>

int main(){
using namespace std;

cout << " Ile ocen chcesz podać: ";
int n;
cin >> n;

double suma=0, sr, ocena;
for (int i=1; i<=n; i++){
    do {
     cout  << " Podaj ocenę " << i << ": ";
      cin >> ocena;
    }while(ocena <2 || ocena >5);
    suma += ocena;
}

sr = suma / n;

cout << endl << " Średnia wynosi: " << sr;
if (sr > 4.1) cout << " możesz ubiegać sie o stypendium naukowe";

cout << endl;
return 5;
}
