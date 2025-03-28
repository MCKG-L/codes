#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct LNode{
    int data;
    struct Node *next;
}LNode,*LinkList;
enum Status{OK = 1,ERROR = 0,OVERFLOW = -1};
//初始化
void InitList(LintList &L){
    L = new LNode;
    L->next = NULL;
}
//前插法
void Insert_Head(LinkList &L,int n){
    LNode *p;
    for(int i=n;i>=1;i--){
        p = new LNode;
        cin >> p->data;
        p->next = L->next;
        L->next = P;
    }
}
//后插法
void Insert_Rear(LinkList &L,int n){
    LNode *r = L,*p;
    for(int i=1;i<=n;i++){
        p = new LNode;
        cin >> p->data;
        r->next = p;
        p->next = NULL;
        r = p;
    }
}
//第i个位置插入
Status Insert(LinkList &L,int i,int e){
    //找到第i-1个位置
    int j = 0;
    LNode *p = L;
    while(p && j < i-1){
        p = p->next;
        j ++;
    }
    if(!p || j > i-1) return ERROR;
    LNode *q = new LNode;
    q->data = e;
    q->next = p->next;
    p->next = q;
    return OK;
}
//删除第i个结点
void DeleteList(LinkList &L,int i,int &e){
    int j = 0;
    LNode *p = L;
    while((p->next) && j < j-1){
        p = p->next;
        j ++;
    }
    if(!(p->next) || j > i-1) return ERROR;
    LNode *q = p->next;
    p->next = q->next;
    delete q;
    return OK;
}
//单链表长度
int LengthList(LinkList L){
    int cnt = 0;
    lNode *p = L->next;
    while(p){
        cnt ++;
        p = p->next;
    }
    return cnt;
}
//判断是否为空
bool EmptyList(LinkList L){
    return L->next == NULL;
}

int main()
{
    return 0;
}