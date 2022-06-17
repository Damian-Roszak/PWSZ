#include<iostream>
#include<cstdlib>
#include<ctime>


int main(){
using namespace std;
srand(time(NULL));

int *I_int =  new int;
*I_int = rand()%333;

double *D_double = new double;
*D_double = rand()%333;

float *F_float = new float;
*F_float = rand()%333;

int N;
cout << "\n Podaj N: ";
cin >> N;

int *I_tab = new int[N];
for (int i=0; i<N; i++){
    I_tab[i] = rand()%333;;
}

cout << "\n *I_int: " << *I_int;
cout << "\n *D_double: " << *D_double;
cout << "\n *F_float: " << *F_float;

cout << "\n I_tab[i]: ";
for (int i=0; i<N; i++){
    cout << I_tab[i] << " ";
}


delete I_int;
delete D_double;
delete F_float;
delete[] I_tab;

cout << endl;
return 5;
}
