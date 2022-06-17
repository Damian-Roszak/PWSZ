#include<iostream>
#include<math.h>

using namespace std;

static double funkcjaLiczoncaWartoszczOdsetek(double wartOdsetek, double kwotaPocz, double procenty, double liczbaKapitalizacjiWRoku);

static double ileLat(double wartOdsetek, double kwotaPocz, double procenty, double liczbaKapitalizacjiWRoku);

int main(){

double wartOdsetek=50,
       kwotaPocz=1000,
       procenty=4, 
       liczbaKapitalizacjiWRoku=4;


/*
cout << "\n Podaj wartość wysokość kwoty początkowej: ";
cin >> kwotaPocz;

cout << "\n Podaj oprocentowanie w skali roku : ";
cin >> procenty;

cout << "\n Podaj wartość odsetek, którą chcesz osiągnąć: ";
cin >> wartOdsetek;

cout << "\n Podaj liczba kapitalizacji w roku: ";
cin >> liczbaKapitalizacjiWRoku;
*/
double odp, odp2;

        odp = funkcjaLiczoncaWartoszczOdsetek(wartOdsetek, kwotaPocz, procenty,  liczbaKapitalizacjiWRoku);

        odp2 = ileLat(wartOdsetek, kwotaPocz, procenty,  liczbaKapitalizacjiWRoku);


        cout << "\n Odpowiedź to: " << odp << " lat.";

        cout << "\n Odpowiedź z ileLat() to: " << odp2 << " lat.";


cout << endl;
return 5;
}

static double ileLat(double wartOdsetek, double kwotaPocz, double procenty, double liczbaKapitalizacjiWRoku){

        double lataOdkladania = (1.0/liczbaKapitalizacjiWRoku)*((log((kwotaPocz+wartOdsetek)/kwotaPocz))/(log(1+((procenty/100)/liczbaKapitalizacjiWRoku))));

return ceil(lataOdkladania);
}


static double funkcjaLiczoncaWartoszczOdsetek(double wartOdsetek, double kwotaPocz, double procenty, double liczbaKapitalizacjiWRoku){

        double lataOdkladania = 0;
        double sumaOdk = kwotaPocz;
        int licznik = 0;

        while(sumaOdk<=(kwotaPocz+wartOdsetek))
        {
            licznik++;
                sumaOdk +=sumaOdk*((procenty/100)/liczbaKapitalizacjiWRoku);
                cout << "\n nowa kwota: " << sumaOdk;
        }
        lataOdkladania = licznik/liczbaKapitalizacjiWRoku;

return ceil(lataOdkladania);
}

