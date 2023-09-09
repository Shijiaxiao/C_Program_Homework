//
//  main.c
//  Experiment 7-2
//
//  Created by 史家箫 on 2021/12/23.
//

/*
Please input the graph:
10
0:1
1:6
2:3 1
3:4
4:
5:6 0
6:7
7:8
8:9 2
9:
^Z
The found cycle: 2 1 6 7 8 2
*/
/*
Please input the graph:
7
0: 1  6
1: 2
2: 3  5
3: 4
4:
5: 4
6: 2
^Z
No cycles.
*/

#include <stdio.h>
#include <stdlib.h>
#include "adjacency_list.h"
#include "find_cycle.h"

int main()
{
    graph* G = (graph*)malloc(sizeof(graph));
    input_graph(G);
    output_graph(G);
    find_cycle(G);
    clear_graph(G);
    return 0;
}
