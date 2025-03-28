#include <iostream>
using namespace std;
typedef struct Node{
    int data;
    Node *next;
}Node;
/*
带头结点单链表  初始化时候创建了头节点 头节点没有数据域，只有指针域，指向下一个结点的地址
*/
//初始化单链表
Node *InitList(Node *L){
    L = new Node;
    L->next = NULL;
    return L;
}
//头插法
Node *HeadCreatList(Node *L,int n){
    
    for(int i=0;i<n;i++){
        int x;cin >> x;
        Node *p = new Node;//临时
        p->data = x;
        p->next = L->next;
        L->next = p;
    }
    return L;
}
//尾插法
Node *RearCreatList(Node *L,int n){
    Node *r = L->next;//r指针记录链表当前的尾结点
    for(int i=0;i<n;i++){
        int x;cin >> x;
        Node *p = new Node;
        p->data = x;
        p->next = NULL;
        r->next = p;
        r = p;
    }
    return L;
}
//输出链表
void PrintList(Node *L){
    Node *p = L->next;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int main()
{
    Node *L1,*L2;
    L1 = InitList(L1);
    L2 = InitList(L2);
    int n;
    //头插法插入
    cout << "输入要插入的结点个数：";cin >> n;
    L1 = HeadCreatList(L1,n);
    PrintList(L1);
    // 二次或多次调用不会覆盖原来的元素
    cout << "输入要插入的结点个数：";cin >> n;
    L1 = HeadCreatList(L1,n);
    PrintList(L1);
    //尾插法
    // cout << "输入要插入的结点个数：";cin >> n;
    // L1 = RearCreatList(L2,n);
    // PrintList(L2);
    //二次调用会覆盖原来的元素
    // cout << "输入要插入的结点个数：";cin >> n;
    // L1 = RearCreatList(L2,n);
    // PrintList(L2);
    return 0;
}