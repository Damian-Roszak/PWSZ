#include<iostream>
#include<string>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include <fstream>

using namespace std;

struct lista{ 
    struct lista *pop, *nast;
    string imie;
    string nazwisko;
    string PESEL;
    int wiek;
};

void zrobElem(lista **l, lista **k);
void poka(lista *l);
void naglowek();
void czyscListe(lista **l);
void pokaRewers(lista *l);
lista* zrobElemStosu();
void zapisz_liste_do_pliku(lista *l, string sciezka);
void usun_Po_Nazwisku(lista **p, lista **k);
void pokazElem(lista *l);
void usun_Po_Nazwisku_wszystkie(lista **p, lista **k);
void edytuj_elem(lista **p);
void wyszukaj_wg_klucza(lista *p);

int main(){

 srand(time(NULL));
lista *Baza = NULL;
lista *Kooniec = NULL;

for(int i=0; i<7; i++) zrobElem(&Baza, &Kooniec);

 char opcja=' ';
    string sciezka = "lista_dwukierunkowa.txt";
    
    while (opcja != 'k' && opcja != 'K'){         
        cout << "\n\t ++++ Lista Dwukierunkowa ++++\n";
        cout << "\t 1) Dodaj element \n";
        cout << "\t 2) usun_Po_Nazwisku \n";
        cout << "\t 3) usun_Po_Nazwisku_wszystkie\n";
        cout << "\t 4) Wyszukaj wg klucza użytkownika\n";
        cout << "\t 5) Pokaż \n";
        cout << "\t 6) edytuj element\n";
        cout << "\t 7) Zapisz Listę do pliku " << sciezka <<"\n";
        cout << "\t 8) Pokaż od końca\n";
	    cout << "\t k/K) Koniec \n";
        cout << "\n Podaj opcje: ";  
	    cin >> opcja;	   
	    if (opcja == '1')  zrobElem(&Baza, &Kooniec);
	    if (opcja == '2')  usun_Po_Nazwisku(&Baza, &Kooniec);
	    if (opcja == '3')  usun_Po_Nazwisku_wszystkie(&Baza, &Kooniec);
	    if (opcja == '4')  wyszukaj_wg_klucza(Baza);
	    if (opcja == '5')  poka(Baza);
	    if (opcja == '6')  edytuj_elem(&Baza);
	    if (opcja == '7')  zapisz_liste_do_pliku(Baza, sciezka);
	    if (opcja == '8')  pokaRewers(Kooniec);		    
    }


czyscListe(&Baza);
return 5;
}
//=+=+=+=+==+=+=+==+ FUNKCJE +=+==+=+=+=+=+=+

void edytuj_elem(lista **p){
if(*p){
poka(*p);
lista *edyt = *p;
string szukane;
cout << "\n Podaj PESEL do wyszukania elementu do edycji: ";
cin >> szukane;
      while(edyt){
	      if(edyt->PESEL==szukane){
	          pokazElem(edyt);
	          cout << "\n Podaj nowe imie: ";
	          cin >> edyt->imie;
	          cout << "\n Podaj nowe nazwisko: ";
	          cin >> edyt->nazwisko;
	          cout << "\n Podaj nowy PESEL: ";
	          cin >> edyt->PESEL;
  	          cout << "\n Podaj nowy wiek: "; 
 	          cin >> edyt->wiek;	
	      }        
	   edyt=edyt->pop;
	  }
poka(*p);
}
}

void wyszukaj_wg_klucza(lista *p){
if(p){
lista *szuk = p;
string szukane;
int lata;
char opcja;
        cout << "\n\t ++++ Wyszukiwanie wg klucza: ++++\n";
        cout << "\t i) Imię \n";
        cout << "\t n) Nazwisko \n";
        cout << "\t p) PESEL\n";
        cout << "\t w) wiek\n";
        cout << "\t Podaj klucz wg którego chcesz szykać: ";
	    cin >> opcja;	   
	    if (opcja == 'i') {
	        cout << "\n Podaj imię do wyszukania: ";
	        cin >> szukane;
	        naglowek();
	        while(szuk){
	            if(szuk->imie==szukane)
	                pokazElem(szuk);
	            szuk=szuk->pop;
	        }
	    }
	    if (opcja == 'n') {	    
	        cout << "\n Podaj nazwisko do wyszukania: ";
	        cin >> szukane;
	        naglowek();
	        while(szuk){
	            if(szuk->nazwisko==szukane)
	                pokazElem(szuk);
	            szuk=szuk->pop;
	        }
	    }
	    if (opcja == 'p') {
	        cout << "\n Podaj PESEL do wyszukania: ";
	        cin >> szukane;
	        naglowek();
	        while(szuk){
	            if(szuk->PESEL==szukane)
	                pokazElem(szuk);
	            szuk=szuk->pop;
	        }
	    }
	    if (opcja == 'w') {
	        cout << "\n Podaj nazwisko do wyszukania: ";
	        cin >> lata;
	        naglowek();
	        while(szuk){
	            if(szuk->wiek==lata)
	                pokazElem(szuk);
	            szuk=szuk->pop;
	        }
	    }
}
}


