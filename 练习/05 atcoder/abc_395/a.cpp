#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  3e5 + 10;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> p1(n+1),p2(n+1),p3(n+1);
    for(int i=1;i<=n;i++){
        p1[i] = p2[i] = p3[i] = i;
    }
    while(m --){
        int op,a,b;
        cin >> op;
        if(op == 1){
            cin >> a >> b;
            p1[a] = p3[b];
        }else if(op == 2){
            cin >> a >> b;
            p2[p3[a]] = b;
            p2[p3[b]] = a;
            swap(p3[a],p3[b]);
        }else{
            cin >> a;
            cout << p2[p1[a]] << endl;
        }
    }
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