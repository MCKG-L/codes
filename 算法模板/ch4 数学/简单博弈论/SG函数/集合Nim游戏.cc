#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
using namespace std;
/*
集合-Nim游戏：限制了每次取出的数量，在一个集合中
对于每一堆石子，都可以构建一个表示状态的有向图，求出SG(s)
分别求出每一堆对应的SG(s)
求SG(s)的异或和，若异或和为0，则必败，否则必胜
*/
const int N = 110,M = 10010;
int n,m;
int s[N],f[M];
int sg(int x){
    if(f[x] != -1) return f[x];
    unordered_set<int> S;
    for(int i=0;i<m;i++){
        int sum = s[i];
        if(x >= sum) S.insert(sg(x-sum));
    }
    for(int i=0;;i++){
        if(!S.count(i)){
            return f[x] = i;
        }
    }
}
int main()
{
    cin >> m;
    for(int i=0;i<m;i++) cin >> s[i];
    cin >> n;
    memset(f,-1,sizeof f);
    int ans = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        ans ^= sg(x);
    }
    if(ans) puts("Yes");
    else puts("No");
    return 0;
}