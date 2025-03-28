#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
void solve(){
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a * a == c){
            cout << "Lv Yan" << endl;
        }else if(a + a == c){
            cout << "Tu Dou" << endl;
        }else{
            cout << "zhe du shi sha ya!" << endl;
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