#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,k,q,flag=0;
    char lett,p='A';
    scanf("%c",&lett);
    if(lett>=97&&lett<=122)
    {
       lett=lett-32;
    }
    if(lett>=65&&lett<=90)
    {
        for(i=lett;i>=65;i--)
        {
            flag++;
            for(j=i;j>65;j--)
            {
                printf(" ");
            }
            for(k=0;k<flag;k++)
            {
                printf("%c",p);
                p++;
            }
            p--;
            for(q=1;q<flag;q++)
            {
                p--;
                printf("%c",p);
            }
            printf("\n");
        }
    }
    else
        {
            printf("Invalid character!");
        }
}
