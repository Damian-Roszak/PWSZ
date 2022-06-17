#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <list>
#include <iterator>
#include <string>
#include <vector>
//#include <

using namespace std;

//g++ -std=c++11 -Wall -fsanitize=address -g3 -o l12 CPP_Lista12.cpp

class przedmiot
{
    public:
        string nazwa_przedmiotu;
        int typ_zal_egz;
        int ocena;
        string data_wpisu;
        string imie_prowadzacego, nazwisko_prowadzacego;
        
        przedmiot(string nazwa, int score, string im, string naz): nazwa_przedmiotu(nazwa), ocena(score), imie_prowadzacego(im), nazwisko_prowadzacego(naz){};
        
        przedmiot()
        { 
            typ_zal_egz = rand()%2;
            ocena = rand()%6;
            while(ocena < 2 || ocena > 5) ocena = rand()%6;
            
            char tempZnak;
            tempZnak = rand()%26+65;
            imie_prowadzacego = imie_prowadzacego + tempZnak;
            for (int j=0; j<5; j++){
                tempZnak = rand()%26+97;
                imie_prowadzacego = imie_prowadzacego + tempZnak;             
            }
            
            tempZnak = rand()%26+65;
            nazwisko_prowadzacego = nazwisko_prowadzacego + tempZnak;
            for (int j=0; j<5; j++){
                tempZnak = rand()%26+97;
                nazwisko_prowadzacego = nazwisko_prowadzacego + tempZnak;             
            }
            
            tempZnak = rand()%26+65;
            nazwa_przedmiotu = nazwa_przedmiotu + tempZnak;
            for (int j=0; j<5; j++){
                tempZnak = rand()%26+97;
                nazwa_przedmiotu = nazwa_przedmiotu + tempZnak;             
            }
            
            tempZnak = rand()%11+48;
            data_wpisu = data_wpisu + tempZnak;
            tempZnak = rand()%11+48;
            data_wpisu = data_wpisu + tempZnak;            
            data_wpisu = data_wpisu + "-";
            for (int j=0; j<2; j++){  
                tempZnak = rand()%11+48;
                data_wpisu = data_wpisu + tempZnak;             
            }      
            data_wpisu = data_wpisu + "-";
            for (int j=0; j<2; j++){  
                tempZnak = rand()%11+48;
                data_wpisu = data_wpisu + tempZnak;             
            }
        };
};

class semestr
{
    public:
        //int nr_semestru;
        list< przedmiot > sem;   // naz_przedm  kurs
        semestr()
        {
            string im;  
            char tempZnak;
            tempZnak = rand()%26+65;
            im = im + tempZnak;
            for (int j=0; j<5; j++){
                tempZnak = rand()%26+97;
                 im = im + tempZnak;             
            }
            przedmiot *kurs = new przedmiot();
            sem.push_back(*kurs);
        };
};

class student
{
  public:
    int nr_albumu, nr_aktualny_semestr;
    string imie, nazwisko;
    semestr aktualny_semestr;
    vector< semestr> historia_semestrow;
    
    student()
    {
        int tmp = 0;
         while(tmp < 1000 || tmp > 1000000) tmp = rand();
        nr_albumu = tmp;
        nr_aktualny_semestr =  rand()%7+1;
         
        char tempZnak;
        tempZnak = rand()%26+65;
        imie = imie + tempZnak;
        for (int j=0; j<5; j++){
            tempZnak = rand()%26+97;
             imie = imie + tempZnak;             
        }
        tempZnak = rand()%26+65;
        nazwisko = nazwisko + tempZnak;
        for (int j=0; j<5; j++){
            tempZnak = rand()%26+97;
            nazwisko = nazwisko + tempZnak;             
        }
        
        if ( nr_aktualny_semestr > 1) 
            for (int i=0; i<nr_aktualny_semestr; i++)
            {
                semestr *sem = new semestr();
                historia_semestrow.push_back(*sem);
            }
            
        
    }
    
    ~student()
    {
       // delete 
    } 

};
    double srednia(list< student> wysw, int ind, int semestrLiczony)
    {
        double sr = 0.0;
        int opcja;
        cout << "\n Jaka średnia: \n";
        cout << "\n 1) ogólna z wszystkich ocen";
        cout << "\n 2) z ocen z egzaminów";
        cout << "\n 3) z ocen z zaliczeń";
        cout << "\n Podaj opcje: ";
        cin >> opcja;
        
        for (list< student>::iterator wskListy = wysw.begin(); wskListy != wysw.end(); wskListy++)
        {
           // cout << "\n wskPrzed:  ";
         if(wskListy->nr_albumu  == ind )
         {
            if ( opcja == 1)
            {  
                for (list< przedmiot>::iterator wskPrzed = wskListy->historia_semestrow[semestrLiczony].sem.begin(); wskPrzed != wskListy->historia_semestrow[semestrLiczony].sem.end(); wskPrzed++)
                {
                   // sr += wskListy->historia_semestrow[semestrLiczony].sem[i];
                   sr += wskPrzed->ocena;
                   cout << "\n wskPrzed:  " << wskPrzed->ocena;
                } 
                sr /= wskListy->historia_semestrow[semestrLiczony].sem.size();
            }
           // if ( opcja == 2)
           // if ( opcja == 3)
         }
        }
     return sr;   
    }

    void pokaListe(list< student> wysw)
    {
        cout << "\n Lista zawiera " << wysw.size() << " elementów \n";
        for (list< student>::iterator wskListy = wysw.begin(); wskListy != wysw.end(); wskListy++)
         //   cout << *wskListy << ", ";
            
        cout << endl;
    }


int ilosc_studentow;
int main()
{
    srand(time(0));
    ilosc_studentow = rand()%333;
    
    list< student> lista_studentow;
    
    for (int i=0; i<ilosc_studentow; i++)
    {
        student *nowy = new student();
        lista_studentow.push_back(*nowy);    
    }

    //pokaListe(lista_studentow);
 list< student>::iterator wskListy = lista_studentow.begin();

 srednia(lista_studentow, wskListy->nr_albumu, 1);

//delete lista_studentow;
return 5;
}
