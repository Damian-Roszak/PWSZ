#include<iostream>

int rysuj(int p);
int poziom(int r);

int main(){
using namespace std;

int a;
    cout << "\n Podaj ilość poziomów: ";
    cin >> a;
//rysuj(a);
poziom(a);

cout << endl;
return 5;
}


int poziom(int r){
    if (r==0) return 1;
    rysuj(r);
    return poziom(r-1);
}

int rysuj(int p){
    if (p==0)
     {
       std::cout << std::endl;
       return 1;
     }  
    std::cout << "*";
    return rysuj(p-1);
}

