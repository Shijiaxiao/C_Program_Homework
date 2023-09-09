#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int prime(int a);
int main()
{
    int i,j,flag,floor,ceil,origin,rever=0,last;
    scanf("%d%d",&floor,&ceil);
    for(i=floor;i<=ceil;i++)
    {
        j=i;
        flag=prime(j);
        if(flag==1)
        {
            origin=j;
           while(j!=0)
           {
              last=j%10;
              rever=rever*10+last;
              j=j/10;
           }
           if(rever==origin)
           {
               printf("%d\n",origin);
           }
           rever=0;
        }
    }
}
int prime(int a)
{
    int i,j,flag=1;
    long int lett[10000];
    for(i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
        {
            flag=0;
        }
    }
    if(flag==1)
    {
        return 1;
    }
    else
    return 0;
}
