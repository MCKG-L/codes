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
const int N = 55;
int a[N],n;
void solve(){
    cin >> n;
    map<int,int> st;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(x >= 1 && x <= n) st[x] ++;
        else{
            while(x > n) x /= 2;
            st[x] ++;
        }
    }
    for(int i=n;i>=1;i--){
        if(!st.count(i)){
            cout << "NO" << endl;
            return;
        }
        if(st[i] > 1){
            st[i/2] += st[i]-1;
        }
    }
    cout << "YES" << endl;
}
signed main()
{
    IOS;int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
