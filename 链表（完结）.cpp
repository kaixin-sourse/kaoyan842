#include <stdio.h>
#include <stdlib.h>
#define Wa 0
#define Ac 1
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} LNode, *LinkList;

//逆位序输入n个元素的值，建立带表头结点的单链线性表L。
void CreateList_L(LinkList &L, int n);

//查找链表（带头节点）中第i个元素（如果存在的话）
Status GetElem_L(LinkList L, int i, ElemType &e);

//展示链表（输出链表）
void ShowList_L(LinkList &L);

//在带头结点的单链线性表L中第i个位置之前插入元素e
Status ListInsert_L(LinkList &L, int i, ElemType &e);

//在带头节点的单链线性表中，删除第i个元素，并用e返回其值
Status ListDelete_L(LinkList &L, int i, ElemType &e);

//创建链表
void test01()
{
    //输入创建链表长度，并逆序输入每一节对应的值
    LinkList L = (LinkList)malloc(sizeof(LNode));
    int len;
    printf("Please input the len of the LinkList:");
    scanf("%d", &len);
    CreateList_L(L, len);
    ShowList_L(L);
    ElemType e = -1, pos = 0;
    ElemType deletee = 0;
    printf("Please input the value of the position and elem_L:");
    scanf("%d%d", &pos, &e);
    // printf("the status of the operation of the GetElem_L is %d\n", GetElem_L(L, 6, e));
    // printf("the value of e is %d", e);
    printf("the status of the operation of the ListInsert_L is %d\n", ListInsert_L(L, pos, e));
    ShowList_L(L);

    printf("Please input the value of the position:");
    scanf("%d", &pos);
    printf("the status of the operation of the ListDelete_L is %d\n", ListDelete_L(L, pos, deletee));
    printf("the value of the number to be deleted is :%d\n", deletee);
    ShowList_L(L);
}

int main()
{
    test01();
    return 0;
}

void CreateList_L(LinkList &L, int n)
{
    //逆位序输入n个元素的值，建立带表头结点的单链线性表L。
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    for (int i = n; i > 0; i--)
    {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
}

Status GetElem_L(LinkList L, int i, ElemType &e)
{
    // L为带头节点的单链表的头指针
    //查找链表中第i个元素（如果存在的话）
    LinkList p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    e = p->data;
    return OK;
}

Status ListInsert_L(LinkList &L, int i, ElemType &e)
{
    //在带头结点的单链线性表L中第i个位置之前插入元素e
    LinkList p = L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
        return ERROR;
    LinkList q = (LinkList)malloc(sizeof(LNode));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return OK;
}

//在带头节点的单链线性表中，删除第i个元素，并用e返回其值
Status ListDelete_L(LinkList &L, int i, ElemType &e)
{
    LinkList p = L;
    int j = 0;
    //这里用p->next而不是使用p是因为下面的if判断可以少判断p地址是否为空
    while (p->next && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p->next || j > i - 1)
        return ERROR;
    LinkList q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return OK;
}

void ShowList_L(LinkList &L)
{
    puts("****************************");
    //展示链表（输出链表）
    LinkList p = L->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    puts("\n****************************");
}