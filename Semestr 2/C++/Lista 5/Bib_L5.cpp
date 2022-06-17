#include "Bib_L5.hpp"

























void ruchCPUvsCPU(vector<vector<char>> &t, int wymiar, char &gracz, int stopienTrudnosci, int t_pozO[][2], int t_pozX[][2])
{
    int w,k,srodek_W = (wymiar)/2,srodek_K = (wymiar)/2;
      int licz = 0, licz2 = 0, licz3 = 0, licz4 = 0;
         //int t_poz[wymiar][2]; 
   
   rysuj_plansze(t, wymiar);
   cout << "\n TERAZ GRACZ " << gracz << " : Twój ruch [ wiersz ] [ kolumna ]: ";
     if(stopienTrudnosci==1)
     {
        w = random()%wymiar-1;
        k = random()%wymiar-1;     
     }  
     else if(stopienTrudnosci==2)
     {
        if(t[srodek_W][srodek_K]==' ')
        {
           w = srodek_W;
           k = srodek_K;
        }
        else
        {
            do{
                w = random()%wymiar;
                k = random()%wymiar;
            }while((w < 0) || (w >= wymiar) ||
                    (k < 0) || (k >= wymiar) || (t[w][k]!=' '));
        }
     } 
     else if(stopienTrudnosci==3)
     {
        if(t[srodek_W][srodek_K]==' ')
        {
           w = srodek_W;
           k = srodek_K;
        }
        else
        { 
             for (int i=0; i < wymiar; i++)
              {
                  for(int j=0; j<wymiar; j++)
                  {
                      if (i==j && t[i][j] == gracz) licz++;
                      if (i+j==wymiar-1 && t[i][j] == gracz) licz2++;
                      if ( t[i][j] == gracz) licz3++;
                      if ( t[j][i] == gracz) licz4++;
                  }
              }
              
            do{
                w = random()%wymiar;
                k = random()%wymiar;
            }while((w < 0) || (w >= wymiar) ||
                    (k < 0) || (k >= wymiar) || (t[w][k]!=' '));
                        
        }
     }    
        
       cout << "-----------------------\n\n";
       
       if (
       (
            (((w) >= 0) && ((w) < wymiar)) && 
            (((k) >= 0) && ((k) < wymiar))
       ) && 
       (t[w][k]=='X' || t[w][k]=='O'))
       {
           cout << "\n POLE ZAJĘTE TRACISZ RUCH !!!\n\n";
       }
       
       if(((w < 0) || (w >= wymiar)) ||
        ((k < 0) || (k >= wymiar)))
       {
           cout << "\n POLE Z !!POZA ZAKRESU!! TRACISZ RUCH !!!\n\n";
       }
       
       if(
       (
             (((w) >= 0) && ((w) < wymiar)) && 
             (((k) >= 0) && ((k) < wymiar))
       ) && 
       (t[w][k] == ' '))
       {
             //cout << "gracz";
             t[w][k] = gracz;
       }
       
      
   gracz = (gracz == 'O') ? 'X' : 'O';
}

void CPU_VS_CPU(vector<vector<char>> &t, int wymiar, int stopienTrudnosci)
{    
    int t_pozO[wymiar+1][2], t_pozX[wymiar+1][2];
    //char g = losuj_kto_pierwszy();
    char g;
    cout << " Kto zaczyna X/O?: ";
    cin >> g;
    if(g=='x') g='X';
    if(g=='o') g='O';
    cout << endl;
    while(!wygrana(t, wymiar,'X') && !wygrana(t, wymiar,'O') && !remis(t, wymiar)) ruchCPUvsCPU(t,wymiar,g, stopienTrudnosci, t_pozO, t_pozX);
}

