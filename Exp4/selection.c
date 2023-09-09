//
//  main.c
//  optimizing selectionSort
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

void selectionSort(void)
{
    int left=0,i,right=N-1,kmax,kmin,max,min;
    int time=1;
    for(right=N-1;right>left;right--,left++,time++)
    {
        min=max=a[right];
        kmax=kmin=right;//remember to redine after each loop
        for(i=right;i>=left;i--)
        {
            
            if(a[i]>max)
            {
                max=a[i];
                kmax=i;
            }
            else if(a[i]<min)
            {
                min=a[i];
                kmin=i;
            }
        }
        swap(kmin,left);
        if(kmax!=left)
            swap(kmax,right);
        //incase a[ka] had been swapped to another position so the program is wrong!
        else
        {
            kmax=kmin;
            swap(kmax,right);
        }
        printf("After sorted for %d times:",time);
        for(i=0;i<N;i++)
            printf("%d ",a[i]);
        printf("\n");
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
    selectionSort();
    printf("After sort:");
    for(i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
