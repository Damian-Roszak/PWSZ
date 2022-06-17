#include <iostream>
#include <string>
#include <locale.h>
using namespace std;
int main ()
{
  setlocale (LC_ALL,"");
  int ileZnakow = 0;
  string str("Test ęóąśłćń ĘÓĄŚŁĆŃ string");
  cout << "Rozmiar - " << str.length()<<endl;
  
  for(unsigned int i=0;i<str.length();i++){
    if (str[i] == 'ą')
        cout<<str[i]<<endl;
    ileZnakow++;
  }
    cout << "ileZnakow: "<< ileZnakow<<endl;
   cout << endl; 
  return 0;
}