void ruchCPU(vector<vector<char>> &t, int wymiar, char &gracz, int stopienTrudnosci, int t_pozO[][2], int t_pozX[][2])
{
   int w=-1,k=-1,srodek_W = (wymiar)/2,srodek_K = (wymiar)/2;
     
  
   
   rysuj_plansze(t, wymiar);
   cout << "\n TERAZ GRACZ " << gracz << " : Twój ruch [ wiersz ] [ kolumna ]: ";
   if(gracz=='X')
   {
       cin >> w;
       cin >> k;
       cout << "-----------------------\n\n";
       
       if (
       (
            (((w-1) >= 0) && ((w-1) < wymiar)) && 
            (((k-1) >= 0) && ((k-1) < wymiar))
       ) && 
       (t[w-1][k-1]=='X' || t[w-1][k-1]=='O'))
       {
           cout << "\n POLE ZAJĘTE TRACISZ RUCH !!!\n\n";
       }
       
       if(((w-1 < 0) || (w-1 >= wymiar)) ||
        ((k-1 < 0) || (k-1 >= wymiar)))
       {
           cout << "\n POLE Z !!POZA ZAKRESU!! TRACISZ RUCH !!!\n\n";
       }
       
       if(
       (
             (((w-1) >= 0) && ((w-1) < wymiar)) && 
             (((k-1) >= 0) && ((k-1) < wymiar))
       ) && 
       (t[w-1][k-1] == ' '))
       {
             t[w-1][k-1] = gracz;
       }       
   //zrob_Info(t, wymiar, gracz, stopienTrudnosci, t_pozO, t_pozX);
   }
   else
   {   
     if(stopienTrudnosci==1)
     {
        w = random()%wymiar-1;
        k = random()%wymiar-1;     
     }  
     else if(stopienTrudnosci==2)
     {
        if(t[srodek_W][srodek_K]==' ')
        {
           w = srodek_W;
           k = srodek_K;
        }
        else
        {
            do{
                w = random()%wymiar;
                k = random()%wymiar;
            }while((w < 0) || (w >= wymiar) ||
                    (k < 0) || (k >= wymiar) || (t[w][k]!=' '));
        }
     } 
     else if(stopienTrudnosci==3)
     {
        if(t[srodek_W][srodek_K]==' ')
        {
           w = srodek_W;
           k = srodek_K;
        }
        else
        {    
         cout << "\n stopień trudności 3: " ;
         cout << "\n t_pozO[wymiar+2][0]: " << t_pozO[wymiar+2][0];
         cout << "\n t_pozO[wymiar+2][1]: " << t_pozO[wymiar+2][1];
         cout << "\n\n t_pozX[wymiar+2][0]: " << t_pozX[wymiar+2][0];
         cout << "\n t_pozX[wymiar+2][1]: " << t_pozX[wymiar+2][1];
         
               
            if ((t_pozO[wymiar+2][0]>-1 && t_pozO[wymiar+2][1]>-1 && t_pozO[t_pozO[wymiar+1][0]][0] == wymiar-1) || (t_pozO[wymiar+2][0]>-1 && t_pozO[wymiar+2][1]>-1 && t_pozO[t_pozO[wymiar+1][1]][1]  == wymiar-1))
            {
               //  && (t_pozX[wymiar][0] > 0 || t_pozX[wymiar][1] > 0)
                    cout << "\n stopień 3 pierwszy IF \n";
                    if(t[t_pozO[wymiar+2][0]][t_pozO[wymiar+2][1]]==' ')
                    {
                        w = t_pozO[wymiar+2][0];
                        k = t_pozO[wymiar+2][1];
                    }
               
            }
            else if ((t_pozX[wymiar+2][0]>-1 && t_pozX[wymiar+2][1]>-1 && t_pozX[t_pozX[wymiar+1][0]][0] == wymiar-1) || (t_pozX[wymiar+2][0]>-1 && t_pozX[wymiar+2][1]>-1 && t_pozX[t_pozX[wymiar+1][1]][1]  == wymiar-1))
            {
                    cout << "\n stopień dla X ELSE IF \n";
                    if(t[t_pozX[wymiar+2][0]][t_pozX[wymiar+2][1]]==' ')
                    {
                        w = t_pozX[wymiar+2][0];
                        k = t_pozX[wymiar+2][1];
                    }
            } 
            else 
            { 
                    czy_zbliza_sie_do_wygranej(t, t_pozX, t_pozO, wymiar);
                    w = t_pozO[wymiar+2][0];
                    k = t_pozO[wymiar+2][1];
                    
                   /* cout << "\n stopień else \n"; 
                    do{
                        w = random()%wymiar;
                        k = random()%wymiar;
                    }while((w < 0) || (w >= wymiar) ||
                            (k < 0) || (k >= wymiar) || (t[w][k]!=' '));*/
            }
            
            if(w<0 || k<0)
            {  
                cout << "\n stopień if(w<0 || k<0) \n";
                do{
                    w = random()%wymiar;
                    k = random()%wymiar;
                }while((w < 0) || (w >= wymiar) ||
                        (k < 0) || (k >= wymiar) || (t[w][k]!=' '));
            } 
        }
        cout << "\n w: " << w << " k: " << k;
     }    
        
       cout << "-----------------------\n\n";
       
       if (
       (
            (((w) >= 0) && ((w) < wymiar)) && 
            (((k) >= 0) && ((k) < wymiar))
       ) && 
       (t[w][k]=='X' || t[w][k]=='O'))
       {
           cout << "\n POLE ZAJĘTE TRACISZ RUCH !!!\n\n";
       }
       
       else if(((w < 0) || (w >= wymiar)) ||
        ((k < 0) || (k >= wymiar)))
       {
           cout << "\n POLE Z !!POZA ZAKRESU!! TRACISZ RUCH !!!\n\n";
       }
       
       else if(
       (
             (((w) >= 0) && ((w) < wymiar)) && 
             (((k) >= 0) && ((k) < wymiar))
       ) && 
       (t[w][k] == ' '))
       {
             //cout << "gracz";
             t[w][k] = gracz;
       }
       
   } 
   zrob_Info(t, wymiar, gracz, stopienTrudnosci, t_pozO, t_pozX);  
   gracz = (gracz == 'O') ? 'X' : 'O';
}

