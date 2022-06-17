#include "bankier.h"

Bank::Bank(){
     //konstruktor obiektu typu Gracz
}

Bank::~Bank(){
     //destruktor obiektu typu Gracz
}

void Bank::pobierz_pieniadze_od_gracza(Gracz& gracz, int ile_pobrac){
	//bankier pobiera 2 obiekty: gracza i sume do przekazania a następnie odbiera graczowi wskazaną kwotę
}

void Bank::daj_pieniadze_graczowi(Gracz& gracz, int ile_dac){
    	//bankier pobiera 2 obiekty: gracza i sume do przekazania a następnie dopisuje graczowi wskazaną kwotę
    	gracz.ustaw_Ilosc_Pieniedzy(gracz.pobierz_Ilosc_Pieniedzy() + ile_dac);
}

void Bank::kupuje_gracz (Gracz  &  gracz, Pole &  miejsce){
    //bankier przeprowadza transakcje: odczytuje ile kosztuje miejsce z pola ceny, następnie, pobiera odpowiednią kwotę od gracza i ustawia index własnosci gracza na nr pola na planszy oraz miejscu który gracz jest jego właścicielem oraz że jest od tej pory zajęte
}

void Bank::sprzedaje_gracz (Gracz & gracz_Kupujacy, Gracz & gracz_Sprzedajacy, Pole & miejsce, int kwota_sprzedazy){
    //bankier przeprowadza transakcje: sprawdza czy gracz kupujący posiada odpowiednią ilość pieniędzy gdy tak: pobiera odpowiednią kwotę, przekazuje ją graczowi sprzedającemu i ustawia index własnosci gracza kupującego na nr pola na planszy oraz miejscu który gracz jest jego właścicielem 
}

void Bank::kredyt(Gracz & gracz, Pole & miejsce){
    //bank udziela pożyczek pod zastaw nieruchomości. Pożyczka wynosi połowę wartości danego obiektu. Bank wypłaca pieniądze - dodając je graczowi, ustawia hipoteke na obiekcie miejsce
}

void Bank::kupuje_Bank(Gracz &  gracz, Pole &  miejsce){
//bank odkupuje od gracza domy i hotele, ale za połowę ich wartości.
}
