#ifndef Bib_Prog2_Lista_4_zad_2
#define Bib_Prog2_Lista_4_zad_2
#include <vector> 
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <ctime>

using namespace std;


vector<vector<int>> wieksza_mniejsza(int rozmiar, vector<vector<int>> m1, vector<vector<int>> m2);


void wczytaj_macierze(int &rozmiar, vector<vector<int>> & m1, vector<vector<int>>& m2);

void poka_macierz(int rozmiar, vector<vector<int>> m1);


        vector<vector<int>> opcja1(int rozmiar, vector<vector<int>> m1, vector<vector<int>> m2);

        vector<vector<int>> opcja2(int rozmiar, vector<vector<int>> m1, vector<vector<int>> m2);

        vector<vector<int>> opcja3(int rozmiar, vector<vector<int>> m1, vector<vector<int>> m2);

#endif
