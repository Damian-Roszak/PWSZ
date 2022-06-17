#include<iostream>
#include<cstdlib>
#include<ctime>
//#include <cstdio>
//#include <iomanip>

int main(){
using namespace std;

int a[10], b[10], c[10];
srand(time(NULL));

cout << endl << "tab a" << endl;
for ( int i=0; i<10; i++) {
    //*(a+i)=rand()%100+1; //działa
    *(a+i)=rand()%100+1;
    cout.width( 10);
    //cout << a[0]+i;
    cout << " a[i]:";
    cout.width( 3);
    cout << a[i];
    cout.width( 10);
    cout << " a[0]+i:";
    cout.width( 3);
    cout << a[0]+i;
    cout.width( 10);
    cout << " *(a+i):" << *(&a[0]+i);
    cout.width( 10);
    cout << " i[a]:" << i[a] << endl;
}

cout << endl << "\ttab a:   ";

for ( int i=0; i<10; i++) {
    cout.width( 3 );
    cout << *(a+i);
}


cout << endl << endl << "tab b = *(b+i)" << endl;

for ( int i=0; i<10; i++) {
    //*(a+i)=rand()%100+1; //działa
    *(b+i)=rand()%100+1;
    cout.width( 5 );
    //cout << b[0]+i;
    cout << b[0]+i;
}

cout << endl << endl << "tab c = i[c]" << endl;

for ( int i=0; i<10; i++) {
    i[c]=rand()%100+1;
    cout.width( 5 );
    cout << c[0]+i;
}

cout << endl;
return 5;
}
