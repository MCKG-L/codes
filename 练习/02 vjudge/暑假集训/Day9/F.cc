#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define int long long
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
typedef long long ll;
PII a[N];
multiset<int> p;
ll n,m,sum;
signed main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        p.insert(x);
        sum += x;
    }
    for(int i=0;i<m;i++){
        int x;cin >> x;
        a[i].first = x;
    }
    for(int i=0;i<m;i++){
        int x;cin >> x;
        a[i].second = x;
    }
    sort(a,a+m,[&](PII p1,PII p2){return p1.second > p2.second;});
    for(auto [l,d] : a){
        auto ps = p.lower_bound(l);
        if(ps == p.end()) continue;
        p.erase(ps);
        sum -= d;
        if(p.size() == 0) break;
    }
    cout << sum << endl;
    return 0;
}