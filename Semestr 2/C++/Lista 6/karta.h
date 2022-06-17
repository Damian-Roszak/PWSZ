#pragma once

#include <string>


using namespace std;

class Karta {
    
    int kod;
    int kasa;
    string tekst_karty;
    
    public:
        Karta();
        Karta(int k, int ks, string s); // konstruktor kopiujący
       // Karta(int k, int ks, string s);
        ~Karta();

};
