#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 1e4 + 10;
void solve(){
    int n;cin >> n;
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        int x,d;
        cin >> x >> d;
        mp[d].push_back(x);
    }
    multiset<int> s;
    int ans = 0;
    for(auto it : mp){
        auto &p = it.second;
        int d = it.first;
        for(auto x : p){
            s.insert(x);
            if((int)s.size() > d) s.erase(s.begin());
        }
    }
    for(auto x : s) ans += x;
    cout << ans << endl;
}
int main()
{
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}