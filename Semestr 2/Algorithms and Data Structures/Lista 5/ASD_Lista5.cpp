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

void zrobElem(lista **p, lista **k);
void zrobElem2(lista **p, lista **k);
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

void pokaPlik(string sciezka);
void usun_Po_Kluczu(lista **p, lista **k);
void usun_Po_Kluczu_wszystkie(lista **p, lista **k);
void zapisz_liste_do_pliku_wg_kryterium(lista *l, string sciezka);
void dopisz_do_pliku(lista *l, string sciezka);

int main(){

 srand(time(NULL));
lista *Baza = NULL;
lista *Kooniec = NULL;

//for(int i=0; i<7; i++) zrobElem(&Baza, &Kooniec);

 char opcja=' ';
 string sciezka = "lista_dwukierunkowa.txt";
    
    while (opcja != 'k' && opcja != 'K'){         
        cout << "\n\t ++++ Lista Dwukierunkowa ++++\n";
        cout << "\t 1) Dodaj element \n";
        cout << "\t 2) Dodaj element i sprawdź czy jest już identyczny \n";
        cout << "\t 3) usun_Po_Kluczu \n";
        cout << "\t 4) usun_Po_Kluczu_wszystkie \n";
        cout << "\t 5) edytuj element \n";
        cout << "\t 6) Zapisz Listę do pliku wg kryterium " << sciezka <<"\n";
        cout << "\t 7) Pokaż listę \n";
        cout << "\t 8) Pokaż plik \n";
	    cout << "\t k/K) Koniec \n";
        cout << "\n Podaj opcje: ";  
	    cin >> opcja;	   
	    if (opcja == '1')  zrobElem(&Baza, &Kooniec);
	    if (opcja == '2')  zrobElem2(&Baza, &Kooniec);
	    if (opcja == '3')  usun_Po_Kluczu(&Baza, &Kooniec);
	    if (opcja == '4')  usun_Po_Kluczu_wszystkie(&Baza, &Kooniec);
	    if (opcja == '5')  edytuj_elem(&Baza);
	    if (opcja == '6')  zapisz_liste_do_pliku_wg_kryterium(Baza, sciezka);
	    if (opcja == '7')  poka(Baza);
	    if (opcja == '8')  pokaPlik(sciezka); 
    }


czyscListe(&Baza);
return 5;
}
//=+=+=+=+==+=+=+==+ FUNKCJE +=+==+=+=+=+=+=+

void dopisz_do_pliku(lista *l, string sciezka)
{
lista *wsk = l;
 fstream wsk_plik;
 wsk_plik.open(sciezka, ios::out | ios::app);

    if (wsk_plik.good())
         wsk_plik << wsk->imie << "   \t  " << wsk->nazwisko  << "    \t " << wsk-> PESEL << "  \t  " << to_string(wsk->wiek) << "\n"; 
    else
         cout << "\n Nie udało się otworzyć pliku: " << sciezka;

wsk_plik.close(); 
}

void zapisz_liste_do_pliku_wg_kryterium(lista *l, string sciezka)
{
 char opcja=' ';      
        cout << "\n\t ++++ Zapisywanie do pliku ++++\n";
        cout << "\t 1) Wszystkie elementy listy\n";
        cout << "\t 2) Elementy o wybranym nazwisku \n";
        cout << "\t 3) osoby pełnoletnie \n";        
        cout << "\n Podaj opcje: ";
        cin >> opcja;   
	    if (opcja == '1')  zapisz_liste_do_pliku(l, sciezka);
	    if (opcja == '2'){	    
                	        lista *szuk = l;
                	        string szukane;
	                        cout << "\n Podaj nazwisko: ";
                	        cin >> szukane;
                	        while(szuk)
                	        {
                        	    if(szuk->nazwisko==szukane)
                    	               dopisz_do_pliku(szuk, sciezka);
                        	    szuk=szuk->pop;
                	        }
	    }
	    if (opcja == '3'){	    
                	        lista *szuk = l;
                	        while(szuk)
                	        {
                        	    if(szuk->wiek >= 18)
                    	               dopisz_do_pliku(szuk, sciezka);
                        	    szuk=szuk->pop;
                	        }
	    }
        
}

