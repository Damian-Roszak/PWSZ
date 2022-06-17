#pragma once

#include <cmath>
#include "pole.h"
#include "ruch.h"
#include "gracz.h"
#include "bankier.h"
#include "kosc.h"
#include "karta.h"

class Plansza {

        int ilosc_Graczy;
        int id_bankrutow[ilosc_Graczy];
        
    protected:
	    Pole pola[40];
	    Gracz* gracze;      
	    Ruch rusz;
	    Bank *bankier;
	    Kostka kosc;
	    Karta karty[100];

	public:
	    //konstruktor
	    Plansza(); 	
	     //destruktor
	    ~Plansza();

	friend class Bank;
void poka_Plansze(int pierwsze_Pole, int ostatnie_Pole, int numer_Gracza);


	    void utworz_Graczy();
	    void utworz_Bankiera();
	    void ustaw_Nazwe_Gracza(int numer_Gracza, string nazwa);
	    
	    void ruch(int numer_Gracza, int ile_Ruchu);
	    
	    Gracz* pobierz_Gracza(int numer);
	    string pobierz_Nazwe_Gracza(int numer_Gracza);
	    int pobierz_Lokalizacje_Gracza(int numer_Gracza);
	    int pobierz_Pieniadze_Gracza(int numer_Gracza);
	    string pobierz_typ_Pola(int index);
	    int pobierz_Akt_Wlasnosci_Pola(int index_Pola);
	    int pobierz_Cene_Wlasnosci_Pola(int index_Pola);

	    int pobierz_Czynsz_Pola(int index_Pola);
	    int pobierz_Podatek_Pola(int index_Pola);

	    string pobierz_Nazwe_Pola(int index_Pola, int index);
	    
	    void upgrade_Pola(int index_Pola);
	    bool czy_Gracz_Bankrut(int numer_Gracza);
	    bool czyGraczNieWWięzieniu(int numer_Gracza);
	    
	    void porazka_Gracza(int numer_Gracza);

        void ustaw_Wlasnosc_Pola(int index_Pola, int numer_Gracza);
        void inicjalizuj_Karty();
        
