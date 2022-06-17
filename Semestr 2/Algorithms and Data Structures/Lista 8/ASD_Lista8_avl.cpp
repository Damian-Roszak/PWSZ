#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct wezel {
	int klucz, bf;
	string imie, nazwisko, tel, miasto;
	struct wezel *lewy, *prawy, *rodzic;
};

wezel *korzen;


void dodaj (int x, wezel **p)
{
    if (korzen == NULL) 
    {        
        korzen = new wezel;
        korzen->klucz = x;
        korzen->lewy = NULL;
        korzen->prawy = NULL;
        korzen->rodzic = NULL;
        cout << "\n *korzen; " << korzen->klucz;
    }   
    
    else if(x == (*p)->klucz) cout << "\n Podana wartość już istnieje";
    else if(x < (*p)->klucz) 
    {
        if ((*p)->lewy != NULL) dodaj ( x, &(*p)->lewy);
        else
        {
             wezel *nowy = new wezel;
            nowy->klucz = x;
            nowy->lewy = NULL;
            nowy->prawy = NULL;
            nowy->rodzic = *p;
            (*p)->lewy=nowy;
        }
    }
    else if(x > (*p)->klucz)
    {
        if((*p)->prawy != NULL) dodaj ( x, &(*p)->prawy);
        else 
        {
            wezel *nowy = new wezel;
            nowy->klucz = x;
            nowy->lewy = NULL;
            nowy->prawy = NULL;
            nowy->rodzic = *p;
            (*p)->prawy=nowy;
        }
    }
    
    
}

void zrobElem()
{

}

void inOrder(wezel *start)
{
  if(start)
  {
    if(start->lewy != NULL) inOrder(start->lewy);     
    cout << " " << start->klucz;      
    if(start->prawy != NULL) inOrder(start->prawy);
  }
}

void usunDrzewo ( wezel * usuwany )
{
  if( usuwany )
  {
    usunDrzewo ( usuwany->lewy );  
    usunDrzewo ( usuwany->prawy ); 
    delete usuwany;               
  }
}

void postOrder ( wezel * v )
{
  if( v )
  {
    postOrder ( v->lewy );  
    postOrder ( v->prawy ); 
    cout << " " << v->klucz;    
  }
}


void preOrder ( wezel * v )
{
  if( v )
  {
    cout << " " << v->klucz;  
    preOrder ( v->lewy );  
    preOrder ( v->prawy );   
  }
}


wezel* naj_lewo( wezel *start)
{
    if(start->lewy != NULL)
        return naj_lewo(start->lewy);
    else return start;
}

wezel* szukaj(wezel *start, int klucz) 
{
    if(start)
    {
        if (start->klucz == klucz) return start;
        else if (klucz < start->klucz && start->lewy != NULL) return szukaj(start->lewy, klucz);        
        else if (klucz > start->klucz && start->prawy != NULL) return szukaj(start->prawy, klucz);
    }
    return NULL;
}
wezel* szukaj2(wezel *start, int klucz) 
{
    if(start)
    {
        if (start->klucz == klucz) return start;
        else if (klucz < start->klucz && start->lewy != NULL) return szukaj(start->lewy, klucz);        
        else if (klucz > start->klucz && start->prawy != NULL) return szukaj(start->prawy, klucz);
    }
    return NULL;
}

void najMin(wezel *start)
{
  if(start)
  {
    if(start->lewy != NULL) inOrder(start->lewy);     
    cout << " " << start->klucz;      
    if(start->prawy != NULL) inOrder(start->prawy);
  }
}

