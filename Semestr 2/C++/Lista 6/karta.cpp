#include "karta.h"


Karta::Karta(){
    //inicjalizuje obiekt klasy Karta
}


Karta::Karta(int k, int ks, string s){
    //inicjalizuje obiekt klasy Karta kopiując podane parametry do pól obiektu w liście inicjalizacyjnej wersja konstruktora kopiującego
     kod = k;
     kasa = ks; 
     tekst_karty = s;
}

Karta::~Karta(){}
