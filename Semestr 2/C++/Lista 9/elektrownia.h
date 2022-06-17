#pragma once

class Elektrownia: public Nieruchomosc {


    public:

    friend void Plansza::upgrade_Pola(int index_Pola);


        Elektrownia();
        ~Elektrownia();
};
