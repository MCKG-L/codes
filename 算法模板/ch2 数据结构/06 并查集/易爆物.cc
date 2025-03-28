#include <iostream>
using namespace std;
/*
入门经典上的一道题：
假定有一些只由两种元素组成的化合物需要装车
爆炸条件：如果车上存在K个化合物（车上的总的化合物>=K）并且刚好由K中元素组成，则会爆炸
如果某种化合物装车后会导致爆炸，则应该拒绝装车，求拒绝装车的化合物数目

考查并查集 将每一种元素最为一个集合的代表元
如果一个化合物的两个组成元素a b同时属于一个集合，则一定存在爆炸的条件，拒绝装车
否则不会导致爆炸，可以装车，a b 所属集合合并
*/
const int N = 1e5 + 10;
int p[N];
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void unite(int a,int b){
    if(find(a) != find(b)) p[find(a)] = find(b);
}
int main()
{
    for(int i=0;i<=N;i++) p[i] = i;
    int n;//n个化合物待装车
    cin >> n;
    int ans = 0;
    for(int i=0;i<n;i++){
        int a,b;cin >> a >> b;
        if(find(a) == find(b)) ans ++;
        else unite(a,b);
    }
    cout << ans << endl;
    return 0;
}