#include <list>
#include <set>
#include <iterator>
#include <algorithm>
#include "iostream"
#include <limits>
#include <string.h>
#include <string>
#include <cstring>
#include <typeinfo>
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>

using namespace std;

class Klasa2 {
	string n;
	int i;
protected:
	int atrybutFriendZone;
	int atrybutFriendZone2;
public:
  ~Klasa2 (){}
	Klasa2(){}
	Klasa2(int p):i(p){
		n = "Klasa2";
		cout << "Utworzenie obiektu klasy czyli typu Klasa2 :D " << endl;
		cout<<n<<" = " <<i<<endl;
		cout << "Opuszczenie konstruktora Klasa2()... " << endl;
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
  ~Klasa_Bazowa (){}
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
  ~Typy_I_Ich_Rozmiary(){}
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
	string literki;
protected:
	int zmiennaSekcjiProtected;
public:
  ~Litery (){}
	Litery () {
	 literki ="abcdefghijklmnopqrstuwxyz1234567890ABCDEFGHIJKLMNOPQRSTUWXYZ";
	 //cout << literki << endl;
	 cout << "    Napierw decymalnie czyli libczami całkowitymi :" << endl;
	 string::const_iterator i = literki.begin();
	 
	 while (i != literki.end()) {
	   cout << *i << ":=" << int(*i) << " ";
	   i++;
	   if (i==literki.begin()+10 || i==literki.begin()+20 || i==literki.begin()+30
	     || i==literki.begin()+40 || i==literki.begin()+50 ){
	     cout<<endl;
	  };
	}
	cout << endl<< endl<< endl;
	i = literki.begin();
	cout << "     Teraz HexaDecymalnie czyli libczami szesnastkowymi :" << endl;
	while (i != literki.end()) {
	   cout << *i << "=" << hex << int(*i) << " ";
	   i++;
	   if (i==literki.begin()+10 || i==literki.begin()+20 || i==literki.begin()+30
	     || i==literki.begin()+40 || i==literki.begin()+50 ){
	     cout<<endl;
	  };
	}
	cout << endl;
	}
};

class Majn{
public:
  ~Majn(){}
  Majn(){
	cout<< "************** obiektKlasy2 **************************"<<endl;
	Klasa2 obiektKlasy2(55);
	cout<<"Zmiana obiektKlasy2 poleceniem obiektKlasy2.set(999) :=" << obiektKlasy2.set(999)<<endl;
	cout<<"Nazwa typu, czyli klasy obiektKlasy2 poleceniem obiektKlasy2.getN() := " << obiektKlasy2.getN()<<endl;
	cout<< "************** obiektKlasy2 KONIEC **************************"<<endl<<endl;
  }
};

template<typename T> class Rozdz4Zad5 {  
  
public:
  ~Rozdz4Zad5 (){}
  Rozdz4Zad5 (){}
  
  static void druk(){
    cout <<"Nazwa typu: "<< typeid(T).name() << ", a zakres wynosi od: '" << numeric_limits<T>::min() << "', do: '" << numeric_limits<T>::max() <<"'"<< endl;
  }
  
   static void d(){
    Rozdz4Zad5<int>::druk();
    Rozdz4Zad5<double>::druk();
    Rozdz4Zad5<char>::druk();
    Rozdz4Zad5<signed>::druk();
    Rozdz4Zad5<unsigned>::druk();
    Rozdz4Zad5<short>::druk();
    Rozdz4Zad5<long double>::druk();
    Rozdz4Zad5<float>::druk();
    Rozdz4Zad5<string>::druk();
    cout<< endl;
   // Rozdz4Zad5<>::druk();
    
    cout <<"String hex: "<< typeid(string).name() << ", a zakres wynosi od: '" << hex << numeric_limits<T>::min() << "', do: '" << numeric_limits<T>::max() <<"'"<< endl;
  }
};

class UseR4z5 {
public:
  ~UseR4z5 (){}
  UseR4z5(){
  Rozdz4Zad5<char>::d();
  }
};

class Kolorki{
public:
  ~Kolorki(){}
  Kolorki(){
    cout << "Kolory CIemne"
	 << "\033[31m 111"
	 << "\033[31m 222"
	 << "\033[32;31;1m 333"
	 << "\033[33m 444"
	 << "\033[34m 555"
	 << "\033[35m 666"
	 << "\033[36m 777"
	 << "\033[37m 888"
	 << "\033[38m 999"
	 << "\033[37m 000"
	 << "\033[97;30m koniec"
	 << endl;
    cout << "Kolory Jasne"
	 << "\033[91m 111"
	 << "\033[92m 222"
	 << "\033[93m 333"
	 << "\033[94m 444"
	 << "\033[95m 555"
	 << "\033[96m 666"
	 << "\033[97m 777"
	 << "\033[96m 888"
	 << "\033[95m 999"
	 << "\033[93m 000"
	 << "\033[97;0m koniec"
	 << endl;
    cout << "\033[43;37m\\033[41m\033[40m\n"
	<< "\033[44;36m\\033[41m\033[40m\n"
	<< "\033[45;34m\\033[41m\033[40m\n"
	<< "\033[46;35m\\033[41mKONIEC\033[40m\n\033[0mkoniec"<<endl;
  }
};

class Deklaracje{
  const string wskaznikDoZnaku;
  const string tablica10LiczbInt;
  const string referencjaDoTablicy10LiczbInt;
  const string wskaznikDoTablicyString;
  const string wskaznikDoWskaznikaDoZnaku;
  const string constInt;
  const string pointerDoConstInt;
  const string constPointerDoInt;
//   const string ;
public:
  ~Deklaracje(){}
  Deklaracje(string a="char *pc = 0;",string b="int tab[10]={1,2,3,4,5,6,7,8,9,10};",string c="int (&refTabInt)[10]=tab;",string d="string (*wskTabStr)[3]={arg1, arg2, arg3};",string e="char **wskDoWskDoChar = &pc;",string f="int const constInt = 34;",string g="int const *wskConstInt;",string h="int *const = constInt;"):wskaznikDoZnaku(a), tablica10LiczbInt(b),referencjaDoTablicy10LiczbInt(c),wskaznikDoTablicyString(d),wskaznikDoWskaznikaDoZnaku(e),constInt(f),pointerDoConstInt(g),constPointerDoInt(h)
  {
    cout << "Wskaźnik do znaku: \033[91m" << wskaznikDoZnaku << "\033[0m" <<endl;
    cout << "Tablica 10 liczb całkowitych: \033[91m" << tablica10LiczbInt <<"\033[0m" << endl;
    cout << "Referencja do tablicy 10 liczb całkowitych: \033[91m" << referencjaDoTablicy10LiczbInt <<"\033[0m" << endl;
    cout << "Wskaźnik do tablicy stringów: \033[91m" << wskaznikDoTablicyString << "\033[0m" <<endl;
    cout << "Wskaźnik do wskaźnika do znaku: \033[91m" << wskaznikDoWskaznikaDoZnaku << "\033[0m" << endl;
    cout << "Stała całkowita: \033[91m" << constInt <<"\033[0m" << endl;
    cout << "Wskaźnik do stałej całkowitej: \033[91m" << pointerDoConstInt << "\033[0m" << endl;
    cout << "Stały wskaźnik do liczby całkowitej: \033[91m" << constPointerDoInt << "\033[0m" <<endl;
  }
};

class ZamianaWartosciInt {
  int a;
  int b;
  clock_t czas;
public:
  ~ZamianaWartosciInt (){}
  ZamianaWartosciInt(int arg1, int arg2): a(arg1), b(arg2){
    cout << "zamiana zwykła:"<<endl;
    czas = clock();  cout << "start:= " << czas <<endl;
    cout << "a: " << a <<"; czas:= " <<clock()<<endl;
    cout << "b: " << b << endl << "czas przed:= " << clock() <<endl;
    int pom = a;  a = b; b = pom;
    cout << "czas po zamianie:= " << clock() << endl << "a: " << a << endl;
    cout << "b: " << b << "; czas:= " << clock() << endl<< endl<< endl;
  }
};

class ZamianaWartosciIntWsk {
  int a;
  int b;
  clock_t czas;
public:
  ~ZamianaWartosciIntWsk(){}
  ZamianaWartosciIntWsk(int *arg1, int *arg2): a(*arg1), b(*arg2){
    cout << "zamiana *wsk:"<<endl;
    czas = clock();  cout << "start:= " << czas <<endl;
    cout << "a: " << a <<"; czas:= " <<clock()<<endl;
    cout << "b: " << b << endl << "czas przed:= " << clock() <<endl;
     int pom = a;  a = b; b = pom;
    cout << "czas po zamianie:= " << clock() << endl << "a: " << a << endl;
    cout << "b: " << b << "; czas:= " << clock() << endl<< endl<< endl;
    }
};

class ZamianaWartosciIntRef {
  int a;
  int b;
  clock_t czas;
public:
  ~ZamianaWartosciIntRef(){}
  ZamianaWartosciIntRef(int &arg1, int &arg2): a(arg1), b(arg2){
    cout << "zamiana &ref:"<<endl;
    czas = clock();  cout << "start:= " << czas <<endl;
    cout << "a: " << a <<"; czas:= " <<clock()<<endl;
    cout << "b: " << b << endl << "czas przed:= " << clock() <<endl;
    int pom = a;  a = b; b = pom;
    cout << "czas po zamianie:= " << clock() << endl << "a: " << a << endl;
    cout << "b: " << b << "; czas:= " << clock() << endl<< endl<< endl;
  }
};

class ZamianaWartosciIntRSym {
  int a;
  int b;
  clock_t czas;
public:
  ~ZamianaWartosciIntRSym(){}
  ZamianaWartosciIntRSym(int arg1, int arg2): a(arg1), b(arg2),czas(clock()){
    cout << "zamiana ^Różnica Symetryczna:"<<endl;
//     czas = clock();
    cout << "start:= " << czas <<endl;
    cout << "a: " << a <<"; czas:= " <<clock()<<endl;
    cout << "b: " << b << endl << "czas przed:= " << clock() <<endl;
    a = a^b;  b = a^b;  a = a^b;
    cout << "czas po zamianie:= " << clock() << endl << "a: " << a << endl;
    cout << "b: " << b << "; czas:= " << clock() << endl<< endl<< endl;
    
  
  }
};

class FunkcjeZad5_6 {
public:
  ~FunkcjeZad5_6(){}
  FunkcjeZad5_6(){}
  void f(char a){
    cout << "f(char):= " << a << endl;
  };
  void g(char &b){
    cout << "g(char &):= " << b << endl;
  };
  void h(const char &c){
    cout << "c(const char &):= " << c << endl;
  };
};

class Miesiac{// tablice a obiekty inicjalizacja i używanie powtórzyć
public:
  ~Miesiac(){}
  char const *nazwa;
  int dlugosc;
  Miesiac(char const *p, int a){
    this->nazwa=p;
    this->dlugosc=a;
    cout << "konstrukcja " << this->nazwa << endl;
  }
};/*
class GetMc{
   Miesiac mc[12];
public:
  ~GetMc(){};
GetMc(){ 
  
mc[12] = {{"styczeń",31},{"luty",28},{"marzec",31},{"kwiecień",30},{"maj",31},{"czerwiec",30},{"lipiec",31},{"sierpień",31},{"wrzesień",30},{"październik",31},{"listopad",30},{"grudzień",31}};

  
}
// for (int i=0; i!=11; i++) cout << mc[i].nazwa << ":\t" << mc[i].dlugosc << "\n";
};


 mc[12] = {{"styczeń",31},{"luty",28},{"marzec",31},{"kwiecień",30},{"maj",31},{"czerwiec",30},{"lipiec",31},{"sierpień",31},{"wrzesień",30},{"październik",31},{"listopad",30},{"grudzień",31}};
  
  mc[12] = {Miesiac("styczeń",31),Miesiac("luty",28),Miesiac("marzec",31),Miesiac("kwiecień",30),Miesiac("maj",31),Miesiac("czerwiec",30),Miesiac("lipiec",31),Miesiac("sierpień",31),Miesiac("wrzesień",30),Miesiac("październik",31),Miesiac("listopad",30),Miesiac("grudzień",31)};
 */

class CzasyIteracji{
  int normal;
  int *pointer;
  int referencja;
  time_t start, czasMemCpy, czasIndexy, czasPointery;
  time_t przed, po;
  int const l_bajt, l_wywolan;
  
public:
  void kopiuj_na_pointerach(char const *z, char *d, int n){
    for (int k = 0; k!=n; ++k) *d++ = *z++;
  }
  void kopiuj_na_indexach(char const *z, char *d, int n){
    for (int k = 0; k!=n; ++k) d[k] = z[k];
  }
  ~CzasyIteracji(){}
  CzasyIteracji(int p=5000):normal(p),referencja(0),pointer(0),start(clock()),l_bajt(100000),l_wywolan(100){
    cout << "cykli od uruchumonienia programu do tego miejsca " << start << endl;
    
    cout << "Iteracja na indexach " << endl;
    przed = clock();    
    for(int i=0; i<=normal; i++){
//       cout << i << endl;
      referencja += i;
    }
    po = clock();
    cout << "Różnica po - przed = " << po - przed << endl<< endl;
    
    referencja = 0;
    cout << "Iteracja na wskaźnikach " << endl;
    przed = clock();    
    for(int i=0; i<=normal; i++){
      referencja += i;
    }
    po = clock();
    cout << "Różnica po - przed = " << po - przed << endl<< endl;
    
    referencja = 0;
    cout << "Iteracja na 3 " << endl;
    przed = clock();    
    for(int i=0; i<=normal; i++){referencja += i;}
    po = clock();
    cout << "Różnica po - przed = " << po - przed << endl<< endl;  
    cout << "zajeło to: " << clock() - start << endl << endl << endl;
    
    char *z = new char[l_bajt];
    char *d = new char[l_bajt];
//     memcpy(d,z,l_bajt);
    
    cout << "czas memcpy: " ; przed = clock();
    for (int k=0; k!=l_wywolan; ++k) memcpy(d,z,l_bajt);
    po = clock(); czasMemCpy = po - przed;
    cout << "wynik " << czasMemCpy << endl << endl;
    
    cout << "czas wskaźniki: "; przed = clock();
    for (int k=0; k!=l_wywolan; ++k) kopiuj_na_pointerach(z,d,l_bajt);
    po = clock(); czasPointery = po - przed;
    cout << "wynik " << czasPointery  << endl << endl;
    
    cout << "czas indexy: "; przed = clock();
    for (int k=0; k!=l_wywolan; ++k) kopiuj_na_indexach(z,d,l_bajt);
    po = clock(); czasIndexy = po - przed;
    cout << "wynik " << czasIndexy << endl << endl;
    
    cout << "STATYSTYKI: \n";
    cout << "Pointery: " << czasPointery/czasMemCpy << " razy wolniej niż memcpy\n";
    cout << "Indexy: " << czasIndexy/czasMemCpy << " razy wolniej niż memcpy\n\n";
    
    delete[] z;
    delete[] d;
  }
  
};


class TabNapi{
  string tab[12];
  time_t przedk, przed, po;
public:
  ~TabNapi(){}
  TabNapi():przedk(clock()){
    przed = clock();
    cout << "przed inicjacja w liście konstruktora: " << przedk << endl;
    cout << "przed wartość po wejściu do konstruktora: " << przed << " a przed inicjacjacją tab: "<< clock() << endl;
    tab[0]="styczeń";	tab[6]="lipiec";
    tab[1]="luty";	tab[7]="sierpień";
    tab[2]="marzec";	tab[8]="wrzesień";
    tab[3]="kwiecień";	tab[9]="październik";
    tab[4]="maj";	tab[10]="listopad";
    tab[5]="czerwiec";	tab[11]="grudzień";
    po = clock();
    cout<< "\n Tutaj po: " << po << endl<<endl;
  }
  void pokaz(){
    przed = clock();
    cout << "przed " << przed <<endl;
    for (int i=0; i<=11; i++) cout << i+1 << ": " << tab[i] << endl;
    po = clock();
    cout << "\n po: " << po << endl;
    cout << "czas wykonania: " << po - przed << endl;
  }
  void pokaz2(){   
    przed = clock();
    cout << "\npokaz2\nprzed " << przed <<endl<<endl;
    copy (&tab[0], &tab[12], ostream_iterator<string>(cout,"\n"));
    po = clock();
    cout << "\n po: " << po << endl;
    cout << "czas wykonania: " << po - przed << endl;
  }
};

class SlowaZKlawirki{
  string szereg, drugi;
public:
  class Zbior{
  public:
    bool jestNieMa;
    string slowo;
    string *nast;
    
