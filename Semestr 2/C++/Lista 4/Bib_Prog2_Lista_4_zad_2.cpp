#include "Bib_Prog2_Lista_4_zad_2.hpp"


vector<vector<int>> wieksza_mniejsza(int rozmiar, vector<vector<int>> m1, vector<vector<int>> m2)
{
    int suma1=0, suma2=0;
    
  for (int i=0; i < rozmiar; i++)
  {
      cout << endl;
      for(int j=0; j<rozmiar; j++)
      {
          suma1 = m1[i][j];
          suma2 = m2[i][j];
      }
  }
  
  if(suma1>suma2){
    cout << "\n zwracam pierwszą: ";
   return m1;
   }
  else if(suma2>suma1)
  {
    cout << "\n  zwracam drugą: ";
     return m2;
  }
  else {
    cout << "\n są równe, zwracam pierwszą: ";
    return m1;
  }  
    
}


void wczytaj_macierze(int &rozmiar, vector<vector<int>> & m1, vector<vector<int>>& m2)
{
int tmp;
    
      cout << "\n Podaj rozmiar macierzy: ";
      cin >> rozmiar;

cout << "\n Macierz pierwsza: ";
  for (int i=0; i < rozmiar; i++)
  {
        m1.push_back(vector<int>());
        for(int j=0; j<rozmiar; j++)
        {
            cout << "\n Podaj element m["<<i<<"]["<<j<<"]: ";
            cin >> tmp;
            m1[i].push_back(tmp);
        }
  }  
//poka_macierz(rozmiar, m1);
cout << "\n Macierz druga: ";
  for (int i=0; i < rozmiar; i++)
  {
        m2.push_back(vector<int>());
        for(int j=0; j<rozmiar; j++)
        {
            cout << "\n Podaj element m["<<i<<"]["<<j<<"]: ";
            cin >> tmp;
            m2[i].push_back(tmp);
        }
  }  
//poka_macierz(rozmiar, m2);
}

vector<vector<int>> opcja1(int rozmiar, vector<vector<int>> m1, vector<vector<int>> m2)
{
 
 vector<vector<int>> m3;
 
  
  for (int i=0; i < rozmiar; i++)
  {
        m3.push_back(vector<int>());
        for(int j=0; j<rozmiar; j++)
        {
            m3[i].push_back(m1[i][j]+m2[i][j]);
        }
  }     
        
//      cout << "\n Wynik dodawania macierzy: ";
//      poka_macierz(N, m3);
return m3;        
}

void poka_macierz(int rozmiar, vector<vector<int>> m1)
{
cout << "\n Wyświetlam macierz:";
 for (int i=0; i < rozmiar; i++)
  {
      cout << endl;
      for(int j=0; j<rozmiar; j++)
      {
          //cout<<"\nelement m["<<i<<"]["<<j<<"]: "<<m1[i][j];
          cout <<" "<< m1[i][j];
      }
  }  

 cout << endl;
}

vector<vector<int>> opcja2(int rozmiar, vector<vector<int>> m1, vector<vector<int>> m2)
{
 
 vector<vector<int>> m3;
 
  
  for (int i=0; i < rozmiar; i++)
  {
        m3.push_back(vector<int>());
        for(int j=0; j<rozmiar; j++)
        {
            m3[i].push_back(m1[i][j]-m2[i][j]);
        }
  }     
        
//      cout << "\n Wynik odejmowania macierzy: ";
//      poka_macierz(N, m3);
return m3;        
}


vector<vector<int>> opcja3(int rozmiar, vector<vector<int>> m1, vector<vector<int>> m2)
{
 
 vector<vector<int>> m3;
 int suma = 0;
  
  for (int i=0; i < rozmiar; i++)
  {
        m3.push_back(vector<int>());
        for(int j=0; j<rozmiar; j++)
        {
            suma = 0;
            for(int k=0; k<rozmiar; k++)
            {
                 suma += m1[i][k] * m2[k][j];
                 
            }
            m3[i].push_back(suma);
        }
  }     
        
//      cout << "\n Wynik mnożenia macierzy: ";
//      poka_macierz(N, m3);
return m3;        
}


