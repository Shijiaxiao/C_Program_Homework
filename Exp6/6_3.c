//
//  main.c
//  Experiment 6-3
//
//  Created by 史家箫 on 2021/12/8.
//
// Non tree

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void QueenDFS(int *board,int *count,int *cnt,int N,int n);
int judge(int *board,int n);

int main()
{
    int N;
    int cnt=0;
    printf("Please input the size of the board:");
    scanf("%d",&N);
    int *board=(int *)malloc(N * sizeof(int));
    int *count=(int *)malloc(MAX * N * sizeof(int));
    QueenDFS(board,count,&cnt,N,0);
    printf("There are %d ways of displaying %d Queens on board that won't cause conflicts.\n",cnt,N);
    putchar('\n');
    
    // times
    for(int i=0;i<cnt;i++) {
        // row
        for(int row=0;row<N;row++) {
            for(int k=0;k<N;k++) {
                if(k==*(count+i*N+row))
                    putchar('Q');
                else
                    putchar('o');
            }
            putchar('\n');
        }
        printf("\n\n");
    }
    free(board);
    free(count);
}


void QueenDFS(int *board,int *count,int *cnt,int N,int n)  // operating line n
{
    int i;
    //  absolutly not N-1!!!
    if(n==N) {
        for(int j=0;j<N;j++)
            *(count+(*cnt)*N+j)=*(board+j);
        (*cnt)++;
    }
    
    else {
        for(i=0;i<N;i++) {
            board[n]=i;
            if(judge(board,n))
                QueenDFS(board,count,cnt,N,n+1);
        }
    }
}

int judge(int *board,int n)
{
    int i;
    int judge;
    for(i=0;i<n;i++) {
        judge=(board[n]-board[i]) > 0 ? (board[n]-board[i]) : (board[i]-board[n]) ;
        if(n-i==judge || judge==0 )
        //if(n-i==((board[n]-board[i]) > 0 ? (board[n]-board[i]) : (board[i]-board[n])) || board[n]-board[i]==0)
            return 0;
    }
    return 1;
}
