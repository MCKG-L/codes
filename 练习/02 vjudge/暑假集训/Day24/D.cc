#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int x[N],y[N];
int n;
vector<int> a,b;
void solve(){
    a.clear();b.clear();
    cin >> n;
    for(int i=0;i<n;i++) cin >> x[i];
    for(int i=0;i<n;i++){
        cin >> y[i];
        int d = y[i] - x[i];
        if(d >= 0) a.push_back(d);
        else b.push_back(-d);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans = 0;
    while(a.size() && b.size()){
        if(b.back() <= a.back()){
            ans ++;
            a.pop_back();b.pop_back();
        }else{
            b.pop_back();
        }
    }
    ans += a.size() / 2;
    cout << ans << endl;
}
signed main()
{
    IOS;int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
