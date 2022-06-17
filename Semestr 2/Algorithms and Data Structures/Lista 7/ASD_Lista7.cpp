#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct wezel {
	int klucz;
	struct wezel *lewy, *prawy, *rodzic;
};

wezel *korzen;

bool member (int x, wezel *A)
{
    if (A == NULL) return false;
    else if(x == A->klucz) return true;
    else if(x < A->klucz) return czlonek ( x, A->lewy);
    else if(x > A->klucz) return czlonek ( x, A->prawy);

return false;
}

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
    start = NULL;
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
    start = NULL;
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
			    kasowanie(szukaj(korzen,wart));
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

