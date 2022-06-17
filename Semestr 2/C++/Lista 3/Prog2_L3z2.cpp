#include<iostream>
#include<ctime>

//GOTOWE

using namespace std;

int znajdzNajwieksza(int t[]);
int znajdzNajmniejsza(int t[]);
double wyznaczSrednia(int t[]);
int podajWartosc(int t[], int poz);
void inicjujTab(int t[]);
void wczytajTab(int t[]);
int ileWiekszych(int t[], double s);

int main(){

int tab[15], poz;

srand(time(NULL));

inicjujTab(tab);

//wczytajTab(tab);

    cout << "\nKtórą pozycję podać? ";
    cin >> poz;

         
        cout << "\n Wartość z pozycji " << poz << ": "<<  podajWartosc(tab, poz);
        cout << "\n Wartość największa: "<< znajdzNajwieksza(tab);
        cout << "\n Wartość najmniejsza: "<<  znajdzNajmniejsza(tab);
        cout << "\n Wartość średnia: "<<  wyznaczSrednia(tab);
        double sr = wyznaczSrednia(tab);
        cout << "\n Ilość liczb większych od Wartość średnia: "<<  ileWiekszych(tab, sr);

cout << endl;
return 5;
}

int ileWiekszych(int t[], double s){
int suma = 0;
for (int i=0; i<15; i++){
    if ((double)t[i] > s) suma++;
  }
  return suma;
}

void wczytajTab(int t[]){
cout << "\n Podaj Elementy tablicy: \n";
for (int i=0; i<15; i++){
    cout << "\nPodaj element " << i << ": ";
    cin >> t[i];
  }
}

int znajdzNajwieksza(int t[]){
    int maks = t[0];
    for (int i=1; i<15; i++)
        if (maks < t[i]) maks = t[i];
    return maks;
}

int znajdzNajmniejsza(int t[]){
    int min = t[0];
    for (int i=1; i<15; i++)
        if (min > t[i]) min = t[i];
    return min;
}

double wyznaczSrednia(int t[]){
    int suma = 0;
    for (int i=0; i<15; i++)
        suma += t[i];
    return (double)suma/15;
}

int podajWartosc(int t[], int poz){
    return t[poz];
}

void inicjujTab(int t[]){
cout << "\n Elementy tablicy: \n";
for (int i=0; i<15; i++){
    t[i] = rand()%7;
    cout << i << ") " << t[i] << "    ";
    if ((i+1)%5 == 0) cout << endl;
  }
}
