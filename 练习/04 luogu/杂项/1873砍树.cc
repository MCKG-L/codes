#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;
int a[N];
ll m_find(int a[],ll n,ll m){
    ll l = 0,r = a[n-1];
    while(l < r){
        ll mid = (l + r + 1) / 2;
        ll sum = 0;
        for(int i=0;i<n;i++){
            if(a[i] > mid){
                sum += a[i] - mid;
            }
        }
        if(sum < m){
            r = mid - 1;
        }else{
            l = mid;
        }
    }
    return l;
}
void solve(){
    ll n,m;
    cin >> n >> m;  
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    cout << m_find(a,n,m);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}