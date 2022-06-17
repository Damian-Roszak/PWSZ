#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <typeinfo>

using namespace std;


/*

void zrob()
{
    T rnd;
   cout << "\n rnd = \n";
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                rnd = (T)(rand()%10)+(T)((rand()%10)/10.0);
                cout << " " << rnd;
                a[i].push_back(rnd);
            }
            cout << endl;
        }
} */

class punkt2d
{
public:
    double x;
    double y;  
    
    punkt2d(double a, double b)
    {
        x = a; y = b;
    }
    punkt2d(double a)
    {
        x = a; y = 0; 
    }
    
    punkt2d()
    {
        zrob();
    }
    
void zrob()
{  
   // T rnd;
    //double x;
   // double y;
  // cout << "\n rnd = \n" ;
     //   for (int i=0; i<N; i++)
      //  {
          //  for (int j=0; j<N; j++)
          //  {
                x = (double)(rand()%10);
                y = (double)(rand()%10);
                //T rnd1( (double)(rand()%10), (double)(rand()%10));
               // rnd.x = x;
              //  rnd.y = y;
             //   cout << " " << rnd;
                //a[i].push_back(rnd);
           // }
          //  cout << endl;
       // }
}

    punkt2d operator+(punkt2d dodawana)
    {          
       punkt2d suma(this->x + dodawana.x, this->y + dodawana.y);
    return suma;   
    }
        
    punkt2d operator-(punkt2d odejmowana)
    {          
       punkt2d roznica(this->x - odejmowana.x, this->y - odejmowana.y);
    return roznica;   
    }

    punkt2d operator*(punkt2d mnozona)
    {     
      punkt2d m3(this->x * mnozona.x, this->y * mnozona.y);    
    return m3;        
    }    
    punkt2d operator*(int mnozona)
    {     
      punkt2d m3(this->x * mnozona, this->y * mnozona);    
    return m3;        
    }    
    punkt2d operator*(double mnozona)
    {     
      punkt2d m3(this->x * mnozona, this->y * mnozona);    
    return m3;        
    }    
    
    punkt2d operator=(punkt2d mnozona)
    {     
      punkt2d m3(this->x = mnozona.x, this->y = mnozona.y);    
    return m3;        
    }  
     punkt2d operator=(int stala)
    {     
      punkt2d m3(this->x = stala, this->y = stala);          
    return m3;        
    }
    friend ostream & operator<< (ostream & m, punkt2d const& o)
    {          
         m << "[" << o.x << "," << o.y << "]";
    return m;   
    }  
};


class zespolona
{
public:
    string name = "zespolona";
    double R;
    double U;
    char i='i';
    
    zespolona(){
        zrobZ();
    }
    
    zespolona(double a, double b)
    {
        R = a; U = b;
    }
    zespolona(double a)
    {
        R = a; U = 0;
    }
      
void zrobZ()
{  
   
  R = (double)(rand()%10);
    U = (double)(rand()%10);
               
}  
    zespolona operator+(zespolona dodawana)
    {          
       zespolona suma(this->R + dodawana.R, this->U + dodawana.U);
    return suma;   
    }
        
    zespolona operator-(zespolona odejmowana)
    {          
        zespolona roznica(this->R - odejmowana.R, this->U - odejmowana.U);
    return roznica;   
    }


    zespolona operator*(zespolona mnozona)
    {     
      double RR = this->R*mnozona.R;
      double RU = this->R*mnozona.U;
      double UR = this->U*mnozona.R;
      double UU = this->U*mnozona.U;
      
      double sumaI = RU + UR;
      
      UU = UU * -1.0;
    //  cout << "\t UU = " << UU;
      double RRplusUU = RR + UU;
      
      zespolona m3(RRplusUU, sumaI);    
    //  cout << "; m3 = " << m3;
            
    return m3;        
    }

    zespolona operator*(int mnozona)
    {     
      double Ri = this->R*mnozona;
        double Ui;
      if (this->U == 0 && mnozona == -1)
        Ui = this->U;
      else
          Ui = this->U*mnozona;
      
      zespolona m3(Ri, Ui);    
    //  cout << "; m3 = " << m3;
            
    return m3;        
    }
    zespolona operator*(double mnozona)
    {     
      double Ri = this->R*mnozona;
       double Ui;
      if (this->U == 0 && mnozona == -1)
        Ui = this->U;
      else
          Ui = this->U*mnozona;
      
      zespolona m3(Ri, Ui);    
    //  cout << "; m3 = " << m3;
            
    return m3;        
    }

