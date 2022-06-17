#pragma once

class Wiezienie: public Pole {
    
	const int czekanie_kolejek;
	
	int id_gracza_ile_czeka_tur[][2];	
	
	public:
	
	friend class Plansza;
	
	    Wiezienie();
	    ~Wiezienie();
	    void ustaw_czekanie_kolejek(bool aktywny);
	    
	    int pobierz_czekanie_kolejek();
        
        void przerzuc_na_pole_wiezienia(Gracz & gracz, int czekanie_kolejek);
};
