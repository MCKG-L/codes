#include <bits/stdc++.h>
using namespace std;
/*
拆分Nim游戏：有n堆石子，每一次操作可以从现有的堆中拿走一堆（所有），然后放入
两堆新的石子，保证新堆的石子数目小于拿走的堆中石子数目。最后无法操作的人视为失败
*/
const int N = 110;
int f[N];
int sg(int x){
    if(f[x] != -1) return f[x];
    unordered_set<int> S;
    for(int i=0;i<x;i++){
        for(int j=0;j<=i;j++){
            S.insert(sg(i)^sg(j));
        }
    }
    //mex
    for(int i=0;;i++){
        if(!S.count(i)) return f[x] = i;
    }
}
int main()
{
    int n;cin >> n;
    memset(f,-1,sizeof f);
    int res = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        res  ^= sg(x);
    }
    if(res) puts("Yes");
    else puts("No");
    return 0;
}