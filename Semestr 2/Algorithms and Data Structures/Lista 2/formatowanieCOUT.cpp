#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

int main(){
using namespace std;
int l = - 3;
cout << l << endl;
cout.width( 10 );
cout << left << l << endl;
cout.width( 10 );
cout << right << l << endl;
cout.width( 10 );
cout << internal << l << endl;

cout << endl << endl;

l = 59;
cout.setf( ios::hex, ios::basefield );
cout << l << endl; //3b
cout.setf( ios::oct, ios::basefield );
cout << l << endl; //73
cout.setf( ios::dec, ios::basefield );
cout << l << endl; //59

cout << endl << endl;

int a = 59;
cout.setf( ios::showpos );
cout << a << endl; //+59

cout << endl << endl;

l = 59;
cout.setf( ios::hex, ios::basefield );
cout.setf( ios::uppercase );
cout << l << endl; //3B

cout << endl << endl;

float x = 1175;
cout << x << endl; //1175
cout.setf( ios::showpoint );
cout << x << endl; //1175.00

cout << endl << endl;

 x = 1175;
cout << x << endl; //1175
cout.setf( ios::scientific );
cout << x << endl; //1.175000e+003

cout << endl << endl;

long kwota[] = { 120, 1650000, 5200, 190000123 };
for( int i = 0; i < 4; i++ )
{
    cout << "Rachunek nr ";
    cout.width( 2 );
    cout << i << " opiewa na sume :";
    cout.width( 10 );
    cout << kwota[ i ] << " DM\n";
}

cout << endl << endl;

cout.width( 10 );
cout <<( cout.width() ); //10

cout << endl << endl;

long kwota2[] = { 120, 1650000, 5200, 190000123 };
for( int i = 0; i < 4; i++ )
{
    cout << "Rachunek nr ";
    cout.width( 2 );
    cout.fill( '*' );
    cout << i << " opiewa na sume :";
    cout.width( 10 );
    cout.fill( '_' );
    cout << kwota2[ i ] << " DM\n";
}

cout << endl << endl;

double kwota3[] = { 1.123456789123, 2.12345, 3.1 };
cout << kwota3[ 0 ] << " DM\n"; //bez formatowania polazuje tylko 6 miejsc
cout.precision( 15 );
for( int i = 0; i < 3; i++ )
{
    cout << "Rachunek nr ";
    cout << i << " opiewa na sume :";
    cout << kwota3[ i ] << " DM\n";
}

cout << endl << endl;

int i = 31;
cout << i << endl; //31
cout.setf( ios::hex, ios::basefield );
cout << i << endl; //1F
cout << hex << i << endl; //1F - drugi sposób (16)
cout << oct << i << endl; //37 - drugi sposób (8)
cout.setf( ios::dec, ios::basefield );

cout << endl << endl;

int m = 437;
cout << setw( 3 ) << m << setw( 6 ) << m << setw( 11 ) << m << endl;

cout << endl << endl;

m = 437;
cout << setw( 3 ) << m << setw( 6 ) << setfill( 'b' ) << m << setw( 11 ) << setfill( '^' ) << m << endl;

cout << endl << endl;

double m2 = 1.123456789;
cout << setprecision( 2 ) << m2
<< "  " << setprecision( 5 ) << m2
<< "  " << setprecision( 12 ) << m2 << endl;

cout << endl << endl;

 i = 224;
cout << hex << i << ", "
<< setiosflags( ios::uppercase ) << i << ", "
<< resetiosflags( ios::uppercase ) << i << endl;

cout << endl;


return 5;
}
