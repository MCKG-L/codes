#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int p[N],a[N];
int n,q;
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int func(int x){
    int res = 0;
    while(x){
        res += x % 10;
        x /= 10;
    }
    return res;
}
void solve(){
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        p[i] = i;
    }
    p[n+1] = n+1;
    while(q--){
        int op,l,r,x;
        cin >> op;
        if(op == 1){
            cin >> l >> r;
            for(int i=l;i<=r;i++){
                i = find(i);
                if(i > r) break;
                a[i] = func(a[i]);
                if(a[i] < 10) p[find(i)] = find(i+1);
            }
        }else{
            cin >> x;
            cout << a[x] << endl;
        }
    }
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}