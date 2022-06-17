#include<iostream>
#include<ctime>
#include <limits>

// GOTOWE

using namespace std;

int N, wymiar;
int sumaPowyzej(int **, int wymiar);
int sumaPonizej(int **, int wymiar);
int sumaWybrana(int **t, int wymiar, char c, int wk);
void wypiszTab(int **, int wymiar);

int podajWartosc(int **t, int poz);
void inicjujTab(int **, int wymiar);
void wczytajTab(int **t, int wymiar);
void sumaPrzek(int **t, int wymiar);
void usun(int **t, int wymiar);

int main(){

/*
    char opcja=' ';
while (opcja != 'k' && opcja != 'K'){ 
        cout << "\n\t ++++ Zadanie 3 ++++\n";
        cout << "\t 1) Funkcja\n";
        cout << "\t 2) Funkcja\n";
        cout << "\t 3) Funkcja\n";
	    cout << "\t k/K) Koniec \n";
        cout << "\n Podaj opcje: ";  
	    cin >> opcja;	   
	    if (opcja == '1')  Funkcja;
	    if (opcja == '2')  Funkcja;	    
	    if (opcja == '3')  Funkcja;	        
	    if (opcja == '4')  Funkcja;
    }

*/
char k;
srand(time(NULL));
do{
    char poz;

    cout << "\nPodaj wymiar macierzy maksymalnie " << numeric_limits<int>::max() << " : ";
    cin >> N;
    int wk;
    int **tab = new int*[N];
    for (int i=0; i<N; i++)
        tab[i] = new int[N];

wczytajTab(tab, N);
//inicjujTab(tab, N);
wypiszTab(tab, N);

 do{
    cout << "\nSumę obliczyć w wierszu (w) czy w kolumnie?[w lub k]: ";
    cin >> poz;
 }while (poz != 'w' && poz != 'k');
 
do{
    cout << "\no numerze: ";
    cin >> wk;
}while (wk<0 || wk >= N);
     
    cout << "\n Wartość sumy poniżej przekątnej: " <<  sumaPonizej(tab, N);
    wypiszTab(tab, N);
    cout << "\n Wartość sumy powyżej przekątnej: "<< sumaPowyzej(tab, N);
    wypiszTab(tab, N);

    if(poz == 'w')
        cout << "\n Wartość sumy w wskazanym " << wk <<" wierszu: "<<  sumaWybrana(tab, N, poz, wk);
    else
        cout << "\n Wartość sumy w wskaznej " << wk <<" kolumnie: "<<  sumaWybrana(tab, N, poz, wk);


    wypiszTab(tab, N);

    sumaPrzek(tab, N);
    usun(tab, N);
    cout << "\n Zakończyć?[t]: ";
    cin >> k;

}while(k != 't');
cout << endl;

return 5;
}

void usun(int **t, int wymiar) {

    for (int i=0; i<N; i++)
         delete[] t[i];
    
    delete[] t;
}

void sumaPrzek(int **t, int wymiar){
     cout << endl;
     int suma = 0;
    for (int i=0; i<wymiar; i++)
    {
        for (int j=0; j<wymiar; j++)
        {
            if (i==j){
                suma += t[i][j];
            }
        }   
    }
    cout << "\n suma na przekątnej wynosi: " << suma <<endl;
}

void wypiszTab(int **t, int wymiar){
    cout << "\n Elementy tablicy: \n";
    for (int i=0; i<wymiar; i++){
    for (int j=0; j<wymiar; j++){
        cout << "["<< i << ',' << j << "]: " << t[i][j] << "  ";
      }
        cout << endl;
      }
}  

void wczytajTab(int **t, int wymiar){
    cout << "\n Podaj Elementy tablicy: \n";
    for (int i=0; i<wymiar; i++)
    {
        for (int j=0; j<wymiar; j++){
          cout << "\nPodaj element [" << i << ',' << j << "]: ";
           cin >> t[i][j];
        }
    }
}

int sumaPowyzej(int **t, int wymiar){
    int suma = 0;
    for (int i=0; i<wymiar; i++)
    {
        for (int j=0; j<wymiar; j++){
             if(j>i)
             suma += t[i][j];
        }
    }
    return suma;
}

int sumaPonizej(int **t, int wymiar){
    int suma = 0;
    for (int i=0; i<wymiar; i++)
    {
        for (int j=0; j<wymiar; j++){
             if(i>j) 
             suma += t[i][j];
        }
    }
    return suma;
}


int sumaWybrana(int **t, int wymiar, char c, int wk){
    int suma = 0;
  if(c == 'w')
      for (int j=0; j<wymiar; j++){
         suma += t[wk][j];
     }
   else
    for (int i=0; i<wymiar; i++){
         suma += t[i][wk];
    }
    return suma;
}

void inicjujTab(int **t, int wymiar){
    for (int i=0; i<wymiar; i++)
    {
        for (int j=0; j<wymiar; j++)
        {
          t[i][j] = rand()%9;
        }
    }
}
