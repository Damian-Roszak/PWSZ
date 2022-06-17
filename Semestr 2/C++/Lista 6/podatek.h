#pragma once

class Podatek {

	    int czynsz;
	    int podatek;
	
	public:
	
	const string nazwa[2];
	const string tekst_akcji[2];
	const string typ_Pola;
	   
	    friend int Plansza::pobierz_Podatek_Pola(int index_Pola);
	    friend int Plansza::pobierz_Czynsz_Pola(int index_Pola);
	
	    Podatek();
	    ~Podatek();
	    void ustaw_Nazwe(string miasto, string ulica);
	    void ustaw_Typ(string typ);
	    void ustaw_Czynsz(int ile_Czynszu);
	    void ustaw_Tekst_Akcji(string tekst1, string tekst2);
	    void ustaw_Podatek(int haracz); 
	    
	    string pobierz_Nazwe(int index_Nazwy);
	    int pobierz_Czynsz();
	    int pobierz_Podatek();
	    string pobierz_Tekst_Akcji(int index_Tekstu);
	    string pobierz_Typ();    


};
