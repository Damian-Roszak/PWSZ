#pragma once

class Wiezienie_Odwiedziny {
    
        
	public:	
	
	const string nazwa[2];
	const string tekst_akcji[2];
	const string typ_Pola;
	   
	
	friend class Plansza;
	
	    Wiezienie_Odwiedziny();
	    ~Wiezienie_Odwiedziny();
	    void ustaw_Nazwe(string miasto, string ulica);
	    void ustaw_Typ(string typ);
	    void ustaw_Tekst_Akcji(string tekst1, string tekst2);
	    
	    string pobierz_Nazwe(int index_Nazwy);
	    string pobierz_Tekst_Akcji(int index_Tekstu);
	    string pobierz_Typ();    
};
