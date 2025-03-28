#include <iostream>
using namespace std;
/*
使用数组模拟链表
*/
//单链表
const int N = 100010;
// int head,e[N],ne[N],idx;//head->头节点
int head,e[N],ne[N],idx;
//初始化
void init(){
    head = -1;
    idx = 0;
}
//头插法
void add_head(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}
//插到下标为k的后面
void add(int k,int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}
//删除操作 删除下标为k的后面的结点
void remove(int k){
    ne[k] = ne[ne[k]];
}
//
int main()
{
    // int m;cin >> m;
    // init();
    // while(m--){
    //     char op;int k,x;
    //     cin >> op;
    //     if(op == 'H'){
    //         cin >> x;
    //         add_head(x);
    //     }else if(op == 'D'){
    //         cin >> k;
    //         if(k == 0) head = ne[head];
    //         else remove(k-1);
    //     }else{
    //         cin >> k >> x;
    //         add(k-1,x);
    //     }
    // }
    // for(int i=head;i != -1;i = ne[i]){
    //     cout << e[i] << " ";
    // }
    init();
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        add_head(x);
    }
    for(int i=head;i != -1;i = ne[i]){
        cout << e[i] << " ";
    }
    return 0;
}