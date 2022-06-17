#pragma once

class Elektrownia {

	    int czynsz;
	    int cena_Wlasnosci;
	    bool hipoteka;
	    int wlasnosc_nr_gracza;
	    
    public:
    
	const string nazwa[2];
	const string tekst_akcji[2];
	const string typ_Pola;
	
    friend void Plansza::upgrade_Pola(int index_Pola);
    
    
        Elektrownia();
        ~Elektrownia();
        void ustaw_Nazwe(string miasto, string ulica);
	    void ustaw_Typ(string typ);
	    void ustaw_Czynsz(int ile_Czynszu);
	    
	    void ustaw_Tekst_Akcji(string tekst1, string tekst2);
	    void ustaw_Cene_Wlasnosci(int koszt);
	    void ustaw_Wlasciciela(int posiadane_przez);
	    
	    void ustaw_Hipoteke(bool czy_Hipoteka);
	    
	    bool upgrade();
	    
	    //pobierz
	    string pobierz_Nazwe(int index_Nazwy);
	    int pobierz_Czynsz();
	    int pobierz_Podatek();
	    string pobierz_Tekst_Akcji(int index_Tekstu);
	    
	    string pobierz_Typ();    
	    int pobierz_Cene_Wlasnosci();
	    
	    int pobierz_Wlasciciela();

};
