#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int a[N];
map<int,ll> mp;
int find(int x,int n){
    if(mp[x]!=0) return mp[x];
    //二分
    int l = 0,r = n - 1;
    while(l < r){
        int mid = (l + r) >> 1;
        if(a[mid] >= x){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    int cnt = 0;
    while(a[l++] == x) cnt++;
    mp[x] = cnt;
    return cnt;
}
int main()
{
    int n,c;cin >> n >> c;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    ll ans = 0;
    for(int i=n-1;i>=0;i--){
        ans += find(a[i]-c,i);
    }
    cout << ans;
    return 0;
}