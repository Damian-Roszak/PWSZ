#pragma once

class Elektrownia: public Pole, public Ulica {

	    
    public:
	
    friend void Plansza::upgrade_Pola(int index_Pola);
    
    
        Elektrownia();
        ~Elektrownia();
};