        void GRA();
        
};
Plansza::Plansza(){
	
	//Użycie funkcji z klasy Pole do inicjalizacji każdego z pól
	
	//pole 0
	pola[0].ustaw_Nazwe("   RUSZAJ!   ", "         ");
	pola[0].ustaw_Typ("START");
	pola[0].ustaw_Cene_Wlasnosci(0);
	pola[0].ustaw_Zajetosc(true);
	pola[0].ustaw_Czynsz(0);
	pola[0].ustaw_Tekst_Akcji("MINĄŁEŚ START RUSZAJ DALEJ! ", "Otrzymujesz 200PLN ");

	//pole 1
	nieruchomosc p1 ("dane", "dane"...);
	pole[1] = p1;
		pole[1] = new (dane...);
	pola[1].ustaw_Nazwe("  Aleja   ", "  Akademicka  ");
	pola[1].ustaw_Typ("Nieruchomość");
	pola[1].ustaw_Cene_Wlasnosci(60);
	pola[1].ustaw_Czynsz(2);
	pola[1].ustaw_Tekst_Akcji("         ", "  60PLN  ");
	pola[1].ustaw_cene_Domu(30);
	pola[1].ustaw_cene_Hotelu(4*pola[1].pobierz_cene_Domu()+50);

	//pole 2
	pola[2].ustaw_Nazwe("Kasa", "  Społeczna  ");
	pola[2].ustaw_Typ("karta");
	pola[2].ustaw_Cene_Wlasnosci(0);
	pola[2].ustaw_Zajetosc(true);
	pola[2].ustaw_Czynsz(0);
	pola[2].ustaw_Tekst_Akcji(" Weź  " ,"  Kartę   ");

	//pole 3
	pola[3].ustaw_Nazwe(" Obrońców  ", " Tobruku ");
	pola[3].ustaw_Typ("Nieruchomość");
	pola[3].ustaw_Cene_Wlasnosci(70);
	pola[3].ustaw_Czynsz(4);
	pola[3].ustaw_Tekst_Akcji("         ", "   60PLN   ");
	pola[3].ustaw_cene_Domu(40);
	pola[3].ustaw_cene_Hotelu(4*pola[3].pobierz_cene_Domu()+50);
	

	//pole 4
	pola[4].ustaw_Nazwe(" skarbówka ", " Nysa ");
	pola[4].ustaw_Typ("podatek");
	pola[4].ustaw_Cene_Wlasnosci(0);
	pola[4].ustaw_Zajetosc(true);
	pola[4].ustaw_Czynsz(4);
	pola[4].ustaw_Podatek(200);
	pola[4].ustaw_Tekst_Akcji("         ", "Płać 200PLN ");

	//pole 5
	pola[5].ustaw_Nazwe(" Głuchołazka  ", " Torpeda ");
	pola[5].ustaw_Typ("Linia Kolejowa");
	pola[5].ustaw_Cene_Wlasnosci(200);
	pola[5].ustaw_Czynsz(25);
	pola[5].ustaw_Tekst_Akcji("         ", "  200PLN   ");
	pola[5].ustaw_cene_Domu(50);
	pola[5].ustaw_cene_Hotelu(4*pola[5].pobierz_cene_Domu()+75);

	//pole 6
	pola[6].ustaw_Nazwe(" Głuchołazy  ", "  Rynek   ");
	pola[6].ustaw_Typ("Nieruchomość");
	pola[6].ustaw_Cene_Wlasnosci(100);
	pola[6].ustaw_Czynsz(6);
	pola[6].ustaw_Tekst_Akcji("         ", "  100PLN  ");
	pola[6].ustaw_cene_Domu(60);
	pola[6].ustaw_cene_Hotelu(4*pola[6].pobierz_cene_Domu()+75);
	
	//pole 7
	pola[7].ustaw_Nazwe(" Szansa  ", "         ");
	pola[7].ustaw_Typ("karta");
	pola[7].ustaw_Cene_Wlasnosci(0);
	pola[7].ustaw_Zajetosc(true);
	pola[7].ustaw_Czynsz(0);
	pola[7].ustaw_Tekst_Akcji(" Weź  ", "  kartę   ");

	//pole 8
	pola[8].ustaw_Nazwe("  Osiedle  ", "  Konstytucji  ");
	pola[8].ustaw_Typ("Nieruchomość");
	pola[8].ustaw_Cene_Wlasnosci(100);
	pola[8].ustaw_Czynsz(6);
	pola[8].ustaw_Tekst_Akcji("         ", "  100PLN  ");
	pola[8].ustaw_cene_Domu(70);
	pola[8].ustaw_cene_Hotelu(4*pola[8].pobierz_cene_Domu()+75);

	//pole 9
	pola[9].ustaw_Nazwe(" Plac  ", " Basztowy   ");
	pola[9].ustaw_Typ("Nieruchomość");
	pola[9].ustaw_Cene_Wlasnosci(120);
	pola[9].ustaw_Czynsz(8);
	pola[9].ustaw_Tekst_Akcji("         ", "  120PLN   ");
	pola[9].ustaw_cene_Domu(80);
	pola[9].ustaw_cene_Hotelu(4*pola[9].pobierz_cene_Domu()+75);


	//pole 10
	pola[10].ustaw_Nazwe(" OJOJ!  ", "         ");
	pola[10].ustaw_Typ("więzienie");
	pola[10].ustaw_Cene_Wlasnosci(0);
	pola[10].ustaw_Zajetosc(true);
	pola[10].ustaw_Czynsz(0);
	pola[10].ustaw_Tekst_Akcji("  ODWIEDZAJĄCY   ", "ODWIEDZAJĄCY ");

	//pole 11
	pola[11].ustaw_Nazwe(" Wieża  ", " Woka  ");
	pola[11].ustaw_Typ("Nieruchomość");
	pola[11].ustaw_Cene_Wlasnosci(140);
	pola[11].ustaw_Czynsz(10);
	pola[11].ustaw_Tekst_Akcji("         ", "  140PLN  ");
	pola[11].ustaw_cene_Domu(90);
	pola[11].ustaw_cene_Hotelu(4*pola[11].pobierz_cene_Domu()+100);

	//pole 12
	pola[12].ustaw_Nazwe(" Elektrownia ", " Atomowa ");
	pola[12].ustaw_Typ("Budynek Użyteczności Publicznej");
	pola[12].ustaw_Cene_Wlasnosci(150);
	pola[12].ustaw_Czynsz(10);
	pola[12].ustaw_Tekst_Akcji("         ", "  150PLN  ");
	pola[12].ustaw_czy_Mozna_Zabudowac(false);


	//pole 13
	pola[13].ustaw_Nazwe(" Prudnik ", "  Kościuszki   ");
	pola[13].ustaw_Typ("Nieruchomość");
	pola[13].ustaw_Cene_Wlasnosci(140);
	pola[13].ustaw_Czynsz(10);
	pola[13].ustaw_Tekst_Akcji("         ", "  140PLN  ");
	pola[13].ustaw_cene_Domu(110);
	pola[13].ustaw_cene_Hotelu(4*pola[13].pobierz_cene_Domu()+100);

	//pole 14
	pola[14].ustaw_Nazwe(" Prudnik  ", " Powstańców śląskich   ");
	pola[14].ustaw_Typ("Nieruchomość");
	pola[14].ustaw_Cene_Wlasnosci(160);
	pola[14].ustaw_Czynsz(12);
	pola[14].ustaw_Tekst_Akcji("         ", "  160PLN  ");
	pola[14].ustaw_cene_Domu(120);
	pola[14].ustaw_cene_Hotelu(4*pola[14].pobierz_cene_Domu()+100);

	//pole 15
	pola[15].ustaw_Nazwe(" PKP ", "   Prudnik   ");
	pola[15].ustaw_Typ("Linia Kolejowa");
	pola[15].ustaw_Cene_Wlasnosci(200);
	pola[15].ustaw_Czynsz(25);
	pola[15].ustaw_Tekst_Akcji("         ", "  200PLN  ");
	pola[15].ustaw_cene_Domu(130);
	pola[15].ustaw_cene_Hotelu(4*pola[15].pobierz_cene_Domu()+100);

	//pole 16
	pola[16].ustaw_Nazwe("  Brzeg  ", "  Bolesława Chrobrego  ");
	pola[16].ustaw_Typ("Nieruchomość");
	pola[16].ustaw_Cene_Wlasnosci(180);
	pola[16].ustaw_Czynsz(14);
	pola[16].ustaw_Tekst_Akcji("         ", "  180PLN  ");
	pola[16].ustaw_cene_Domu(140);
	pola[16].ustaw_cene_Hotelu(4*pola[16].pobierz_cene_Domu()+125);

	//pole 17
	pola[17].ustaw_Nazwe("Kasa", "  Społeczna  ");
	pola[17].ustaw_Typ("karta");
	pola[17].ustaw_Cene_Wlasnosci(0);
	pola[17].ustaw_Zajetosc(true);
	pola[17].ustaw_Czynsz(0);
	pola[17].ustaw_Tekst_Akcji(" Weź  ", "  Kartę   ");

	//pole 18
	pola[18].ustaw_Nazwe("  Brzeg   ", "  Kazimierza Wielkiego  ");
	pola[18].ustaw_Typ("Nieruchomość");
	pola[18].ustaw_Cene_Wlasnosci(180);
	pola[18].ustaw_Czynsz(14);
	pola[18].ustaw_Tekst_Akcji("         ", "  180PLN ");
	pola[18].ustaw_cene_Domu(150);
	pola[18].ustaw_cene_Hotelu(4*pola[18].pobierz_cene_Domu()+125);

	//pole 19
	pola[19].ustaw_Nazwe("  Brzeg   ", " Rynek  ");
	pola[19].ustaw_Typ("Nieruchomość");
	pola[19].ustaw_Cene_Wlasnosci(200);
	pola[19].ustaw_Czynsz(16);
	pola[19].ustaw_Tekst_Akcji("         ", "  200PLN ");
	pola[19].ustaw_cene_Domu(160);
	pola[19].ustaw_cene_Hotelu(4*pola[19].pobierz_cene_Domu()+125);

	//pole 20
	pola[20].ustaw_Nazwe(" Darmowy ", "   Parking   ");
	pola[20].ustaw_Typ("Darmowy Parking");
	pola[20].ustaw_Cene_Wlasnosci(0);
	pola[20].ustaw_Zajetosc(true);
	pola[20].ustaw_Czynsz(0);
	pola[20].ustaw_Tekst_Akcji("         ", "         ");

	//pole 21
	pola[21].ustaw_Nazwe(" Aleja  ", " Powstańców Warszawskich ");
	pola[21].ustaw_Typ("Nieruchomość");
	pola[21].ustaw_Cene_Wlasnosci(220);
	pola[21].ustaw_Czynsz(18);
	pola[21].ustaw_Tekst_Akcji("         ", "  220PLN  ");
	pola[21].ustaw_cene_Domu(170);
	pola[21].ustaw_cene_Hotelu(4*pola[21].pobierz_cene_Domu()+150);

	//pole 22
	pola[22].ustaw_Nazwe(" Szansa  ", "         ");
	pola[22].ustaw_Typ("karta");
	pola[22].ustaw_Cene_Wlasnosci(0);
	pola[22].ustaw_Zajetosc(true);
	pola[22].ustaw_Czynsz(0);
	pola[22].ustaw_Tekst_Akcji(" Weź  ", "  Kartę   ");

	//pole 23
	pola[23].ustaw_Nazwe(" Aleja ", " Dębowa  ");
	pola[23].ustaw_Typ("Nieruchomość");
	pola[23].ustaw_Cene_Wlasnosci(220);
	pola[23].ustaw_Czynsz(18);
	pola[23].ustaw_Tekst_Akcji("         ", "  220PLN  ");
	pola[23].ustaw_cene_Domu(180);
	pola[23].ustaw_cene_Hotelu(4*pola[23].pobierz_cene_Domu()+150);

	//pole 24
	pola[24].ustaw_Nazwe(" Aleja ", "  Jana Pawła II  ");
	pola[24].ustaw_Typ("Nieruchomość");
	pola[24].ustaw_Cene_Wlasnosci(240);
	pola[24].ustaw_Czynsz(20);
	pola[24].ustaw_Tekst_Akcji("         ", "  240PLN  ");
	pola[24].ustaw_cene_Domu(190);
	pola[24].ustaw_cene_Hotelu(4*pola[24].pobierz_cene_Domu()+150);

	//pole 25
	pola[25].ustaw_Nazwe(" Kolej ", " Magnetyczna ");
	pola[25].ustaw_Typ("Linia Kolejowa");
	pola[25].ustaw_Cene_Wlasnosci(200);
	pola[25].ustaw_Czynsz(25);
	pola[25].ustaw_Tekst_Akcji("         ", "  200PLN  ");
	pola[25].ustaw_cene_Domu(200);
	pola[25].ustaw_cene_Hotelu(4*pola[25].pobierz_cene_Domu()+150);

	//pole 26
	pola[26].ustaw_Nazwe(" Opole ", "  Kopernika  ");
	pola[26].ustaw_Typ("Nieruchomość");
	pola[26].ustaw_Cene_Wlasnosci(260);
	pola[26].ustaw_Czynsz(22);
	pola[26].ustaw_Tekst_Akcji("         ", "  260PLN  ");
	pola[26].ustaw_cene_Domu(210);
	pola[26].ustaw_cene_Hotelu(4*pola[26].pobierz_cene_Domu()+175);

	//pole 27
	pola[27].ustaw_Nazwe(" Opole  ", " Katowicka ");
	pola[27].ustaw_Typ("Nieruchomość");
	pola[27].ustaw_Cene_Wlasnosci(260);
	pola[27].ustaw_Czynsz(22);
	pola[27].ustaw_Tekst_Akcji("         ", "  260PLN  ");
	pola[27].ustaw_cene_Domu(220);
	pola[27].ustaw_cene_Hotelu(4*pola[27].pobierz_cene_Domu()+175);

	//pole 28
	pola[28].ustaw_Nazwe(" Wodociągi ", "  ");
	pola[28].ustaw_Typ("Budynek Użyteczności Publicznej");
	pola[28].ustaw_Cene_Wlasnosci(150);
	pola[28].ustaw_Czynsz(10);
	pola[28].ustaw_Tekst_Akcji("         ", "  150PLN  ");
	pola[28].ustaw_cene_Domu(230);
	pola[28].ustaw_cene_Hotelu(4*pola[28].pobierz_cene_Domu()+175);

	//pole 29
	pola[29].ustaw_Nazwe(" Opole  ", " Kępska ");
	pola[29].ustaw_Typ("Nieruchomość");
	pola[29].ustaw_Cene_Wlasnosci(280);
	pola[29].ustaw_Czynsz(22);
	pola[29].ustaw_Tekst_Akcji("         ", "  280PLN  ");
	pola[29].ustaw_cene_Domu(240);
	pola[29].ustaw_cene_Hotelu(4*pola[29].pobierz_cene_Domu()+175);

	//pole 30
	pola[30].ustaw_Nazwe(" Idziesz do ", " więzienia ");
	pola[30].ustaw_Typ("RuchDoWięzienia");
	pola[30].ustaw_Cene_Wlasnosci(0);
	pola[30].ustaw_Zajetosc(true);
	pola[30].ustaw_Czynsz(0);
	pola[30].ustaw_Tekst_Akcji("         ", "         ");
	pola[30].ustaw_kod_Akcji(1);
	pola[30].ustaw_czekanie_kolejek(3);

	//pole 31
	pola[31].ustaw_Nazwe(" Gdańsk ", "  Pomorska   ");
	pola[31].ustaw_Typ("Nieruchomość");
	pola[31].ustaw_Cene_Wlasnosci(300);
	pola[31].ustaw_Czynsz(26);
	pola[31].ustaw_Tekst_Akcji("         ", "  300PLN  ");
	pola[31].ustaw_cene_Domu(250);
	pola[31].ustaw_cene_Hotelu(4*pola[31].pobierz_cene_Domu()+200);

	//pole 32
	pola[32].ustaw_Nazwe("  Gdańsk  ", " Opolska  ");
	pola[32].ustaw_Typ("Nieruchomość");
	pola[32].ustaw_Cene_Wlasnosci(300);
	pola[32].ustaw_Czynsz(26);
	pola[32].ustaw_Tekst_Akcji("         ", "  300PLN  ");
	pola[32].ustaw_cene_Domu(260);
	pola[32].ustaw_cene_Hotelu(4*pola[32].pobierz_cene_Domu()+200);

	//pole 33
	pola[33].ustaw_Nazwe("Kasa", "  Społeczna  ");
	pola[33].ustaw_Typ("karta");
	pola[33].ustaw_Cene_Wlasnosci(0);
	pola[33].ustaw_Zajetosc(true);
	pola[33].ustaw_Czynsz(0);
	pola[33].ustaw_Tekst_Akcji(" Weź  ", "  Kartę   ");

	//pole 34
	pola[34].ustaw_Nazwe(" Opera  ", " Leśna   ");
	pola[34].ustaw_Typ("Nieruchomość");
	pola[34].ustaw_Cene_Wlasnosci(320);
	pola[34].ustaw_Czynsz(28);
	pola[34].ustaw_Tekst_Akcji("         ", "  320PLN  ");
	pola[34].ustaw_cene_Domu(270);
	pola[34].ustaw_cene_Hotelu(4*pola[34].pobierz_cene_Domu()+200);

	//pole 35
	pola[35].ustaw_Nazwe("   Dworzec   ", " Centralny ");
	pola[35].ustaw_Typ("Linia Kolejowa");
	pola[35].ustaw_Cene_Wlasnosci(200);
	pola[35].ustaw_Czynsz(25);
	pola[35].ustaw_Tekst_Akcji("         ", "  200PLN  ");
	pola[35].ustaw_cene_Domu(280);
	pola[35].ustaw_cene_Hotelu(4*pola[35].pobierz_cene_Domu()+200);

	//pole 36
	pola[36].ustaw_Nazwe(" Szansa  ", "         ");
	pola[36].ustaw_Typ("karta");
	pola[36].ustaw_Cene_Wlasnosci(0);	
	pola[36].ustaw_Zajetosc(true);
	pola[36].ustaw_Czynsz(0);
	pola[36].ustaw_Tekst_Akcji(" Weź  ", "  Kartę   ");

	//pole 37
	pola[37].ustaw_Nazwe(" Kraków  ", " Kopiec Kościuszki ");
	pola[37].ustaw_Typ("Nieruchomość");
	pola[37].ustaw_Cene_Wlasnosci(350);
	pola[37].ustaw_Czynsz(35);
	pola[37].ustaw_Tekst_Akcji("         ", "  350PLN  ");
	pola[37].ustaw_cene_Domu(290);
	pola[37].ustaw_cene_Hotelu(4*pola[37].pobierz_cene_Domu()+250);

	//pole 38
	pola[38].ustaw_Nazwe(" PODATEK OD", "  WZBOGACENIA   "); 
	pola[38].ustaw_Typ("podatek");
	pola[38].ustaw_Cene_Wlasnosci(0);
	pola[38].ustaw_Zajetosc(true);
	pola[38].ustaw_Czynsz(0);
	pola[38].ustaw_Podatek(75);
	pola[38].ustaw_Tekst_Akcji("         ", " Płać 75PLN ");

	//pole 39
	pola[39].ustaw_Nazwe(" Kraków ", " Wawel ");
	pola[39].ustaw_Typ("Nieruchomość");
	pola[39].ustaw_Cene_Wlasnosci(400);
	pola[39].ustaw_Czynsz(50);
	pola[39].ustaw_Tekst_Akcji("         ", "  400PLN  "); 
	pola[39].ustaw_cene_Domu(300);
	pola[39].ustaw_cene_Hotelu(4*pola[39].pobierz_cene_Domu()+250);      
	
	utworz_Graczy();
    utworz_Bankiera();
    inicjalizuj_Karty();
}

