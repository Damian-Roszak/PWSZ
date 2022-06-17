#pragma once

class Podatek: public Pole {

	    int czynsz;
	    int podatek;
	
	public:
	   
	    friend int Plansza::pobierz_Podatek_Pola(int index_Pola);
	    friend int Plansza::pobierz_Czynsz_Pola(int index_Pola);
	
	    Podatek();
	    ~Podatek();
	    void ustaw_Czynsz(int ile_Czynszu);
	    void ustaw_Podatek(int haracz); 

	    
	    int pobierz_Czynsz();
	    int pobierz_Podatek();


};
