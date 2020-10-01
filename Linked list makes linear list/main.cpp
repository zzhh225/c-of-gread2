#include <iostream>
#include<cstdlib>

using namespace std;

typedef int ElemType;

//初始化链表
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node,*LinkList;

//创建空表
void InitList_L(LinkList &L)
{
    L = (LinkList)malloc(sizeof(Node));
    L->next = NULL;
};

//创建非空表
void CreateList_L(LinkList &L, ElemType A[], int n)
{
    L = (LinkList)malloc(sizeof(Node));
    L->next = NULL;
    LinkList s;
    for (int i = n-1;i>=0; i--)
    {
        s = (LinkList)malloc(sizeof(Node));
        s->data = A[i];
        s->next = L->next;
        L->next = s;
    }
}

//遍历链表
void Show_L(LinkList L)
{
    LinkList p;
    p = L->next;
    while(p)
    {
        cout<<p->data
            <<"\n";
        p = p->next;
    }
}

//获取链表长度
int ListLength_L(LinkList L)
{
    LinkList p;
    p = L->next;
    int k = 0;
    while(p)
    {
        k++;
        p = p->next;
    }
    return k;
}

//查找
int LocateElem_l(LinkList L, ElemType e)
{
    LinkList p;
    p = L->next;
    int index = 1;
    while (p && p->data != e)
    {
        p = p->next;
        index++;
    }
    if(p) return index;
    else return 0;
}
//增加链表
void ListInsert_L(LinkList &L, int i,ElemType e){
    int j;
    LinkList p, s;
    p = L;
    j = 0;
    while(p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if(!p || j > i - 1){
        cout<<"插入位置非法";
        return;
    }
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    cout<<"Success"<<endl;
}
//删除链表
void ListDelete_L(LinkList &L, int i, ElemType &e){
    LinkList p;
    int j;
    j = 0;
    p = L;
    while(p && j< i - 1){
        p = p->next;
        j++;
    }
    if(!p || !(p->next)){
        cout<<"删除地址非法";
        return;
    }
    LinkList q;
    q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
}
int main()
{
    LinkList L;
    ElemType A[3],B;
    B=2;
    //int a,index;
    for (int i = 0; i<=3; i++)
    {
        A[i] = i;
    }
    CreateList_L(L, A, 3);
    //Show_L(L);
    //a = ListLength_L(L);
    //cout<<a;
    //index = LocateElem_l(L, B);
    //cout<<index;
    ListDelete_L(L,3,B);
    Show_L(L);
    return 0;
}
