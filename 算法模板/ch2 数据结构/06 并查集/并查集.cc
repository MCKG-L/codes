/*
并查集作用：
1、将两个集合合并
2、询问两个元素是否在一个集合中

基本原理：
每一个集合用树来表示，集合编号为根节点的编号
存储每一个结点的父节点,也称为代表元

1、判断树根 p[x] == x ? 
2、求x的集合编号：while(p[x] != x) x = p[x];
3、合并两个集合 将两个树的根节点连接起来 px是x的集合编号 py是y的集合编号 -> p[x] = y;

优化：
路径压缩优化 在某一个求x集合编号的过程中，把路径上的所有结点直接指向根节点，以后查询复杂度为O(1);

*/
#include <iostream>
using namespace std;
const int N = 100010;
int p[N];
int n,m;
//返回x所属的根节点 + 路径压缩
int find(int x){
    //递归 路径压缩
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    cin >> n >> m;
    for(int i=0;i<=n;i++){
        p[i] = i;
    }
    while(m--){
        char op[2];//读入字符串 会过滤空格换行
        int a,b;
        cin >> op >> a >> b;
        if(op[0] == 'M') p[find(a)] = find(b);//集合合并
        else{//判断两个数是否属于同一个集合
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}