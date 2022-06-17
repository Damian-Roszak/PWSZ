#pragma once

class Podatek_od_Luksusu: public Pole {
    
	    int czynsz;
	    int podatek;
	
	public:
	   
	 friend int Plansza::pobierz_Podatek_Pola(int index_Pola);
	 friend int Plansza::pobierz_Czynsz_Pola(int index_Pola);
	
	    Podatek_od_Luksusu();
	    ~Podatek_od_Luksusu();
	    void ustaw_Czynsz(int ile_Czynszu);
	    void ustaw_Podatek(int haracz); 

	    
	    int pobierz_Czynsz();
	    int pobierz_Podatek();


};
