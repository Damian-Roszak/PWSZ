#include "pole.h"
#include <iostream>

//konstruktor
Pole::Pole(){
    ile_Domow = 0;
    wlasnosc_nr_gracza = -1;
    zajetosc = false;
    hipoteka = false;
    czy_Mozna_Zabudowac = true;
    podatek = 0;
    kod_Akcji = 0;
    czekanie_kolejek = 0;
}

Pole::~Pole(){}

//funkcje do ustawiania wartości
void Pole::ustaw_Nazwe(string miasto, string ulica){
	nazwa[0] = miasto;
	nazwa[1] = ulica;
}

void Pole::ustaw_Tekst_Akcji(string tekst1, string tekst2){
	tekst_akcji[0] = tekst1;
	tekst_akcji[1] = tekst2;
}

void Pole::ustaw_Typ(string typ){
	typ_Pola = typ;
}

void Pole::ustaw_czekanie_kolejek(int tury){
    czekanie_kolejek = tury;
}

void Pole::ustaw_Cene_Wlasnosci(int koszt){
	cena_Wlasnosci = koszt;
}

void Pole::ustaw_kod_Akcji(int kod){
	kod_Akcji = kod;
}

void Pole::ustaw_Zajetosc(bool zajete){
	zajetosc = zajete;
}

void Pole::ustaw_Wlasciciela(int posiadane_przez){
	wlasnosc_nr_gracza = posiadane_przez;
}

void Pole::ustaw_Hipoteke(bool czy_Hipoteka){
	hipoteka = czy_Hipoteka;
}

void Pole::ustaw_Czynsz(int ile_Czynszu){
	czynsz = ile_Czynszu;
}

void Pole::ustaw_Podatek(int haracz){
	podatek = haracz;
}

void Pole::ustaw_ile_Domow(int ilosc_Domow){
	ile_Domow += ilosc_Domow;
}

void Pole::ustaw_czy_Mozna_Zabudowac(bool prawo_budowy){
    czy_Mozna_Zabudowac = prawo_budowy;
}

void Pole::ustaw_cene_Domu(int ile_kosztuje){
    cena_Domu = ile_kosztuje;
}

void Pole::ustaw_cene_Hotelu(int ile_kosztuje){
    cena_Hotelu = ile_kosztuje;
}

bool Pole::upgrade(){
	if(ile_Domow < 5 ){
	    czynsz = czynsz * 2;
	    ile_Domow++;
	    return true;
	} else {
	    return false;
	}
}
	
//funkcje do pobierania wartości
string Pole::pobierz_Nazwe(int index_Nazwy){
	return nazwa[index_Nazwy];
}

string Pole::pobierz_Tekst_Akcji(int index_Tekstu){
	return tekst_akcji[index_Tekstu];
}

int Pole::pobierz_Cene_Wlasnosci(){
	return cena_Wlasnosci;
}

bool Pole::pobierz_Hipoteke(){
	return hipoteka;
}

int Pole::pobierz_Czynsz(){
	return czynsz;
}

int Pole::pobierz_Podatek(){
	return podatek;
}

string Pole::pobierz_Typ(){
	return typ_Pola;
}

int Pole::pobierz_Wlasciciela(){
	return wlasnosc_nr_gracza;
}

int Pole::pobierz_ile_Domow(){
	return ile_Domow;
}

int Pole::pobierz_kod_Akcji(){
	return kod_Akcji;
}

bool Pole::pobierz_Zajetosc(){
	return zajetosc;
}

bool Pole::pobierz_czy_Mozna_Zabudowac(){
    return czy_Mozna_Zabudowac;
}

int Pole::pobierz_cene_Domu(){
    return cena_Domu;
}

int Pole::pobierz_czekanie_kolejek(){
    return czekanie_kolejek;
}

int Pole::pobierz_cene_Hotelu(){
    return cena_Hotelu;
}


