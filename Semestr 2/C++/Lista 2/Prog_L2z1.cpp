#include<iostream>


using namespace std;

void kula();
void prost();
void stoz();

int main(){
char odp;
cout << "Która bryła (a,b,c): "<<endl;
cout << "a) kula "<<endl;
cout << "b) prostopadłościan "<<endl;
cout << "c) stożek "<<endl;
cin >> odp;

if (odp == 'a') kula();
if (odp == 'b') prost();
if (odp == 'c') stoz();


return 5;
}


void kula(){
cout <<endl<< "Podaj promień: ";
double r;
cin >> r;

cout << endl << " Objętość: " << (4/3.0)*(3.14)*r*r*r << endl << " Pole powierchni: " << 4.0*3.14*r*r << endl;
}

void prost(){
double d,s,w;
cout <<endl<< "Podaj długość: ";
cin >> d;
cout <<endl<< "Podaj szerokość: ";
cin >> s;
cout <<endl<< "Podaj wysokość: ";
cin >> w;

cout << endl << " Objętość: " << d*s*w << endl << " Pole powierchni: " << 2*d*s + 2*d*w + 2*s*w << endl;
}

void stoz(){
double r,l,h;
cout <<endl<< "Podaj promień podstawy: ";
cin >> r;
cout <<endl<< "Podaj długość tworzącej stożek: ";
cin >> l;
cout <<endl<< "Podaj wysokość: ";
cin >> h;

cout << endl << " Objętość: " << (3.14*r*r*h)/3.0 << endl << " Pole powierchni: " << 3.14*r*r+3.14*r*l << endl;

}




