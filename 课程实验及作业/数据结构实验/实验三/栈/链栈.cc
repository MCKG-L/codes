#include <iostream>
#define MAXSIZE 10010
#define OK 1
#define ERROR 0
#define Status int
using namespace std;
//链栈没有必要使用头节点 栈顶指针就是栈的头指针
typedef struct StackNode{
    int data;
    struct StackNode *next;
}StackNode,*LinkStack;
//初始化栈
Status IniteStack(LinkStack &S){
    S = NULL;
    return OK;
}
//创建栈
Status CreateStack(LinkStack &S,int n){
	//if(!IniteStack(S)) return ERROR;
	cout << "请输入要插入的元素：";
	StackNode *p;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        p = new StackNode;
        p->data = x;
        p->next = S;
        S = p;
    }
	return OK;
}
//判断栈是否为空
bool EmptyStack(LinkStack S){
    return S == NULL;
}
//求栈的长度
int StackLength(LinkStack S){
    int res = 0;
    while(S){
        res ++;
        S = S->next;
    }
    return res;
}
//清空栈
Status ClearStack(LinkStack &S){
    S = NULL;
    return OK;
}
//摧毁栈
Status DestroyStack(LinkStack &S){
    StackNode *p;
    while(S){
        p = S;
        S = S->next;
        delete p;
    }
    S = NULL;
}
//入栈
Status Push(LinkStack &S,int e){
    StackNode *p = new StackNode;
    p->data = e;
    p->next = S;
    S = p;
    return OK;
}
//出栈
Status Pop(LinkStack &S,int &e){
    if(S == NULL){
        cout << "栈为空！" << endl;
        return ERROR;
    }
    StackNode *p;
    e = S->data;
    p = S;
    S = S->next;
    delete p;
    return OK;
}
//取出栈顶元素
Status getTop(LinkStack S,int &e){
    if(S == NULL){
        return ERROR;
    }
    e = S->data;
    return OK;
}
void show_help()
{
    cout << "******* Data Structure ******" << endl;
    cout << "1----清空栈" << endl;
    cout << "2----判断栈是否为空" << endl;
    cout << "3----求栈长度" << endl;
    cout << "4----创建栈" << endl;
    cout << "5----插入元素" << endl;
    cout << "6----删除元素" << endl;
    cout << "7----取出栈顶元素" << endl;
    cout << "0----退出！" << endl;
}
int main()
{
    string op;//读取操作字符串
    show_help();
    /*定义线性表变量，如LinkList L;*/
    LinkStack S;
    IniteStack(S);
    cout << "请输入操作码: ";
    while(cin >> op)
    {
        if(op == "1"){
            if(ClearStack(S)){
                cout << "已成功清空！" << endl;
            }else{
                cout << "清空失败！" << endl;
            }

        }else if(op == "2"){
            if(EmptyStack(S)){
                cout << "栈为空！" << endl;
            }else{
                cout << "栈非空！" << endl;
            }
        }else if(op == "3"){
            cout << "栈的长度为：" << StackLength(S) << endl;
        }else if(op == "5"){
            cout << "请输入要插入的元素：";
            int x;
            cin >> x;
            if(Push(S,x)){
                cout << "插入成功！" << endl;
            }else{
                cout << "插入失败！" << endl;
            }
        }else if(op == "4"){
        	cout << "请输入要插入的元素个数：";
			int n;cin >> n;
			if(CreateStack(S,n)){
				cout << "创建成功！" << endl;
			}else{
				cout << "创建失败！" << endl;
			}
		}else if(op == "6"){
            int e;
            if(Pop(S,e)){
                cout << "删除成功！" << endl;
            }else{
                cout << "删除失败！" << endl;
            }
        }else if(op == "7"){
            int e;
            if(getTop(S,e)){
                cout << "栈顶元素值为：" << e << endl;
            }else{
                cout << "栈为空！" << endl;
            }
        }else if(op == "0"){
            cout << "成功退出！" << endl;
            break;
        }else{
            cout << "操作码错误！" << endl;
        }
        cout << "请输入操作码：";
    }
    DestroyStack(S);
    return 0;
}