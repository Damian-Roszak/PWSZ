#include<iostream>

int main(){

using namespace std;

int l;

 cout << "\n Podaj ilość poziomów imperialnego krążownika: ";
 cin >>l;

for(int n = 1; n<=l; n++){
   for (int i = 1; i<=n; i++){
    for (int j = 0; j<n-i; j++){
      cout << " "; 
    }
    for (int k=0; k<2*i-1; k++)
        if (k==0 || k==2*i-2 || i==n) cout << "*";
        else cout << "*";
        
        cout << "\n";
   }

}

return 5;
}