int czy_zbliza_sie_do_wygranej(vector<vector<char>> t, int t_pozX[][2], int t_pozO[][2], int wymiar)
{
     cout << "\n czy_zbliza_sie_do_wygranej: ";
     
    if(t_pozX[wymiar][0]==wymiar-1)
    {//przekątna główna
        cout << "\n t_pozX[wymiar][0]: " << t_pozX[wymiar][0];
        int flaga = -1;
        for(int i=0; i<wymiar; i++)
        {
            if (t[i][i] ==' ') 
            {
                flaga=i;
            }
        }
        t_pozX[wymiar+3][0]=t_pozX[wymiar+3][1]=flaga;
        cout << "\n t_pozX[wymiar+3][0]=t_pozX[wymiar+3][1] = " << t_pozX[wymiar+3][0];
    }
    else if(t_pozX[wymiar][1]==wymiar-1)
    {//przekątna 2
        cout << "\n t_pozX[wymiar][1]: " << t_pozX[wymiar][1];
        int flaga1 = -1, flaga2 = -1;
        for(int i=0; i<wymiar; i++)
        {
            for(int j=0; j<wymiar; j++)
            {
                if (i+j==wymiar-1 && t[i][j] == ' ') 
                {
                    flaga1=i;
                    flaga2=j;
                }
            }
        }
        t_pozX[wymiar+3][0]=flaga1;
        t_pozX[wymiar+3][1]=flaga2;
        cout << "\n t_pozX[wymiar+3][0]= " << t_pozX[wymiar+3][0] << " t_pozX[wymiar+3][1]= " << t_pozX[wymiar+3][1];
    }
    if(t_pozX[t_pozX[wymiar+1][0]][0] == wymiar-1)
    {// wymiar+1 to poz wiersza z max
        cout << "\n t_pozX[wymiar+1][0]: " << t_pozX[wymiar+1][0];
        t_pozX[wymiar+2][0]= t_pozX[wymiar+1][0];
        int flaga=-1;
        for(int i=0; i<wymiar; i++)
        {
            if (t[t_pozX[wymiar+1][0]][i] ==' ') 
            {
                flaga=i;
            }            
        }
        t_pozX[wymiar+2][1]=flaga;
        cout << "\n t_pozX[wymiar+2][0]: " << t_pozX[wymiar+2][0] << " t_pozX[wymiar+2][1]= " << t_pozX[wymiar+2][1];
    }
   else if(t_pozX[t_pozX[wymiar+1][1]][1] == wymiar-1)
    {// wymiar+1 to poz kolumny z max
    cout << "\n t_pozX[wymiar+1][1]: " << t_pozX[wymiar+1][1];
        t_pozX[wymiar+2][1]= t_pozX[wymiar+1][1];
        int flaga=-1;
        for(int i=0; i<wymiar; i++)
        {
            if (t[i][t_pozX[wymiar+1][1]] ==' ') 
            {                
                flaga=i;
            }
        }
        t_pozX[wymiar+2][0]=flaga;
        cout << "\n t_pozX[wymiar+2][0]: " << t_pozX[wymiar+2][0] << " t_pozX[wymiar+2][1]= " << t_pozX[wymiar+2][1];
    }
    /*else if(t_pozX[wymiar+2][0]>-1 && t_pozX[wymiar+2][1]>-1)
    {
        if(t[t_pozX[wymiar+2][0]][t_pozX[wymiar+2][1]]!=' ')
        {
            t_pozX[wymiar+2][0]=-1;
            t_pozX[wymiar+2][1]=-1;
        }
        cout << "\n t_pozX[wymiar+2][0]: " << t_pozX[wymiar+2][0] << " t_pozX[wymiar+2][1]= " << t_pozX[wymiar+2][1];
    }*/
    if(t_pozO[wymiar][0]==wymiar-1)
    {//przekątna 1
        cout << "\n t_pozO[wymiar][0]: " << t_pozO[wymiar][0];
        int flaga=-1;
        for(int i=0; i<wymiar; i++)
        {
            if (t[i][i] ==' ') 
            {
                flaga=i;
            }
        }
        t_pozO[wymiar+3][0]=t_pozO[wymiar+3][1]=flaga;
        cout << "\n t_pozO[wymiar+3][0]=t_pozO[wymiar+3][1] = " << t_pozO[wymiar+3][0];
    }
    else if(t_pozO[wymiar][1]==wymiar-1)
    {//przekątna 2
        cout << "\n t_pozO[wymiar][1]: " << t_pozO[wymiar][1];
        int flaga1 = -1, flaga2 = -1;
        for(int i=0; i<wymiar; i++)
        {
            for(int j=0; j<wymiar; j++)
            {
                if (i+j==wymiar-1 && t[i][j] == ' ') 
                {
                    flaga1=i;
                    flaga2=j;
                }
            }
        }
        t_pozO[wymiar+3][0]=flaga1;
        t_pozO[wymiar+3][1]=flaga2;
        cout << "\n t_pozO[wymiar+3][0]: " << t_pozO[wymiar+3][0] << " t_pozO[wymiar+3][1]= " << t_pozO[wymiar+3][1];
    }
    else if(t_pozO[t_pozO[wymiar+1][0]][0] == wymiar-1)
    {// wymiar+1 to max w wierszu
        cout << "\n t_pozO[wymiar+1][0]: " << t_pozO[wymiar+1][0];
        t_pozO[wymiar+2][0]= t_pozO[wymiar+1][0];
        int flaga=-1;
        for(int i=0; i<wymiar; i++)
        {
            if (t[t_pozO[wymiar+1][0]][i] ==' ') 
            {
                flaga=i;
            }
        }
        t_pozO[wymiar+2][1]=flaga;
        cout << "\n t_pozO[wymiar+2][0]: " << t_pozO[wymiar+2][0] << " t_pozO[wymiar+2][1]= " << t_pozO[wymiar+2][1];
    }
    else if(t_pozO[t_pozO[wymiar+1][1]][1] == wymiar-1)
    {// wymiar+1 to max w kolumnie
    cout << "\n t_pozO[wymiar+1][1]: " << t_pozO[wymiar+1][1];
        t_pozO[wymiar+2][1]= t_pozO[wymiar+1][1];
        int flaga=-1;
        for(int i=0; i<wymiar; i++)
        {
            if (t[i][t_pozO[wymiar+1][1]] ==' ') 
            {                
                flaga=i;
            }
        }
        t_pozO[wymiar+2][0]=flaga;
        cout << "\n t_pozO[wymiar+2][0]: " << t_pozO[wymiar+2][0] << " t_pozO[wymiar+2][1]= " << t_pozO[wymiar+2][1];
    }
    else if(t_pozO[wymiar+2][0]>-1 && t_pozO[wymiar+2][1]>-1)
    {
        if(t[t_pozO[wymiar+2][0]][t_pozO[wymiar+2][1]]!=' ')
        {
            t_pozO[wymiar+2][0]=-1;
            t_pozO[wymiar+2][1]=-1;
        }
        cout << "\n else if(t_pozO[wymiar+2][0]>-1 && t_pozO[wymiar+2][1]>-1) if(t[t_pozO[wymiar+2][0]][t_pozO[wymiar+2][1]]!=' ') t_pozO[wymiar+2][0]: " << t_pozO[wymiar+2][0] << " t_pozO[wymiar+2][1]= " << t_pozO[wymiar+2][1];
    }
  /*if()
    if()
    if()
    if()
    if()
    if()
    if()
    if()
    if()*/
 cout << "\n czy_zbliza_sie_do_wygranej: KONIEC";
return 0;
}