void usun_Po_Nazwisku_wszystkie(lista **p, lista **k){
 cout << "\n Usuń po Nazwisku: ";
   if(*p != NULL){
    lista *tmp, *licznik =*p;
    string wzor = "Covid";
        while(licznik){
            cout << "\n while";
            if(licznik->nazwisko==wzor) {
                tmp=licznik;
             cout << "\n tmp: "; pokazElem(tmp);
                    if(!licznik->nast && !licznik->pop){
                         cout << "\n if(!licznik->nast && !licznik->pop)";
                         *p=NULL;
                         *k=NULL;
                         licznik=NULL;
                         delete tmp;
                    }else if (!licznik->nast){
                         cout << "\n !licznik->nast";
                         *p=licznik->pop;
                         licznik->pop->nast = NULL;
                         delete tmp;
                         licznik = *p;
                    }else if (licznik->nast && licznik->pop){
                         cout << "\n licznik->nast && licznik->pop";
                         licznik->nast->pop = licznik->pop;
                         licznik->pop->nast = licznik->nast;
                         licznik = licznik->nast;
                         delete tmp;
                    }else if(!licznik->pop){
                        cout << "\n !licznik->pop";
                        licznik->nast->pop = NULL;
                        licznik = licznik->nast;
                        delete tmp;
                     }          
            }else
                 licznik=licznik->pop; 
        }
   }
poka(*p);
}

/*
void usun_Po_Nazwisku_wszystkie(lista **p, lista **k){
 cout << "\n Usuń po Nazwisku: ";
   if(*p != NULL){
    lista *tmp, *licznik =*p;
    string wzor = "Covid";
        while(licznik){
            cout << "\n while";
            if(licznik->nazwisko==wzor) {
                tmp=licznik;
                    if(!licznik->nast && !licznik->pop){
                            *p=NULL;
                            *k=NULL;
                            licznik =*p;
                            cout << "\n if(!licznik->nast && !licznik->pop)";
                    }else if (!licznik->nast){
                            licznik->pop->nast = NULL;
                            *p=licznik->pop;
                            licznik =*p;
                            cout << "\n (!licznik->nast)";
                    }else if (!licznik->pop){
                            licznik->nast->pop = NULL;
                            *k=licznik->nast;
                            licznik =*p;
                            cout << "\n (!licznik->pop)";
                    }else{
                         //licznik->nast->pop = licznik->pop;
                       //  licznik->pop->nast = licznik->nast;
                         licznik =*p;
                            cout << "\n else";
                     }
                delete tmp;            
            }
               // licznik=(*p)->pop; 
        }
   }
poka(*p);
}


void usun_Po_Nazwisku_wszystkie(lista **p, lista **k){
 cout << "\n Usuń po Nazwisku: ";
   if(*p != NULL){
    lista *tmp, *licznik =*p, flaga;
    string wzor = "Covid";
        while(licznik){
            if(licznik->nazwisko==wzor) {
                tmp=licznik;
                    if(!licznik->nast && !licznik->pop){
                            *p=NULL;
                            *k=NULL;
                    }else if (!licznik->nast){
                            licznik->pop->nast = NULL;
                            *p=licznik->pop;
                    }else if (!licznik->pop){
                            licznik->nast->pop = NULL;
                            *k=licznik->nast;
                    }else{
                         licznik->nast->pop = licznik->pop;
                         licznik->pop->nast = licznik->nast;
                     }
              licznik = licznik->pop;       
                delete tmp;
            }
        }
   }
poka(*p);
}*/

