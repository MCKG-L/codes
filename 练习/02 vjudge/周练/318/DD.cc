/*
x代表元就是从x开始向后第一个满足A[x%N] == -1的位置
路径压缩后从x到x的代表元之间的所有数会直接指向其代表元(第一个满足A[x%N]==-1的位置)
进行一次t == 1后的操作后：A[(x的代表元)] = x(!=-1),则x的新的代表元
将和x原代表元位置的下一个元素的代表元相同，相当于两个集合合并(向后合并)
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1048576;
int p[N];
long long a[N];
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void merge(int a,int b){
    a = find(a);
    b = find(b);
    p[a] = b;
}
int main()
{
    memset(a,-1,sizeof(a));
    for(int i=0;i<N;i++) p[i] = i;
    int q;cin >> q;
    while(q--){
        long long x;int t;
        cin >> t >> x;
        int h = x % N;
        if(t == 1){
            h = find(h);
            a[h] = x;
            merge(h,(h+1)%N);
        }else{
            cout << a[h] << endl;
        }
    }
    return 0;
}