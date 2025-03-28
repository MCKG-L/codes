#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
int s[10];
int a[100];
int min_n,l,r,ans;
void dfs(int x,int y){
    if(x == s[y]){
        min_n = min(min_n,max(l,r));
        return;
    }
    l += a[x];
    dfs(x+1,y);
    l -= a[x];//回溯

    r += a[x];
    dfs(x+1,y);
    r -= a[x];//回溯
}
int main()
{
    for(int i=0;i<4;i++) cin >> s[i];
    for(int i=0;i<4;i++){
        memset(a,0,sizeof(a));
        l = r = 0;
        min_n = INF;
        for(int j=0;j<s[i];j++) cin >> a[j];
        dfs(0,i);
        ans += min_n;
    }
    cout << ans;
    return 0;
}