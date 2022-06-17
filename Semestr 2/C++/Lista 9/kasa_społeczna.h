#pragma once

class Kasa_Społeczna: public Pole {
    
   
    int kod;
    int kasa;
	    
    public:
	
        Kasa_Społeczna();
        ~Kasa_Społeczna();
	    
	    void ustaw_kod_i_kase(int kod_karty, int many);
	    
	    void wykonaj_działanie();
	    
	    
};
//  0-nic się nie dzieje, wyświetla sam tekst
    //  1-trzeba zapłacić
    //  2-dostaje się bonus
    //  3-wykonuje się przejście na start i otrzymuje bonus
    //  4-trafia się do więzienia
    //  5-przechodzi się na darmowy parking bez bonusu
