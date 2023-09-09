//
//  adjacency_list.h
//  Experiment 7-2
//
//  Created by 史家箫 on 2021/12/23.
//

#ifndef adjacency_list_h
#define adjacency_list_h

#include <stdio.h>


struct node {
    int v;
    struct node *next;
};
typedef struct node node;


struct vertex {
    int discovered;
    int on_stack;
};
typedef struct vertex vertex;


struct graph {
    int nv;      //number of vertices
    node **adj;
    vertex *vertices;
};
typedef struct graph graph;


void init_graph(graph *G, int nv);//初始化图G

void set_edge(graph *G, int v1, int v2);//建立v1和v2之间的一条边，顶点集不变

int is_edge(graph *G, int v1, int v2);//判断从v1到v2是否有边

void input_graph(graph *G);//读取图

void output_graph(graph *G);//输出图G

void clear_graph(graph *G);//释放图G的存储空间

#endif /* adjacency_list_h */
