#include <stdio.h>
#include <time.h>
int main()
{
    time_t czas;
    char *c;
    time( &czas );
    c = ctime( &czas );
    printf( "Czas lokalny: %s\n", c );
    
    return 0;
}
