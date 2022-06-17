#pragma once

class Darmowy_Parking {
    
	
	public:
	
	const string nazwa[2];
	const string tekst_akcji[2];
	const string typ_Pola;
	
	friend void Plansza::upgrade_Pola(int index_Pola);
	    
	    Darmowy_Parking();
	    ~Darmowy_Parking();
	    void ustaw_Nazwe(string miasto, string ulica);
	    void ustaw_Typ(string typ);
	    void ustaw_Tekst_Akcji(string tekst1, string tekst2);
	    
	    string pobierz_Nazwe(int index_Nazwy);
	    string pobierz_Tekst_Akcji(int index_Tekstu);
	    string pobierz_Typ();    

};
