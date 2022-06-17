#include "gracz.h"

Gracz::Gracz(){
    ++licznik_Graczy;
	ustaw_Nazwe_Gracza();
	ile_Pieniedzy = 1500;
	lokalizacja = 0;
	for(int i = 0; i < 40; i++){
		index_Wlasnosci[i] = false;
	}
	aktywny = true;
	bankrut = false;
	ilosc_pozostalych_kolejek = 0;
}
Gracz::~Gracz(){
 //destruktor obiektu typu Gracz
 }

void Gracz::ustaw_Nazwe_Gracza(){
    string nazwa;
    cout << "\n Podaj swoją nazwę " << licznik_Graczy << " graczu: ";
    cin >> nazwa;
	nazwa_Gracza = nazwa;
}

void Gracz::ustaw_Lokalizacje(int numer_miejsca){
	lokalizacja = numer_miejsca;	
}

string Gracz::pobierz_Nazwe_Gracza(){
	return nazwa_Gracza;
}

void Gracz::ustaw_Ilosc_Pozostalych_Kolejek(int ile_tur){
    ilosc_pozostalych_kolejek = ile_tur;
}

int Gracz::pobierz_Ilosc_Pozostalych_Kolejek(){
    return ilosc_pozostalych_kolejek;
}

void Gracz::daj_Pieniadze(int ile){
	ile_Pieniedzy = ile_Pieniedzy - ile;
}

int Gracz::pobierz_Ilosc_Pieniedzy(){
	return ile_Pieniedzy;
}

void Gracz::wez_Pieniadze(int ile){
	ile_Pieniedzy = ile_Pieniedzy + ile;
}

void Gracz::rusz_Gracza(int ile){
	ustaw_Lokalizacje(pobierz_Lokalizacje() + ile);
}

int Gracz::pobierz_Lokalizacje(){
	return lokalizacja;
}


void Gracz::ustaw_Posiadane_Wlosci(int index, bool czy_Posiadane){
	index_Wlasnosci[index] = czy_Posiadane;
}

bool Gracz::pobierz_Posiadane_Wlosci(int index){
	return index_Wlasnosci[index];
}

bool Gracz::czy_Aktywny(){
	return aktywny;
}

void Gracz::reset(){
	ile_Pieniedzy = 0;
	lokalizacja = 0;
	aktywny = false;
	bankrut = true;
}

void Gracz::ustaw_Ilosc_Pieniedzy(int ile_forsy){
	ile_Pieniedzy = ile_forsy;
}

int Gracz::podaj_licznik_Graczy(){
    return licznik_Graczy;
}



