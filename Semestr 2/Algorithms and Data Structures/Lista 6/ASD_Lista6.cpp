#include<iostream>
#include<time.h>
#include<cstdlib>
#include<vector>

#include "poczatek_ini.hpp"
#include "calkowite.hpp"
#include "rzeczywiste.hpp"
//#include "wspolne.hpp"

#include <chrono>

using namespace std;


int     rozmiar_30_tys = 30000,             rozmiar_500_tys = 500000,
        rozmiar_50_tys = 50000,             rozmiar_1_mln = 1000000,
        rozmiar_100_tys = 100000,           rozmiar_2_mln = 2000000,
        rozmiar_150_tys = 150000,           rozmiar_5_mln = 5000000,
        rozmiar_200_tys = 200000,           rozmiar_10_mln = 10000000 ;
        
        
         vector <int> tc1;          vector <int> tc6;
         vector <int> tc2;          vector <int> tc7;
         vector <int> tc3;          vector <int> tc8;
         vector <int> tc4;          vector <int> tc9;
         vector <int> tc5;          vector <int> tc10;
         vector <int> c_vec_usr; 
         
         
         vector <double> td1;          vector <double> td6;
         vector <double> td2;          vector <double> td7;
         vector <double> td3;          vector <double> td8;
         vector <double> td4;          vector <double> td9;
         vector <double> td5;          vector <double> td10;
         vector <double> d_vec_usr;

//void wszystkie_C (vector <int> c_vec_usr);
//void wszystkie_D (vector <double> d_vec_usr);


