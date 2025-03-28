#include <bits/stdc++.h>
using namespace std;
const int N = 12;
int a[N],b[N];
int n,ans = INT_MAX;
int s1=1,s2;
void dfs(int i){
    if(i == n + 1){
        return;
    }
    
    //加入
    s1 *= a[i];
    s2 += b[i];
    //更新答案
    ans = min(ans,abs(s1-s2));
    //回溯
    dfs(i+1);
    s1 /= a[i];
    s2 -= b[i];

    //不加入
    dfs(i+1);
}
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> b[i];
    }
    dfs(1);
    cout << ans;
    return 0;
}