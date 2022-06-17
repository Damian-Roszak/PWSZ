#pragma once

class Wiezienie {
    
	const int czekanie_kolejek;
	
	int id_gracza_ile_czeka_tur[][2];	
	
	public:
	const string nazwa[2];
	const string tekst_akcji[2];
	const string typ_Pola;
	
	
	friend class Plansza;
	
	    Wiezienie();
	    ~Wiezienie();
	    void ustaw_Nazwe(string miasto, string ulica);
	    void ustaw_Typ(string typ);
	    void ustaw_Tekst_Akcji(string tekst1, string tekst2);
	    void ustaw_czekanie_kolejek(bool aktywny);
	    
	    string pobierz_Nazwe(int index_Nazwy);
	    string pobierz_Tekst_Akcji(int index_Tekstu);
	    string pobierz_Typ();    
	    int pobierz_czekanie_kolejek();

        
        void przerzuc_na_pole_wiezienia(Gracz & gracz, int czekanie_kolejek);
};
