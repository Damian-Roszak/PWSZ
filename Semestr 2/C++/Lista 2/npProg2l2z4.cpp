#include <iostream>
#include <string>
using namespace std;
int main(int argc, char** argv) {



    string zdanie;
    int x,litery,literybezznaku=0,literybezspacji;
    char znak;
    cout<<"Wpisz zdanie: ";
    getline(cin, zdanie);
    x=zdanie.size();
    cout<<"Jaki znak chcesz pominac w liczeniu liter: ";
    cin>>znak;
    for(int i=0;i<x;i++){
        litery=litery+1;
        if(zdanie[i]!=znak){
            literybezznaku++;
        }
        if(zdanie[i]!=' '){
            literybezspacji++;
        }
    }
    cout<<"Ilosc wszystkich znakow: "<<litery<<endl;
    cout<<"Ilosc znakow bez spacji: "<<literybezspacji<<endl;
    cout<<"Ilosc znakow z pominieciem litery "<<znak<<" "<< literybezznaku<<endl;
    
    for(int i=0;i<x;i++){
        if(zdanie[i]==' '){
            cout<<endl;
        }
        else cout<<zdanie[i];
    }
    cout<<endl;cout<<endl;
    
    cout << endl <<"sizeof(char): " << sizeof(char)<<endl;
    cout << endl <<"sizeof(\"ą\"): " << sizeof("ą")<<endl;
  //  cout << endl <<"sizeof('ą'): " << sizeof('ą')<<endl;
    char a = *("ą");
    cout << endl <<"sizeof(char a = 'ą'): " << sizeof(a)<<endl;
    cout << endl <<"sizeof(char a = *(\"ą\")): " << sizeof(*("ą"))<<endl;
    
    cout<<endl;
    return 0;
}
