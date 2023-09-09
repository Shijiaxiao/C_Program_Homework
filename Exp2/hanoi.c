//

#include <stdio.h>
void hanoi ( int n, char a,  char b,  char c )
{
    if  (1 == n)
        printf("Move %d: from %c to %c\n",n,a,b);
    else
    {
        hanoi ( n-1,  a,  b,  c ) ;
        printf("Move %d: from %c to %c\n",n,a , b) ;
    }
}
int main ()
{
    int  n ;
    printf( "Input the number of diskes:") ;
    scanf("%d",&n) ;
    printf("Steps of moving %d disks from A to B by means of C:\n",n);
    hanoi ( n,  'A' ,  'B' , 'C' ) ;
    return 0;
}
