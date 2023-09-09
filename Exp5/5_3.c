#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _ListNode{
    int data;
    struct _ListNode* next;
};
typedef struct _ListNode ListNode;

/*
    head -> 1 -> 2 -> 4 -> 8 -> 16 -> NULL
    倒过来
    head -> 16 -> 8 -> 4 -> 2 -> 1

    栈
    后进先出LIFO
    head   -> NULL
    stack  -> 16 -> 8 -> 4 -> 2 -> 1 -> NULL

*/

/*
    head  -> 2 -> NULL
    stack -> 1 -> ... -> NULL
*/
ListNode * createList(int n);   // 创建链表（带头结点）
ListNode * reverseList(ListNode * p);   // 反转
void output(ListNode * list);   // 输出
void deleteList(ListNode * list);   //删除链表节点

int main()
{
    int n;
    printf("Please enter the length of list: ");
    scanf("%d", &n);
    if(n <= 0){
        exit(0);
    }
    ListNode * head = createList(n);    //创建
    output(head);  //输出
    ListNode * p = reverseList(head);   //反转
    output(p);  //输出
    deleteList(p);//删除链表

    return 0;
}

ListNode * createList(int n){
    if(n < 0){
        return NULL;
    }
    ListNode * head;
    ListNode * p;
    ListNode * tail;
    head = (ListNode*)malloc(sizeof(ListNode));
    head->next = NULL;
    tail = head;
    for(int i = 0; i < n; ++i){
        //创建节点，读取数据
        printf("Please enter number %d: ", i + 1);
        p = (ListNode*)malloc(sizeof(ListNode));
        p->next = NULL;
        scanf("%d", &(p->data));
        //把节点接到链表上
        tail->next = p;
        tail = p;   //or you can write tail = tail->next
    }
    return head;
}

ListNode * reverseList(ListNode * p){
    ListNode * stack = (ListNode*)malloc(sizeof(ListNode));
    stack->next = NULL;
    ListNode * temp;
    while(p->next){
        //取出了一个节点
        temp = p->next;
        p->next = p->next->next;
        //temp->next = NULL;
        //入栈
        //头插法
        temp->next = stack->next;   //把stack后面的链表接到temp后
        stack->next = temp; //把temp节点紧跟stack
    }
    free(p);
    return stack;
}

void output(ListNode * list){
    ListNode * p = list->next;
    if(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    while(p){
        printf("-> %d ", p->data);
        p = p->next;
    }
    putchar('\n');
    return;
}

void deleteList(ListNode * list){
    ListNode * temp;
    while(list){
        temp = list->next;
        free(list);
        list = temp;
    }
    return;
}