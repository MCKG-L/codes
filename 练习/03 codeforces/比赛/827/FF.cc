#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
void solve(){
    int n;cin >> n;
    int a = 1,b = 1;
    bool f = 0,f2 = 0;
    while(n--){
        int op,k;string x;
        cin >> op >> k >> x;
        if(op == 2){
            if(!f) for(auto i : x){
                if(i == 'a') b += k;
                else f = 1;
            }
        }else{
            for(auto i : x){
                if(i == 'a') a += k;
                else f2 = 1;
            }
        }
        if(f || (!f2 && a < b)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
signed main()
{
    IOS;
	int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}