    ~Zbior(){}
    Zbior(){
      nast=0;
    }
    
  };
class CoszNaIteratorach{};
  ~SlowaZKlawirki(){}
  SlowaZKlawirki(){
    for (string nowe_slowo; cin >>nowe_slowo, nowe_slowo!="Koniec";){
      szereg += ' '+nowe_slowo;
    };
  }
  void f(){
  cout << szereg << endl;
  for (string::iterator it = szereg.begin(); it <= szereg.end();++it){
    cout << "*it: " << *it << endl;
    for (string::iterator it2 = szereg.begin(); it2 <= szereg.end();++it2){
      if (*it!=*it2){
// 	drugi += ' '+*it;
	cout << "*it2: " << *it2 << endl;
      };
      
    };
//     cout << drugi << endl;
  }
  }
};

class SlowaZBibliotekiStandardowej{
  typedef set<string> ZbiorSlow;
  typedef ZbiorSlow::iterator IterSlow;
  typedef list<IterSlow> Indeks;
  ZbiorSlow slowa;
  Indeks porzadek_we;  
public:
  ~SlowaZBibliotekiStandardowej(){}
  SlowaZBibliotekiStandardowej(){
    for (string nowe_slowo; cin >> nowe_slowo, nowe_slowo!="Koniec";){
      pair<IterSlow, bool> const &slad = slowa.insert(nowe_slowo);
      if (slad.second) porzadek_we.push_back(slad.first);
    }
    cout << "\n>>>Słowa bez powtórzeń w porządku wejściowym:\n";
    for (Indeks::iterator p = porzadek_we.begin(); p!=porzadek_we.end(); ++p){
      cout << *(*p) << '\n';
    }
    cout << "\n>>>Słowa bez powtórzeń w domyślnym porządku:\n";
    copy(slowa.begin(), slowa.end(), ostream_iterator<string>(cout, "\n"));
  }
};
class SlowoIWsk{
    string slowo;
    SlowoIWsk *wsk;
  public:
    ~SlowoIWsk(){}
    SlowoIWsk(string s):slowo(s),wsk(0){}
    string getSlowo(){return slowo;}
    void setSlowo(string s){slowo=s;}
    void setWsk(SlowoIWsk *w){wsk=w;}
    SlowoIWsk* getWsk(){return wsk;}
  };
class ListaSlow{
    SlowoIWsk slowoZListy;
    SlowoIWsk *pierwszy;
  public:
    ListaSlow(string s="pierwszy"):slowoZListy(s),pierwszy(&slowoZListy){
//       pierwszy = &slowoZListy;
      cout <<"Konstruktor początek: "<< slowoZListy.getSlowo() << " wprowadź słowa: ";
      for (string tmp; cin >> tmp, tmp!="Koniec";){
	if (tmp!="Koniec"){      
	  cout << tmp << endl;
	  SlowoIWsk *n = new SlowoIWsk(tmp);
	  cout <<"\033[93m "<< n->getSlowo() << "\033[0m" << endl;
	  slowoZListy.setWsk(n); // NADAL WSKAZUJE NA ZERO
	  cout << "\033[92m " << slowoZListy.getWsk()->getSlowo() << "\033[0m" << endl;
	  delete n;
	};
      };
      cout << "\npierwszy: " << pierwszy << endl << "pierwszy->getSlowo(): " << pierwszy->getSlowo() << endl;
      cout << "pierwszy->getWsk(): " << pierwszy->getWsk()->getSlowo() << endl;
      
      
  string ciag1[20];
  string nowe_slowo;
  int i = 0;
  cout << "Podaj słowa do ciągu 1: ";
  for (string tmp; cin >> tmp, tmp!="Koniec";){
    //getline(cin,tmp);
    if(i==19) break;
    if (tmp!="Koniec"){      
      ciag1[i] = tmp;
    };
    ++i;    
    
  };  
  for (int j=0;j<=19;j++){
    if (j==0){
  for (int i=0;i<=19;i++){    
    if (ciag1[i]==ciag1[i+1]){
      cout << " ciag1[\033[93m"<<i<<"\033[0m]: " << ciag1[i] << " równe do: " << "ciag1[\033[93m"<<i+1<<"\033[0m]: "<< ciag1[i+1] <<  endl;
      if (i==10){
	cout << endl;
      };};};
  };};  
  cout << endl;
  
  for(int i=0;i<=19;i++){
    
  };
    }
    ~ListaSlow(){}
  };
  
class lotek{
  //pliki wczytywane do dynamicznych zmiennych
  fstream tab1;
public:
  lotek(){
    tab1.open("lotek/plik",ios::in);
      if(tab1.good()==false)
      {
	cout<<"Plik nie istnieje!";
	exit(0);
      }
      //wczytywanie danych do zmiennych dynamicznych
      //getline(tab1,linia)
      string linia = "a:";
      
	string data, godzina, wynik_losowania,p,super,szansa;
	int w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13,w14,w15,w16,w17,w18,w19,w20,plus,ssc1,ssc2,ssc3,ssc4,ssc5,ssc6,ssc7,licznik=0;
	int licz_linie=0, linie_licz=0;
	
	while(getline(tab1,linia))
	{
	  licz_linie++;
	  cout <<licz_linie <<' '<< linia <<endl;
	}
	cout<<endl;
	//tab1.close();
	//tab1.open("lotek/plik",ios::in);
	tab1.clear();
	tab1.seekg(0,ios::beg);
	while(tab1)
	{
	  linie_licz++;
	  getline(tab1,linia);
	  cout<<linie_licz<<"- drugi while = " <<linia<<endl;
	}
	tab1.clear();
	tab1.seekg(0,ios::beg);
	//tab1.close();
	//tab1.open("lotek/plik",ios::in);
	cout<<endl;
      for(int i=0;i<licz_linie;i++){
	licznik++;
	//cout<<licznik<<' '<<licz_linie<<endl;
	
	
	//cout<<licz_linie;
	
	//tab1, data , godzina , w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13,w14,w15,w16,w17,w18,w19,w20, p,plus , super,szansa,ssc1,ssc2,ssc3,ssc4,ssc5,ssc6,ssc7
	
	tab1 >> data >> godzina >> w1>>w2>>w3>>w4>>w5>>w6>>w7>>w8>>w9>>w10>>w11>>w12>>w13>>w14>>w15>>w16>>w17>>w18>>w19>>w20>> p>>plus >> super>>szansa>>ssc1>>ssc2>>ssc3>>ssc4>>ssc5>>ssc6>>ssc7;
	
	cout<<licznik<<") "<<data<<" "<<godzina<<" wyniki: \033[1;32m"<<w1<<' '<<w2<<' '<<w3<<' '<<w4<<' '<<w5<<' '<<w6<<' '<<w7<<' '<<w8<<' '<<w9<<' '<<w10<<' '<<w11<<' '<<w12<<' '<<w13<<' '<<w14<<' '<<w15<<' '<<w16<<' '<<w17<<' '<<w18<<' '<<w19<<' '<<w20<<"\033[0m"<<"\033[1;31m "<<p<<" \033[0m"<<plus<<"\033[1;31m "<<super<<' '<<szansa<<"\033[0m "<< ssc1<<' '<<ssc2<<' '<<ssc3<<' '<<ssc4<<' '<<ssc5<<' '<<ssc6<<' '<<ssc7<<endl;	
      }
//porównania:
//   określające prawdopodobieństwo wylosowania
//   określające trafienia w każdej kategorii porównań osobno
//
    tab1.close();
  }
lotek(int){
    cout << " begin"<<endl;
    tab1.open("lotek/plik",ios::out | ios::app);
     if(tab1.good()==true)
      {
	cout<<"Plik istnieje!"<<endl;
	tab1<<"DATA GODZINA "<<" --- >>>WYNIKI LOSOWANIA<<< --- PLUS ;D === SUPER SZANSA =co by wiedzieć czy wygrałem więcej\n";
      }
    tab1.close();
  }
};  
  /*
   
  string slowa[5], slowo_tymczasowe;
////////////////////////////////////////////////////////////////////////////////////////;
  /*cout << "\n >>>Podaj wyrazy ciągu słowo 'Koniec' NIE kończy pracy: \n";  
  for (int i=0; i<5; i++)
  {
   cout<<"Podaj wyraz nr: \033[93m"<<i+1<<"\033[0m ";
   cin>>slowo_tymczasowe;
   //cout<<endl;
   slowa[i] =  slowo_tymczasowe;
   cout << "NAMIAR "<< i << " = ";
  }
  cout << " NAMIAR KONIEC ";
//////////////////////////////////////////////////////////////////////////////////////
  cout << "\n>>>Wyrazy ciągu w kolejności podawania: \n";
  for (int i=0; i<5; i++)
  {
    
   cout<<"slowo nr\033[93m"<<i+1<<"\033[0m"<<": \033[92m"<<slowa[i]<<"\033[0m \n";
  }
  
//////////////////////////////////////////////////////////////////////////////////////

  string posortowana[5]; int licznik_posortowanej; licznik_posortowanej = 0;
  int liczA, liczB;
  
  for(int j=0;j<5;j++){
    //cout<<"\n wart I: "<<j<<"\n";
    
    
  for(int i=0;i<5;i++)
  {
    
    //każde słowo musi być porównane z każdym, ostatnie z pierwszym, porównanie słów znak po znaku,
    //najpierw muszę znać ile jest słów, dalej ile liter ma każde słowo, następnie porównać ze sobą słowa litera po literze
//==============    
    //sprawdzanie które słowa mają tyle samo liter a potem czy to te same litery
    liczA = slowa[j].size();
    liczB = slowa[i].size();
    
    
    
    if(liczA==liczB)
    {
      posortowana[licznik_posortowanej]=slowo_tymczasowe; 
      licznik_posortowanej++;
    }
    
  
    //założenie słowa są takie same jeśli wszystkie ich litery są sobie równe, sprawdzanie zaczynam od porównania ilości liter i jeśli ilości liter w obu porównywanych słowach są takie same wtedy zaczynam porównywać litera po literze
    //jeśli słowa są takie same to powtórzonego słowa nie kopiuję do posortowanej bez powtórzeń
    slowo_tymczasowe = slowa[i];
    //cout << "slowo_tymczasowe: >>>\033[1;31m "<< slowo_tymczasowe<<" \033[0m<<<";
    //cout << "j:\033[1;31m"<< j << "\033[0m\ti:\033[1;31m"<<i <<"\033[0m"<<endl;
    
    if(liczA==liczB)
    {      
      if (liczA==liczB) 
      {}	
    }
    else
    {      
       if (liczA==liczB) 
      {}
    }
    //cout << "slowo : \033[1;31m "<< slowa[i]<<"\033[0m ma liter: \033[1;32m"<<slowa[i].size()<<"\033[0m\n";
  }
    
  }
 // cout << "\n>>>Wyrazy ciągu alfabetycznie: \n";
  for (int i=0; i<5; i++)
  {
  // cout<<"slowo nr\033[93m"<<i+1<<"\033[0m"<<": \033[92m"<<slowa[i]<<"\033[0m \n";
  }
///////////////////////////////////////////////////////////////////////////////////////////////////
  cout << "\n>>>Wyrazy posortowana: \n";
  for (int i=0; i<5; i++)
  {
   cout<<"slowo nr\033[93m"<<i+1<<"\033[0m"<<": \033[92m"<<posortowana[i]<<"\033[0m \n";
  }
};

   */
class Zbiorcza {
  string tabNaWyrazy[5], wyrazTymczasowy,wyrazTymczasowyJ,wyrazTymczasowyI,tabPosortowana;
  int rozmiarWyrazu1, rozmiarWyrazu2;
public:
Zbiorcza(){
  cout << "Podaj 5 wyrazów: \n";
  for (int i=0; i<5; i++)
  {
    cout<<"slowo nr\033[93m"<<i+1<<"\033[0m"<<": \033[92m"<<tabNaWyrazy[i]<<"\033[0m ";
    cin >> tabNaWyrazy[i];
  }
  cout << "\n>>>Wyrazy ciągu w kolejności podawania: \n";
  for (int i=0; i<5; i++)
  {
   cout<<"slowo nr\033[93m"<<i+1<<"\033[0m"<<": \033[92m"<<tabNaWyrazy[i]<<"\033[0m \n";
  }
  for (int j=0; j<5; j++)
  {
    rozmiarWyrazu1 = tabNaWyrazy[j].size();
    for (int i=0; i<5; i++)
    {
      if(j!=i)
      {
	rozmiarWyrazu2 = tabNaWyrazy[i].size();
	if (rozmiarWyrazu1 == rozmiarWyrazu2)
	{
	  //cout <<"J: "<<j+1<<" I: "<<i+1<< " Rozmiary równe";
	  cout << " Rozmiary równe"; 
	  //dostęp do wyruzu i dalej do jego liter
	  wyrazTymczasowyJ = tabNaWyrazy[j];
	  wyrazTymczasowyI = tabNaWyrazy[i];
	  //wyświetlanie wyrazów o tym samym rozmiarze
	  cout<<"\tslowo J-te\033[93m"<<j+1<<"\033[0m"<<": \033[92m"<<wyrazTymczasowyJ<<"\033[0m"<<"\tslowo I-te\033[93m"<<i+1<<"\033[0m"<<": \033[92m"<<wyrazTymczasowyI<<"\033[0m \n";
	  //wyświetlanie literka po literce pierwszego wyrazu
	 // for (int h=0; h<rozmiarWyrazu1;h++)
	  {
	    
	   // cout<<"\tsłowo J-te\033[93m"<<j+1<<"\033[0m"<<": \033[92m "<<wyrazTymczasowyJ[h]<<" \033[0m"
	  //  <<"\tsłowo I-te\033[93m"<<i+1<<"\033[0m"<<": \033[92m "<<wyrazTymczasowyI[h]<<" \033[0m \n";
	    //porównanie liter 
	   //wyrazTymczasowyJ==wyrazTymczasowyI nie rozróżnia wielkości liter 
	    if (stricmp(wyrazTymczasowyJ,wyrazTymczasowyI)==0)
	    {
	      cout <<"wyrazJ == wyrazI: "<< wyrazTymczasowyJ << endl;
	      //cout<<"\tliterka J-te\033[93m"<<j+1<<"\033[0m"<<": \033[92m "<<wyrazTymczasowyJ[h]<<" \033[0m"
	      //<<"\tliterka I-te\033[93m"<<i+1<<"\033[0m"<<": \033[92m "<<wyrazTymczasowyI[h]<<" \033[0m \n";
	      //zapisz wyraz w posortowanej tablicy
	      //Jak posortowanej?
	      //tabPosortowana += ' ' + wyrazTymczasowyJ;
	      //cout << "tabPosortowana: " << tabPosortowana;
	      //cout<<"\t tabPosortowana:\033[93m"<<tabPosortowana<<"\033[0m ";
	      
	    }
	  }
	  
	}
	else cout <<"J: "<<j+1<<" I: "<<i+1<< " Różne\n"; 
      }
    }
  }
}
};

int main (){  
  
  //lotek l;
  Zbiorcza Zbior;
  
  /*
  SlowaZKlawirki sk;
  ListaSlow l;
  
     SlowaZBibliotekiStandardowej s2;
TabNapi tn;
tn.pokaz(); tn.pokaz2();
   
  CzasyIteracji C;
  for (int i=0; i!=11; i++) cout << mc[i].nazwa << ":\t" << mc[i].dlugosc << "\n";
  char c;
  unsigned char uc;
  signed char sc;
  FunkcjeZad5_6 f;
  f.f('a');  f.f(49);  f.f(3300);  f.f(c);  f.f(uc);  f.f(sc);
  f.g('a');  f.g(49);  f.g(3300);  f.g(c);  f.g(uc);  f.g(sc);
  f.h('a');  f.h(49);  f.h(3300);  f.h(c);  f.h(uc);  f.h(sc);
  
  ZamianaWartosciInt zi(-2,339);
  int ia = 1; int ib=2;
  int *pia = &ia;
  int *pib = &ib;
ZamianaWartosciIntWsk zw(pia,pib); 
  int wia = 14; int wib=42;
  int &ria = ia;
  int &rib = ib;
ZamianaWartosciIntRef zr(ria,rib); 
  ZamianaWartosciIntRSym rsym(-1,99);
  
  Deklaracje d;
  cout << "Tekściu przed kolorkami"<<endl;
  Kolorki k;
  cout << "Tekściu po kolorkach"<<endl;
  UseR4z5 u;
  Litery l;
  Majn obiektKlasyMajn;
  Klasa_Bazowa obiektKlasyBazowejJeden(3,4);
  obiektKlasyBazowejJeden.set(1,2);
  obiektKlasyBazowejJeden.setWew(5);
  obiektKlasyBazowejJeden.get();
  Typy_I_Ich_Rozmiary obiektKlasyTypyIIchRozmiary;
  obiektKlasyTypyIIchRozmiary.get();	
  */
}