#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n,m,a[N];
int process(int i,int j){
    if(j == 0) return 1;
    if(i == n + 1) return 0;
    int ans = 0;
    for(int k=0;k<=a[i] && j>=k;k++){
        ans += process(i+1,j-k);
    }
    return ans;
}
int solve(){
    return process(1,m);
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    cout << solve();
}