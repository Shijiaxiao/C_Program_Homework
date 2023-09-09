//
//  queue.h
//  Experiment 7-1
//
//  Created by 史家箫 on 2021/12/22.
//
/*
 *数据类型=数据+操作
 *数据用变量存放，变量的类型可以是int,float,double,char, char *, array, struct, pointer
 *操作用函数实现
 *本代码为用链式存储结构实现队列
 *通过typedef使得队列数据类型更通用
 *结构体的定义和函数的声明放在头文件queue.h中，
 *函数的实现放在queue.c中
 */
#ifndef queue_h
#define queue_h
#include "position.h"

typedef Position ElemType;

struct Node {
    ElemType item;  // position
    struct Node *next;
};
typedef struct Node Node;

struct Queue {
    struct Node *first;
    struct Node *last;
};
typedef struct Queue Queue;

void init_queue(Queue *p);  // construct queue
int empty(Queue *p);  // test whether the queue is empty, return value 1 for empty, 0 for non-empty
void push(Queue *p, ElemType val);  // insert element at the end of the queue
void pop(Queue *p);  // remove the front element
ElemType front(Queue *p);  // return the front element, the front element is not removed
void clear_queue(Queue *p);  //clean the queque

#endif /* queue_h */
