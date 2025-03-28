#include <bits/stdc++.h>
using namespace std;
bool check(int a[],int n,int m,int x){
    int cs = 0,cnt = 0;
    for(int i=1;i<=n+1;i++){
        if(a[i]-cs < x){
            cnt++;
        }else{
            cs = a[i];
        }
    }
    if(cnt > m) return false;
    return true;
}
void solve(){
    int l,n,m;
    cin >> l >> n >> m;
    int a[n+2] = {};
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    a[n + 1] = l;
    int ll = 0,rr = l;
    int ans = 0;
    while(ll <= rr){
        int mid = (ll + rr) / 2;
        if(check(a,n,m,mid)){
            ll = mid + 1;
            ans = mid;
        }else{
            rr = mid - 1;
        }
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}