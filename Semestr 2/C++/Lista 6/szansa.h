#pragma once

class Szansa {
    	
    int kod;
    int kasa;
	    
    public:
    
	const string nazwa[2];
	const string tekst_akcji[2];
	const string typ_Pola;
	   
        Szansa();
        ~Szansa();
        
        friend void Plansza::upgrade_Pola(int index_Pola);
        
        void ustaw_Nazwe(string miasto, string ulica);
	    void ustaw_Tekst_Akcji(string tekst1, string tekst2);
	    void ustaw_Typ(string typ);
	    
	    void ustaw_kod_i_kase(int kod_karty, int many);
	    
	    void wykonaj_działanie();
	    
	    //pobierz
	    string pobierz_Nazwe(int index_Nazwy);
	    string pobierz_Tekst_Akcji(int index_Tekstu);	    
	    string pobierz_Typ();    
	    
};
//  0-nic się nie dzieje, wyświetla sam tekst
    //  1-trzeba zapłacić
    //  2-dostaje się bonus
    //  3-wykonuje się przejście na start i otrzymuje bonus
    //  4-trafia się do więzienia
    //  5-przechodzi się na darmowy parking bez bonusu