void usun_Po_Nazwisku(lista **p, lista **k){
 cout << "\n Usuń po Nazwisku: ";
   if(*p != NULL){
    lista *tmp, *licznik =*p;
    string wzor = "Covid";
        while(licznik){
            if(licznik->nazwisko==wzor) {
                tmp=licznik;
                    if(!licznik->nast && !licznik->pop){
                            *p=NULL;
                            *k=NULL;
                    }else if (!licznik->nast){
                            licznik->pop->nast = NULL;
                            *p=licznik->pop;
                    }else if (!licznik->pop){
                            licznik->nast->pop = NULL;
                            *k=licznik->nast;
                    }else{
                         licznik->nast->pop = licznik->pop;
                         licznik->pop->nast = licznik->nast;
                     }
                delete tmp;
                break;
            }
            licznik=licznik->pop;
        }
   }
poka(*p);
}


void pokazElem(lista *l){
if(l){
//cout << "\n Pokaż Elem: \n";
    lista *wsk = l;    
   // naglowek();    
       cout << " " << wsk->imie;
	   cout << "  \t  " << wsk->nazwisko;
       cout << "  \t  " << wsk->PESEL; 
	   cout << "  \t  " << wsk->wiek;       
       cout << "\n";
 }
}

void zapisz_liste_do_pliku(lista *l, string sciezka){
lista *wsk = l;
poka(l);
 fstream wsk_plik;
 wsk_plik.open(sciezka, ios::out | ios::app);

    if (wsk_plik.good())
     while (wsk != NULL){ 
        wsk_plik << wsk->imie << "   \t  " << wsk->nazwisko  << "    \t " << wsk->PESEL << "  \t  " << to_string(wsk->wiek) << "\n";
         wsk=wsk->pop;
     }  
    else
       cout << "\n Nie udało się otworzyć pliku: " << sciezka;

wsk_plik.close(); 
}

void pokaRewers(lista *l){
if(l){
cout << "\n Wyświetlanie od końca:\n"; 
    lista *p = l;
   naglowek();
      int i = 1;
    while(p){
       cout << i << ")";
       cout << "  \t " << p->imie;
       cout << "  \t " << p->nazwisko;
       cout << "  \t " << p->PESEL;
       cout << "  \t " << p->wiek;
       p=p->nast;
       cout << endl;
       i++; 
    }
cout << endl;
}
}

void czyscListe(lista **l){    
if(*l){
    while(*l){
        //pokazElem(*l);
        lista *temp=*l;
        *l=(*l)->pop;
        delete temp;
    }
 }
}

void poka(lista *l){
cout << "\n Wyświetlanie od początku:\n"; 
if(l){ 
    lista *p = l;
   naglowek();
      int i = 1;
    while(p){
       cout << i << ")";
       cout << "  \t " << p->imie;
       cout << "  \t " << p->nazwisko;
       cout << "  \t " << p->PESEL;
       cout << "  \t " << p->wiek;
       p=p->pop;
       cout << endl;
       i++; 
    }
cout << endl;
} 
}

void zrobElem(lista **l, lista **k){
    lista *nowy = zrobElemStosu();
if(*l){
     nowy->pop=NULL;
     nowy->nast=*k;
     (*k)->pop=nowy;
     *k=nowy;  
}else{    
     nowy->pop=nowy->nast=NULL;
     *l=nowy;
     *k=nowy;     
    }
    
}


lista* zrobElemStosu(){
    lista *nowy = new lista;
    char tempZnak;
    int wyznacznik = rand()%5;
    
    tempZnak = rand()%26+65;
    nowy->imie = nowy->imie + tempZnak;
        for (int j=0; j<5; j++){
            tempZnak = rand()%26+97;
             nowy->imie = nowy->imie + tempZnak;             
        }    
    
    if (wyznacznik==0){             
    tempZnak = rand()%26+65;
    nowy->nazwisko = nowy->nazwisko + tempZnak;
        for (int j=0; j<5; j++){
            tempZnak = rand()%26+97;
             nowy->nazwisko = nowy->nazwisko + tempZnak;             
        }
    }
    else if(wyznacznik==1){nowy->nazwisko = "Covid";}
        else if(wyznacznik==2){nowy->nazwisko = "Dawid";}
            else if(wyznacznik==3){nowy->nazwisko = "Edward";}
                else if(wyznacznik==4){nowy->nazwisko ="Felix"; }
                 else if(wyznacznik==5){nowy->nazwisko = "Genowefa";}    
  //nowy->nazwisko = "Covid";    
        
    nowy->wiek = rand()%99;                        
   for (int j=0; j<12; j++) nowy->PESEL = nowy->PESEL + to_string(rand()%10);
return nowy;   
}

void naglowek(){
    cout << "\n \t IMIE   \t NAZWISKO   \t  PESEL  \t WIEK \t\n"; 
}

