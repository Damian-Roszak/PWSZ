#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Typ węzłów drzewa BST

struct BSTNode
{
  BSTNode * up, * left, * right;
  int key;
};

// Zmienne globalne

string cr, cl, cp;      // łańcuchy do znaków ramek

// Procedura wypisuje drzewo
//--------------------------
void printBT ( string sp, string sn, BSTNode * v )
{
  string s;

  if( v )
  {
    s = sp;
    if( sn == cr ) s [ s.length( ) - 2 ] = ' ';
    printBT ( s + cp, cr, v->right );

    s = s.substr ( 0, sp.length( ) - 2 );
    cout << s << sn << v->key << endl;

    s = sp;
    if( sn == cl ) s [ s.length( ) - 2 ] = ' ';
    printBT ( s + cp, cl, v->left );
  }
}

// Procedura DFS:postorder usuwająca drzewo
//-----------------------------------------
void DFSRelease ( BSTNode * v )
{
  if( v )
  {
    DFSRelease ( v->left );  // usuwamy lewe poddrzewo
    DFSRelease ( v->right ); // usuwamy prawe poddrzewo
    delete v;                // usuwamy sam węzeł
  }
}

// Procedura wstawia do drzewa BST węzeł o kluczu k
//-------------------------------------------------
void insertBST ( BSTNode * & root, int k )
{
  BSTNode * w, * p;

  w = new BSTNode;           // Tworzymy dynamicznie nowy węzeł

  w->left = w->right = NULL; // Zerujemy wskazania synów
  w->key = k;                // Wstawiamy klucz

  p = root;                  // Wyszukujemy miejsce dla w, rozpoczynając od korzenia

  if( !p )                   // Drzewo puste?
    root = w;                // Jeśli tak, to w staje się korzeniem
  else
    while( true )            // Pętla nieskończona
      if( k < p->key )       // W zależności od klucza idziemy do lewego lub
      {                      // prawego syna, o ile takowy istnieje
        if( !p->left )       // Jeśli lewego syna nie ma, 
        {
          p->left = w;       // to węzeł w staje się lewym synem
          break;             // Przerywamy pętlę while
        }
        else p = p->left;
      }
      else
      {
        if( !p->right )      // Jeśli prawego syna nie ma, 
        {
          p->right = w;      // to węzeł w staje się prawym synem
          break;             // Przerywamy pętlę while
        }
        else p = p->right;
      }

  w->up  = p;                // Ojcem węzła w jest zawsze węzeł wskazywany przez p
}

// Funkcja szuka w drzewie BST węzła o zadanym kluczu.
// Jeśli go znajdzie, zwraca jego wskazanie. Jeżeli nie, 
// to zwraca wskazanie puste.
// Parametrami są:
// p - wskazanie korzenia drzewa BST
// k - klucz poszukiwanego węzła
//----------------------------------------------------
BSTNode * findBST ( BSTNode * p, int k )
{
  while( p && p->key != k )
    p = ( k < p->key ) ? p->left: p->right;

  return p;
}

// Funkcja zwraca wskazanie węzła o najmniejszym kluczu.
// Parametrem jest wskazanie korzenia drzewa BST.
//------------------------------------------------------
BSTNode * minBST ( BSTNode * p )
{
  if( p ) while( p->left ) p = p->left;

  return p;
}

// Funkcja znajduje następnik węzła p
//-----------------------------------
BSTNode * succBST ( BSTNode * p )
{
  BSTNode * r;

  if( p )
  {
    if( p->right ) return minBST ( p->right );
    else
    {
      r = p->up;
      while( r && ( p == r->right ) )
      {
        p = r;
        r = r->up;
      }
      return r;
    }
  }
  return p;
}

// Procedura usuwa węzeł z drzewa BST
// root - referencja do zmiennej wskazującej węzeł
// X    - wskazanie węzła do usunięcia
//----------------------------------------------
void removeBST ( BSTNode * & root, BSTNode * X )
{
  BSTNode * Y, * Z;

  if( X )
  {
    // Jeśli X nie ma synów lub ma tylko jednego, to Y wskazuje X
    // Inaczej Y wskazuje następnik X

    Y = !X->left || !X->right ? X : succBST ( X );

    // Z wskazuje syna Y lub NULL

    Z = Y->left ? Y->left : Y->right;

    // Jeśli syn Y istnieje, to zastąpi Y w drzewie

    if( Z ) Z->up = Y->up;

    // Y zostaje zastąpione przez Z w drzewie

    if( !Y->up ) root = Z;
    else if( Y == Y->up->left ) Y->up->left  = Z;
    else                        Y->up->right = Z;

    // Jeśli Y jest następnikiem X, to kopiujemy dane

    if( Y != X ) X->key = Y->key;

    delete Y;

  }
}

// **********************
// *** PROGRAM GŁÓWNY ***
// **********************

int main( )
{
  int Tk [ 15 ];   // tablica kluczy węzłów
  int i, x, i1, i2;
  BSTNode * root = NULL;

  // ustawiamy łańcuchy znakowe, ponieważ nie wszystkie edytory pozwalają
  // wstawiać znaki konsoli do tworzenia ramek.
  // cr = +--
  //      |

  // cl = |
  //      +--

  // cp = |
  //      |

  cr = cl = cp = "  ";
  cr [ 0 ] = 218; cr [ 1 ] = 196;
  cl [ 0 ] = 192; cl [ 1 ] = 196;
  cp [ 0 ] = 179;

  srand ( time ( NULL ) );   // inicjujemy generator pseudolosowy

  for( i = 0; i < 15; i++ )  // Tablicę wypełniamy wartościami kluczy
    Tk [ i ] = i + 1;

  for( i = 0; i < 100; i++ ) // Mieszamy tablicę
  {
    i1 = rand( ) % 15;       // Losujemy 2 indeksy
    i2 = rand( ) % 15;

    x = Tk [ i1 ];           // Wymieniamy Tk [ i1 ] <--> Tk [ i2 ] 
    Tk [ i1 ] = Tk [ i2 ];
    Tk [ i2 ] = x;
  }

  for( i = 0; i < 15; i++ )  // Na podstawie tablicy tworzymy drzewo BST
  {
    cout << setw ( 3 ) << Tk [ i ];
    insertBST ( root, Tk [ i ] );
  }

  cout << endl << endl;

  printBT ( "", "", root );  // Wyświetlamy zawartość drzewa BST

  cout << endl << endl;

  for( i = 0; i < 100; i++ ) // Ponownie mieszamy tablicę
  {
    i1 = rand( ) % 15; i2 = rand( ) % 15;
    x = Tk [ i1 ]; Tk [ i1 ] = Tk [ i2 ]; Tk [ i2 ] = x;
  }

  for( i = 0; i < 5; i++ )   // Usuwamy 5 węzłów
  {
    cout << setw ( 3 ) << Tk [ i ];
    removeBST ( root, findBST ( root, Tk [ i ] ) );
  }

  cout << endl << endl;

  printBT ( "", "", root );  // Wyświetlamy zawartość drzewa BST

  DFSRelease ( root );       // Usuwamy drzewo BST z pamięci

  return 0;
} 
