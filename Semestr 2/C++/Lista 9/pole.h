#pragma once
#include "ruch.h"


class Pole {


public:

	const string nazwa[2];
	const string tekst_akcji[2];
	const string typ_Pola;
	const int numer_pola;

	friend class Bank;
    friend class Plansza;

	    //konstruktor
	    Pole();
	    //destruktor
	    ~Pole();
	    //funkcje do ustawiania wartości
	    void virtual  ustaw_Nazwe(string miasto, string ulica);
	    void  virtual ustaw_Typ(string typ);
	    void virtual  ustaw_Tekst_Akcji(string tekst1, string tekst2);
	    void  virtual ustaw_Numer_Pola(int nr);

	    //funkcje do pobierania wartości
	    string virtual  pobierz_Nazwe(int index_Nazwy);
	    string virtual  pobierz_Tekst_Akcji(int index_Tekstu);
	    string virtual  pobierz_Typ();
	    int virtual  pobierz_Numer_Pola();
};

