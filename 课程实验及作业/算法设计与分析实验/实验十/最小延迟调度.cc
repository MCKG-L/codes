#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#define endl '\n'
using namespace std;
void solve(){
    int n;cin >> n;
    vector<array<int,3>> p(n);
    vector<int> t(n);
    for(int i=0;i<n;i++) cin >> t[i];
    for(int i=0;i<n;i++){
        int d;cin >> d;
        p[i] = {i+1,d,t[i]};
    }
    sort(p.begin(),p.end(),[&](array<int,3> A,array<int,3> B){
        return A[1] < B[1];
    });
    vector<int> res;
    int ans = 0,ed = 0;
    for(int i=0;i<n;i++){
        ed += p[i][2];
        res.push_back(p[i][0]);
        ans = max(ans,max(0,ed-p[i][1]));
    }
    for(auto x : res) cout << x << ' ';
    cout << '\n' << ans << endl;
}
int main()
{
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}