void zrob_Info(vector< vector<char> > t, int wymiar, char gracz, int stopienTrudnosci, int t_pozO[][2], int t_pozX[][2])
{
 int  licz = 0, licz2 = 0, licz3 = 0, licz4 = 0;
 for (int i=0; i < wymiar; i++)
 {
    for(int j=0; j<wymiar; j++)
    {
       if (i==j && t[i][j] == gracz)
       {
          licz++;
          
       }
       else if(i==j && t[i][j] == ((gracz == 'O') ? 'X' : 'O'))
       {
                            
       }
       if (i+j==wymiar-1 && t[i][j] == gracz)
       {
          licz2++;
       }
       if ( t[i][j] == gracz)
       {
           licz3++;
       }
       if ( t[j][i] == gracz)
       {
           licz4++;
       }
   }
   if (gracz == 'X')
   {
       t_pozX[i][0]=licz3;
       t_pozX[i][1]=licz4;
   }
   if (gracz == 'O')
   {
      t_pozO[i][0]=licz3;
      t_pozO[i][1]=licz4;
   }
 
       licz3=0;
       licz4=0;
   
 }
 if (gracz == 'X')
 {
   t_pozX[wymiar][0]=licz;
   t_pozX[wymiar][1]=licz2;
 }
 if (gracz == 'O')
 {
    t_pozO[wymiar][0]=licz;
    t_pozO[wymiar][1]=licz2;
 }
 
 
//pozycja maksimum wiersze i kolumny
int maxKO=t_pozO[0][1], maxKX=t_pozX[0][1], maxWO=t_pozO[0][0], maxWX=t_pozX[0][0]; //, pozWO=-1, pozKO=-1, pozWX=-1, pozKX=-1

  for(int w=1; w<wymiar; w++)
  { 
  cout << "\n t_pozO["<< w << "][0] = " << t_pozO[w][0] << " t_pozO["<< w << "][1] = " << t_pozO[w][1];
  cout << "\n t_pozX["<< w << "][0] = " << t_pozX[w][0] << " t_pozX["<< w << "][1] = " << t_pozX[w][1] << endl;
    if (maxKO < t_pozO[w][1]){ maxKO = t_pozO[w][1]; t_pozO[wymiar+1][1]=w;}
    if (maxKX < t_pozX[w][1]){ maxKX = t_pozX[w][1]; t_pozX[wymiar+1][1]=w;}
    if (maxWO < t_pozO[w][0]){ maxWO = t_pozO[w][0]; t_pozO[wymiar+1][0]=w;}
    if (maxWX < t_pozX[w][0]){ maxWX = t_pozX[w][0]; t_pozX[wymiar+1][0]=w;}
    
  }
  
  cout << "\n\n t_pozO[wymiar+1][0] = " << t_pozO[wymiar+1][0];
  cout << "\n t_pozO[wymiar+1][1] = " << t_pozO[wymiar+1][1];
  cout << "\n t_pozX[wymiar+1][0] = " << t_pozX[wymiar+1][0];
  cout << "\n t_pozX[wymiar+1][1] = " << t_pozX[wymiar+1][1];
 
czy_zbliza_sie_do_wygranej(t, t_pozX, t_pozO, wymiar);
}

