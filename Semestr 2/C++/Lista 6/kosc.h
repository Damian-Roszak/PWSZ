#pragma once
#include <iostream>
using namespace std;

class Kostka {

	    int ile_stron;

	public:
	
	friend void Ruch::rusz_o_ilosc(Gracz *gracz, int ile_Pol);
	
	    Kostka(); 
	    ~Kostka(); 
	
	    int rzut_Kostka();	    

};