void kasowanie2(wezel **start, int usuwany)
{
    //cout << "\n ";
    if (start!=NULL)
    {
        if (usuwany < (*start)->klucz)
        {
            if ((*start)->lewy==NULL) cout << "\n Brak elementu w drzewie";
            else kasowanie2(&(*start)->lewy, usuwany);
        } 
        else if (usuwany > (*start)->klucz)
        {
             if ((*start)->prawy==NULL) cout << "\n Brak elementu  w drzewie";
            else kasowanie2(&(*start)->prawy, usuwany);
        }
        else if (usuwany == (*start)->klucz)
        {
            if((*start)->rodzic==NULL && (*start)->lewy==NULL && (*start)->prawy==NULL) // TYLKO KORZEŃ
            {
                cout << "\n Usuwam korzeń";
                wezel *tmp = *start;
                *start=NULL;
                delete tmp;
            }  
            else if((*start)->rodzic!=NULL && (*start)->lewy==NULL && (*start)->prawy==NULL) // JEST Rodzic I BRAK POTOMKÓW
            {
                wezel *tmp = *start;
                if((*start)->rodzic->lewy!=NULL)
                {
                    cout << "\n 1";
                    if ((*start)->rodzic->lewy->klucz == usuwany)
                    {
                        cout << "\n JEST Rodzic I BRAK POTOMKÓW lewy ";
                        (*start)->rodzic->lewy = NULL;
                        delete tmp;
                    }
                }
                else if((*start)->rodzic->prawy!=NULL)
                {
                    cout << "\n 2";
                    if((*start)->rodzic->prawy->klucz == usuwany)
                    {
                        cout << "\n JEST Rodzic I BRAK POTOMKÓW prawy ";
                        (*start)->rodzic->prawy = NULL;
                        delete tmp;
                    }
                }
            }   
            else if((*start)->lewy!=NULL && (*start)->prawy==NULL) // PRZYPADEK JEDEN POTOMEK = LEWY
            {
                if((*start)->rodzic!=NULL)
                {
                    cout << "\n 3";
                    if((*start)->rodzic->lewy->klucz == usuwany)
                    {
                        cout << "\n JEST Rodzic z lewej POTOMeK z lewym ";
                        wezel *tmp = *start;
                        (*start)->lewy->rodzic = (*start)->rodzic;
                        (*start)->rodzic->lewy = (*start)->lewy;
                        delete tmp;                    
                    }
                    else if((*start)->rodzic->prawy->klucz == usuwany)
                    {
                        cout << "\n JEST Rodzic z prawej POTOMeK z lewym ";
                        wezel *tmp = *start;
                        (*start)->lewy->rodzic = (*start)->rodzic;
                        (*start)->rodzic->prawy = (*start)->lewy;     
                        delete tmp; 
                    }
                }
                else
                {
                    wezel *tmp = *start;
                    cout << "\n KORZEŃ !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!2";
                    (*start)->lewy->rodzic = NULL;
                    (*start) = (*start)->lewy;
                    delete tmp; 
                }
            }    
            else if((*start)->lewy==NULL && (*start)->prawy!=NULL) // PRZYPADEK JEDEN POTOMEK = PRAWY
            {
                cout << "\n 4";
                if((*start)->rodzic!=NULL)
                {
                    cout << "\n jeden potomek 5: "; 
                    if((*start)->rodzic->lewy!=NULL)
                    {    
                        cout << "\n jeden potomek 6: ";
                        if((*start)->rodzic->lewy->klucz == usuwany)
                        {
                            cout << "\n JEST Rodzic z lewej POTOMeK z prawym ";
                            wezel *tmp = *start;
                            (*start)->prawy->rodzic = (*start)->rodzic;
                            (*start)->rodzic->lewy = (*start)->prawy;   
                            delete tmp;                    
                        }
                    }
                    if((*start)->rodzic->prawy!=NULL)    
                    {    
                        
                        cout << "\n jeden potomek 7: ";
                        if((*start)->rodzic->prawy->klucz == usuwany)
                        {
                            cout << "\n JEST Rodzic z prawej POTOMeK z prawym ";
                            wezel *tmp = *start;
                            (*start)->prawy->rodzic = (*start)->rodzic;
                            (*start)->rodzic->prawy = (*start)->prawy;  
                            delete tmp; 
                        }
                    }    
                }
                else
                {
                    wezel *tmp = *start;
                    cout << "\n KORZEŃ !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1";
                    (*start)->prawy->rodzic = NULL;
                    (*start) = (*start)->prawy;
                    delete tmp; 
                }
            }    
            else if((*start)->lewy!=NULL && (*start)->prawy!=NULL) // PRZYPADEK: DWA POTOMKI
            {
                cout << "\n 8";
                if((*start)->rodzic!=NULL)
                {
                    cout << "\n 9";
                    if((*start)->rodzic->lewy->klucz == usuwany)
                    {
                        wezel *najLew = naj_lewo((*start)->prawy);
                        cout << "\n naj lewo: " << najLew->klucz;
                        cout <<"\n 2xPotomki-rodzic-lewy: " << (*start)->rodzic->lewy->klucz << endl;
                         int tmp = najLew->klucz;
                         kasowanie2(start, tmp);                  
                         (*start)->klucz = tmp;
                    }
                    else if((*start)->rodzic->prawy->klucz == usuwany)
                    {                        
                        cout <<"\n 2xPotomki-rodzic-prawy: " << (*start)->rodzic->prawy->klucz << endl;
                        wezel *najLew = naj_lewo((*start)->prawy);
                        cout << "\n naj lewo: " << najLew->klucz;
                         int tmp = najLew->klucz;
                         kasowanie2(start, tmp);                  
                         (*start)->klucz = tmp;                        
                    }
                }
                else
                {
                   wezel *najLew = naj_lewo((*start)->prawy);
                   cout << "\n naj lewo: " << najLew->klucz;
                   cout <<"\n 2xPotomki-rodzic= NULL: " << (*start)->klucz << endl;   
                   int tmp = najLew->klucz;
                   kasowanie2(start, tmp);                  
                   (*start)->klucz = tmp;                    
                }
            }
        }
    }
}

