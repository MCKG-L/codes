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
    int M = -1,pos = -1;
    for(int i=0;i<n;i++){
        cin >> a[i];b[i] = a[i];
        if(a[i] > M){
            M = a[i];
            pos = i;
        }
    }
    sort(b,b+n);
    int m = b[n-2];
    for(int i=0;i<n;i++){
        if(i == pos){
            cout << a[i] - m << ' ';
        }else{
            cout << a[i] - M << ' ';
        }
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