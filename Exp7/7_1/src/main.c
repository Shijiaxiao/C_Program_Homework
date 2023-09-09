//
//  main.c
//  Experiment 7-1
//
//  Created by 史家箫 on 2021/12/22.
//

/*
程序运行示例1：
Please input the graph:
10 10
0 1 1 0 0 1 0 0 0 0
0 0 0 1 1 1 1 1 0 1
0 1 0 0 1 0 0 1 0 0
1 1 0 1 0 1 0 1 1 1
0 1 0 0 1 1 0 1 1 1
0 1 0 0 1 1 1 1 1 1
0 0 1 0 0 0 0 0 0 0
0 0 1 0 1 0 1 0 1 1
0 1 1 0 0 0 1 0 0 1
0 0 1 0 1 1 0 1 0 0
18 steps:
(0, 0)
(1, 0)
(1, 1)
(1, 2)
(2, 2)
(3, 2)
(4, 2)
(4, 3)
(5, 3)
(6, 3)
(6, 4)
(6, 5)
(6, 6)
(6, 7)
(7, 7)
(8, 7)
(8, 8)
(9, 8)
(9, 9)

程序运行示例2：
Please input the graph:
10 10
0 1 1 0 0 1 0 0 0 0
0 0 0 1 1 1 1 1 0 1
0 1 0 0 1 0 0 1 0 0
1 1 1 1 0 1 0 1 1 1
0 1 0 0 1 1 0 1 1 1
0 1 0 0 1 1 1 1 1 1
0 0 1 0 0 0 0 0 0 0
0 0 1 0 1 0 1 0 1 1
0 1 1 0 0 0 1 0 0 1
0 0 1 0 1 1 0 1 0 0
No path exists!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "position.h"

struct Direction {
    int dr;
    int dc;
} dir[4] = { {-1,0}, {1, 0}, {0, -1}, {0, 1} };  // up down left right.

int m, n;

void print_path(int *predecessor, int s, int v);

int main()
{
    printf("Please input the size of the maze:\n");
    scanf("%d%d", &m, &n);
    int *matrix = (int *)malloc(m * n * sizeof(int));  // maze.
    int *discovered = (int *)malloc(m * n * sizeof(int));  // whether a node has been visited.
    int *predecessor = (int *)malloc(m * n * sizeof(int));
    printf("Please input the maze:\n");
    for (int i = 0; i < m; i ++)
        for (int j = 0; j < n; j ++) {
            scanf("%d", &matrix[i * n + j]);
            discovered[i * n + j] = 0;
            predecessor[i * n + j] = -1;
        }
    
    // initialize the starting point.
    Position start;
    start.r = 0;
    start.c = 0;
    start.steps = 0;
    discovered[0 * n + 0] = 1;
    
    // initialize the queue.
    Queue q;
    init_queue(&q);  // empty.
    push(&q, start);  
    
    // DFS. Traversal.
    Position u;
    while (!empty(&q)) {
        u = front(&q); // the position of last time
        
        // head to the terminal successfully!
        if (u.r == m-1 && u.c == n-1)
            break;
        
        // every loop starts with an empty queue. If there is a way to the next position, enter next loop.
        pop(&q);
        
        for (int i = 0; i < 4; i ++) {
            int nr = u.r + dir[i].dr;  // the next row.
            int nc = u.c + dir[i].dc;  // the next column.
            
            if (nr <0 || nr >= m || nc < 0 || nc >= n || matrix[nr* n + nc] == 1)  // cross the border or encounter obstacle.
                continue;
            
            // if the new node hasn't been visited.
            if (!discovered[nr * n + nc]) {
                discovered[nr * n + nc] = 1;  // been visited by now.
                predecessor[nr * n + nc] = u.r * n + u.c;  // pre % n == c ; pre / n == r ;  ( how to calculate the pre coordinate. )
                Position p;
                p.r = nr;
                p.c = nc;
                p.steps = u.steps + 1;
                push(&q, p);  // in queue.
            }
        }
    }
    
    // judging whether there is a path.
    if (empty(&q))
        printf("No path exists!\n");
    
    else {
        printf("%d steps:\n", u.steps);
        print_path(predecessor, 0, m * n - 1);
    }
    
    return 0;
}


// Reverse printing !!!
void print_path(int *predecessor, int s, int v)
{
    if(v == s)
        return;
    
    else
        print_path(predecessor, 0, predecessor[v]);
    
    printf("(%d,%d)\n",predecessor[v] / n,predecessor[v] % n);
    
    if(v == m * n - 1)
        printf("(%d,%d)\n",m-1,n-1);
    
    return;
}


