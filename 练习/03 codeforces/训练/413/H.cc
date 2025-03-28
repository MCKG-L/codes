#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef pair<int,int> PII;
/*
d1 = x1 - t1 = x2 - t2  --> x2 - x1 = t2 - t1
d2 = x1 - u1 = x2 - u2  --> x2 - x1 = u2 - u1
--> x2 - x1 = t2 - t1 = u2 - u1 --> x = t = u
*/
void solve(){
    string s;cin >> s;
    int n = s.size();
    vector<int> X(n+1),T(n+1),U(n+1);
    for(int i=0;i<n;i++){
        X[i+1] = X[i] + (s[i] == 'X');
        T[i+1] = T[i] + (s[i] == 'T');
        U[i+1] = U[i] + (s[i] == 'U');
    }
    map<PII,int> mp;mp[{0,0}] = 1;
    long long ans = 0;
    for(int i=1;i<=n;i++){
        int d1 = X[i] - T[i];
        int d2 = X[i] - U[i];
        ans += mp[{d1,d2}];
        mp[{d1,d2}] ++;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}