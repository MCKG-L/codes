#include <iostream>
#define MAXSIZE 10010
#define OK 1
#define ERROR 0
#define Status int
using namespace std;
typedef int ElemType;
//队列的链式存储表示
//结点的存储表示
typedef struct QNode{
    int data;
    struct QNode *next;
}QNode,*QueuePtr;
//定义了头指针和尾指针
typedef struct{
    QueuePtr head;
    QueuePtr rear;
}LinkQueue;
//使用带有头节点的链表
//初始化队列
Status IniteQueue(LinkQueue &Q){
    Q.rear = new QNode;
    Q.head = Q.rear;
    Q.head ->next = NULL;
    return OK;
}
//摧毁队列
Status DestroyQueue(LinkQueue &Q){
    while(Q.head){
        Q.rear = Q.head->next;
        delete Q.head;
        Q.head = Q.rear;
    }
    return OK;
}
//清空队列
Status ClearQueue(LinkQueue &Q){
    Q.head->next = NULL;
    Q.rear = Q.head;
    return OK;
}
//判断队列是否为空
bool EmptyQueue(LinkQueue Q){
    return Q.head == Q.rear;
}
//求队列的长度
int QueueLength(LinkQueue Q){
    QNode *p = Q.head->next; //首元结点
    int cnt = 0;
    while(p){
        cnt ++;
        p = p->next;
    }
    return cnt;
}
//遍历队列
Status QueueTraverse(LinkQueue Q){
    QNode *p = Q.head->next;//首元结点
    while(p){
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
    return OK;
}
//获取队头元素
Status getHead(LinkQueue Q,ElemType &e){
    if(Q.head == Q.rear) return ERROR;
    e = Q.head->next->data;
    return OK;
}
//入队
Status push(LinkQueue &Q,ElemType e){
    QNode *p = new QNode;
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}
//出队
Status pop(LinkQueue &Q,ElemType &e){
    if(Q.head == Q.rear) return ERROR;
    QNode *p = Q.head->next;
    e = p->data;
    Q.head->next = p->next;
    //出队操作 可能会影响尾指针的位置
    if(Q.rear == p) Q.rear = Q.head;
    delete p;
    return OK;
}
//创建队列
Status CreateQueue(LinkQueue &Q,int n){
    cout << "请输入元素值：";
    for(int i=0;i<n;i++){
        int x;cin >> x;
        push(Q,x);
    }
    return OK;
}
void show_help()
{
    cout << "******* Data Structure ******" << endl;
    cout << "1----清空栈队列" << endl;
    cout << "2----判断队列是否为空" << endl;
    cout << "3----求队列长度" << endl;
    cout << "4----创建队列" << endl;
    cout << "5----插入元素" << endl;
    cout << "6----删除元素" << endl;
    cout << "7----取出队头元素" << endl;
    cout << "8----遍历队列元素" << endl;
    cout << "0----退出！" << endl;
}
int main()
{
    string op;//读取操作字符串
    show_help();
    /*定义线性表变量，如LinkList L;*/
    LinkQueue Q;
    IniteQueue(Q);
    cout << "请输入操作码: ";
    while(cin >> op)
    {
        if(op == "1"){
            if(ClearQueue(Q)){
                cout << "已成功清空！" << endl;
            }else{
                cout << "清空失败！" << endl;
            }

        }else if(op == "2"){
            if(EmptyQueue(Q)){
                cout << "队列为空！" << endl;
            }else{
                cout << "队列非空！" << endl;
            }
        }else if(op == "3"){
            cout << "队列的长度为：" << QueueLength(Q) << endl;
        }else if(op == "5"){
            cout << "请输入要插入的元素：";
            int x;
            cin >> x;
            if(push(Q,x)){
                cout << "插入成功！" << endl;
            }else{
                cout << "插入失败！" << endl;
            }
        }else if(op == "4"){
        	cout << "请输入要插入的元素个数：";
			int n;cin >> n;
			if(CreateQueue(Q,n)){
                cout << "创建成功！" << endl;
            }else{
                cout << "创建失败！" << endl;
            }
		}else if(op == "6"){
            int e;
            if(pop(Q,e)){
                cout << "删除成功！" << endl;
            }else{
                cout << "删除失败！" << endl;
            }
        }else if(op == "7"){
            int e;
            if(getHead(Q,e)){
                cout << "队头元素值为：" << e << endl;
            }else{
                cout << "队列为空！" << endl;
            }
        }else if(op == "0"){
            cout << "成功退出！" << endl;
            break;
        }else if(op == "8"){
        	if(QueueTraverse(Q)){
        		cout << "遍历结束！" << endl;
			}else{
				cout << "遍历失败！" << endl;
			}
		}else{
            cout << "操作码错误！" << endl;
        }
        cout << "请输入操作码：";
    }
    DestroyQueue(Q);
    return 0;
}