void usun_Po_Kluczu(lista **p, lista **k)
{
 cout << "\n Usuń po Nazwisku jeden wpis: ";
   if(*p != NULL){
    lista *tmp, *licznik =*p;
    string wzor;
    cout << "\n Podaj nazwisko po którym chcesz usunąć wpis: " ;
    cin >> wzor;
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
   else{
    cout << "\n Brak Listy do wyświetlenia";
   }
poka(*p);

}

void usun_Po_Kluczu_wszystkie(lista **p, lista **k)
{
 cout << "\n Usuń po Nazwisku wszystkie: ";
   if(*p != NULL){
    lista *tmp, *licznik =*p;
    string wzor;
    cout << "\n Podaj nazwisko po którym chcesz usunąć WSZYSTKIE wpisy: " ;
    cin >> wzor;
        while(licznik){
            cout << "\n while";
            if(licznik->nazwisko==wzor) {
                tmp=licznik;
             cout << "\n tmp: "; pokazElem(tmp);
                    if(!licznik->nast && !licznik->pop){
                         *p=NULL;
                         *k=NULL;
                         licznik=NULL;
                         delete tmp;
                    }else if (!licznik->nast){
                         *p=licznik->pop;
                         licznik->pop->nast = NULL;
                         delete tmp;
                         licznik = *p;
                    }else if (licznik->nast && licznik->pop){
                         licznik->nast->pop = licznik->pop;
                         licznik->pop->nast = licznik->nast;
                         licznik = licznik->nast;
                         delete tmp;
                    }else if(!licznik->pop){
                        licznik->nast->pop = NULL;
                        licznik = licznik->nast;
                        *k = licznik;
                        delete tmp;
                     }          
            }else
        licznik=licznik->pop; 
        }
   }
   else{
    cout << "\n Brak Listy do wyświetlenia";
   }
poka(*p);
}

void pokaPlik(string sciezka)
{
 string record;
 int i=0;
 fstream wsk_plik;
 wsk_plik.open(sciezka); //, ios::in bez tego też działa

    if (wsk_plik.good()){
     naglowek();
     while (getline(wsk_plik, record)){ 
        cout << ++i << ") " << record << endl;
     }
    }else
       cout << "\n Nie udało się otworzyć pliku: " << sciezka;

wsk_plik.close(); 
    
}

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
 cout << "\n Usuń wszystkie po Nazwisku : ";
   if(*p != NULL){
    lista *tmp, *licznik =*p;
    string wzor = "Covid";
        while(licznik){
            cout << "\n while";
            if(licznik->nazwisko==wzor) {
                tmp=licznik;
             cout << "\n element usuwany to: "; pokazElem(tmp);
                    if(!licznik->nast && !licznik->pop){
                        // cout << "\n if(!licznik->nast && !licznik->pop)";
                         *p=NULL;
                         *k=NULL;
                         licznik=NULL;
                         delete tmp;
                    }else if (!licznik->nast){
                       //  cout << "\n !licznik->nast";
                         *p=licznik->pop;
                         licznik->pop->nast = NULL;
                         delete tmp;
                         licznik = *p;
                    }else if (licznik->nast && licznik->pop){
                       //  cout << "\n licznik->nast && licznik->pop";
                         licznik->nast->pop = licznik->pop;
                         licznik->pop->nast = licznik->nast;
                         licznik = licznik->nast;
                         delete tmp;
                    }else if(!licznik->pop){
                      //  cout << "\n !licznik->pop";
                        licznik->nast->pop = NULL;
                        licznik = licznik->nast;
                        *k = licznik;
                        delete tmp;
                     }          
            }else
                 licznik=licznik->pop; 
        }
    poka(*p);
   }
   else{
        cout << "\n Brak listy z której można by cokolwiek usunąć \n";
   }
}


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
   poka(*p);
   }
   else{
        cout << "\n Brak listy z której można by cokolwiek usunąć \n";
   }
}


