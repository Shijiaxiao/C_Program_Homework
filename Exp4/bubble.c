//
//  main.c
//  optimizing bubbleSort
//
//  Created by 史家箫 on 2021/11/2.
//


#include <stdio.h>
#define N 10
int a[N];//define globle variable array. So the address won't be changed.

void swap(int i,int j)//why not pointer? Array offers address. pointer array? adress of address
{
    int medium=a[i];
    a[i]=a[j];
    a[j]=medium;
}

void bubbleSort(void)
{
    int i,j,right;
    int rank=1;
    int Newposition=N-1;
    int position=0;
    for(right=N-1;right>0;right--,rank++)
    {
        int flag=0,time=1;
        for(i=0;i<=Newposition-1;i++)
        {
            if(a[i]>a[i+1])
            {
                swap(i,i+1);//max become final
                flag=1;//did swap
                position=i;
                printf("After sorted for (%d,%d) times ",rank,time++);
                for(j=0;j<N;j++)
                    printf("%d ",a[j]);
                printf("\n");
            }
        }
        Newposition=position;
        if(!flag)
            break;
    }
}

int main()
{
    int i;
    printf("Please enter %d numbers:",N);
    for(i=0;i<N;i++)
        scanf("%d",a+i);
    printf("Before sort:");
    for(i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\n");
    bubbleSort();
    printf("After sort:");
    for(i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
