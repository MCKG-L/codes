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
int n,p;
int qmi(int n,int p){
    int ans = 2;
    for(int i=0;i<n;i++){
        ans = ans * ans % p;
    }
    return ans;
}
void solve(){
    cin >> n >> p;
    cout << qmi(n,p) << endl;
}
signed main()
{
    IOS;int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
