#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
typedef pair<int,int> PII;
struct Node{
    ll val,i,j,k;
    bool operator < (const Node p)const {
        return val < p.val;
    }
};
void solve(){
    int n,K;
    cin >> n >> K;
    vector<ll> a(n),b(n),c(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) cin >> c[i];
    sort(a.begin(),a.end(),greater<ll>());
    sort(b.begin(),b.end(),greater<ll>());
    sort(c.begin(),c.end(),greater<ll>());
    priority_queue<Node> heap;
    auto cal = [&](int i,int j,int k)->ll{
        return a[i]*b[j] + b[j]*c[k] + c[k]*a[i];
    };
    map<array<int,3>,int> mp;
    auto add = [&](int i,int j,int k)->void{
        if(i < n && j < n && k < n && !mp.count({i,j,k})){
            heap.push((Node){cal(i,j,k),i,j,k});
            mp.insert({{i,j,k},1});
        }
    };
    add(0,0,0);
    for(int _=0;_<K;_++){
        auto [val,i,j,k] = heap.top();//最大值
        if(_ == K - 1) cout << val << endl;
        heap.pop();
        add(i+1,j,k),add(i,j+1,k),add(i,j,k+1);
    }
}   
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}