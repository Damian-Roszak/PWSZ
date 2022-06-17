#include <math.h>
#include <stdio.h>
#include <limits.h>
int main()
{
  printf("\n   x    \t   log   \t   log2   \t   log10   \t   log1p");  
  for(double x=0; x<=10; x+=0.5)
    printf("\n%lf\t%lf\t%lf\t%lf\t%lf", x, log(x), log2(x), log10(x), log1p(x));   
    printf("\n");
    
    
   printf("\n\nThe maximum value of INT = %d\n", INT_MAX);
    
    
    
    
    
    
  return 0;
}
