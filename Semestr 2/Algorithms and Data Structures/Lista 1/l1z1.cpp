#include<iostream>

int rekur(int param);

int main(){

using namespace std;

int N;
do{
    cout << "\n Podaj liczbę do silni: ";
    cin >> N;
}while(N<0 || N>10);

cout << "\n Silnia = " << rekur(N) << endl;
return 5;
}

int rekur(int param){
    if (param == 0) return 1;   
    return param * rekur(param-1);

}
