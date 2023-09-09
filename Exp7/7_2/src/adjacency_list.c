//
//  adjacency_list.c
//  Experiment 7-2
//
//  Created by 史家箫 on 2021/12/23.
//

#include <stdio.h>
#include <stdlib.h>
#include "adjacency_list.h"


void skip_blank(void)
{
    char c;
    while((c = getchar()) == ' ');
    ungetc(c, stdin);
}


void init_graph(graph *G, int nv)
{
    G->nv = nv;
    G->vertices = (vertex *)malloc(G->nv * sizeof(vertex));
    G->adj = (node **)malloc(G->nv * sizeof(node *));
    for (int i = 0; i < G->nv; i++)
        G->adj[i] = NULL;
}


void set_edge(graph *G, int v1, int v2)
{
    // way 1: head-plug chain table.
    // why using this: because we need to update adj[v1] every time without replcing the former data.
    
    node* q = (node *)malloc(sizeof(node));
    q->v = v2;
    q->next = G->adj[v1];  // if first, G->adj[v1] == NULL!
    G->adj[v1] = q;
}


void input_graph(graph *G)
{
    int nv;
    printf("Please input the number of vertices of a graph: ");
    scanf("%d", &nv);
    init_graph(G, nv);
    printf("Please input the graph:\n");
    while(1) {
        int u;
        if (scanf("%d:", &u) != 1) break;
        skip_blank();
        char c;
        while((c = getchar()) != '\n') {
            ungetc(c, stdin);
            int v;
            scanf("%d", &v);
            set_edge(G, u, v);
            skip_blank();
        }
    }
}


void output_graph(graph *G)
{
    printf("\nG = ( V,E )\n");
    printf("V = { ");
    for (int i = 0; i < G->nv - 1; i ++)
        printf("%d, ", i);
    printf("%d", G->nv - 1);
    printf(" }\n");
    printf("E = { ");
    int number = 0;
    for (int i = 0; i < G->nv; i ++) {
        node *p = G->adj[i];
        while(p != NULL) {
            if (number > 0) printf(", ");
            printf("(%d,%d)", i, p->v);
            number++;
            p = p->next;
        }
    }
    printf(" }\n");
    printf("\nThere are %d edges in all.\n\n",number);
}


void clear_graph(graph *G)
{
    for (int i = 0; i < G->nv; i++) {
        node * q;
        for (node *p = G->adj[i]; p != NULL; p = q) {
            q = p->next;
            free(p);
        }
    }
    free(G->adj);
}
