#include <iostream>
#define MAXSIZE 10010
using namespace std;
//1.定义存储表示
typedef struct{
    int *elem;
    int length;
}SqList;
void Init_List(SqList &L){
    L.elem = new int[MAXSIZE];
    L.length = 0;
}
//2.定义操作函数 清空线性表
void Clear_List(SqList &L){
    L.length = 0;
}
//3.定义操作函数 判断是否为空
bool Empty_List(SqList &L){
    if(L.length) return false;
   	return true;
}

//4.定义操作函数 获取顺序表的长度
int Length_List(SqList &L){
    return L.length;
}
//指定元素的位置
int Locate_List(SqList &L,int x){
    for(int i=0;i<L.length;i++){
        if(L.elem[i] == x) return i + 1;
    }
    return -1;
}
//插入指定元素
/*
合法的插入：插入位置在已有的顺序表之内 并且插入后没有达到最大内存
*/
bool Insert_List(SqList &L,int pos,int x){
    //插入位置不合法
    if(pos <= 0 || pos > L.length + 1){
        return false;
    }
    //内存已满
    if(L.length == MAXSIZE) return false;
    //插入元素
    for(int i=L.length-1;i>=pos-1;i--){
        L.elem[i+1] = L.elem[i];
    }
    L.elem[pos-1] = x;
    L.length ++;
    return true;
}

//求前驱 ok: 0-->为第一个元素 1-->元素不存在 2-->存在结果
int Pre_List(SqList &L,int x,int &ok){
    int pos = -1;
    for(int i=0;i<L.length;i++){
        if(L.elem[i] == x){
            pos = i;
            ok = 2;
            break;
        }
    }
    if(pos == -1) ok = 1;//不存在该元素
    if(pos == 0){
        ok = 0;
    }
    if(pos != -1 && pos) return L.elem[pos-1];
    return 0;
}
//后驱
int Suc_List(SqList &L,int x,int &ok){
    int pos = -1;
    for(int i=0;i<L.length;i++){
        if(L.elem[i] == x){
            pos = i;
            ok = 2;
            break;
        }
    }
    if(pos == -1) ok = 1;//不存在该元素
    if(pos == L.length-1){
        ok = 0;
    }
    if(pos != -1 && pos+1 < L.length) return L.elem[pos+1];
    return -1;
}
//删除指定位置元素
void Delete_List(SqList &L,int pos){
    if(pos <= 0 || pos > L.length){
        cout << "位置有误！" << endl;
        return;
    }
    //从前往后删除元素
    for(int i=pos-1;i<L.length-1;i++){
        L.elem[i] = L.elem[i+1];
    }
    L.length --;
    cout << "删除成功" << endl;
}
//摧毁顺序表
void Destroy_List(SqList &L){
    if(L.elem) delete[] L.elem;
    L.elem = NULL;
    L.length = 0;
}
void show_help()
{
    cout << "******* Data Structure ******" << endl;
    cout << "1----清空线性表" << endl;
    cout << "2----判断线性表是否为空" << endl;
    cout << "3----求线性表长度" << endl;
    cout << "4----获取线性表指定元素位置" << endl;
    cout << "5----求前驱" << endl;
    cout << "6----求后继" << endl;
    cout << "7----在线性表指定位置插入元素" << endl;
    cout << "8----删除线性表指定位置元素" << endl;
    cout << "9----显示线性表" << endl;
    cout << "0----退出线性表" << endl;

}
int main()
{
    string op;//读取操作字符串
    show_help();
    /*定义线性表变量，如SqList L;*/
    SqList L;
    Init_List(L);
    //调用初始化线性表函数，如Init_List(L);
    cout << "请输入操作码: ";
    while(cin >> op)
    {
//    	system("cls");
//    	cout << "操作反馈：" << endl;
        if(op.size() != 1 || !isdigit(op.front())){
            cout << "操作码错误，请输入0~9的整数！" << endl;
            continue;
        }
        char operate_code = op[0];
        // cin>>operate_code;
        if(operate_code == '1')
        {
            //调用操作函数1
            Clear_List(L);
            cout << "已成功清空！" << endl;
        }
        else if (operate_code == '2')
        {
            if(Empty_List(L)){
                cout << "线性表为空！" << endl;
            }else{
                cout << "线性表非空！" << endl;
            }
        }
        else if (operate_code == '3')
        {
            cout << "线性表的长度为：";
            cout << Length_List(L) << endl;
        }
        else if (operate_code == '4')
        {
        	cout << "请输入要查找的元素值：";
            int x;cin >> x;
            int pos = Locate_List(L,x);
            if(pos != -1){
                cout << "位置为：" << pos << endl;
            }else{
                cout << "不存在" << endl;
            }
        }
        else if (operate_code == '5')
        {
            int ok;
            cout << "请输入元素：" << endl;
            int x;cin >> x;
            int res = Pre_List(L,x,ok);
            if(ok == 0){
                cout << "第一个元素不存在前驱！" << endl;
            }else if(ok == 1){
                cout << "该元素不存在！" << endl;
            }else{
                cout << "前驱为：" << res << endl;
            }
        }
        else if (operate_code == '6')
        {
            int ok;
            cout << "请输入元素：" << endl;
            int x;cin >> x;
            int res = Suc_List(L,x,ok);
            if(ok == 0){
                cout << "最后一个元素不存在后驱！" << endl;
            }else if(ok == 1){
                cout << "该元素不存在！" << endl;
            }else{
                cout << "后驱为：" << res << endl;
            }
        }
        else if (operate_code == '7')
        {
            cout << "请输入要插入的元素个数：" << endl;
            int n;cin >> n;
            int pos,x;
            bool is_ok = true;
            cout << "请输入要插入的位置和元素值：" << endl;
            for(int i=0;i<n;i++){
                cin >> pos >> x;
                if(!Insert_List(L,pos,x)){
                    cout << "插入值(" << pos << ',' << x << ")不合法！" << endl;
                    is_ok = false;
                }else{
                	cout << "(" << pos << ',' << x << ")成功插入！" << endl;
				}
            }
            if(is_ok){
                cout << "已经全部成功插入！" << endl;
            }else{
                cout << "插入结束！" << endl;
            }
        }
        else if (operate_code == '8')
        {
            cout << "请输入要删除的位置：" << endl;
            int pos;cin >> pos;
            Delete_List(L,pos);
        }
        else if (operate_code == '9')
        {
        	if(L.length == 0){
        		cout << "线性表为空！" << endl;
        		continue;
			}
            for(int i=0;i<L.length;i++){
                cout << L.elem[i] << ' ';
            }
            cout << endl;
        }
        else if (operate_code == '0')
        {
        	cout << "成功退出！" << endl;
            break;
        }
        cout << "请输入操作码: ";
    }
    //调用销毁线性表函数，如Destroy_List(L);
    Destroy_List(L);
    return 0;
}
