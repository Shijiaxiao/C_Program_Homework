//
//  stack.h
//  Experiment 7-2
//
//  Created by 史家箫 on 2021/12/23.
//

/*
 *数据类型=数据+操作
 *数据用变量存放，变量的类型可以是int,float,double,char, char *, array, struct, pointer
 *操作用函数实现
 *本代码用链式存储结构实现栈
 *通过typedef使得栈数据类型更通用
 *结构体的定义和函数的声明放在头文件stack.h中，
 *函数的实现放在stack.c中
 */

#ifndef stack_h
#define stack_h

#include <stdio.h>

typedef int ElemType;


struct Node {
    ElemType item;
    struct Node *next;
};
typedef struct Node Node;


struct Stack {
    Node *first;
    Node *last;
};
typedef struct Stack Stack;


void init_stack(struct Stack *p);//construct stack

int empty(struct Stack *p);//test whether the stack is empty, return value 1 for empty, 0 for non-empty

void push(struct Stack *p, ElemType val);//insert element

void pop(struct Stack *p);//remove the top element

ElemType top(struct Stack *p);//return the top element, the top element is not removed

void clear_stack(struct Stack *p);//destroy stack

#endif /* stack_h */
