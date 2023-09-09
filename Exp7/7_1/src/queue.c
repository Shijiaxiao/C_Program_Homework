//
//  queue.c
//  Experiment 7-1
//
//  Created by 史家箫 on 2021/12/22.
//

/*
 *数据类型=数据+操作
 *数据用变量存放，变量的类型可以是 int,float,double,char, char *, array, struct, pointer
 *操作用函数实现
 *本代码为用链式存储结构实现队列
 *通过typedef使得队列数据类型更通用
 *结构体的定义和函数的声明放在头文件queue.h中，
 *函数的实现放在queue.c中
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void init_queue(Queue *p)
{
    p->first = NULL;
    p->last = NULL;
}

int empty(Queue *p)
{
    return p->first == NULL;
}

void push(Queue *p, ElemType val)
{
    struct Node *r = (Node *)malloc(sizeof(struct Node));  // temp.
    r->item = val;  // the element need to be inserted.
    r->next = NULL;  // the last.

    if (p->last == NULL) {
        p->first = r;
        p->last = r;
    }
    
    else {
        p->last->next = r;
        p->last= r;
    }
}

void pop(Queue *p)
{
    if (p->first == NULL) {
        printf("error:Queue empty!\n");
        exit(1);
    }
    else if (p->last == p->first)
        p->last = NULL;
    
    struct Node *t = p->first;  // to free the first space.
    p->first = p->first->next;
    free(t);
}

ElemType front(Queue *p)
{
    return p->first->item;
}

void clear_queue(Queue *p)
{
    while(!empty(p))
        pop(p);
}