Plansza::~Plansza(){
 //destruktor obiektu typu Plansza
  delete [] gracze;
  delete bankier;
 }

void Plansza::utworz_Graczy(int ilosc){
    if (ilosc > 0)
	{	    
       ilosc_Graczy = ilosc;
	   gracze = new Gracz[ilosc_Graczy];
	   for(int i=0; i<ilosc_Graczy; i++)  id_bankrutow[i] = 0;
    }
	else
	    cout << "\n Żaden gracz NIE został utworzony \n";    
	    
}

void Plansza::utworz_Bankiera(){
    bankier = new Bank;
    for (int i=0; i<ilosc_Graczy; i++)
    {
        bankier->daj_pieniadze_graczowi(gracz[i], 1500);
    }
}

void Plansza::inicjalizuj_Karty(){
    // funkcja inicjalizująca karty, nadająca im kody działania, tekst wyświetlany po jej wyciągnięciu, i ewentualnie ilość pieniedzy do działania
    // kody to:
    //  0-nic się nie dzieje, wyświetla sam tekst
    //  1-trzeba zapłacić
    //  2-dostaje się bonus
    //  3-wykonuje się przejście na start i otrzymuje bonus
    //  4-trafia się do więzienia
    //  5-przechodzi się na darmowy parking bez bonusu
}

string Plansza::pobierz_Nazwe_Gracza(int numer_Gracza){
	return gracze[numer_Gracza].pobierz_Nazwe_Gracza();
}

int Plansza::pobierz_Lokalizacje_Gracza(int numer_Gracza){
	return gracze[numer_Gracza].pobierz_Lokalizacje();
}

bool Plansza::czy_Gracz_Bankrut(int numer_Gracza){
	return gracze[numer_Gracza].czy_Bankrut();
}

bool Plansza::czyGraczNieWWięzieniu(int numer_Gracza){
	return czy_W_Wiezieniu(numer_Gracza);
}





