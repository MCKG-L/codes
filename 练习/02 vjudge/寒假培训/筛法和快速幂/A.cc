#include <bits/stdc++.h>
using namespace std;
const int N = 1e8+1;
int p[(N/100)*6];
bool st[N];
int cnt;
//线性筛 O(n)
void getprimes(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]) p[cnt++] = i;
        for(int j=0;p[j]<=n/i;j++){//j<=cnt可以不加
            st[p[j]*i] = 1;
            if(i % p[j] == 0) break;
        }
    }
}
void solve(){
    int n,q;
    cin >> n >> q;
    getprimes(n);
    while(q--){
        int k;
        cin >> k;
        cout << p[k-1] << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}