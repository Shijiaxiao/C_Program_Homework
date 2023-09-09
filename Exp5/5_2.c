#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _ListNode{
    int data;
    struct _ListNode* next;
};
typedef struct _ListNode ListNode;

ListNode * createList(int n);   //创建一个n个节点的链表
ListNode * mergeList(ListNode * p1, ListNode * p2); //归并两个有序链表
void output(ListNode * list);   //输出链表

/*
    p1
    fuzhu -> 1 -> 3 -> 5 -> NULL

    p2
    fuzhu -> 2 -> 4 -> 6 -> NULL
*/





int main()
{
    int n1, n2;
    // 创建了两个链表（按顺序）
    printf("Please enter the length of first list: ");
    scanf("%d", &n1);
    ListNode * p1 = createList(n1);
    output(p1);
    printf("Please enter the length of second list: ");
    scanf("%d", &n2);
    ListNode * p2 = createList(n2);
    output(p2);
    // 归并
    ListNode * head = mergeList(p1, p2);

    output(head);   
	//大家补充上5-3里的删除链表的操作
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

ListNode * mergeList(ListNode * p1, ListNode * p2){
    //申请辅助头节点
    ListNode * head = (ListNode*)malloc(sizeof(ListNode));
    ListNode * tail = head;
    //每次判断两个链表的开头，谁更小，就把谁拿过来接到head后面
    while(p1->next && p2->next){
        if(p1->next->data < p2->next->data){
            //把p1->next节点拿出来，接到tail上
            tail->next = p1->next;
            p1->next = p1->next->next;
            tail = tail->next;
            tail->next = NULL;
        }
        else{
            //把p2->next节点拿出来，接到tail上
            tail->next = p2->next;
            p2->next = p2->next->next;
            tail = tail->next;
            tail->next = NULL;
        }
    }
    if(p1->next == NULL){
        tail->next = p2->next;
    }
    else{
        tail->next = p1->next;
    }
    free(p1);
    free(p2);
    return head;
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