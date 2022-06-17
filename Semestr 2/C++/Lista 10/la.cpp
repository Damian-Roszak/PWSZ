#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>

using namespace std;


class uczen 
{
    public:
        int oceny[5];
        
        uczen()
        {
            for (int i=0; i<5; i++)
            {
                oceny[i]=rand()%6+1;
            }
        }
        
        bool operator<(uczen a)
        {
            float sr1=0.0, sr2=0.0;
            for (int i=0; i<5; i++)
            {
                sr1 += this->oceny[i];
                sr2 += a.oceny[i];
            }
            sr1 /=5;
            sr2 /=5;
            
            if(sr1 < sr2) return true;
            else return false;
        }
        bool operator>(uczen a)
        {
            float sr1=0.0, sr2=0.0;
            for (int i=0; i<5; i++)
            {
                sr1 += this->oceny[i];
                sr2 += a.oceny[i];
            }
            sr1 = sr1 / 5.0;
            sr2 = sr2 / 5.0;
            
            if(sr1 > sr2) return true;
            else return false;
        }
        void poka()
        {
            for (int i=0; i<5; i++)
            {
                cout << " " << this->oceny[i];
            }
        }
};

int main()
{
srand(time(0));
  uczen u1,u2;
  
      cout << "\n Uczeń 1: ";
      u1.poka();
      cout << "\n Uczeń 2: ";
      u2.poka();
  
  if(u1>u2) cout << "\n Uczeń 1 ma większą średnią";

  else if(u1<u2) cout << "\n Uczeń 2 ma większą średnią";
    
    else cout << "\n Uczeniowie 1 i 2 mają równą średnią";

cout << endl;
return 5;
}
