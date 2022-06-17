#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
//#include"mala_klasa.hpp"

using namespace std;

class Mala_Klasa {
    
    static vector <int> wektor_zbioru;
    
    public:
            static void wypelnij();
            static int minimum();
            static int maksimum();
            
            static double srednia();
            static double mediana();
            static int dominanta();

};


    vector <int> Mala_Klasa::wektor_zbioru;


int main()
{
    srand(time(0));
    
    int min, maks, dom;
    double sr, med;
    
    Mala_Klasa::wypelnij();
    
    min = Mala_Klasa::minimum();
    
    maks = Mala_Klasa::maksimum();
    
    sr = Mala_Klasa::srednia();
    
    dom = Mala_Klasa::dominanta();
    
    med = Mala_Klasa::mediana();


return 5;
}

