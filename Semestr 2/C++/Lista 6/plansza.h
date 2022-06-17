#pragma once

#include "pole.h"
#include "ruch.h"
#include "gracz.h"
#include "bankier.h"
#include "kosc.h"
#include "karta.h"

class Plansza {

        int ilosc_Graczy;
        int id_bankrutow[ilosc_Graczy];
        
    protected:
	    Pole pola[40];
	    Gracz* gracze;      
	    Ruch rusz;
	    Bank *bankier;
	    Kostka kosc;
	    Karta karty[100];

	public:
	    //konstruktor
	    Plansza(); 	
	     //destruktor
	    ~Plansza();

	friend class Bank;
void poka_Plansze(int pierwsze_Pole, int ostatnie_Pole, int numer_Gracza);


	    void utworz_Graczy();
	    void utworz_Bankiera();
	    void ustaw_Nazwe_Gracza(int numer_Gracza, string nazwa);
	    
	    string pobierz_Nazwe_Gracza(int numer_Gracza);

	    void ruch(int numer_Gracza, int ile_Ruchu);
	    
	    Gracz* pobierz_Gracza(int numer);
	    int pobierz_Lokalizacje_Gracza(int numer_Gracza);
	    int pobierz_Pieniadze_Gracza(int numer_Gracza);
	    string typ_Pola(int index);
	    int pobierz_Akt_Wlasnosci_Pola(int index_Pola);
	    int pobierz_Cene_Wlasnosci_Pola(int index_Pola);

	    int pobierz_Czynsz_Pola(int index_Pola);
	    int pobierz_Podatek_Pola(int index_Pola);

	    string pobierz_Nazwe_Pola(int index_Pola, int index);
	    void upgrade_Pola(int index_Pola);
	    bool czy_Gracz_Aktywny(int numer_Gracza);
	    void porazka_Gracza(int numer_Gracza);

        void ustaw_Wlasnosc_Pola(int index_Pola, int numer_Gracza);
        void inicjalizuj_Karty();
        
        void GRA();
        
};


