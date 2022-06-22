#include "iostream"
#include <limits>
//#include ""

using namespace std;

class Klasa2 {
	string n;
	int i;
protected:
	int atrybutFriendZone;
	int atrybutFriendZone2;
public:
	Klasa2(){}
	Klasa2(int p):i(p){
		n = "Klasa2";
		cout<<n<<" = " <<i<<endl;
	}
	int set(int p){
		return i = p;
	}
	string getN(){
		return n;
	}
};

class Klasa_Bazowa {
private:
	//class Klasa_Skladnikowa_Prywatna;
	class Klasa_Skladnikowa_Prywatna{
	private:
		int atrybutKlasySkladnikowejJeden;
	protected:
	public:
		Klasa_Skladnikowa_Prywatna(){};
		Klasa_Skladnikowa_Prywatna(int parametr):atrybutKlasySkladnikowejJeden (parametr){};
		int get(){
			return atrybutKlasySkladnikowejJeden;
		}
		int set(int p){
			atrybutKlasySkladnikowejJeden = p;
		}
	};

	Klasa_Skladnikowa_Prywatna obiektKlasySkladnikowej;
	
	int atrybutJeden, a1, a2;
	int atrybutDwa;
	
protected:
	int atrybutFriendZoneJeden;
	int atrybutFriendZoneDwa;
	
public:
	Klasa_Bazowa (){}
	Klasa_Bazowa (int parametr, int param2):atrybutJeden (parametr), atrybutDwa (param2), obiektKlasySkladnikowej(333) {
		//obiektKlasySkladnikowej.set(77);
	}
	int get(){
		cout << "*******************           Klasa_Bazowa           ***********************************" << endl;
		cout << "atrybutJeden = " << atrybutJeden << endl;
		cout << "atrybutDwa = " << atrybutDwa << endl;
		cout << "a1 = " << a1 << endl;
		cout << "a2 = " << a2 << endl;
		cout << "obiektKlasySkladnikowej = " << obiektKlasySkladnikowej.get() << endl;
		cout << "*******************           Klasa_Bazowa  Koniec    ***********************************" << endl<<endl<<endl;
	}
	void set (int p1, int p2){
		a1 = p1;
		a2 = p2; 
	}
	void setWew(int p){
		obiektKlasySkladnikowej.set(p);
	}
	
};