bool wygrana(vector<vector<char>> &t, int wymiar, char g)
{
  bool test;
  int i, licz = 0, licz2 = 0, licz3 = 0, licz4 = 0;
  
  test = false;
    
  
      for (i=0; i < wymiar; i++)
      {
          for(int j=0; j<wymiar; j++)
          {
              if (i==j && t[i][j] == g) licz++;
              if (i+j==wymiar-1 && t[i][j] == g) licz2++;
              if ( t[i][j] == g) licz3++;
              if ( t[j][i] == g) licz4++;
          }
          
          if (licz3 == wymiar ) test=true;
          else licz3=0;
          
          if (licz4 == wymiar ) test=true;
          else licz4=0;
      }
       
  if (licz == wymiar ) { cout << "test true licz"; test=true; }
  if (licz2 == wymiar ) { cout << "test true licz2"; test=true; }
  
  
  if(test)
  {
    rysuj_plansze(t, wymiar);
    cout << "\nGRACZ " << g << " WYGRYWA!!!\n\n";
    return true;
  }
  return false;
}

bool remis(vector<vector<char>> &t, int wymiar)
{
  for(int i = 0; i < wymiar; i++)
      for(int j=0; j < wymiar; j++)
            if(t[i][j] == ' ') return false;
  rysuj_plansze(t, wymiar);
  cout << "\nREMIS !!!\n\n";
  return true;     
}

