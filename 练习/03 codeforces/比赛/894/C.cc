#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
int a[N],b[N];
int n;
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int j = n;
    for(int i=1;i<=n;i++){    
        while(j >= 0 && a[j] < i) j --;
        b[i] = j;
    }
    for(int i=1;i<=n;i++){
        if(a[i] != b[i]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}