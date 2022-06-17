#pragma once
#include "ruch.h"


class Pole {

	    int cena_Wlasnosci;
	    bool zajetosc;
	    int wlasnosc_nr_gracza;
	    bool czy_Mozna_Zabudowac;
	    bool hipoteka;
	    int ile_Domow;
	    int czynsz;
	    int podatek;
	    int kod_Akcji;//0-normalne działanie, 1-więzienie, 2-przechodzisz przez start i otrzymujesz 200PLN
	    int czekanie_kolejek; // 0-bez czekania lub ilość kolejek bez ruchu
	
	protected:    
	    //koszty zakupu
	    int cena_Domu;
	    int cena_Hotelu;
	    //int cena_
	    

	public:
	
	const string nazwa[2];
	const string tekst_akcji[2];
	const string typ_Pola;
	   
	friend class Bank;
    friend class Plansza;
	    
	    //konstruktor
	    Pole();
	    //destruktor
	    ~Pole();
	    //funkcje do ustawiania wartości
	    void ustaw_Nazwe(string miasto, string ulica);
	    void ustaw_Typ(string typ);
	    void ustaw_Cene_Wlasnosci(int koszt);
	    void ustaw_Zajetosc(bool zajete);
	    void ustaw_Hipoteke(bool czy_Hipoteka);
	    void ustaw_Czynsz(int ile_Czynszu);
	    void ustaw_Podatek(int haracz); 
	    void ustaw_Tekst_Akcji(string tekst1, string tekst2);
	    void ustaw_ile_Domow(int ilosc_Domow);
	    void ustaw_czy_Mozna_Zabudowac(bool prawo_budowy);
	    void ustaw_kod_Akcji(int kod);
	    void ustaw_czekanie_kolejek(int tury);
	    
	    void ustaw_cene_Domu(int ile_kosztuje);
	    void ustaw_cene_Hotelu(int ile_kosztuje);
	    bool upgrade();
	
	    //funkcje do pobierania wartości
	    string pobierz_Nazwe(int index_Nazwy);
	    int pobierz_Cene_Wlasnosci();
	    bool pobierz_Hipoteke();
	    //int pobierz_Czynsz();
	    int pobierz_Podatek();
	    int pobierz_Wlasciciela();
	    string pobierz_Tekst_Akcji(int index_Tekstu);
	    string pobierz_Typ();
	    int pobierz_ile_Domow();	    
	    bool pobierz_Zajetosc();
	    bool pobierz_czy_Mozna_Zabudowac();
	    int pobierz_kod_Akcji();
	    int pobierz_czekanie_kolejek();
	    
	    int pobierz_cene_Domu();
	    int pobierz_cene_Hotelu();
};