class Typy_I_Ich_Rozmiary{
	string typIJegoNazwa;
protected:
	int atrybutFriendZone;
public:
	Typy_I_Ich_Rozmiary(){}
	void get(){
		cout << "      CHAR " << endl;
		cout << "Typ char=sizeof(char) := "<< sizeof(char) <<endl;
		cout << "numeric_limits=numeric_limits<char>::is_signed := "<< numeric_limits<char>::is_signed <<endl;
		cout << "Typ char*=sizeof(char*) := "<< sizeof(char*) <<endl;
		cout << "Typ char&=sizeof(char&) := "<< sizeof(char&) <<endl;
        cout << "Typ wchar_t=sizeof(wchar_t) := "<< sizeof(wchar_t) <<endl;
		cout << "*******************   CHAR Koniec   ***********************************" << endl<<endl<<endl;
		
		cout << "      STRING   " << endl;
		cout << "Typ string=sizeof(string) := "<< sizeof(string) <<endl;
		cout << "Typ string&=sizeof(string&) := "<< sizeof(string&) <<endl;
		cout << "Typ string*=sizeof(string*) := "<< sizeof(string*) <<endl;
		cout << "*******************  STRING  Koniec   ***********************************" << endl<<endl<<endl;

		cout << "     DOUBLE  " << endl;
		cout << "Typ double=sizeof(double) := "<< sizeof(double) <<endl;
		cout << "Typ double&=sizeof(double&) := "<< sizeof(double&) <<endl;
		cout << "Typ double*=sizeof(double*) := "<< sizeof(double*) <<endl;
		cout << "*******************  DOUBLE  Koniec   ***********************************" << endl<<endl<<endl;
		

		cout << "       LONG   " << endl;
		cout << "Typ long=sizeof(long) := "<< sizeof(long) <<endl;
		cout << "Typ long&=sizeof(long&) := "<< sizeof(long&) <<endl;
		cout << "Typ long*=sizeof(long*) := "<< sizeof(long*) <<endl;
		cout << "*******************  LONG  Koniec   ***********************************" << endl<<endl<<endl;

		cout << "      FLOAT   " << endl;
		cout << "Typ float=sizeof(float) := "<< sizeof(float) <<endl;
		cout << "Typ float&=sizeof(float&) := "<< sizeof(float&) <<endl;
		cout << "Typ float*=sizeof(float*) := "<< sizeof(float*) <<endl;
		cout << "*******************  FLOAT  Koniec   ******************" << endl<<endl<<endl;

		cout << "   SHORT  " << endl;
		cout << "Typ short=sizeof(short) := "<< sizeof(short) <<endl;
		cout << "Typ short&=sizeof(short&) := "<< sizeof(short&) <<endl;
		cout << "Typ short*=sizeof(short*) := "<< sizeof(short*) <<endl;
		cout << "*******************  SHORT  Koniec   ******************" << endl<<endl<<endl;

		cout << "   INT  " << endl;
		cout << "Typ int=sizeof(int) := "<< sizeof(int) <<endl;
		cout << "Typ int&=sizeof(int&) := "<< sizeof(int&) <<endl;
		cout << "Typ int*=sizeof(int*) := "<< sizeof(int*) <<endl<<endl;
		cout << "*******************  INT Koniec  **********************" << endl<<endl<<endl;
		

		cout << "  LONG INT  " << endl;
		cout << "Typ long int=sizeof(long int) := "<< sizeof(long int) <<endl;
		cout << "Typ long int&=sizeof(long int&) := "<< sizeof(long int&) <<endl;
		cout << "Typ long int*=sizeof(long int*) := "<< sizeof(long int*) <<endl<<endl;
		cout << "******************* LONG INT Koniec  **********************************" << endl<<endl<<endl;
		

		cout << "   SHORT INT  " << endl;
		cout << "Typ short int=sizeof(short int) := "<< sizeof(short int) <<endl;
		cout << "Typ short int&=sizeof(short int&) := "<< sizeof(short int&) <<endl;
		cout << "Typ short int*=sizeof(short int*) := "<< sizeof(short int*) <<endl;
		cout << "*******************  SHORT INT Koniec   ***************************" << endl<<endl<<endl;
		

		cout << "   BOOL   " << endl;
		cout << "Typ bool=sizeof(bool) := "<< sizeof(bool) <<endl;
		cout << "Typ bool&=sizeof(bool&) := "<< sizeof(bool&) <<endl;
		cout << "Typ bool*=sizeof(bool*) := "<< sizeof(bool*) <<endl;
		cout << "*******************  BOOL  Koniec   ***********************************" << endl<<endl<<endl;

		
	}
	//Rozmiar_Typów(int p){}
	
};

class Litery {
	char literki[];
protected:
	int zmiennaSekcjiProtected;
public:
	Litery (){
        literki [] = "abcdefghijklmnopqrstuwxyz!@#$%^&*()_+}{P?>,,./<|:;";
		cout << " Litery: " << endl;
		cout << " a := " << endl;
	}
};


int main (){
	Klasa_Bazowa obiektKlasyBazowejJeden(3,4);
	obiektKlasyBazowejJeden.set(1,2);
	//obiektKlasyBazowejJeden.setWew(5);
	obiektKlasyBazowejJeden.get();
    
	cout<< "************** MAIN COUT **************************"<<endl;
	Klasa2 obiektKlasy2(55);
	cout<<"zmiana obiektKlasy2 " << obiektKlasy2.set(999)<<endl;
	cout<<"nazwa typu obiektKlasy2 " << obiektKlasy2.getN()<<endl;
    cout<< "************** MAIN COUT KONIEC **************************"<<endl<<endl;
	
	Typy_I_Ich_Rozmiary obiektKlasyTypyIIchRozmiary;
	obiektKlasyTypyIIchRozmiary.get();
	
	cout << "dupa";
}
