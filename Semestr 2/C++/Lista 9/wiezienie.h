#pragma once

class Wiezienie: public Pole {
    	
	int id_gracza_ile_czeka_tur[][2];	
	
	public:
	
	friend class Plansza;
	
	    Wiezienie();
	    ~Wiezienie();
	    
	    int pobierz_czekanie_kolejek(int gracz);
        
        void przerzuc_na_pole_wiezienia(Gracz & gracz, int czekanie_kolejek);
        
        bool czy_W_Wiezieniu(int gracz);
};


bool Wiezienie::czy_W_Wiezieniu(int gracz){
	return id_gracza_ile_czeka_tur[gracz][0];
}
