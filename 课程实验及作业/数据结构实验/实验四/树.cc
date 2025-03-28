#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#define endl '\n'
using namespace std;
using ll = long long;
typedef pair<int,int> PII;
typedef int ElemType;
enum {OK = 1,ERROR = 0,OVERFLOW = -1};
//存储表示
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//使用先序遍历的顺序创建二叉树
//ABC##DE#G##F###
bool CreateBiTree(BiTree &T){
    char ch;
    cin >> ch;
    if(ch == '#'){
        T = NULL;
    }else{
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}
//二叉树的先序遍历
void PreOrderTraverse(BiTree T){
    if(T == NULL) return;
    cout << (char)T->data << ' ';
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}
//二叉树的中序遍历  
void InOrderTraverse(BiTree T){
    if(T == NULL) return;
    InOrderTraverse(T->lchild);
    cout << (char)T->data << ' ';
    InOrderTraverse(T->rchild);
}
//二叉树的后序遍历
void PostOrderTraverse(BiTree T){
    if(T == NULL) return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    cout << (char)T->data << ' ';
}
//二叉树的层序遍历
void LayerOrderedTraverse(BiTree T){
    //使用队列存储结点 实现层先遍历
    queue<BiTNode*> q;
    q.push(T);
    while(q.size()){
        BiTNode *p = q.front();
        q.pop();
        cout << (char)p->data << ' ';
        if(p->lchild) q.push(p->lchild);
        if(p->rchild) q.push(p->rchild);
    }
}
//求二叉树的深度
int Depth(BiTree T){
    if(T == NULL) return 0;
    return max(Depth(T->lchild),Depth(T->rchild)) + 1;
}
//非递归算法实现中序遍历
void InOrderTraverse1(BiTree T){
    stack<BiTNode *> stk;
    BiTNode *p = T;
    while(p || stk.size()){
        if(p){
            stk.push(p);
            p = p->lchild;
        }else{
            //访问根节点
            BiTNode *q = stk.top();
            stk.pop();
            cout << (char)q->data << ' ';
            //遍历右子节点
            p = q->rchild;
        }
    }
}
//非递归算法实现先序遍历
void PreOrderTraverse1(BiTree T){
    stack<BiTNode *> stk;
    BiTNode *p = T;
    while(p || stk.size()){
        if(p){
            stk.push(p);
            cout << (char)p->data << ' ';
            p = p->lchild;
        }else{
            // BiTNode *q = stk.top();
            // stk.pop();
            p = stk.top()->rchild;
            stk.pop();
        }
    }
}
//非递归算法实现后序遍历
void PostOrderTraverse1(BiTree T){
    stack<BiTNode *> stk;
    BiTNode *p = T,*r = NULL;
    while(p || stk.size()){
        if(p){
            stk.push(p);
            p = p->lchild;
        }else{
            BiTNode *q = stk.top();
            //如果存在右子节点且未被访问
            if(q->rchild && q->rchild != r){
                stk.push(q->rchild);
                p = q->rchild->lchild;
            }else{ //右儿子为空或者已经被访问过
                //出栈
                BiTNode *q = stk.top();stk.pop();
                cout << (char)q->data << ' ';
                r = q;
            }
        }
    }
}
void show_help()
{
    cout << "******* Data Structure ******" << endl;
    cout << "1----使用先序遍历创建二叉树" << endl;
    cout << "2----先序遍历二叉树（递归实现）" << endl;
    cout << "3----中序遍历二叉树（递归实现）" << endl;
    cout << "4----后序遍历二叉树（递归实现）" << endl;
    cout << "5----层序遍历二叉树" << endl;
    cout << "6----先序遍历二叉树（非递归实现）" << endl;
    cout << "7----中序遍历二叉树（非递归实现）" << endl;
    cout << "8----后序遍历二叉树（非递归实现）" << endl;
    cout << "9----求二叉树的深度" << endl;
    cout << "0----退出" << endl;
}
int main()
{
    show_help();
    string op;
    BiTree T;
    cout << "请输入操作码：";
    while(cin >> op)
    {
        if(op == "1"){
            cout << "请输入先序结果：";
            if(CreateBiTree(T)){
                cout << "创建成功！" << endl;
            }else{
                cout << "创建失败！" << endl;
            }
        }else if(op == "2"){
            cout << "先序遍历的结果为：";
            PreOrderTraverse(T);
            cout << endl;
        }else if(op == "3"){
            cout << "中序遍历的结果为：";
            InOrderTraverse(T);
            cout << endl;
        }else if(op == "4"){
            cout << "后序遍历的结果为：";
            PostOrderTraverse(T);
            cout << endl;
        }else if(op == "5"){
            cout << "层序遍历的结果为：";
            LayerOrderedTraverse(T);
            cout << endl;
        }else if(op == "6"){
            cout << "先序遍历（非递归）的结果为：";
            PreOrderTraverse1(T);
            cout << endl;
        }else if(op == "7"){
            cout << "中序遍历（非递归）的结果为：";
            InOrderTraverse1(T);
            cout << endl;
        }else if(op == "8"){
            cout << "后序遍历（非递归）的结果为：";
            PostOrderTraverse1(T);
            cout << endl;
        }else if(op == "9"){
            cout << "二叉树的深度为：" << Depth(T) << endl;
        }else if(op == "0"){
            cout << "成功退出！" << endl;
            break;
        }else{
            cout << "操作码错误！" << endl;
        }
        cout << "请输入操作码：";
    }
    return 0;
}