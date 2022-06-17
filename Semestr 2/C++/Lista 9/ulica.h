#pragma once


class Ulica: public Pole {

	    int cena_Wlasnosci;
	    int wlasnosc_nr_gracza;
	    bool hipoteka;
	    int czynsz;
	    
	public:
	
	    //konstruktor
	    Ulica();
	    //destruktor
	    ~Ulica();
	friend class Bank;
	friend class Plansza;
	    void ustaw_Czynsz(int ile_Czynszu);
	    void ustaw_Cene_Wlasnosci(int koszt);
	    void ustaw_Wlasciciela(int posiadane_przez);	    
	    void ustaw_Hipoteke(bool czy_Hipoteka);	    
	    
	    //pobierz
	    int pobierz_Czynsz();	    
	    int pobierz_Cene_Wlasnosci();	    
	    int pobierz_Wlasciciela();
	    bool pobierz_Hipoteke();   	 
	
};