void ruch(vector<vector<char>> &t, int wymiar, char &gracz)
{
   int w,k;
   
   rysuj_plansze(t, wymiar);
   cout << "\n TERAZ GRACZ " << gracz << " : Twój ruch [ wiersz ] [ kolumna ]: ";
   cin >> w;
   cin >> k;
   cout << "-----------------------\n\n";
   
   if (
   (
        (((w-1) >= 0) && ((w-1) < wymiar)) && 
        (((k-1) >= 0) && ((k-1) < wymiar))
   ) && 
   (t[w-1][k-1]=='X' || t[w-1][k-1]=='O'))
   {
       cout << "\n POLE ZAJĘTE TRACISZ RUCH !!!\n\n";
   }
   
   if(((w-1 < 0) || (w-1 >= wymiar)) ||
    ((k-1 < 0) || (k-1 >= wymiar)))
   {
       cout << "\n POLE Z !!POZA ZAKRESU!! TRACISZ RUCH !!!\n\n";
   }
   
   if(
   (
         (((w-1) >= 0) && ((w-1) < wymiar)) && 
         (((k-1) >= 0) && ((k-1) < wymiar))
   ) && 
   (t[w-1][k-1] == ' '))
   {
         //cout << "gracz";
         t[w-1][k-1] = gracz;
   }
   
   gracz = (gracz == 'O') ? 'X' : 'O';
}


void rysuj_plansze(vector<vector<char>> &t, int wymiar)
{
//int licz=0;
 cout << endl <<  "   "; 
 for (int k=1; k<=wymiar; k++)
        if(k>=10) cout <<  " " << k << " ";
        else cout <<  " " << k << "  ";
    cout << endl;
  for (int i=0; i <wymiar; i++)
  {
        if(i>=9) cout << i+1 << " ";
        else cout <<  " " << i+1 << " ";
        for(int j=0; j<wymiar; j++)
        {             
             //cout << ' ' << t[i][j] << ' ';licz++
             cout << " " << t[i][j] << " "; 
             if (j < wymiar-1) cout  << "|";            
        }
        if(i != wymiar-1) 
        {
            cout << "\n   ";
            //if(i>=10) cout << " ";
            for (int j=0; j<wymiar; j++)
            {
                    cout << "---";
                if (j < wymiar-1) 
                    cout  << "+";
                   
            }
            cout << "\n";
            //cout << "\n---+---+---\n";
        }        
        //cout << endl;
  }
}


