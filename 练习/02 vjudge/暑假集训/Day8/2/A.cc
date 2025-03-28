#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 1e5 + 10;
int a[N],n,m;
int b[N];
void solve(){
    cin >> n >> m;
    vector<pair<int,int>> p;
    for(int i=0;i<n;i++){
        cin >> a[i];a[i] += i;
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
        if(a[i] <= m) p.push_back({b[i],i+1});
    }
    if(p.size() == 0){
        cout << -1 << endl;
        return;
    }
    sort(p.begin(),p.end());
    cout << p.back().second << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}