void kasowanie(wezel *start)
{
if (start != NULL)
{   
    if(start->lewy==NULL && start->prawy==NULL)
    {
        if(start->rodzic->lewy==start)
        {
            start->rodzic->lewy=NULL;
        }
        else
        {  
            start->rodzic->prawy=NULL;
        }
    delete start;
   // start = NULL;
    }
    else if(start->lewy==NULL || start->prawy==NULL)
    {

        if(start->lewy==NULL)
        {
            if(start->rodzic==NULL)
            {
                korzen=start->prawy;
            }

            else if(start->rodzic->lewy==start)
            {            
                start->rodzic->lewy=start->prawy;
            }
            else
            {            
                start->rodzic->prawy=start->prawy;
            }
       }
       else
       {        
            if(start->rodzic==NULL)
            {
                korzen=start->lewy;
            }
            
            else if(start->rodzic->lewy==start)
            {            
                start->rodzic->lewy=start->lewy;
            }
            else
            {            
                start->rodzic->prawy=start->lewy;
            }
       }
        delete start;
    //start = NULL;
    }
    else
    {
    
        wezel *temp;
        temp=naj_lewo(start->prawy);
        start->klucz = temp->klucz;
        kasowanie(temp);
    }
}
}

int main()
{
bool czyDziala = true;
korzen = NULL;
	int odp, wart;
	while (czyDziala) {
		
		cout << endl;

		cout << "########### MENU ###########" << endl;
		cout << "[1] Dodaj węzeł" << endl;
		cout << "[2] Usuń węzeł" << endl;
		cout << "[3] Pokaż inOrder" << endl;
		cout << "[4] Pokaż postOrder" << endl;
		cout << "[5] Pokaż preOrder" << endl;
		cout << "[0] Wyjdź" << endl;
		cout << "##########################" << endl;
		cout << "Podaj opcje: ";

		cin >> odp;
		cout << endl;

		switch (odp) {
		case 1: {
			cout << "Wprowadź wartość węzła: ";
			cin >> wart;
			dodaj(wart, &korzen);
			break;
		}
		case 2: {
			if (korzen == NULL) {
				cout << "Brak korzenia - drzewo jest puste" << endl;
			}
			else
			{			    
			    cout << "Wprowadź wartość do usuniecia: ";
			    cin >> wart;
			    //kasowanie(szukaj(korzen,wart));
			    kasowanie2(&korzen,wart);
			    //kasowanie2(szukaj2(korzen,wart));
			}            
			break;
		}
		case 3: {
			cout << "Pokaż inOrder = " ;
			inOrder(korzen);
			break;
		}
		case 4: {
			cout << "Pokaż postOrder = " ;
			postOrder(korzen);
			break; 
		}
		case 5: {
			cout << "Pokaż preOrder = " ;
			preOrder(korzen);
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

usunDrzewo(korzen);
return 5;
}
