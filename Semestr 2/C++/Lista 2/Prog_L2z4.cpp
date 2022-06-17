#include<iostream>
#include<string>
#include <cstring>
#include<locale>
#include<cstdlib>
#include <regex> 
#include <locale.h>

int main(){

using namespace std;

  setlocale (LC_ALL,"");
//string n = "óóó.oléłóćńę.ęą/ Ala ma kota, a kot ma Alę. W marcu jak w garncu. A w kwietniu to: kwiecień plecień porzeplata trochę zimy trochę lata. :D" ; 
string n;// = "ąAla ma kota, a kot ma Alę.ocne";
 //"ąóóó.oléł.óćńę.ęą/ .aącć,eęłl,db" ; // "oléłóćńę" ;
int sumaBezSpacji=0, sumaBezZnakuDoPominiecia=0, sumaSamychLiter=0, sumaSpacji=0, sumaZnakPominiecia=0;
char znakDoPominiecia;// = 'o' ;
char znakPodzialu;// = ' ' ;

    stdin = freopen(NULL,"r",stdin); 
 cout << "\n Podaj ciąg stringowy: ";
 getline (cin , n);
    stdin = freopen(NULL,"r",stdin); 


 cout << "\n Podaj znakDoPominiecia: ";
cin.get(znakDoPominiecia);
    stdin = freopen(NULL,"r",stdin); 


 cout << "\n Podaj znakPodzialu: ";
cin.get(znakPodzialu);
    stdin = freopen(NULL,"r",stdin); 

 
  cout << "\n Podane zdanie/a to: \n\t";
  cout << "\"" << n << "\"\n";
  
  if (znakDoPominiecia!=' '){
      cout << "\n znak Do Pominiecia to: ";
      cout << "\"" << znakDoPominiecia << "\"\n";
      }else{        
      cout << "\n znak Do Pominiecia to: ";
      cout << "\"" << znakDoPominiecia << "\"" << " (spacja)\n";
  }
  

   
   cout << "\n Wypisuje wszystkie wyrazy w zdaniu na ekran: \n\t";
for (unsigned int i=0; i<n.length(); i++){
    if (n[i] == ' ') sumaSpacji++;
    if (n[i] == znakDoPominiecia) sumaZnakPominiecia++;
    if (((n[i] >= 65 && n[i] <= 90) || (n[i] >= 97 && n[i] <= 122)) && (n[i] != znakDoPominiecia)) {
        sumaBezZnakuDoPominiecia++;  
    }
    if ( (n[i] != ' ') && !(((n[i] >= 32 && n[i] <= 64) || (n[i] >= 91 && n[i] <= 96) || (n[i] >= 123 && n[i] <= 127) ) )){
         sumaBezSpacji++;
        
    }
    if ((n[i] >= 65 && n[i] <= 90) || (n[i] >= 97 && n[i] <= 122)){       
         sumaSamychLiter++;
    }
    if( !(((n[i] >= 32 && n[i] <= 64) || (n[i] >= 91 && n[i] <= 96) || (n[i] >= 123 && n[i] <= 127) ) )) cout << n[i];
    else cout << ' ';
}
/*
// WYŚWIETLANIE ZMIENNYCH
cout << "\n suma Liter Bez Spacji to: ";
  cout << "\"" << sumaBezSpacji << "\"\n";
  
cout << "\n suma Liter Bez Znaku Do Pominiecia to: ";
  cout << "\"" << sumaBezZnakuDoPominiecia << "\"\n";
  
cout << "\n suma Znaków Do Pominiecia to: ";
  cout << "\"" << sumaZnakPominiecia << "\"\n";
  
cout << "\n suma Spacji to: ";
  cout << "\"" << sumaSpacji << "\"\n";
  
cout << "\n suma Samych Liter: ";
  cout << "\"" << sumaSamychLiter << "\"\n";
  */
  
//cout << "\n podaj tab: ";
//  char tab[1];
 // cin.getline( tab, 1); //znakDoPominiecia
 
 /*
 string *tabNap = (string*)realloc((tabNap) ,sizeof(tabNap));
 cout << "\n 1 sizeof(tabNap) " << sizeof(*tabNap);
      tabNap[0] = "lol";
  for (int i=2; i<n.length(); i++){
     tabNap = (string*)realloc((tabNap) , i*2*sizeof(string));
     
 cout <<"\n" << i << " sizeof(tabNap) " << sizeof(*tabNap);
 cout << "\n sizeof(tabNap) " << sizeof(*tabNap);
     //tabNap[i] = "lol";
    //tabNap[i] = n[i];
  }
  
 cout << "\n tabNap " << *tabNap;
 */
unsigned int licznikPodzialu = 0;
 string *tabNap = new string[sizeof(string)];
 string *tmp = new string[1];
 size_t rozmiar;
 
 
   if (znakPodzialu!=' '){
          tabNap[0] = tabNap[0] + "Podział w oparciu o znak podziału: '" + znakPodzialu + "'" + ".";
      }else{        
          tabNap[0] = tabNap[0] + "Podział w oparciu o znak podziału: '" + znakPodzialu + "'" + " (spacje).";
  }
     
  for (unsigned int i=1; i<n.length(); i++){
    
          for (unsigned int j=0; j<i ; j++) tmp[j] = tabNap[j];
          
     if (i == 0)
             rozmiar = sizeof(string)*1;
        else
             rozmiar = sizeof(string)*i;
      delete[] tabNap;             
      
     tabNap = new string[rozmiar];
       for (unsigned int j=0; j<i ; j++) tabNap[j] = tmp[j];
      
       delete[] tmp;
     tmp = new string[rozmiar];
     
     while((licznikPodzialu < n.length()) ){     
         tabNap[i] = tabNap[i] + n[licznikPodzialu];
         licznikPodzialu++;
         if (n[licznikPodzialu] == znakPodzialu){
             tabNap[i] = tabNap[i] + n[licznikPodzialu];
             //cout << "\n tabNap[i][0] '" << tabNap[i][0] << "'";
             licznikPodzialu++;
             break;
         }
     }
     if( n[licznikPodzialu] == '\0') break;
  }
    
 
    int t2 = 0, t1 = 0;
    for (auto znak : n) {
        if ((znak & 0xC0) != 0x80) {
            t1 += 1;
        }        
        if ( ((znak & 0xC0) == 0x80 ) ) {
            t2 += 1;
        }
    };
    
    for (unsigned int i=0; i<n.length(); i++){
        
        cout << "znak: " << *n[i][1];
    }
    
    cout << endl << "\nIlość znaków: " << t1;
    cout << "\nIlość Wszystkich Liter z spacjami: " << t2 + sumaSamychLiter + sumaSpacji ;
    cout << "\nIlość Wszystkich Liter (BEZ SPACJI): " << t2 + sumaSamychLiter ;
    cout << "\nIlość Wszystkich Liter (BEZ SPACJI) z pominięciem znaku do pominięcia: " << t2 + sumaSamychLiter - sumaZnakPominiecia << endl;
      
  
  for (unsigned int j=0; j<n.length(); j++){
    if( tabNap[j].empty()) break;
     cout << "\n tabNap " << j << ": " <<tabNap[j];
  }
  
cout << endl << endl;
return 5;
}
