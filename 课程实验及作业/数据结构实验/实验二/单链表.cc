#include <iostream>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
enum Status{OK = 1,ERROR = 0,OVERFLOW = -1};
//初始化单链表
Status IniteList(LinkList &L){
    L = new LNode;
    L->next = NULL;
    return OK;
}
//前插法
Status CreateList_Head(LinkList &L,int n){
    // L = new LNode;
    // L->next = NULL;
    IniteList(L);
    LNode *p;
    cout << "请输入要插入的元素：";
    for(int i=n;i>0;i--){
        p = new LNode;
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
    return OK;
}
//后插法
Status CreateList_Rear(LinkList &L,int n){
    IniteList(L);
    LNode *r = L;
    LNode *p;
    cout << "请输入要插入的元素：";
    for(int i=1;i<=n;i++){
        p = new LNode;
        cin >> p->data;
        r->next = p;
        p->next = NULL;
        r = p;
    }
    return OK;
}
//摧毁单链表
Status DestroyList(LinkList &L){
    LNode *p;
    while(L){
        p = L;
        L = L->next;
        delete p;
    }
    return OK;
}
//清空单链表
Status ClearList(LinkList &L){
    LNode *p,*q;
    p = L->next;
    while(p){
        q = p->next;
        delete p;
        p = q;
    }
    L->next = NULL;
    return OK;
}
//求单链表长度
int ListLength(LinkList L){
    int cnt = 0;
    LNode *p = L->next;
    while(p){
        cnt ++;
        p = p->next;
    }
    return cnt;
}
//判断单链表是否为空
bool ListEmpty(LinkList L){
    return L->next == NULL;
}
//获取单链表指定位置元素
Status GetElem(LinkList &L,int i,int &e){
    LNode *p = L->next;
    int j = 1;
    while(p && j < i){
        p = p->next;
        j ++;
    }
    if(!p || j > i) return ERROR;
    e = p->data;
    return OK;
}
//求前驱
void Pre_List(LinkList L,int i){
    LNode *p = L->next;
    int j = 1;
    LNode *lst = p;
    while(p && j < i){
    	lst = p;
    	p = p->next;
    	j ++;
	}
	if(!p || j > i){
		cout << "位置不合法！" << endl;
	}else{
		if(lst == p){
			cout << "第一个位置不存在前驱！" << endl;
		}else{
			cout << "前驱为：" << ' ' << lst->data << endl;
 		}
	}
}
//求后继
void Next_List(LinkList L,int i){
	LNode *p = L->next;
	int j = 1;
	while(p && j < i){
		p = p->next;
		j ++;
	}
	if(!p || j > i) {
		cout << "位置不合法！" << endl;
	}else{
		if(p->next == NULL){
			cout << "最后一个位置不存在后继！" << endl;
 		}else{
 			cout << "后继为：" << ' ' << p->next->data << endl;
		 }
	}
}
//插入元素 在指定位置插入元素
Status InsertList(LinkList &L,int i,int e){
    LNode *p = L;
    int j = 0;
    //找到第i-1个位置
    while(p && j < i-1){
        p = p->next;
        j ++;
    }
    if(!p || j > i-1) return ERROR;
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}
//删除指定位置的节点
Status ListDelete(LinkList &L,int i){
    LNode *p = L;
    int j = 0;
    //需要保证第i个元素存在
    while((p->next) && j < i-1){
        p = p->next;
        j ++;
    }
    if(!(p->next) || j > i-1) return ERROR;
    LNode *q = p->next;
    p->next = q->next;
    delete q;
    return OK;
}

//定位元素
LNode* LocateElem(LinkList L,int e){
    LNode *p = L->next;
    while(p && (p ->data != e)) p = p->next;
    return p;
}

//输出单链表
Status show_list(LinkList L){
    LNode *p = L->next;
    while(p){
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
    return OK;
}
void show_help()
{
    cout << "******* Data Structure ******" << endl;
    cout << "1----清空单链表" << endl;
    cout << "2----判断单链表是否为空" << endl;
    cout << "3----求单链表长度" << endl;
    cout << "4----获取单链表指定元素位置" << endl;
    cout << "5----求前驱" << endl;
    cout << "6----求后继" << endl;
    cout << "7----在单链表指定位置插入元素" << endl;
    cout << "8----删除单链表指定位置元素" << endl;
    cout << "9----显示单链表" << endl;
    cout << "0----退出单链表" << endl;
    cout << "11---使用前插法创建单链表" << endl;
    cout << "12---使用后插法创建单链表" << endl;
}
int main()
{
    string op;//读取操作字符串
    show_help();
    /*定义线性表变量，如LinkList L;*/
    LinkList L;
    IniteList(L);
    cout << "请输入操作码: ";
    while(cin >> op)
    {
        if(op == "1"){
            ClearList(L);
            cout << "单链表已成功清空！" << endl;

        }else if(op == "2"){
            if(ListEmpty(L)){
                cout << "单链表为空！" << endl;
            }else{
                cout << "单链表非空！" << endl;
            }

        }else if(op == "3"){
            cout << "单链表的长度为：";
            cout << ListLength(L) << endl;
        }else if(op == "4"){
            cout << "请输入需要查询的位置：";
            int n;cin >> n;
            int e = 0;
            if(GetElem(L,n,e)){
                cout << "该位置元素为："  << e << endl;
            }else{
                cout << "位置不合法！" << endl;
            }
        }else if(op == "5"){
        	int i;
        	cout << "请输入位置：";
        	cin >> i;
            Pre_List(L,i);
        }else if(op == "6"){
			int i;
			cout << "请输入位置：";
			cin >> i;
			Next_List(L,i);
        }else if(op == "7"){
            cout << "请输入要插入的位置及元素值：";
            int i,e;cin >> i >> e;
            if(InsertList(L,i,e)){
                cout << "插入成功！" << endl;
            }else{
                cout << "插入位置不合法！" << endl;
            }
        }else if(op == "8"){
            cout << "请输入要删除的位置：";
            int i;cin >> i;
            if(ListDelete(L,i)){
                cout << "删除成功！" << endl;
            }else{
                cout << "删除的位置不合法！" << endl;
            }
        }else if(op == "9"){
            show_list(L);
        }else if(op == "11"){
            int n;
            cout << "请输入要插入的元素个数：";
            cin >> n;
            if(CreateList_Head(L,n)){
                cout << "使用前插法创建单链表成功！" << endl;
            }else{
                cout << "创建失败！" << endl;
            }
        }else if(op == "12"){
            int n;
            cout << "请输入要插入的元素个数：";
            cin >> n;
            if(CreateList_Rear(L,n)){
                cout << "使用后插法创建单链表成功！" << endl;
            }else{
                cout << "创建失败！" << endl;
            }
        }else if(op == "0"){
            cout << "成功退出！" << endl;
            break;
        }else{
            cout << "操作码错误！" << endl;
        }
        cout << "请输入操作码：";
    }
    DestroyList(L);
    return 0;
}