void pokazElem(lista *l){
if(l){
cout << "\n Pokaż Elem: \n";
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
        wsk_plik << wsk->imie << "   \t  " << wsk->nazwisko  << "    \t " << wsk-> PESEL << "  \t  " << to_string(wsk->wiek) << "\n";
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
else{
cout << "\n Brak Listy do Wyświetlenia:\n";     
} 
}

void zrobElem(lista **p, lista **k){
    lista *nowy = zrobElemStosu();
    lista *l = *p;
    if(*p){
        while(l)
        {
            if((*l).nazwisko.compare(nowy->nazwisko) <= 0 && (!l->pop))
            {
                     nowy->pop=NULL;
                     nowy->nast=*k;
                     (*k)->pop=nowy;
                    *k=nowy; 
                     break;                     
            }
            if((*l).nazwisko.compare(nowy->nazwisko) > 0)
            {
                    if (!l->nast){
                            (*p)->nast = nowy;
                            nowy->nast = NULL;
                            nowy->pop = l;
                            *p = nowy;
                    }else if (!l->pop){
                        nowy->pop=*k;
                        nowy->nast=(*k)->nast;
                        (*k)->nast->pop = nowy;
                        (*k)->nast=nowy;
                    }else{
                         nowy->nast = l->nast;
                         nowy->pop = l->nast->pop;
                         l->nast->pop = nowy;
                         l->nast = nowy;
                     }
                     break;
           }
        l=l->pop;
      }
    }else{    
         nowy->pop=nowy->nast=NULL;
         *p=nowy;
         *k=nowy;     
    }
    poka(*p);
}


void zrobElem2(lista **p, lista **k){
    lista *nowy = zrobElemStosu();
    lista *l = *p;
    if(*p){
        while(l)
        {
            if( ((*l).nazwisko == nowy->nazwisko) && 
            ((*l).imie == nowy->imie) &&
            ((*l).PESEL == nowy->PESEL) &&
            ((*l).wiek == nowy->wiek) )
            {
                cout << "\n ELEMENT IDENTYCZNY: \n";
                pokazElem(l);
            }
        l=l->pop;
        }
        l = *p;
        while(l)
        {
            if(((*l).nazwisko == nowy->nazwisko) )
            {
                cout << "\n ELEMENT IDENTYCZNY kluczem nazwisko: \n";
                pokazElem(l);
            }
        l=l->pop;
        }
        l = *p;
        while(l)
        {
            if((*l).nazwisko.compare(nowy->nazwisko) <= 0 && (!l->pop))
            {
                     nowy->pop=NULL;
                     nowy->nast=*k;
                     (*k)->pop=nowy;
                    *k=nowy; 
                     break;                     
            }
            if((*l).nazwisko.compare(nowy->nazwisko) > 0)
            {
                    if (!l->nast){
                            (*p)->nast = nowy;
                            nowy->nast = NULL;
                            nowy->pop = l;
                            *p = nowy;
                    }else if (!l->pop){
                        nowy->pop=*k;
                        nowy->nast=(*k)->nast;
                        (*k)->nast->pop = nowy;
                        (*k)->nast=nowy;
                    }else{
                         nowy->nast = l->nast;
                         nowy->pop = l->nast->pop;
                         l->nast->pop = nowy;
                         l->nast = nowy;
                     }
                     break;
           }
        l=l->pop;
      }
    }else{    
         nowy->pop=nowy->nast=NULL;
         *p=nowy;
         *k=nowy;     
    }
    poka(*p);
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
