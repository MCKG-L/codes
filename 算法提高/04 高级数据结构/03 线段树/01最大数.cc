#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int m,p;
struct Node{
    int l,r;
    int v;//最大值
}tr[N*4];
void pushup(int u){//由子节点信息计算父节点的信息
    tr[u].v = max(tr[u<<1].v,tr[u<<1|1].v);
}
//建立
void build(int u,int l,int r){
    tr[u].l = l,tr[u].r = r;
    if(l == r) return;
    int mid = l + r >> 1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    //pushup
}
//查询
int query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].v;
    int mid = tr[u].l + tr[u].r >> 1;
    int v = 0;
    if(l <= mid) v = query(u<<1,l,r);
    if(r > mid) v = max(v,query(u<<1|1,l,r));
    return v;
}
//修改
void modify(int u,int x,int v){
    if(tr[u].l == x && tr[u].r == x) tr[u].v = v;
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u<<1,x,v);
        else modify(u<<1|1,x,v);
        pushup(u);
    }
}
int main()
{
    int n = 0,a = 0;
    cin >> m >> p;
    build(1,1,m);
    while(m--){
        string op;int x;
        cin >> op >> x;
        if(op == "Q"){
            a = query(1,n-x+1,n);
            cout << a << endl;
        }else{
            modify(1,n+1,(a+x)%p);
            n ++;
        }
    }
    return 0;
}
