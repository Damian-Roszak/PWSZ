#pragma once
#include "ruch.h"


class Pole {


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
	    void ustaw_Tekst_Akcji(string tekst1, string tekst2);
	
	    //funkcje do pobierania wartości
	    string pobierz_Nazwe(int index_Nazwy);
	    string pobierz_Tekst_Akcji(int index_Tekstu);
	    string pobierz_Typ();
};

