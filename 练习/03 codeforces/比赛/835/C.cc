#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
void solve(){
    int n;cin >> n;
    vector<int> a(n),b(n);
    int pos = -1,M = -1;
    for(int i=0;i<n;i++){
        cin >> a[i];
        b[i] = a[i];
        if(a[i] > M){
            M = a[i];
            pos = i;
        }
    }
    sort(b.begin(),b.end());
    int m = b[n-2];
    for(int i=0;i<n;i++){
        if(i == pos) cout << a[i] - m << ' ';
        else cout << a[i] - M << ' ';
    }
    cout << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}