    friend ostream & operator<< (ostream & m, zespolona const& o)
    {    
         if(o.U < 0)      
            m << " " << o.R << o.U << o.i << " ";
         else
            m << " " << o.R << "+" << o.U << o.i << " ";
    return m;   
    }  
    
    zespolona operator=(zespolona mnozona)
    {     
      zespolona m3(this->R = mnozona.R, this->U = mnozona.U);    
    return m3;        
    }  
    
    zespolona operator+=(zespolona mnozona)
    {     
      zespolona m3(this->R = mnozona.R, this->U = mnozona.U);    
    return m3;        
    } 
    /*zespolona operator=(int mnozona)
    {     
      zespolona m3(this->R = mnozona.R, this->U = mnozona.U);          
    return m3;        
    } */
      
};

//template <class T>
class punkt3d
{
public:
    double x;
    double y;
    double z;    
    punkt3d()
    {
        zrobP();
    }
    punkt3d(double a, double b, double c)
    {
        x = a; y = b; z = c;
    }
    punkt3d(double a, double b)
    {
        x = a; y = b; z = 0;
    }
    punkt3d(double a)
    {
        x = a; y = 0; z = 0;
    }

void zrobP()
{  
    //T rnd;
   // double x;
  //  double y;
   // double z;
  /* cout << "\n rnd = \n" ;
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {*/
                x = (double)(rand()%10);
                y = (double)(rand()%10);
                z = (double)(rand()%10);
                //T rnd1( (double)(rand()%10), (double)(rand()%10));
              /*  rnd.x = x;
                rnd.y = y;
                rnd.z = z;
                cout << " " << rnd;*/
               // a[i].push_back(rnd);
           /* }
            cout << endl;
        }*/
}

/*
void wczytaj()
{
       // T rnd;
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                cout << "\n Podaj element [" << i << "][" << j << "]=";
               // cin >> rnd;
               // a[i].push_back();
            }            
        }     
}*/
    punkt3d operator+(punkt3d dodawana)
    {          
       punkt3d suma(this->x + dodawana.x, this->y + dodawana.y, this->z + dodawana.z);
    return suma;   
    }
        
    punkt3d operator-(punkt3d odejmowana)
    {          
       punkt3d roznica(this->x - odejmowana.x, this->y - odejmowana.y, this->z - odejmowana.z);
    return roznica;   
    }

    punkt3d operator*(punkt3d mnozona)
    {     
      punkt3d m3(this->x * mnozona.x, this->y * mnozona.y, this->z * mnozona.z);    
    return m3;        
    }    
    punkt3d operator*(int mnozona)
    {     
      punkt3d m3(this->x * mnozona, this->y * mnozona, this->z * mnozona);    
    return m3;        
    }    
    punkt3d operator*(double mnozona)
    {     
      punkt3d m3(this->x * mnozona, this->y * mnozona, this->z * mnozona);    
    return m3;        
    }    
    
    punkt3d operator=(punkt3d mnozona)
    {     
      punkt3d m3(this->x = mnozona.x, this->y = mnozona.y, this->z = mnozona.z);    
    return m3;        
    }  
     punkt3d operator=(int stala)
    {     
      punkt3d m3(this->x = stala, this->y = stala, this->z = stala);          
    return m3;        
    }
    friend ostream & operator<< (ostream & m, punkt3d const& o)
    {          
         m << "[" << o.x << "," << o.y << "," << o.z << "]";
    return m;   
    }  
};


template <class T> 
class macierz
{
public:
    vector < vector< T>> a;
    int N;    
    
