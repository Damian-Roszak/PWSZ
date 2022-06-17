#include <iostream>
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
    cout << s << sn << " klucz= " << v->key << endl;

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
  w->key = k;                // Wstawiamy klucz.

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

// **********************
// *** PROGRAM GŁÓWNY ***
// **********************

int main( )
{
  BSTNode * root = NULL;
  int i, k;

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

  srand ( time ( NULL ) );  // inicjujemy generator pseudolosowy

  for( i = 0; i < 30; i++ ) // Wypełniamy drzewo BST węzłami
  {
    k = 1 + rand( ) % 119;    // Generujemy klucz 1...9
    cout << k << " ";       // Wyświetlamy klucz
    insertBST ( root, k );  // Tworzymy nowy węzeł o kluczu k i umieszczamy go w drzewie
  }

  cout << endl << endl;

  printBT ( "+", "-", root ); // Wyświetlamy drzewo
  DFSRelease ( root );      // Usuwamy drzewo z pamięci

  return 0;
} 
