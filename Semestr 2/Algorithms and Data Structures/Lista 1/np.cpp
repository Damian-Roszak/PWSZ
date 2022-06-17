#include <iostream>

void f( int a )
{
    if( a > 0 )
    {
        std::cout << a << std::endl;
        f( a - 1 );
        std::cout << a << std::endl;
    }
}

int main()
{
    f( 5 );
}