void inicjuj_plansze(vector<vector<char>> &t, int wymiar)
{
  for (int i=0; i <wymiar; i++)
  {
        t.push_back(vector<char>());
        for(int j=0; j<wymiar; j++)
        {
            t[i].push_back(' ');
        }
  }
}

char losuj_kto_pierwszy()
{
    char los;
    int tmp=rand()%333;
    if(tmp%2==0) los = 'O';
    else los = 'X';
    return los;
}

void graj(vector<vector<char>> &t, int wymiar)
{
    //char g = losuj_kto_pierwszy();
    char g;
    cout << " Kto zaczyna X/O?: ";
    cin >> g;    
    if(g=='x') g='X';
    if(g=='o') g='O';
    cout << endl;
   while(!wygrana(t, wymiar,'X') && !wygrana(t, wymiar,'O') && !remis(t, wymiar)) 
   ruch(t,wymiar,g);
}

void graj_VS_CPU(vector<vector<char>> &t, int wymiar, int stopienTrudnosci)
{
    int t_pozO[wymiar+4][2], t_pozX[wymiar+4][2];
    for(int i=0; i<2; i++)
        for(int j=0; j<=wymiar+3; j++)
        {
            t_pozO[j][i] = t_pozX[j][i] = -1;
            cout << "\n t_pozO["<<j<<"]["<<i<<"]: " << t_pozO[j][i] << " t_pozX["<<j<<"]["<<i<<"]: " << t_pozX[j][i];
        }
       
    //char g = losuj_kto_pierwszy();
    char g;
    cout << " Kto zaczyna X/O?: ";
    cin >> g;
    if(g=='x') g='X';
    if(g=='o') g='O';
    cout << endl;
    while(!wygrana(t, wymiar,'X') && !wygrana(t, wymiar,'O') && !remis(t, wymiar)) ruchCPU(t,wymiar,g, stopienTrudnosci, t_pozO, t_pozX);
}


int wczytajStopienTrudnosci(int &stopienTrudnosci)
{
    do
    {
        cin >> stopienTrudnosci;
    }while(stopienTrudnosci <1 || stopienTrudnosci>3);
    cout << "======================================\n\n";
return stopienTrudnosci;
}

void menuStopienTrudnosci()
{
    cout << "\n\tWybierz stopień trudności:\n"
            "======================================\n";
                
    cout << "\n1 == Łatwy\n"
            "\n2 == Normalny\n"
            "\n3 == Trudny\n"
            "\nJaki jest twój wybór: ";
}

int wczytajWymiar(int &wymiar)
{
    do
    {
        cin >> wymiar;
    }while(wymiar <3 || wymiar>INT_MAX);
    cout << "======================================\n\n";
return wymiar;
}

void menuWymiar()
{    
    cout << "\n\tJaki chcesz wymiar planszy (od 3 do "<< INT_MAX << "): ";
}

int wczytajTryb(int &tryb)
{
    do{
        cin >> tryb;
    }while(tryb <1 || tryb>3);
    
return tryb;
}

void menuGlowne()
{

    cout << "\n\tWitaj Wędrowcze :D \n"
            "======================================";
    cout << "\nGra w Kółko i Krzyżyk dla dwóch graczy\n"
            "======================================\n";
    
    cout << "\n\tWybierz tryb:\n"
            "======================================\n";
    
    cout << "\n1 == Człowiek VS Człowiek\n"
            "\n2 == Człowiek VS CPU\n"
            "\n3 == CPU VS CPU\n"
            "\nJaki jest twój wybór: ";
}

int sizeVectory(vector<vector<char>> &t)
{
    int rozmiar = t.size();
    
    for(unsigned int i=0; i!=t.size(); i++)
    {
        for (unsigned int j=0; j!=t[i].size(); j++)
        {
           // cout << "\nt[i].size(): " << t[i].size() << endl;
            rozmiar += t[i].size();
        }
    }
return rozmiar;
}

