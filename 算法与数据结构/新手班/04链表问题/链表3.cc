#include <bits/stdc++.h>
using namespace std;
//定义结点结构
template <class T>
struct Node{
    T data;
    Node<T> *next;
};
/*
1、生成结点：Node<T> *p = new Node<T>
2、为结点赋值：
p->data = 12;
p->next = (其他结点的地址)
3、释放结点：delete p;
*/
template<class T>
class LinkList{
public:
    LinkList();
    LinkList(T a[],int n);//头插法构造
    LinkList(int n,T a[]);//尾插法构造
    int Length();
    void Print();
    // T Get(int i);//查找
    Node<T>* Get(int i);
    int Locate(T);//定位
    void Insert(T,int);//插入
    void InsertAfter(Node<T> *p,T x);
    void InsertBefore(Node<T> *p,T x);
    T Delete(int);//删除
    T Delete(Node<T> *p);
    ~LinkList();//析构
private:
    Node<T> *first;//头节点 数据域为空 指向第一个结点(首结点)
};
//构造函数
//空链表
template<class T>
LinkList<T>::LinkList(){
    first = new Node<T>;
    first->next = NULL;
}

//头插法构造函数
template<class T>
LinkList<T>::LinkList(T a[],int n){
    first = new Node<T>;
    first->next = NULL;
    for(int i=0;i<n;i++){
        Node<T> *p = new Node<T>;//生成新结点
        p->data = a[i];
        p->next = first->next;
        first->next = p;
    }
}
// //尾插法配套函数
// template<class T>
// Node<T> *RearInsert(Node<T> *first,T a[],int n){
//     Node<T> *r = first->next;
//     for(int i=0;i<n;i++){
//         Node<T> *p = new Node<T>;
//         p->data = a[i];
//         p->next = NULL;
//         r->next = p;
//         r = p;
//     }
//     return first;
// }

//尾插法构造函数
template<class T>
LinkList<T>::LinkList(int n,T a[]){
    Node<T> *first = new Node<T>;
    Node<T> *r = first;//尾节点
    for(int i=0;i<n;i++){
        Node<T> *s = new Node<T>;
        s->data = a[i];
        // s->next = NULL;
        r->next = s;
        r = s;//尾指针后移
    }
    r->next = NULL;

    // Node<T> *first = new Node<T>;
    // // Node<T> *r;
    // Node<T> *h = new Node<T>;
    // h->data = a[0];
    // first->next = h;
    // // r = h;
    // for(int i=1;i<n;i++){
    //     Node<T> *p = new Node<T>;
    //     p->data = a[i];
    //     // r->next = p;
    //     // r = p;
    //     p->next = NULL;
    //     h->next = p;
    // }
    // // r->next = NULL;

    // Node<T> *first = new Node<T>;
    // first->next = NULL;
    // first = RearInsert(first,a,n);
}
//打印函数
template<class T>
void LinkList<T>::Print(){
    Node<T> *p = first->next;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
//析构函数
template<class T>
LinkList<T>::~LinkList(){
    while(first != NULL){
        Node<T> *p = first;//定义一个指针，没有申请内存空间，单纯的是一个指针变量，4字节
        first = first->next;
        delete p;
    }
}
//成员函数
//定位函数
template<class T>
int LinkList<T>::Locate(T x){//返回结点序号
    Node<T> *p = first->next;
    int j = 1;
    while(p != NULL){
        if(p->data == x) return j;
        p = p->next;
        j++;
    }
    return -1;
}
//获取结点函数
template<class T>
Node<T> *LinkList<T>::Get(int i){
    //返回地址
    Node<T> *p = first->next;
    int j= 1;
    while(p != NULL && j < i){
        p = p->next;
        j++;
    }
    if(i < 1) return NULL;
    return p;
}
// template<class T>
// T LinkList<T>::Get(int i){
//     Node<T> *p = first->next;
//     int j = 1;
//     while(j < i && p != NULL){
//         p = p->next;
//         j++;
//     }
//     if(p == NULL || i < 1) cout << "位置非法" << endl;
//     return p->data;
// }
//插入函数
template<class T>
void LinkList<T>::Insert(T x,int i){
    //找到编号为i-1的结点
    Node<T> *p = first;
    int j = 0;
    while(p != NULL && j != i-1){
        p = p->next;
        j++;
    }
    if(p == NULL) throw "插入位置非法";
    else{
        Node<T> *s = new Node<T>;
        s->data = x;
        s->next = p->next;
        p->next = s;
    }
}
template<class T>
void LinkList<T>::InsertAfter(Node<T> *p,T x){
    Node<T> *s = new Node<T>;
    s->data = x;
    s->next = p->next;
    p->next = s;
}
template<class T>
void LinkList<T>::InsertBefore(Node<T> *p,T x){
    //O(N)
    // Node<T> *q = first;
    // while(q->next != p) q = q->next;
    // InsertAfter(q,x);

    //O(1)
    Node<T> *s = new Node<T>;
    *s = *p;
    p->next = s;
    p->data = x;
}

//删除函数
template<class T>
T LinkList<T>::Delete(int i){
    //找到编号i-1的结点
    Node<T> *p = first;
    int j = 0;
    while(p->next != NULL && j != i-1){
        p = p->next;
        j++;
    }
    if(p->next == NULL) throw "删除位置非法";
    else{
        Node<T> *q = p->next;
        p->next = q->next;
        delete q;
    }
}
template<class T>
T LinkList<T>::Delete(Node<T> *p){
    if(p->next != NULL){
        // T x = p->data;
        p->data = p->next->data;
        Node<T> *q = p->next;
        p->next = q->next;
        delete q;
    }else{
        //找到前一个结点
        Node<T> *s = first;
        while(s->next != p) s = s->next;
        Node<T> *q = s->next;
        s->next = NULL;
        delete q;//可以对指向NULL的指针使用delete
    }
}
//获取结点个数
template<class T>
int LinkList<T>::Length(){
    Node<T> *p = first;
    int cnt = 1;
    while(p->next != NULL){
        cnt++;
        p = p->next;
    }
    return cnt;
}
int main()
{
    int n;cin >> n;
    int a[n] = {};
    for(int i=0;i<n;i++) cin >> a[i];
    LinkList L1(a,n);//头插法
    // LinkList L1(n,a);//尾插法 有问题！！！
    cout << L1.Length() << endl;
    L1.Print();
    L1.Insert(3,2);
    L1.Print();
    return 0;

}