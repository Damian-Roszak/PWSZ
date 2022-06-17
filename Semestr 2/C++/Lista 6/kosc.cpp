#include "kosc.h"
#include <cstdlib>
#include <ctime>

Kostka::Kostka(){
	ile_stron = 6;
}

Kostka::~Kostka(){}

int Kostka::rzut_Kostka(){

	int rzut = 0;
	rzut = rand() % ile_stron + 1;
	cout << "\n Rzut kostką: " << rzut << endl;
	return rzut;
}
