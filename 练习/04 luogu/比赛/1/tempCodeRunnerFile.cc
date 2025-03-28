#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;

void solve(){
    int x,y,z,m;
    cin >> x >> y >> z >> m;
    int a = 0,b = 0,c = 0;
    while(m--){
        int op,k;
        cin >> op >> k;
        if(op == 1){
            if(k > a) a = min(k,x);
            cout << (x-a)*(y-b)*(z-c) << endl;
        }else if(op == 2){
            // if(k <= b){
            //     cout << 0 << endl;
            //     continue;
            // }
            if(k > b) b = min(k,y);   
            cout << (x-a)*(y-b)*(z-c) << endl;
        }else{
            // if(k <= c){
            //     cout << 0 << endl;
            //     continue;
            // }
            if(k > c ) c = min(k,z);
            cout << (x-a)*(y-b)*(z-c) << endl;
        }
    }
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}