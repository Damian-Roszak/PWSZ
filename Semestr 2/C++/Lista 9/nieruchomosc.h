#pragma once


class Nieruchomosc: public Pole {

	    int cena_Wlasnosci;
	    int wlasnosc_nr_gracza;
	    bool czy_Hipoteka;


	public:

	    //konstruktor
	    Nieruchomosc();
	    //destruktor
	    ~Nieruchomosc();
	friend class Bank;
	friend class Plansza;

	    void  virtual ustaw_Cene_Wlasnosci(int koszt);
	    void  virtual ustaw_Wlasciciela(int posiadane_przez);
	    void virtual  ustaw_Hipoteke(bool hipoteka );

	    //pobierz
	    int virtual  pobierz_Czynsz();
	    int virtual  pobierz_Cene_Wlasnosci();
	    int virtual  pobierz_Wlasciciela();
	    bool  virtual pobierz_Hipoteke();

};

