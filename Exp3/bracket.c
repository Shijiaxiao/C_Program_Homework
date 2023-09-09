#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char sen[10000],bra[10000];
    int i=1,top=0,flag=1,dead=0;
    printf("Please input a sentence which has brackets:");
    gets(sen);
    top=strlen(sen);
    top=top-1;
    for(;top>=0;top--)
    {
        if(sen[top]==')')
        {
            bra[i]=')';
            i++;
        }
        if(sen[top]=='(')
        {
            if(bra[i-1]==')')
            {
                i--;
            }
            else
            {
                flag=0;
            }
        }
        if((sen[top]<'0'||sen[top]>'9')&&(sen[top]!='%')&&(sen[top]!='(')&&(sen[top]!=')')&&(sen[top]!='\n')&&(sen[top]!='+')&&(sen[top]!='-')&&(sen[top]!='*')&&(sen[top]!='/')&&(sen[top]!='='))
        {
            flag=0;
            break;
        }
    }
    if(i!=1)
    {
        flag=0;
    }
    if(flag==0)
    {
        printf("no");
    }
    else if(flag==1)
    {
        printf("yes");
    }
}