    macierz();
    macierz(int n)
    {        
        N = n;        
        for (int i=0; i<N; i++)
        {
            a.push_back(vector< T>());
            for (int j=0; j<N; j++)
            {
                T elem;
                elem = rand()%10;
                //cout << "elem: " << elem;
                 a[i].push_back(elem);
            }
        }
    }
 macierz(int n, T neutral)
    {        
        N = n;        
        for (int i=0; i<N; i++)
        {
            a.push_back(vector< T>());
            for (int j=0; j<N; j++)
            {
                //T elem=0;
               // elem = rand()%10;
                //cout << "elem: " << elem;
                 a[i].push_back(neutral);
            }
        }
    }

 
macierz<T> operator-(macierz<T> odejmowana)
{
            macierz<T> roznica(this->N);            
            for (int i=0; i<N; i++)
            {
                for (int j=0; j<N; j++)
                {
                   roznica.a[i].push_back(this->a[i][j] - odejmowana.a[i][j]);
                }
            }   
        
return roznica;   
}

macierz<T> operator*(macierz<T> mnozona)
{
     macierz<T> m3(mnozona.N);
     T suma = 0;
  
      for ( int i=0; i < mnozona.N; i++)
      {
        for( int j=0; j<mnozona.N; j++)
        {
            suma = 0;
            for( int k=0; k<mnozona.N; k++)
            {
                 suma = suma + ( this->a[i][k] * mnozona.a[k][j]);
                 //cout << "\n this->a["<<i<<"]["<<k<<"] " << this->a[i][k] << "* mnozona.a["<<i<<"]["<<k<<"] " << mnozona.a[k][j] << " = " << this->a[i][k] * mnozona.a[k][j] << " suma " << suma;                 
            }
            m3.a[i].push_back(suma);
        }
      }     
        
return m3;        
}

macierz<T> operator*(int mnozona)
{
     macierz<T> m3(N);
     //T suma = 0;
  
      for ( int i=0; i < N; i++)
      {
        for( int j=0; j<N; j++)
        {
            //suma = 0;
            for( int k=0; k<N; k++)
            {
                 
            m3.a[i].push_back( this->a[i][k] * mnozona);
                 //cout << "\n this->a["<<i<<"]["<<k<<"] " << this->a[i][k] << "* mnozona.a["<<i<<"]["<<k<<"] " << mnozona.a[k][j] << " = " << this->a[i][k] * mnozona.a[k][j] << " suma " << suma;                 
            }
        }
      }     
        
return m3;        
}
friend ostream & operator<< (ostream & m, macierz<T> const& o)
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
        
macierz<T> operator+(macierz<T> dodawana)
{          
            macierz<T> suma(N,0);            
            for (unsigned int i=0; i<dodawana.a.size(); i++)
            {
                for (unsigned int j=0; j<dodawana.a[i].size(); j++)
                {
                   cout << "\nBEFOR suma.a[i]= " << suma.a[i][j];
                   //suma.a[i].push_back(this->a[i][j] + dodawana.a[i][j]);
                   suma.a[i][j] = this->a[i][j] + dodawana.a[i][j];
                   cout << "\n suma.a[i]= " << suma.a[i][j] << " this.a = " << this->a[i][j] << " + dodawana.a[i][j] = " << dodawana.a[i][j];
                   cout << "\n suma " << this->a[i][j] + dodawana.a[i][j];
                }
            }        
return suma;   
}

};






