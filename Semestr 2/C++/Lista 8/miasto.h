#pragma once


class Miasto: public Pole, public Ulica  {
    
	    //koszty zakupu
	    int cena_Domu;
	    int cena_Hotelu;
	    int ile_Domow;	    

	public:
	
	   
	friend class Bank;
    friend class Plansza;

	    //konstruktor
	    Miasto();
	    //destruktor
	    ~Miasto();

	    //funkcje do ustawiania wartości
	    void ustaw_ile_Domow(int ilosc_Domow);
	    void ustaw_cene_Domu(int ile_kosztuje);
	    void ustaw_cene_Hotelu(int ile_kosztuje);
	
	    //funkcje do pobierania wartości
	    int pobierz_ile_Domow();
	    int pobierz_cene_Domu();
	    int pobierz_cene_Hotelu();
};

