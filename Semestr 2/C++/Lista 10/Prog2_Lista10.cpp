#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>

using namespace std;


class macierz
{
public:
    vector < vector< int>> a;
    int N;
    
    //int arr[][];
    
    macierz();
    macierz(int n)
    {
        
        N = n;
        
        for (int i=0; i<N; i++)
        {
            a.push_back(vector< int>()); //.resize(M)
            //a[i].resize(N);
        }
        
        
    }
    void zrob()
    {
        int rnd;
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                rnd = (int)rand()%10;
                cout << "\n rnd = " << rnd;
            //cout << "\n macier = " << a[i][j];
            a[i].push_back(rnd);
            }
            //a[i].push_back(rnd);
        } 
    
    }
    void wczytaj()
    {
        int rnd;
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                cout << "\n Podaj element [" << i << "][" << j << "]=";
                cin >> rnd;
                a[i].push_back(rnd);
            }            
        } 
    
    }
    macierz operator+(macierz dodawana)
    {          
            macierz suma(this->N);            
            for (unsigned int i=0; i<dodawana.a.size(); i++)
            {
                for (unsigned int j=0; j<dodawana.a[i].size(); j++)
                {
                   suma.a[i].push_back(
                   this->a[i][j] + 
                   dodawana.a[i][j]);
                }
            }   
        
    return suma;   
    }
     
    macierz operator-(macierz odejmowana)
    {
            macierz roznica(this->N);            
            for (int i=0; i<N; i++)
            {
                for (int j=0; j<N; j++)
                {
                   roznica.a[i].push_back(this->a[i][j] - odejmowana.a[i][j]);
                }
            }   
        
    return roznica;   
    }
    macierz operator*(macierz mnozona)
    {
     macierz m3(mnozona.N);
     int suma = 0;
  
      for ( int i=0; i < mnozona.N; i++)
      {
        //m3.a[i].push_back(vector<int>());
        for( int j=0; j<mnozona.N; j++)
        {
            suma = 0;
            for( int k=0; k<mnozona.N; k++)
            {
                 suma += this->a[i][k] * mnozona.a[k][j];
                 
            }
            m3.a[i].push_back(suma);
        }
      }     
        
    return m3;        
   }
   void poka()
   {
          for ( int i=0; i < N; i++)
          {
              cout << endl;
              for( int j=0; j<N; j++)
              {
                  //cout<<"\nelement m["<<i<<"]["<<j<<"]: "<<m1[i][j];
                  cout <<" "<< a[i][j];  //m1.a[i][j];
              }
          }  
   };
   
    bool operator==(macierz porownywana)
    {
        int suma1=0, suma2=0;
        
          for (int i=0; i < porownywana.N; i++)
          {                
                for(int j=0; j<porownywana.N; j++)
                {
                    suma1 += this->a[i][j];
                }
          }    
          for (int i=0; i < porownywana.N; i++)
          {                
                for(int j=0; j<porownywana.N; j++)
                {
                    suma2 += porownywana.a[i][j];
                }
          }   
          
          if (suma1==suma2) return true;
          else return false;
    }
    bool operator<(macierz porownywana)
    {
        int suma1=0, suma2=0;
        
          for (int i=0; i < porownywana.N; i++)
          {                
                for(int j=0; j<porownywana.N; j++)
                {
                    suma1 += this->a[i][j];
                }
          }    
          for (int i=0; i < porownywana.N; i++)
          {                
                for(int j=0; j<porownywana.N; j++)
                {
                    suma2 += porownywana.a[i][j];
                }
          }   
          
          if (suma1<suma2) return true;
          else return false;
    }
    
    bool operator>(macierz porownywana)
    {
        return !(*this < porownywana);
    }
    
    macierz negacja()
    {
         macierz neg(this->N);            
            for (int i=0; i<N; i++)
            {
                for (int j=0; j<N; j++)
                {
                   neg.a[i].push_back(this->a[i][j] * -1);
                }
            }   
        
    return neg; 
    }


friend ostream & operator<< (ostream & m, macierz const& o)
    {
                       
            for (int i=0; i<o.N; i++)
            {
                for (int j=0; j<o.N; j++)
                {
                   m << " " << o.a[i][j];
                }
                m << endl;
            }   
        
    return m;   
    }

};


void poka_macierz(macierz m1)
{
cout << "\n Wyświetlam macierz: ";
 for (unsigned int i=0; i < m1.a.size(); i++)
  {
      cout << endl;
      for(unsigned int j=0; j<m1.a[i].size(); j++)
      {
          //cout<<"\nelement m["<<i<<"]["<<j<<"]: "<<m1[i][j];
          cout <<" "<< m1.a[i][j];  //m1.a[i][j];
      }
  }  

 cout << endl;
}









int main()
{
int n,odp;
srand(time(0));
       
			 cout << "\n podaj wymiar macierzy A i B: ";
             cin >> n;
             cout << "\n macierz A: ";
             macierz a(n);
             a.zrob();
             //a.wczytaj();
             cout << "\n macierz B: ";
             macierz b(n);
             b.zrob();
             //b.wczytaj();
             cout << "\n si Aut: \n";
             cout << a;
         
            cout << "\n poka a: ";
            poka_macierz(a);
            cout << "\n poka b: ";
            poka_macierz(b);
            

bool czyDziala = true;
	while (czyDziala) {
		
		cout << endl;

		cout << "########### MENU ###########" << endl;
		cout << "[1] Dodaj" << endl;
		cout << "[2] Odejmij" << endl;
		cout << "[3] Pomnóż" << endl;
		cout << "[4] Zaneguj" << endl;
		cout << "[5] Porównaj operatorem <" << endl;
		cout << "[6] Porównaj operatorem >" << endl;
		cout << "[7] Porównaj operatorem ==" << endl;
		cout << "[0] Wyjdź" << endl;
		cout << "##########################" << endl;
		cout << "Podaj opcje: ";

		cin >> odp;
		cout << endl;

		switch (odp) {
		case 1: {			
            macierz suma(n);  
            cout << "\n Suma macierzy to: "; 
            suma = a + b;
            poka_macierz(suma);
			break;
		}
		case 2: {
			cout << "\n Różnica  macierzy to " ;
			macierz rozn(n);
			rozn = a - b;
            poka_macierz(rozn);
			break;
		}
		case 3: {
			cout << "\n Iloczyn  macierzy to " ;
			macierz il(n);
			il = a * b;
            poka_macierz(il);
			break; 
		}
		case 4: {
			cout << "\n Negacja  macierzy to " ;
			macierz negA(n);
			macierz negB(n);
			negA = a.negacja();
            poka_macierz(negA);
			negB = b.negacja();
            poka_macierz(negB);
			break;
		}
		case 5: {
			cout << "\n Porównanie operatorem <  macierzy to " ;
			
			if (a < b)
			    cout << "a jest mniejsze";
			else
			    cout << "a nie jest mniejsze";
			break;
		}
		case 6: {
			cout << "\n Porównanie operatorem >  macierzy to " ;
			
			if (a > b)
			    cout << "a jest wieksze";
			else
			    cout << "a nie jest wieksze";
			break;
		}
		case 7: {
			cout << "\n Porównanie operatorem ==  macierzy to " ;
			
			if (a == b)
			    cout << "a i b są równe";
			else
			    cout << "nie są równe";
			break;
		}
		case 0: {
			czyDziala = false;
			break;
		}
		default: {
			cout << "Zły wybór!" << endl;
			
			break;
		}
		}
	}           
           

cout << endl;
return 5;
}