int main()
{
int n=3,odp;
char typ='i';

bool czyDziala = true;
srand(time(0));
       
      
       
	//typ = 'p'; odp =0; n = 2;
       
	cout << "\n podaj TYP macierzy A i B int=[i] / double=[d] / zespolona=[z] / punkt3d=[p] / punkt2d=[n]: ";
	//cin >> typ;
	cout << "\n podaj wymiar macierzy A i B: ";
    //cin >> n;
	if (typ == 'i'){
        macierz<int> a(n);
	    cout << "\n macierz A: \n" << a;
      //  a.zrob();
        //a.wczytaj();
        macierz<int>   b(n);
        cout << "\n macierz B: \n" << b;
      //  b.zrob();
        //b.wczytaj();	
        while (czyDziala) {
		
		cout << endl;

		cout << "########### MENU ###########" << endl;
		cout << "[1] Dodaj" << endl;
		cout << "[2] Odejmij" << endl;
		cout << "[3] Pomnóż" << endl;
		cout << "[4] Pomnóż przez liczbę" << endl;
		cout << "[0] Wyjdź" << endl;
		cout << "##########################" << endl;
		cout << "Podaj opcje: ";
		cin >> odp;
		cout << endl;
		

		switch (odp) {
		case 1: {			
            macierz<int> suma(n,0);  
            cout << "\n Suma : \n" << suma; 
            suma = a + b;
            cout << "\n Suma macierzy to: \n" << suma; 
            //poka_macierz(suma);
			break;
		}
		case 2: {
			macierz<int> rozn(n);
			rozn = a - b;
			cout << "\n Różnica  macierzy to: \n" << rozn;
           // poka_macierz(rozn);
			break;
		}
		case 3: {
			macierz<int> il(n);
			il = a * b;
			cout << "\n Iloczyn  macierzy to \n" << il;
            //poka_macierz(il);
			break; 
		}
		case 4: {
		    int liczba;
		    cout << "\n Podaj liczbę całkowitą do pomnożenia macierzy A: ";
		    cin >> liczba;
		    macierz<int> lm(n);
		    lm = a * liczba;
			cout << "\n Mnożenie macierzy przez liczbę to \n" << lm;
			break;
		}
		case 5: {
			cout << "\n Porównanie operatorem <  macierzy to " ;
			
		//	if (a < b)
			    cout << "a jest mniejsze";
	//		else
			    cout << "a nie jest mniejsze";
			break;
		}
		case 6: {
			cout << "\n Porównanie operatorem >  macierzy to " ;
			
		//	if (a > b)
			    cout << "a jest wieksze";
		//	else
			    cout << "a nie jest wieksze";
			break;
		}
		case 7: {
			cout << "\n Porównanie operatorem ==  macierzy to " ;
			
		//	if (a == b)
			    cout << "a i b są równe";
		//	else
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
	}
	else if (typ == 'd'){
        macierz<double> a(n);
	    cout << "\n macierz A: \n" << a;
      //  a.zrob();
        //a.wczytaj();
        macierz<double> b(n);
        cout << "\n macierz B: \n" << b;
      //  b.zrob();
        //b.wczytaj();
        while (czyDziala) {
		
		cout << endl;

		cout << "########### MENU ###########" << endl;
		cout << "[1] Dodaj" << endl;
		cout << "[2] Odejmij" << endl;
		cout << "[3] Pomnóż" << endl;
		cout << "[4] Pomnóż przez liczbę" << endl;
		cout << "[0] Wyjdź" << endl;
		cout << "##########################" << endl;
		cout << "Podaj opcje: ";

		cin >> odp;
		cout << endl;

		switch (odp) {
		case 1: {			
            macierz<double> suma(n);  
            suma = a + b;
            
            cout << "\n Suma macierzy to: \n"<< suma; 
           // poka_macierz(suma);
			break;
		}
		case 2: {
			macierz<double> rozn(n);
			rozn = a - b;
			cout << "\n Różnica  macierzy to: \n" << rozn;
            //poka_macierz(rozn);
			break;
		}
		case 3: {
			macierz<double> il(n);
			il = a * b;
			cout << "\n Iloczyn  macierzy to \n" << il;
           // poka_macierz(il);
			break; 
		}
		case 4: {
		    int liczba;
		    cout << "\n Podaj liczbę całkowitą do pomnożenia macierzy A: ";
		    cin >> liczba;
		    macierz<double> lm(n);
		    lm = a * liczba;
			cout << "\n Mnożenie macierzy przez liczbę to \n" << lm;
			break;
		}
		case 5: {
			cout << "\n Porównanie operatorem <  macierzy to " ;
			
		//	if (a < b)
			    cout << "a jest mniejsze";
	//		else
			    cout << "a nie jest mniejsze";
			break;
		}
		case 6: {
			cout << "\n Porównanie operatorem >  macierzy to " ;
			
		//	if (a > b)
			    cout << "a jest wieksze";
		//	else
			    cout << "a nie jest wieksze";
			break;
		}
		case 7: {
			cout << "\n Porównanie operatorem ==  macierzy to " ;
			
		//	if (a == b)
			    cout << "a i b są równe";
		//	else
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
	}
	else if (typ == 'z'){
        macierz<zespolona> a(n);
	    cout << "\n macierz A: \n" << a;
	  //  a.zrobZ();
        //a.wczytaj();
        macierz<zespolona> b(n);
        cout << "\n macierz B: \n" << b;
     //   b.zrobZ();
        //b.wczytaj();
        while (czyDziala) {
		
		cout << endl;

		cout << "########### MENU ###########" << endl;
		cout << "[1] Dodaj" << endl;
		cout << "[2] Odejmij" << endl;
		cout << "[3] Pomnóż" << endl;
		cout << "[4] Pomnóż przez liczbę" << endl;
		cout << "[0] Wyjdź" << endl;
		cout << "##########################" << endl;
		cout << "Podaj opcje: ";

		cin >> odp;
		//cout << endl;

		switch (odp) {
		case 1: {			
            macierz<zespolona> suma(n);  
            suma = a + b;
            cout << "\n Suma macierzy to: \n" << suma; 
            //poka_macierz(suma);
			break;
		}
		case 2: {
			macierz<zespolona> rozn(n);
			rozn = a - b;
			cout << "\n Różnica  macierzy to \n" << rozn;
            //poka_macierz(rozn);
			break;
		}
		case 3: {
			macierz<zespolona> il(n);
			il = a * b;
			cout << "\n Iloczyn  macierzy to \n" << il;
            //poka_macierz(il);
			break; 
		}
		case 4: {
		    int liczba;
		    cout << "\n Podaj liczbę całkowitą do pomnożenia macierzy A: ";
		    cin >> liczba;
		    macierz<zespolona> lm(n);
		    lm = a * liczba;
			cout << "\n Mnożenie macierzy przez liczbę to \n" << lm;
			break;
		}
		case 5: {
			cout << "\n Porównanie operatorem <  macierzy to " ;
			
		//	if (a < b)
			    cout << "a jest mniejsze";
	//		else
			    cout << "a nie jest mniejsze";
			break;
		}
		case 6: {
			cout << "\n Porównanie operatorem >  macierzy to " ;
			
		//	if (a > b)
			    cout << "a jest wieksze";
		//	else
			    cout << "a nie jest wieksze";
			break;
		}
		case 7: {
			cout << "\n Porównanie operatorem ==  macierzy to " ;
			
		//	if (a == b)
			    cout << "a i b są równe";
		//	else
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
	}
	else if (typ == 'p'){
        macierz<punkt3d> a(n);
	    cout << "\n macierz A: \n" << a;
      //  a.zrobP();
        //a.wczytaj();
        macierz<punkt3d> b(n);
        cout << "\n macierz B: \n" << b;
       // b.zrobP();
        //b.wczytaj();
        while (czyDziala) {
		
		cout << endl;

		cout << "########### MENU ###########" << endl;
		cout << "[1] Dodaj" << endl;
		cout << "[2] Odejmij" << endl;
		cout << "[3] Pomnóż" << endl;
		cout << "[4] Pomnóż przez liczbę" << endl;
		cout << "[0] Wyjdź" << endl;
		cout << "##########################" << endl;
		cout << "Podaj opcje: ";

		cin >> odp;
		cout << endl;

		switch (odp) {
		case 1: {			
            macierz<punkt3d> suma(n);  
            suma = a + b;
            
            cout << "\n Suma macierzy to: \n"<< suma; 
           // poka_macierz(suma);
			break;
		}
		case 2: {
			macierz<punkt3d> rozn(n);
			rozn = a - b;
			cout << "\n Różnica  macierzy to: \n" << rozn;
            //poka_macierz(rozn);
			break;
		}
		case 3: {
			macierz<punkt3d> il(n);
			il = a * b;
			cout << "\n Iloczyn  macierzy to \n" << il;
           // poka_macierz(il);
			break; 
		}
		case 4: {
		    int liczba;
		    cout << "\n Podaj liczbę całkowitą do pomnożenia macierzy A: ";
		    cin >> liczba;
		    macierz<punkt3d> lm(n);
		    lm = a * liczba;
			cout << "\n Mnożenie macierzy przez liczbę to \n" << lm;
			break;
		}
		case 5: {
			cout << "\n Porównanie operatorem <  macierzy to " ;
			
		//	if (a < b)
			    cout << "a jest mniejsze";
	//		else
			    cout << "a nie jest mniejsze";
			break;
		}
		case 6: {
			cout << "\n Porównanie operatorem >  macierzy to " ;
			
		//	if (a > b)
			    cout << "a jest wieksze";
		//	else
			    cout << "a nie jest wieksze";
			break;
		}
		case 7: {
			cout << "\n Porównanie operatorem ==  macierzy to " ;
			
		//	if (a == b)
			    cout << "a i b są równe";
		//	else
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
	}
	else if (typ == 'n'){
        macierz<punkt2d> a(n);
	    cout << "\n macierz A: \n" << a;
        //a.zrobN();
        //a.wczytaj();
        macierz<punkt2d> b(n);
        cout << "\n macierz B: \n" << b;
       // b.zrobN();
        //b.wczytaj();
        while (czyDziala) {
		
		cout << endl;

		cout << "########### MENU ###########" << endl;
		cout << "[1] Dodaj" << endl;
		cout << "[2] Odejmij" << endl;
		cout << "[3] Pomnóż" << endl;
		cout << "[4] Pomnóż przez liczbę" << endl;
		cout << "[0] Wyjdź" << endl;
		cout << "##########################" << endl;
		cout << "Podaj opcje: ";

		cin >> odp;
		cout << endl;

		switch (odp) {
		case 1: {			
            macierz<punkt2d> suma(n);  
            suma = a + b;
            
            cout << "\n Suma macierzy to: \n"<< suma; 
           // poka_macierz(suma);
			break;
		}
		case 2: {
			macierz<punkt2d> rozn(n);
			rozn = a - b;
			cout << "\n Różnica  macierzy to: \n" << rozn;
            //poka_macierz(rozn);
			break;
		}
		case 3: {
			macierz<punkt2d> il(n);
			il = a * b;
			cout << "\n Iloczyn  macierzy to \n" << il;
           // poka_macierz(il);
			break; 
		}
		case 4: {
		    int liczba;
		    cout << "\n Podaj liczbę całkowitą do pomnożenia macierzy A: ";
		    cin >> liczba;
		    macierz<punkt2d> lm(n);
		    lm = a * liczba;
			cout << "\n Mnożenie macierzy przez liczbę to \n" << lm;
			break;
		}
		case 5: {
			cout << "\n Porównanie operatorem <  macierzy to " ;
			
		//	if (a < b)
			    cout << "a jest mniejsze";
	//		else
			    cout << "a nie jest mniejsze";
			break;
		}
		case 6: {
			cout << "\n Porównanie operatorem >  macierzy to " ;
			
		//	if (a > b)
			    cout << "a jest wieksze";
		//	else
			    cout << "a nie jest wieksze";
			break;
		}
		case 7: {
			cout << "\n Porównanie operatorem ==  macierzy to " ;
			
		//	if (a == b)
			    cout << "a i b są równe";
		//	else
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
	}
	
	
	           
         

cout << endl;
return 5;
}

// ==============================================================================

/*

   
    bool operator==(macierz porownywana)
    {
        T suma1=0, suma2=0;
        
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
        T suma1=0, suma2=0;
        
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



*/

/*   
macierz<int> operator+(macierz<int> dodawana)
{          
            macierz<int> suma(this->N);            
            for (unsigned int i=0; i<dodawana.a.size(); i++)
            {
                for (unsigned int j=0; j<dodawana.a[i].size(); j++)
                {
                   suma.a[i].push_back(this->a[i][j] + dodawana.a[i][j]);
                }
            }   
        
return suma;   
}
    
macierz<double> operator+(macierz<double> dodawana)
{          
            macierz<double> suma(this->N);            
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
    
macierz<zespolona> operator+(macierz<zespolona> dodawana)
{          
            macierz<zespolona> suma(this->N);            
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
}*/
     

/*
macierz<int> operator*(macierz<int> mnozona)
{
     macierz<int> m3(mnozona.N);
     T suma = 0;
  
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



macierz<int> operator*(macierz<int> mnozona)
{
     macierz<int> m3(mnozona.N);
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

macierz<zespolona> operator*(macierz<zespolona> mnozona)
{
     macierz<zespolona> m3(mnozona.N);
     T suma = 0;
  
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
   */
   /*
macierz<double> operator-(macierz<double> odejmowana)
{
            macierz<double> roznica(this->N);            
            for (int i=0; i<N; i++)
            {
                for (int j=0; j<N; j++)
                {
                   roznica.a[i].push_back(this->a[i][j] - odejmowana.a[i][j]);
                }
            }   
        
return roznica;   
}

macierz<zespolona> operator-(macierz<zespolona> odejmowana)
{
            macierz<zespolona> roznica(this->N);            
            for (int i=0; i<N; i++)
            {
                for (int j=0; j<N; j++)
                {
                   roznica.a[i].push_back(this->a[i][j] - odejmowana.a[i][j]);
                }
            }   
        
return roznica;   
}
  */  


/*
template <class T2>
class zespolona
{
    T2 R;
    T2 U;
    int i;
    
    zespolona(T2 a, T2 b);
};*/




   
