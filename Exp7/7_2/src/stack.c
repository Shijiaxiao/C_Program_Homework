//
//  stack.c
//  Experiment 7-2
//
//  Created by 史家箫 on 2021/12/23.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void init_stack(struct Stack *p)
{
    p->first = NULL;
    p->last = NULL;
}


int empty(struct Stack *p)
{
    return p->first == NULL;
}


void push(Stack *p, ElemType val)
{
    Node *r = (Node *)malloc(sizeof(Node));
    r->item = val;
    r->next = p->first;
    p->first = r;

    if (p->last == NULL)
        p->last = r;
}


void pop(Stack *p)
{
    if (p->first == NULL) {
        printf("error:stack empty!\n");
        exit(1);
    }
    
    else if (p->last == p->first) {
        p->last = NULL;
    }
        
    Node *t = p->first;
    p->first = p->first->next;
    free(t);
}


ElemType top(Stack *p)
{
    return p->first->item;
}


void clear_stack(struct Stack *p)
{
    while(!empty(p)) 
        pop(p);
}
