#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
using ull = unsigned long long;
const int N = 1e6 + 10,P = 131;
int h[N],p[N];
string str;
ull get(int l,int r){
    return h[r] - h[l-1] * p[r-l+1];
}

void solve(){
    cin >> str;
    str = ' ' + str;
    p[0] = 1;
    int n = str.size();
    for(int i=1;i<=n;i++){
        p[i] = p[i-1] * P;
        h[i] = h[i-1] * P + str[i];
    }
    ull hash = get(1,1000);
    for(int i=1001;i+1000<n;i++){
        if(get(i,i+1000-1) == hash){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}   
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}