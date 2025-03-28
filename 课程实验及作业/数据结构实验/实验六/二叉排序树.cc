#include <iostream>
#define endl '\n'
#define KeyType int
#define MAXSIZE 110
using namespace std;
//存储表示
typedef struct {
    int data;
}InfoType;
typedef struct{
    KeyType key;
    InfoType data;
}ElemType;
//顺序存储表示
typedef struct{
    ElemType R[MAXSIZE];
    int length;
}SSTable;
//链式存储表示
typedef struct BSTNode{
    ElemType data;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;
//创建顺序表
void CreatST(SSTable &ST,int n){
    cout << "请输入元素的关键字：" << endl;
    for(int i=0;i<n;i++){
        ElemType e;cin >> e.key;
        ST.R[i + 1] = e;ST.length ++;
    }
}
//顺序表的二分查找
int search_Bin(SSTable ST,KeyType key,int &cnt){
    int low = 1,high = ST.length;
    while(low <= high){
        int mid = (low + high) / 2;
        cnt ++;
        if(key == ST.R[mid].key) return mid;
        else if(key < ST.R[mid].key) high = mid - 1;
        else low = mid + 1;
    }
    return 0;
}
//初始化顺序表
void IniteST(SSTable &ST){
    ST.length = 0;
}
//初始化二叉排序树
void IniteBST(BSTree &T){
    T = NULL;
}
//二叉排序树的查找算法
BSTree SearchBST(BSTree T,KeyType key,int &cnt){
    cnt ++;
    if(!T || key == T->data.key){
        return T;
    }
    if(key < T->data.key) return SearchBST(T->lchild,key,cnt);
    else return SearchBST(T->rchild,key,cnt);
}
//在二叉排序树中插入值
void InsertBST(BSTree &T,ElemType e){
    if(!T){
        BSTNode *s = new BSTNode;
        s->data = e;
        s->lchild = s->rchild = NULL;
        T = s;
    }else if(e.key < T->data.key){
        InsertBST(T->lchild,e);
    }else{
        InsertBST(T->rchild,e);
    }
}
//创建二叉排序树
void CreatBST(BSTree &T,int n){
    cout << "请输入要插入的元素的关键字：" << endl;
    for (int i=0;i<n;i++){
        ElemType e;cin >> e.key;
        InsertBST(T,e);
    }
}
//快速排序
int Partition(SSTable &L,int low,int high){
    L.R[0] = L.R[low];
    int prvotkey = L.R[low].key;
    while(low < high){
        while(low < high && L.R[high].key >= prvotkey) high --;
        L.R[low] = L.R[high];
        while(low < high && L.R[low].key <= prvotkey) low ++;
        L.R[high] = L.R[low];
    }
    L.R[low] = L.R[0];
    return low;
}
void QSort(SSTable &L,int low,int high){
    if(low < high){
        int pivotloc = Partition(L,low,high);
        QSort(L,low,pivotloc-1);
        QSort(L,pivotloc+1,high);
    }
}
void QuickSort(SSTable &L){
    QSort(L,1,L.length);
}
void print(SSTable L){
    for(int i=1;i<=L.length;i++){
        cout << L.R[i].key << ' ';
    }
    cout << endl;
}
//归并排序
void Merge(ElemType R[],ElemType T[],int low,int mid,int high){
    int i = low,j = mid + 1,k = low;
    while(i <= mid && j <= high){
        if(R[i].key <= R[j].key) T[k++] = R[i++];
        else T[k++] = R[j++];
    }
    while(i <= mid) T[k++] = R[i++];
    while(j <= high) T[k++] = R[j++];
}
void MSort(ElemType R[],ElemType T[],int low,int high){
    if(low == high) T[low] = R[low];
    else{
        ElemType S[MAXSIZE];
        int mid = (low + high) / 2;
        MSort(R,S,low,mid);
        MSort(R,S,mid+1,high);
        Merge(S,T,low,mid,high);
    }
}
void MergeSort(SSTable &L){
    MSort(L.R,L.R,1,L.length);
}
void show_help()
{
    cout << "******* Data Structure ******" << endl;
    cout << "1----创建顺序表" << endl;
    cout << "2----顺序表的折半查找" << endl;
    cout << "3----创建二叉排序树" << endl;
    cout << "4----二叉排序树的查找" << endl;
    cout << "5----使用快速排序算法对顺序表进行排序" << endl;
    cout << "6----使用归并排序算法对顺序表进行排序" << endl;
    cout << "0----退出" << endl;
}
int main()
{
    string op;//读取操作字符串
    show_help();
    BSTree T;
    SSTable ST;
    IniteBST(T);
    IniteST(ST);
    cout << "请输入操作码: ";
    while(cin >> op)
    {
        if(op == "1"){
            IniteST(ST);
            cout << "请输入要插入的元素个数：";
            int n;cin >> n;
            CreatST(ST,n);
            cout << "插入成功！" << endl;
        }else if(op == "2"){
            int key,cnt = 0;
            cout << "请输入要查找的元素值：";
            cin >> key;
            int pos = search_Bin(ST,key,cnt);
            if(pos == 0){
                cout << "查找失败！查找次数为：" << cnt << endl;
            }else{
                cout << "查找成功！查找次数为：" << cnt << endl;
                cout << key << " 的位置为: " << pos << endl;
            }
        }else if(op == "3"){
            IniteBST(T);
            cout << "请输入要插入的元素个数：";
            int n;cin >> n;
            CreatBST(T,n);
            cout << "插入成功！" << endl;
        }else if(op == "4"){
            int key,cnt = 0;
            cout << "请输入要查找的元素值：";
            cin >> key;
            BSTNode *res = SearchBST(T,key,cnt);
            if(!res){
                cout << "查找失败！查找次数为：" << cnt << endl;
            }else{
                cout << "查找成功！查找次数为：" << cnt << endl;
            }
        }else if(op == "5"){
            cout << "排序前：";
            print(ST);
            QuickSort(ST);
            cout << "排序后：";
            print(ST);
        }else if(op == "6"){
            cout << "排序前：";
            print(ST);
            MergeSort(ST);
            cout << "排序后：";
            print(ST);
        }else if(op == "0"){
            cout << "退出成功！" << endl;
            break;
        }else{
            cout << "操作码错误！请重新输入！" << endl;
        }
        cout << "请输入操作码：";
    }
    return 0;
}