#pragma once

#include "gracz.h"
#include <string>
using namespace std;

class Ruch {


	public:
	//konstruktor
	Ruch();
	~Ruch();

	// funkcje
	friend void Plansza::upgrade_Pola(int index_Pola);

	void rusz_o_ilosc(Gracz *gracz, int ile_Pol);
	
	 
};

