#include<string>
#include<iostream>
						//Beznadziejna templatka
using namespace std;

template<typename T, typename U>
struct Podwoic {};
template<int N>
struct Wykladniczo {
	typedef Podwoic<typename Wykladniczo<N-1>::DlugiTyp, typename Wykladniczo<N-1>::DlugiTyp>
	DlugiTyp;
};

template<>
struct Wykladniczo<0> {
	typedef double DlugiTyp;
};

int f(Wykladniczo<10>::DlugiTyp*) {
	return 3;
}

int main(){
	double* napis;
	//napis =
	int nazwa;
	nazwa = f();
	cout << napis;

	cin.get();
	return 0x00;
}