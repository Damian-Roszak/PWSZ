#include<iostream>

int NWDw1rekursja(int a, int b);
int NWDw2moduloRekursja(int a, int b);


int main(){

using namespace std;

int a, b;
    cout << "\n Podaj liczby do NWD: ";
    cin >> a >> b;

cout << "\n NWD wersja 1: " << NWDw1rekursja( a, b);
cout << "\n NWD wersja 2: " << NWDw2moduloRekursja( a, b) << endl;

return 5;
}

int NWDw1rekursja(int a, int b)
{
    if(a!=b)
        return NWDw1rekursja(a>b ? a-b : a , b>a ? b-a : b);
    return a;
}

int NWDw2moduloRekursja(int a, int b)
{
    if(b!=0)
        return NWDw2moduloRekursja(b, a%b);
    return a;
}

