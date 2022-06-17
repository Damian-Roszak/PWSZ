#include<iostream>
#include<string>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include <fstream>

using namespace std;

struct lista{ 
    struct lista *pocz, *kon;
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

int dodaj(lista **k, lista **p);
void poka(lista *p);
void pokaKon(lista *p);
void zdejm(lista **p, lista **k);
void zdejmWszystkie(lista **p, lista **k);
void zapiszKolejkeDoPliku(lista *l, string sciezka);
void zapisz_do_pliku_po_sortowaniu(lista **p, lista **k, string sciezka);
void usun_Po_Imieniu(lista **p, lista **k);
void sortuj(lista **p, lista **k, string wzor);

int main(){

 srand(time(NULL));
    char opcja=' ';
    string sciezka = "kolejka.txt";
    lista *Stos=NULL;
    lista *wierzch=NULL, *koniec=NULL;//, *Kolejka=NULL;
           
    
    while (opcja != 'k' && opcja != 'K'){         
        cout << "\n\t ++++ Kolejka ++++\n";
        cout << "\t 1) Dodaj element \n";
        cout << "\t 2) zdejm(&wierzch); \n";
        cout << "\t 3) poka(wierzch);\n";
        cout << "\t 4) Usuń Wszystkie(wierzch);\n";
        cout << "\t 5) zapisz_do_pliku_po_sortowaniu(wierzch);" << sciezka <<"\n";
        cout << "\t 6) Usuń po imieniu;\n";
       // cout << "\t 7) Zapisz Kolejkę do pliku " << sciezka <<"\n";
     //   cout << "\t 8) pokaKon(koniec);\n";
      //  cout << "\t 9) sortuj;\n";
	    cout << "\t k/K) Koniec \n";
        cout << "\n Podaj opcje: ";  
	    cin >> opcja;	   
	    if (opcja == '1')  dodaj(&koniec, &wierzch);
	    if (opcja == '2')  zdejm(&wierzch, &koniec);
	    if (opcja == '3')  poka(wierzch);
	    if (opcja == '4')  zdejmWszystkie(&wierzch, &koniec);
	    if (opcja == '5')  zapisz_do_pliku_po_sortowaniu(&wierzch, &koniec, sciezka);
	    if (opcja == '6')  usun_Po_Imieniu(&wierzch, &koniec);
	  //  if (opcja == '7')  wierzch = zrobElemStosu();
	  //  if (opcja == '7')  zapiszKolejkeDoPliku(wierzch, sciezka);
	   // if (opcja == '8')  pokaKon(koniec);		    
//	    if (opcja == '9')  sortuj(&wierzch, &koniec, sciezka);	
    }

if (wierzch){
     while (wierzch)
         zdejm(&wierzch, &koniec);
     
}

if (Stos)
     while (Stos){
         zdejmZStosu(&Stos);
     }
    
return 5;
}


// ++++++++++++++++    FUNKCJE +++++++++++++++++++++++++++


void usun_Po_Imieniu(lista **p, lista **k){
 if(*p != NULL){
    lista *tmp, *licznik =*p;
  string wzor = "Covid";
   while(licznik){
            cout << "\n while";
            if(licznik->imie==wzor) {
                tmp=licznik;
             cout << "\n tmp: "; pokazElem(tmp);
                    if(!licznik->kon && !licznik->pocz){
                         cout << "\n if(!licznik->kon && !licznik->pocz)";
                         *p=NULL;
                         *k=NULL;
                         licznik=NULL;
                         delete tmp;
                    }else if (!licznik->kon){
                         cout << "\n !licznik->kon";
                         *p=licznik->pocz;
                         licznik->pocz->kon = NULL;
                         delete tmp;
                         licznik = *p;
                    }else if (licznik->kon && licznik->pocz){
                         cout << "\n licznik->kon && licznik->pocz";
                         licznik->kon->pocz = licznik->pocz;
                         licznik->pocz->kon = licznik->kon;
                         licznik = licznik->kon;
                         delete tmp;
                    }else if(!licznik->pocz){
                        cout << "\n !licznik->pocz";
                        licznik->kon->pocz = NULL;
                        licznik = licznik->kon;
                        *k = licznik;
                        delete tmp;
                    }          
            }else
                 licznik=licznik->pocz; 
        }
}
poka(*p);

}

void usun_Po_Imieniu1(lista **p, lista **k){
  //  cout << "\n usun_Po_Imieniu: ";
 if(*p != NULL){
// cout << "\n usun_Po_Imieniu WEW: ";
  string wzor = "Covid";
  sortuj(p, k, wzor);
  while ((*p)->imie == wzor){
         zdejm(p,k);
     }
}
poka(*p);

}


void sortuj(lista **p, lista **k, string wzor){
if(*p){
  lista *licznik=*k;
  lista *o=*k;
  lista tmp;
  int licz1 = 0, licz2 = 0;
do{
    cout << "\n licz1: " << licz1++;
    o=*k;
     
    do{   
      cout << "\n licz2: " << licz2++;        
         if (o->imie == wzor){
               tmp.imie = o->imie;
	           tmp.nazwisko = o->nazwisko;
	           tmp.wiek = o->wiek;
               tmp.PESEL = o->PESEL;
                    
                    o->imie = o->kon->imie;
	                o->nazwisko = o->kon->nazwisko;
	                o->wiek = o->kon->wiek;
                    o->PESEL = o->kon->PESEL;
               
               o->kon->imie = tmp.imie;
	           o->kon->nazwisko = tmp.nazwisko;
	           o->kon->wiek = tmp.wiek;
               o->kon->PESEL = tmp.PESEL;
         }
           
      o=o->kon;
      if(!o->kon) break;
    }while (o);
    
    licznik=licznik->kon;
}while (licznik);
poka(*p);
}
}

void zapisz_do_pliku_po_sortowaniu(lista **p, lista **k, string sciezka){
  lista *licznik=*p;
  lista *o=*p;
  lista tmp;
if(*p){
if (!(*p)->pocz){   zapiszKolejkeDoPliku(*p, sciezka);}
else{
do{
     o=*p;
    do{           
         if (o->wiek > o->pocz->wiek){
            
               tmp.imie = o->pocz->imie;
	           tmp.nazwisko = o->pocz->nazwisko;
	           tmp.wiek = o->pocz->wiek;
               tmp.PESEL = o->pocz->PESEL;
                    
                    o->pocz->imie = o->imie;
	                o->pocz->nazwisko = o->nazwisko;
	                o->pocz->wiek = o->wiek;
                    o->pocz->PESEL = o->PESEL;
               
               o->imie = tmp.imie;
	           o->nazwisko = tmp.nazwisko;
	           o->wiek = tmp.wiek;
               o->PESEL = tmp.PESEL;
         }            
    o=o->pocz;
    if(!o->pocz) break;
    }while (o);
    
licznik=licznik->pocz;
}while (licznik);
    cout<< "\n poka kontrola\n";
    poka(*p);
    zapiszKolejkeDoPliku(*p, sciezka);
}}
}

void zapiszKolejkeDoPliku(lista *l, string sciezka){
lista *wsk = l;
poka(l);
 fstream wsk_plik;
 wsk_plik.open(sciezka, ios::out | ios::app);

    if (wsk_plik.good())
     while (wsk != NULL){ 
        wsk_plik << wsk->imie << "   \t  " << wsk->nazwisko << "  \t  " << to_string(wsk->wiek) << "  \t " << wsk->PESEL  << "\n";
         wsk=wsk->pocz;
     }  
    else
       cout << "\n Nie udało się otworzyć pliku: " << sciezka;

wsk_plik.close(); 
}

void zdejmWszystkie(lista **p, lista **k){
    int usuwany = 0;

    if (*p){
         while (*p != 0){
             usuwany++;
             cout << "\n Usuwany: " << usuwany;
             zdejm(p,k);
         }   
         *k=NULL;
         *p=NULL;
      }else{
            cout << " \n Brak Kolejki w pamięci " << endl;
             *k=NULL;
             *p=NULL;
      }   
}

void zdejm(lista **p, lista **k){        
    if(*p != NULL)
    {
        lista *temp=*p; 
             cout << "\n Usuwam następujący element: \n";
             pokazElem(temp);         
        *p = (*p)->pocz;
        if(*p) (*p)->kon = NULL;    
        delete temp;        
        if(*p==NULL)
        {
            *k=NULL;
            *p=NULL;
        }
    }
    else {
        cout << "\n Brak Kolejki w pamięci \n";
        *k=NULL;
        *p=NULL;
     }
}

int dodaj(lista **k, lista **p){
    lista *nowy=zrobElemStosu();
    pokazElem(nowy);
        
    if(*k){      
        cout << "\n dodaj if(*k)" << endl;
        nowy->kon=*k;
        nowy->pocz = NULL;       
        (*k)->pocz=nowy;   
        *k=nowy;
    }
    else{
        cout << "\n dodaj else" << endl;
        nowy->kon = nowy->pocz = NULL;
        *k = nowy;
        *p = nowy;
    }
return 5;
}

void poka(lista *p){
lista *wsk = p;  
cout << "\n Wyświetlanie od początku:\n";  
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
       //wsk=wsk->kon;
       i++; 
    }
}

void pokaKon(lista *p){
lista *wsk = p;    
cout << "\n Wyświetlanie od końca:\n"; 
   naglowek();
      int i = 1;
    while (wsk != NULL){
    cout << i << ")";
       cout << wsk->imie;
	   cout << "  \t " << wsk->nazwisko;
	   cout << "  \t " << wsk->wiek;
       cout << "  \t " << wsk->PESEL;        
       cout << "\n";
       //wsk=wsk->pocz;
       wsk=wsk->kon;
       i++; 
    }
}


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
    int wyznacznik = rand()%5;
    if (wyznacznik==0){
    tempZnak = rand()%26+65;
    nowy->imie = nowy->imie + tempZnak;
        for (int j=0; j<5; j++){
            tempZnak = rand()%26+97;
             nowy->imie = nowy->imie + tempZnak;             
        }
    }
    else if(wyznacznik==1){nowy->imie = "Covid";}
        else if(wyznacznik==2){nowy->imie = "Dawid";}
            else if(wyznacznik==3){nowy->imie = "Edward";}
                else if(wyznacznik==4){nowy->imie ="Stefan"; }
                 else if(wyznacznik==5){nowy->imie = "Józek";}
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


