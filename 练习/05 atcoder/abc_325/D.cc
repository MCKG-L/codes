#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
void solve(){
    int n;cin >> n;
    vector<PII> a;
    for(int i=0;i<n;i++){
        int t,d;cin >> t >> d;
        a.push_back({t,t+d});
    }
    sort(a.begin(),a.end());
    priority_queue<int,vector<int>,greater<int>> heap;//小根堆
    int i = 0,t = 0;
    int ans = 0;
    while(i < n || !heap.empty()){
        if(heap.empty()){
            t = a[i].first;
            heap.push(a[i++].second);
        }
        while(i < n && a[i].first <= t) heap.push({a[i++].second});

        while(!heap.empty() && heap.top() < t) heap.pop();
        if(heap.size()){
            ans ++;t ++;
            heap.pop();
        }
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}