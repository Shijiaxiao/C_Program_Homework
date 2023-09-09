#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int i,j,k=0,q=0;
    char sentence[100][100];
    while(1==1)
    {
        while(1==1)
        {
            scanf("%c",&sentence[k][q]);
            if(sentence[k][q]==' '||sentence[k][q]=='.')
            {
                break;
            }
            q++;
        }
        if(sentence[k][q]=='.')
        {
            break;
        }
        k++;
        q=0;
    }
     for(i=k;i>=0;i--)
    {
        for(j=0;j<=q;j++)
        {
            printf("%c",sentence[i][j]);
        }
        printf(" ");
    }
}
