#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> p[3];
void solve(){
    for(int i=0;i<3;i++) p[i].clear();
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;string op;
        cin >> x >> op;
        // cout << x << ' ' << op << endl;
        if(op[0] == '1' && op[1] == '1') p[2].push_back(x);
        else if(op[0] == '1') p[0].push_back(x);
        else if(op[1] == '1') p[1].push_back(x);
    }
    for(int i=0;i<3;i++) sort(p[i].begin(),p[i].end());
    int ans = 1e9 + 10;
    if(!p[2].size() && (!p[0].size() || !p[1].size())) ans = -1;
    else{
        if(p[1].size() && p[0].size()) ans = min(ans,p[1][0] + p[0][0]);
        if(p[2].size()) ans = min(ans,p[2][0]);
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}