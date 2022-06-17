#pragma once

#include <string>
#include <iostream>
#include "gracz.h"
#include "pole.h"

using namespace std;

class Bank {

public:

    friend void Plansza::utworz_Bankiera();
     

	Bank();	
	~Bank();
    int pobierz_Czynsz_Pola(int index_Pola);
    void ustaw_Wlasciciela(int posiadane_przez);
    void pobierz_pieniadze_od_gracza(Gracz & gracz, int ile_pobrac);
    void daj_pieniadze_graczowi(Gracz & gracz, int ile_dac);

    void kupuje_gracz (Gracz &gracz, Pole & miejsce);
    void sprzedaje_gracz (Gracz & gracz_Kupujacy, Gracz &  gracz_Sprzedajacy, Pole  & miejsce, int kwota_sprzedazy);
    
    void kredyt(Gracz &  gracz, Pole &  miejsce);
    void kupuje_Bank(Gracz &  gracz, Pole &  miejsce);
};

