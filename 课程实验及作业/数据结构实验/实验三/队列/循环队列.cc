#include <iostream>
#define MAXSIZE 10010
#define endl '\n'
#define OK 1
#define ERROR 0
using namespace std;
typedef int QElemType;
typedef int Status;
//顺序结构实现的循环队列 存储表示
typedef struct{
    QElemType *base;
    int head;
    int rear;
}SqQueue;
//初始化队列
Status IniteQueue(SqQueue &Q){
    Q.base = new int[MAXSIZE];
    Q.head = Q.rear = 0;
    return OK;
}
//摧毁队列
Status DestroyQueue(SqQueue &Q){
    if(Q.base) delete[] Q.base; 
    return OK;
}
//清空队列
Status ClearQueue(SqQueue &Q){
    Q.head = Q.rear;
    return OK;
}
//判断队列是否为空
bool EmptyQueue(SqQueue Q){
    return Q.head == Q.rear;
}
//求队列的长度
int QueueLength(SqQueue Q){
    return (Q.rear - Q.head + MAXSIZE) % MAXSIZE;
}
//遍历队列元素
Status QueueTraverse(SqQueue Q){
    int k = Q.head;
    while(k != Q.rear){
        cout << Q.base[k] << ' ';
        k = (k + 1) % MAXSIZE;
    }
    cout << endl;
    return OK;
}
//获得队头元素
Status getHead(SqQueue Q,QElemType &e){
    e = Q.base[Q.head];
    return OK;
}
//入队
Status push(SqQueue &Q,QElemType e){
    //队列满
    if((Q.rear + 1) % MAXSIZE == Q.head) return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return OK;
}
//出队
Status pop(SqQueue &Q,QElemType &e){
    //队列为空
    if(Q.head == Q.rear) return ERROR;
    e = Q.base[Q.head];
    Q.head = (Q.head + 1) % MAXSIZE;
    return OK;
}
//创建队列
Status CreateQueue(SqQueue &Q,int n){
    cout << "请输入元素：";
    bool ok = true;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(!push(Q,x)) ok = false;
    }
    return ok;
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
    SqQueue Q;
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