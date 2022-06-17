#pragma once
#include <string>
#include <iostream>

using namespace std;


class Gracz {
        
	    static int licznik_Graczy;
	    
	    int ile_Pieniedzy;
	    bool aktywny;
	    bool bankrut;
	    int ilosc_pozostalych_kolejek; // 0-bez czekania lub ilość kolejek bez ruchu

	public:
	
	const string nazwa_Gracza; 
	int lokalizacja;
	
	friend class Bank;
    friend class Plansza;    
     
    friend void Wiezienie::przerzuc_na_pole_wiezienia(Gracz & gracz, bool aktywny );
        
          
        
	    //konstruktory
	    Gracz();
	    ~Gracz();

	    //funkcje do ustawiania wartości
	    void ustaw_Nazwe_Gracza();
	    void ustaw_Posiadane_Wlosci(int index, bool czy_Posiadane); 
	    void ustaw_Ilosc_Pieniedzy(int ile_forsy);
	    void ustaw_Ilosc_Pozostalych_Kolejek(int ile_tur); 
	
	    //funkcje do pobierania wartości
	    string pobierz_Nazwe_Gracza();
	    int pobierz_Ilosc_Pieniedzy();
	    bool pobierz_Posiadane_Wlosci(int index);
	    int pobierz_Lokalizacje();
	    bool czy_Bankrut();
	    static int podaj_licznik_Graczy();
	    int pobierz_Ilosc_Pozostalych_Kolejek();

	    //pozostałe funkcje
	    void daj_Pieniadze(int ile);
	    void wez_Pieniadze(int ile);
	    void rusz_Gracza(int ile);
	    void reset();	    

};

bool Gracz::czy_Bankrut()
{
    return bankrut;
}
