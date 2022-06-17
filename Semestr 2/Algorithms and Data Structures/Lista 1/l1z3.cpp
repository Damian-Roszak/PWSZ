#include<iostream>

int f(int p);

int main(){
using namespace std;

int a;
    cout << "\n Podaj N-ty wyraz ciągu fibonacciego do obliczenia: ";
    cin >> a;

cout << f(a);

cout << endl;
return 5;
}

int f (int p){
 if (p<=0) return 0;   
  if (p==1) return 1;   
return f(p-1) + f(p-2);
}


