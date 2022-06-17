#include <iostream>
#include <vector>
#include "darmowy_parking.h"
#include "elektrownia.h"
#include "kasa_społeczna.h"
#include "miasto.h"
#include "nieruchomosc.h"
#include "podatek.h"
#include "podatek_od_luksusu.h"
#include "pole.h"
#include "ulica.h"
#include "wiezienie.h"
#include "wiezienie_odwiedziny.h"
#include "plansza.h"
//#include ""
//#include ""
//#include ""
//#include ""
//#include ""
//#include ""

using namespace std;


int main()
{
srand(time(0));
    int ileGraczy = 0;
    char pionki[10] = {'~', '!', '@', '#', '$', '%', '^', '&', '*', '?'};
    int ilePionków = 10; 

cout << "Ilu graczy chce grać? ";
cin >> ileGraczy;


    Plansza plansza;
    plansza.utworz_Graczy(ileGraczy);   

    
    int rzutKoscia1;
    int rzutKoscia2;
    int iluZywych = ileGraczy;

    while(iluZywych > 1){
    
     
    for (int i = 0; i < ileGraczy; i++){

      if(plansza.czy_Gracz_Bankrut(i) == false && plansza.czyGraczNieWWięzieniu(i) == false){

    	cout << "Teraz kolej gracza: " << plansza.pobierz_Nazwe_Gracza(i);
    	cout << "!" << endl;
	
	int odp = 0;
	
	while(odp != 1){
	    do{
		    cout << "Wybierz opcje..." << endl;
		    cout << " 1. Rzuć kośćmi" << endl;
		    cout << " 2. Upgrade - kup ulice lub nieruchomość itp." << endl;
		    cout << " 3. Następny gracz" << endl;
		    cout << "Która opcja: ";
		    cin >> odp;
		    
             if(odp < 1 || odp > 3){
			   cout << "\nOpcja z poza zakresu... Spróbuj jeszcze raz!" << endl << endl;
		     }	
	    } while (odp < 1 || odp > 3);


				//is out of money! He drops out of the game!
				// "All of " << plansza.getPlayerName(i) << "'s properties are now returned to the bank." 
				

	//if the space is Go To Jail...
	//if the space is Community Chest...
	//if the space is Chance...	
 switch(odp){
	case 1:
	{   //zrob ruch:
	    //rzuć koścmi, jeśli wypadną dwie 6 będzie powtórka rzutu gdy 3 razy z rzędu wypadną dwie 6 gracz idzie do więzienia i ruch ma następny gracz	    
	    rzutKoscia1 = rand()%6+1;
        rzutKoscia2 = rand()%6+1;
        bool mv = true;
        int ile_6 = 0;
        while(mv){
        cout << "Wyrzuciłeś na kościach " << rzutKoscia1 + rzutKoscia2 << " oczek." << endl << endl;
            if(rzutKoscia1 == 6 && rzutKoscia2 == 6){
              ile_6++;
              if(ile_6 == 3){
                plansza.graczDoWiezienia(gracz);
                mv = false;
                i++;
                break;
              }
              plansza.zrobRuch(gracz, rzutKoscia1 + rzutKoscia2);
              //po rzucie przesuń gracza o wyrzuconą ilość oczek, sprawdź czy ma zapłacić za stanie na tym polu - bo ktoś jest właścicielem lub to opodatkowane pole
	    // jeśli tak, pobierz opłate jeśli gracz nie ma gotówki na zapłate, ale ma nieruchomości to może zaciągnąć kredyt i uregulować należność, w przypadku gdy nie chce zaciągnąć kredytu lub nie ma nieruchomości pod zastaw bankrutuje
	            int poprzedniaLokacja = plansza.pobierzLokalizacjeGracza(i);
	            int obecnaLokacja = plansza.pobierzLokalizacjeGracza(i);
	            if (obecnaLokacja == idźDoWięzienia){
	                    plansza.graczDoWiezienia(gracz)
	                    mv = false;
                        i++;
                        break;
	            }
	            int obecnyWłaściciel = plansza.pobierzKtoJestWłaścicielem(obecnaLokacja);
	            if (obecnaLokacja == obecnyWłaściciel.NIERUCHOMOŚĆ.wolna){
	                    cout << jesteś na wolnym miejscu możesz kupić to miejsce
	                    //kup lub nie i przejdź do następnego rzutu
	            }
	            else if (obecnaLokacja == obecnyWłaściciel.NIERUCHOMOŚĆ.GRACZA){
	                    cout << jesteś u siebie możesz kupić nieruchomość
	                    //kup lub nie i przejdź do następnego rzutu
	            }
                else if (obecnaLokacja == obecnyWłaściciel.NIERUCHOMOŚĆ.zajęta){
	                    cout << jesteś u kogoś płacisz czynsz lub podatek
	                    //płać i przejdź do następnego rzutu lub bankrutuj
	            }
	            else
	            {
	                cout << lokacja wolna od czynszu
	            }

	            if(obecnaLokacja-40 > 0){//FORMUŁA DO POZYCJI CHWILOWEJ PRZED USTAWIENIEM WŁAŚCIWEJ
		            Bank(plansza.Gracz(i), dodaj,  200);
		            cout << "*** Minąłeś start! dostajesz 200 PLN !!! ***" << endl << endl;
	            }

	        rzutKoscia1 = rand()%6+1;
            rzutKoscia2 = rand()%6+1;
           }
           else{
                plansza.zrobRuch(gracz, rzutKoscia1 + rzutKoscia2);
                mv = false;
              //po rzucie przesuń gracza o wyrzuconą ilość oczek, sprawdź czy ma zapłacić za stanie na tym polu - bo ktoś jest właścicielem lub to opodatkowane pole
	    // jeśli tak, pobierz opłate jeśli gracz nie ma gotówki na zapłate, ale ma nieruchomości to może zaciągnąć kredyt i uregulować należność, w przypadku gdy nie chce zaciągnąć kredytu lub nie ma nieruchomości pod zastaw bankrutuje
	            int poprzedniaLokacja = plansza.pobierzLokalizacjeGracza(i);
	            int obecnaLokacja = plansza.pobierzLokalizacjeGracza(i);
	            if (obecnaLokacja == idźDoWięzienia){
	                    plansza.graczDoWiezienia(gracz)
                        break;
	            }
	            int obecnyWłaściciel = plansza.pobierzKtoJestWłaścicielem(obecnaLokacja);
	            if (obecnaLokacja == obecnyWłaściciel.NIERUCHOMOŚĆ.wolna){
	                    cout << jesteś na wolnym miejscu możesz kupić to miejsce
	                    //kup lub nie i przejdź do następnego rzutu
	            }
	            else if (obecnaLokacja == obecnyWłaściciel.NIERUCHOMOŚĆ.GRACZA){
	                    cout << jesteś u siebie możesz kupić nieruchomość
	                    //kup lub nie i przejdź do następnego rzutu
	            }
                else if (obecnaLokacja == obecnyWłaściciel.NIERUCHOMOŚĆ.zajęta){
	                    cout << jesteś u kogoś płacisz czynsz lub podatek
	                    //płać i przejdź do następnego rzutu lub bankrutuj
	            }
	            else
	            {
	                cout << lokacja wolna od czynszu
	            }

	            if(obecnaLokacja-40 > 0){//FORMUŁA DO POZYCJI CHWILOWEJ PRZED USTAWIENIEM WŁAŚCIWEJ
		            Bank(plansza.Gracz(i), dodaj,  200);
		            cout << "*** Minąłeś start! dostajesz 200 PLN !!! ***" << endl << endl;
	            }
             
             i++;
           }             
        }	
	  break;
	}  
	case 2:
	{
        //czy gracz znajduje się na wolnym polu lub należącym do niego
        //jeśli tak to czy ma odowiednią ilość gotówki do zakupu nieruchomości, domku lub hotelu
        //jeśli nie to następny gracz
        if(plansza.graczLokalizacja.Wlasciciel == 0 || plansza.graczLokalizacja.Wlasciciel == numerGracza)
        {
            //jesli ulica wolna kup ulice jak już należy do gracza kup domek
            if(kasaGracza >= ileTrzebaZapłacić){
                kup();
            }
            else{
                i++;
            }
        }
        else i++;
    break;
	}
	case 3:
	    //następny gracz
        i++;
	    
	    
	    
	break;
	}
	
	
	
	
	}
}
else if(plansza.czy_Gracz_Bankrut(i) == false && plansza.czyGraczNieWWięzieniu(i) == true)
{
    cout << "\n Graczowi nr: " << plansza.czyGraczNieWWięzieniu(i) << " pozostało " <<  << " kolejek w więzieniu.";
    //zmniejsz ilość kolejek
}


if(i == ileGraczy) i = 0;
}



}
cout << "GRATULACJE "<< gracz.zywy.pobierzNazwe() <<"!!!!!!!!!! WYGRAŁEŚ\n ZOSTAŁEŚ  MONOPOLISTĄ"<< endl;






return 5;
}



