//
//  find_cycle.c
//  Experiment 7-2
//
//  Created by 史家箫 on 2021/12/23.
//

#include <stdio.h>
#include <stdlib.h>
#include "adjacency_list.h"
#include "find_cycle.h"
#include "stack.h"


void find_cycle(graph *G)
{
    
    for(int i = 0; i < G->nv; i ++) {
        
            G->vertices[i].discovered = 0;
            G->vertices[i].on_stack = 0;
    }
    
    
    for (int i = 0; i < G->nv; i ++) {
        
        if (G->vertices[i].discovered == 0) {
            
            G->vertices[i].discovered = 1;
            Stack *s = (Stack *)malloc(sizeof(Stack));
            init_stack(s);
            push(s, i);  // i is the head node (serial number).
            
            // can't work without this.
            G->vertices[i].on_stack = 1;
            
            while(!empty(s)) {
                
                // record the head node (serial number).
                int x = top(s);
                int finished = 1;
                
                for (node *p = G->adj[x]; p != NULL; p = p->next) {
                    
                    
                    // found a cycle.
                    if (G->vertices[p->v].on_stack == 1) {
                        
                        /*
                         // way 1: the head is the first.
                         
                         push(s, p->v);
                         int head = p->v;
                         
                         Stack *print = (Stack *)malloc(sizeof(Stack));
                         init_stack(print);
                         push(print,head);
                         
                         // construct stack.
                         for (Node *f = s -> first -> next; f != NULL && f -> item != head; f = f -> next)
                             push(print,f->item);
                         push(print,head);
                         
                         printf("The found cycle: ");
                         
                         for (Node *f = print -> first; f != NULL; ) {
                             
                             if (f == print -> first)
                                 printf("%d ",f -> item);
                             
                             else
                                 printf("-> %d ",f -> item);
                             
                             // free print.
                             Node *temp = f;
                             f = f -> next;
                             free(temp);
                         }
                         
                         printf("\n\n");
                         
                         
                         // clear storage.
                         clear_stack(s);
                         
                         */
    
                        
                        // way 2: similiar to the experiment (print as soon as found an on-stack node).
                                            
                        Stack *print = (Stack *)malloc(sizeof(Stack));
                        init_stack(print);
                        //push(print,head);
                        
                        // construct stack.
                        while(1) {
                            push(print,s->first->item);
                            if(s->first->item == p->v) {
                                pop(s);
                                push(print,x);
                                break;
                            }
                            pop(s);
                        }
                        
                        printf("The found cycle: ");
                        
                        for (Node *f = print -> first; f != NULL; ) {
                            
                            if (f == print -> first)
                                printf("%d ",f -> item);
                            
                            else
                                printf("-> %d ",f -> item);
                            
                            // free print.
                            Node *temp = f;
                            f = f -> next;
                            free(temp);
                        }
                        
                        printf("\n\n");
                        
                        
                        // clear storage.
                        clear_stack(s);
                        
                        return;
                        
                    }
                    
                    // discover a new node -> push into stack.
                    if (G->vertices[p->v].discovered == 0) {
                        
                        G->vertices[p->v].discovered = 1;
                        push(s, p->v);
                        
                        G->vertices[p->v].on_stack = 1;
                        finished = 0;
                        break;
                    }
                }
                
                
                // didn't find a possible pathway.
                if (finished) {
                    int x = top(s);
                    pop(s);
                    G->vertices[x].on_stack = 0;
                }
            }
        }
    }
    
    printf("No cycles.\n");
}

