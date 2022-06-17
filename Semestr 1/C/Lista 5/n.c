#include<stdio.h>
#include<string.h>























/*
char dziel(int a)
{
    char s;
    sprintf(&s,*(&char)(a),2);
    return s;
}
*/

void main()
{
    printf("podaj n: ");
    int n;
    scanf("%d", &n);
    
char *s, *d;
while(n!=0)
{
   // *s+=n%2;
    //sprintf(s,(*int)(n%2),2);
//    strcpy(s, (*)char(n/2));
printf("lol \n");
   sprintf(s, "%d",n/2);
//printf("%s ", s);
 printf("%s", strcat(d, s));
    n/=2;
}
//*s += 121;

//*s +='\0';
printf("%s", s);

printf("\n");

}
