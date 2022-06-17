#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string.h>

using namespace std;

int N=10;

void inicjujTab1(int tab[], int rozmiar);
void index(int a[], int *b[], int rozmiar);
void index2(int a[], int *b[], int rozmiar);
void pokaz(int *b[], int rozmiar);
void pokaz2(int b[], int rozmiar);

int main(){
srand(time(NULL));

int tab1[N];
int* tab2[N];
//int* tab3[N];


inicjujTab1( tab1,  N);
index( tab1, tab2, N);
pokaz(tab2, N);
pokaz2(tab1, N);

cout << endl;
return 5;
}

// +++++++++++++++    FUNKCJE +++++++++++++++++


void index(int a[], int *b[], int rozmiar){
    for (int i = 0; i<rozmiar; i++){
             b[i] = &a[i];
    }
    
int licz=rozmiar; 
 int *tmp;
do{
    for (int i = 0; i<rozmiar-1; i++){
         if (*b[i] > *b[i+1]) {        
            tmp = b[i];
            b[i] = b[i+1];
            b[i+1] = tmp;
         }
    }
licz--;
}while(licz > 0);

}

void pokaz(int *b[], int rozmiar){
cout << endl <<  "pokaz wskażniki na int\t ";
    for (int i = 0; i<rozmiar; i++)
    {
        cout << *b[i] << ' ';
    };
}

void pokaz2(int b[], int rozmiar){
cout << endl <<  "pokaz tablica całkowitych\t ";
    for (int i = 0; i<rozmiar; i++)
    {
        cout << " " << b[i];
    };
}

void inicjujTab1(int tab[], int rozmiar){
cout << endl << "inicjuj tab całkowitych\t ";
    for(int i=0; i<rozmiar; i++){
        tab[i] = rand()%56;
        cout << tab[i] << ' ';
    }
}