int main(){
    srand(time(0));
    char calkowite_czy_rzeczywiste;
    
 char opcja;
 string sciezka = "sort.txt";

    int rozmiar_usr, zakres;
        

//cout << "\nrozmiar_30_tys:" << rozmiar_30_tys;
    

    cout << "\n Jaki rodzaj liczb zdefiniować (c)ałkowite czy (r)zeczywiste?: ";
    cin >> calkowite_czy_rzeczywiste;
    cout << "\n Jaki rozmiar użytkownika?: ";
    cin >> rozmiar_usr;
    
    switch (calkowite_czy_rzeczywiste)
    {
        case 'c':       
                    tc1.resize(rozmiar_30_tys);
                    tc2.resize(rozmiar_50_tys);
                    tc3.resize(rozmiar_100_tys);
                    tc4.resize(rozmiar_150_tys);
                    tc5.resize(rozmiar_200_tys);
                    tc6.resize(rozmiar_500_tys);
                    tc7.resize(rozmiar_1_mln);
                    tc8.resize(rozmiar_2_mln);
                    tc9.resize(rozmiar_5_mln);
                    tc10.resize(rozmiar_10_mln);
                c_vec_usr.resize(rozmiar_usr);
                //cout << "\n rozm usr przed wypelnij: " << c_vec_usr.capacity();
                wypelnij_calkowite( tc1); 
                wypelnij_calkowite( tc2); 
                wypelnij_calkowite( tc3); 
                wypelnij_calkowite( tc4); 
                wypelnij_calkowite( tc5); 
                wypelnij_calkowite( tc6); 
                wypelnij_calkowite( tc7); 
                wypelnij_calkowite( tc8); 
                wypelnij_calkowite( tc9); 
                wypelnij_calkowite( tc10);
                wypelnij_calkowite( c_vec_usr); 
                //cout << "\n rozm usr po wype: " << c_vec_usr.capacity();
                
                //poka_C(c_vec_usr);                
                while (opcja != 'k' && opcja != 'K'){         
                        cout << "\n\t ++++ Sortowanie Całkowite++++\n";
                        cout << "\t==========================================  \n";
                        cout << "\t\t TABLICE PREDEFINIOWAWNE:  \n";
                        cout << "\t 1) Sortowanie WYBRANEJ predefiniowanEJ tablicY WSZYSTKIMI algorytmami  \n";
                        cout << "\t 2) Sortowanie WSZYSTKICH predefiniowanych tablic po kolei wybranym algorytmem \n";
                        cout << "\t 3) Sortowanie WYBRANEJ JEDNEJ predefiniowanEJ tablicY JEDNYM algorytmEM \n";
                        cout << "\t 4) Sortowanie WSZYSTKICH predefiniowanych tablic WSZYSTKIMI algorytmami \n";
                        cout << "\t ========================================== \n";
                        cout << "\t\t TABLICA UŻYTKOWNIKA  \n";
                        cout << "\t ========================================== \n";
                        cout << "\t 5) Sortowanie tablicy użytkownika wybranym algorytmem  \n";
                        cout << "\t 6) Sortowanie tablicy użytkownika WSZYSTKIMI algorytmami  \n";
                        cout << "\t 7) Zmiana rozmiaru tablicy użytkownika \n";
                        cout << "\t k/K) Koniec \n";
                        cout << "\n Podaj opcje: ";  
	                    cin >> opcja;	   
	                    
	                    if (opcja == '1') menu4_C(tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8, tc9, tc10); 
	                    if (opcja == '2') menu1_C(tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8, tc9, tc10); 
	                    if (opcja == '3') menu2_C(tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8, tc9, tc10); 
	                    if (opcja == '4') wszystkie_C(tc1, tc2, tc3, tc4, tc5, tc6, tc7, tc8, tc9, tc10);
	                    if (opcja == '5') alg_usr(c_vec_usr);
	                    if (opcja == '6') wszystkie_C_usr(c_vec_usr);
	                    if (opcja == '7') {
                                    cout << "\n Podaj nowy rozmiar tablicy użytkownika: ";
	                                cin >> rozmiar_usr;
                                    c_vec_usr.resize(rozmiar_usr);
                                    wypelnij_calkowite( c_vec_usr); 
                       }
                }
            break;
        case 'r':                            
                        td1.resize(rozmiar_30_tys);
                     //   cout << "\ntd1.size():" << td1.size();
                      //  cout << "\ntd1.capacity():" << td1.capacity();
                        td2.resize(rozmiar_50_tys);
                        td3.resize(rozmiar_100_tys);
                        td4.resize(rozmiar_150_tys);
                        td5.resize(rozmiar_200_tys);
                        td6.resize(rozmiar_500_tys);
                        td7.resize(rozmiar_1_mln);
                        td8.resize(rozmiar_2_mln);
                        td9.resize(rozmiar_5_mln);
                        td10.resize(rozmiar_10_mln);
                    d_vec_usr.resize(rozmiar_usr);
                    
                    wypelnij_rzeczywiste( td1); 
                    wypelnij_rzeczywiste( td2); 
                    wypelnij_rzeczywiste( td3); 
                    wypelnij_rzeczywiste( td4); 
                    wypelnij_rzeczywiste( td5); 
                    wypelnij_rzeczywiste( td6); 
                    wypelnij_rzeczywiste( td7); 
                    wypelnij_rzeczywiste( td8); 
                    wypelnij_rzeczywiste( td9); 
                    wypelnij_rzeczywiste( td10);
                    wypelnij_rzeczywiste( d_vec_usr); 
                    
                    while (opcja != 'k' && opcja != 'K'){   
                            cout << "\n\t ++++ Sortowanie Rzeczywiste++++\n";
                            cout << "\t==========================================  \n";
                            cout << "\t\t TABLICE PREDEFINIOWAWNE:  \n";
                            cout << "\t 1) Sortowanie WYBRANEJ predefiniowanEJ tablicY WSZYSTKIMI algorytmami  \n";
                            cout << "\t 2) Sortowanie WSZYSTKICH predefiniowanych tablic po kolei wybranym algorytmem \n";
                            cout << "\t 3) Sortowanie WYBRANEJ JEDNEJ predefiniowanEJ tablicY JEDNYM algorytmEM \n";
                            cout << "\t 4) Sortowanie WSZYSTKICH predefiniowanych tablic WSZYSTKIMI algorytmami \n";
                            cout << "\t ========================================== \n";
                            cout << "\t\t TABLICA UŻYTKOWNIKA  \n";
                            cout << "\t ========================================== \n";
                            cout << "\t 5) Sortowanie tablicy użytkownika wybranym algorytmem  \n";
                            cout << "\t 6) Sortowanie tablicy użytkownika WSZYSTKIMI algorytmami  \n";
                            cout << "\t k/K) Koniec \n";
                            cout << "\n Podaj opcje: ";  
	                        cin >> opcja;	   
	                        
	                        if (opcja == '1') menu4_D(td1, td2, td3, td4, td5, td6, td7, td8, td9, td10); 
	                        if (opcja == '2') menu1_D(td1, td2, td3, td4, td5, td6, td7, td8, td9, td10); 
	                        if (opcja == '3') menu2_D(td1, td2, td3, td4, td5, td6, td7, td8, td9, td10); 
	                        if (opcja == '4') wszystkie_D(td1, td2, td3, td4, td5, td6, td7, td8, td9, td10);
	                        if (opcja == '5') alg_usrD(d_vec_usr);
	                        if (opcja == '6') wszystkie_D_usr(d_vec_usr);
                            if (opcja == '7') {
                                    cout << "\n Podaj nowy rozmiar tablicy użytkownika: ";
	                                cin >> rozmiar_usr;
                                    d_vec_usr.resize(rozmiar_usr);
                                    wypelnij_rzeczywiste( d_vec_usr); 
                            }
	               // opcja = 'k'; 
                    }           
            break;
        default:
            cout << "\n Nie ma takiej opcji \n ";
            break;
    }
    
    
    

cout << endl;
return 5;
}
//=======================  FUNKCJE ============================
 


