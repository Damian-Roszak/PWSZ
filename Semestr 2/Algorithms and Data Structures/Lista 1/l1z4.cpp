#include<iostream>
#include<cstdlib>
#include<ctime>

int N = 50;
int f(int p[], int rozmiar, int m);

int main(){

using namespace std;

srand(time(NULL));

int a[N];
for (int i=N-1; i>=0; i--) a[i]=rand()%101;
for (int i=N-1; i>=0; i--) {
    cout << a[i] << " ";
    if (i%10 == 0) cout << endl;
}

int max = a[N-1];
max = f(a, N-1, max);

cout << "maks: " << max;
cout << endl;
return 5;
}

int f(int p[], int rozmiar, int m){
    if (p[rozmiar]>m) m=p[rozmiar];
    if (rozmiar==0) return m;
return f(p, rozmiar-1, m);
}
