//
//  main.c
//  optimizing insertSort
//
//  Created by 史家箫 on 2021/11/3.
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

void insertSort(void)//swap one by one
{
    int i,j;
    for(i=1;i<N;i++)
    {
        for(j=i-1;j>=0&&a[j]>a[j+1];j--)//count from the last, swap at the same time
            swap(j,j+1);
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
    insertSort();
    printf("After sort:");
    for(i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}

