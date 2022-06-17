#pragma once


class Ulica {

	    int cena_Wlasnosci;
	    int wlasnosc_nr_gracza;
	    bool hipoteka;
	    int ile_Domow;
	    int czynsz;
	    
	    //koszty zakupu
	    int cena_Domu;
	    int cena_Hotelu;
	    //int cena_
	    
	    void ustaw_Czynsz(int ile_Czynszu);

	public:
	
	    
	const string nazwa[2];
	const string tekst_akcji[2];
	const string typ_Pola;
	   
	
	friend class Bank;
	friend class Plansza;

	    //konstruktor
	    Ulica();
	    //destruktor
	    ~Ulica();
	    //funkcje do ustawiania wartości
	    void ustaw_Nazwe(string miasto, string ulica);
	    void ustaw_Typ(string typ);
	    void ustaw_Cene_Wlasnosci(int koszt);
	    void ustaw_Hipoteke(bool czy_Hipoteka);
	    void ustaw_Tekst_Akcji(string tekst1, string tekst2);
	    void ustaw_ile_Domow(int ilosc_Domow);
	    
	    void ustaw_cene_Domu(int ile_kosztuje);
	    void ustaw_cene_Hotelu(int ile_kosztuje);
	    bool upgrade();
	
	    //funkcje do pobierania wartości
	    string pobierz_Nazwe(int index_Nazwy);
	    int pobierz_Cene_Wlasnosci();
	    bool pobierz_Hipoteke();
	    int pobierz_Czynsz();
	    int pobierz_Wlasciciela();
	    string pobierz_Tekst_Akcji(int index_Tekstu);
	    string pobierz_Typ();
	    int pobierz_ile_Domow();	 
	    
	    int pobierz_cene_Domu();
	    int pobierz_cene_Hotelu();
};

