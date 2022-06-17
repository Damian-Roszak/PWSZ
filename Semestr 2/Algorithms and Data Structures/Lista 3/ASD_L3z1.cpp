#include<iostream>
#include<string>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include <fstream>

using namespace std;

struct lista{ 
    struct lista *pocz;
    string imie;
    string nazwisko;
    string PESEL;
    int wiek;
};

void dodajNaStos(lista **l);
lista* zrobElemStosu();
void zdejmZStosu(lista **l);
void pokazStos(lista *l);
void zapiszStosDoPliku(lista *Stos, string sciezka);
void naglowek();
void pokazElem(lista *l);


int main(){

 srand(time(NULL));
    char opcja=' ';
    string sciezka = "stos.txt";
    lista *Stos=NULL;
    
    while (opcja != 'k' && opcja != 'K'){ 
        cout << "\n\t ++++ Stos ++++\n";
        cout << "\t 1) Dodaj element na stos\n";
        cout << "\t 2) Usuń element z stosu\n";
        cout << "\t 3) Pokaż stos\n";
        cout << "\t 4) Zapisz stos do pliku " << sciezka <<"\n";
	    cout << "\t k/K) Koniec \n";
        cout << "\n Podaj opcje: ";  
	    cin >> opcja;	   
	    if (opcja == '1')  dodajNaStos(&Stos);
	    if (opcja == '2')  zdejmZStosu(&Stos);	    
	    if (opcja == '3')  pokazStos(Stos);	        
	    if (opcja == '4')  zapiszStosDoPliku(Stos, sciezka);
	   //stdin = freopen(NULL, "r", stdin);  
    }

if (Stos)
     while (Stos){
         zdejmZStosu(&Stos);
     }
     
return 5;
}


// ++++++++++++++++    FUNKCJE +++++++++++++++++++++++++++

void zapiszStosDoPliku(lista *l, string sciezka){
 lista *wsk = l;
 fstream wsk_plik;
 wsk_plik.open(sciezka, ios::out | ios::app);

    if (wsk_plik.good())
     while (wsk != NULL){ 
        wsk_plik << wsk->imie << "  \t " << wsk->nazwisko << "  \t " << to_string(wsk->wiek) << "  \t " << wsk->PESEL  << "\n";
         wsk=wsk->pocz;
     }  
    else
       cout << "\n Nie udało się otworzyć pliku: " << sciezka;

wsk_plik.close();   
}

void pokazStos(lista *l){    
   lista *wsk = l;    
   naglowek();
      int i = 1;
    while (wsk != NULL){
    cout << i << ")";
       cout << wsk->imie;
	   cout << "  \t " << wsk->nazwisko;
	   cout << "  \t " << wsk->wiek;
       cout << "  \t " << wsk->PESEL;        
       cout << "\n";
       wsk=wsk->pocz;
       i++; 
    }
//   cout << "\n";
}

void zdejmZStosu(lista **l){
    if(*l){
        lista *temp=*l;
        *l =(*l)->pocz;
        cout << "\n Usuwam następujący element: \n";
        pokazElem(temp);
        delete temp;
    }
    else {
        cout << "\n Brak Stosu w pamięci \n";
         //(*l)=NULL;
        }
}


void dodajNaStos(lista **l){
    //lista *nowy=new lista;  === NIE INICJALIZUEJE SIĘ TAK ŻE DO NOWO-ZAALOKOWANEJ PAMIĘCI PRZYPISUJE SIĘ DRUGĄ NOWO-ZALAOKOWANĄ PAMIĘĆ = FUNKCJĄ PONIŻEJ.
    lista *nowy=zrobElemStosu();
    pokazElem(nowy);
    nowy->pocz=*l;
    *l=nowy;
}

lista* zrobElemStosu(){
    lista *nowy = new lista;
    char tempZnak;
    tempZnak = rand()%26+65;
    nowy->imie = nowy->imie + tempZnak;
        for (int j=0; j<5; j++){
            tempZnak = rand()%26+97;
             nowy->imie = nowy->imie + tempZnak;             
        }
    tempZnak = rand()%26+65;
    nowy->nazwisko = nowy->nazwisko + tempZnak;
        for (int j=0; j<5; j++){
            tempZnak = rand()%26+97;
             nowy->nazwisko = nowy->nazwisko + tempZnak;             
        }
    nowy->wiek = rand()%99;                        
   for (int j=0; j<12; j++) nowy->PESEL = nowy->PESEL + to_string(rand()%10);
return nowy;   
}

void pokazElem(lista *l){
    lista *wsk = l;    
    naglowek();
    //while (wsk != NULL){
    
       cout << " " << wsk->imie;
	   cout << "  \t  " << wsk->nazwisko;
	   cout << "  \t  " << wsk->wiek;
       cout << "  \t  " << wsk->PESEL;        
       cout << "\n";
      //  wsk=wsk->next;
   // }
   cout << "\n";
}

void naglowek(){
    cout << "\n  IMIE  \t  NAZWISKO \t WIEK \t PESEL \t\n"; 
}
