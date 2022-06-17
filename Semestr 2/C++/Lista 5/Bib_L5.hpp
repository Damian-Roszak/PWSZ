#ifndef Bib_L5
#define Bib_L5
#include <vector> 
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <limits.h>

using namespace std;



void menuGlowne();
int wczytajTryb(int &tryb);
void menuWymiar();
int wczytajWymiar(int &wymiar);
void menuStopienTrudnosci();
int wczytajStopienTrudnosci(int &stopienTrudnosci);

int sizeVectory(vector<vector<char>> &t);

void graj(vector<vector<char>> &t, int wymiar);
void graj_VS_CPU(vector<vector<char>> &t, int wymiar, int stopienTrudnosci);

void inicjuj_plansze(vector<vector<char>> &t, int wymiar);
void rysuj_plansze(vector<vector<char>> &t, int wymiar);


void ruch(vector<vector<char>> &t, int wymiar, char &gracz);
bool remis(vector<vector<char>> &t, int wymiar);
bool wygrana(vector<vector<char>> &t, int wymiar, char g);

void ruchCPU(vector<vector<char>> &t, int wymiar, char &gracz, int stopienTrudnosci, int t_pozX[][2], int t_pozO[][2]);

void CPU_VS_CPU(vector<vector<char>> &t, int wymiar, int stopienTrudnosci);
void ruchCPUvsCPU(vector<vector<char>> &t, int wymiar, char &gracz, int stopienTrudnosci, int t_pozO[][2], int t_pozX[][2]);

void zrob_Info(vector< vector<char> > t, int wymiar, char gracz, int stopienTrudnosci, int t_pozO[][2], int t_pozX[][2]);
int czy_zbliza_sie_do_wygranej(vector<vector<char>> t, int t_pozX[][2], int t_pozO[][2], int wymiar);

char losuj_kto_pierwszy();

#endif
