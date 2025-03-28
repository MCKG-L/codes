#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
using namespace std;
//超时 需要用到线段树
const int N = 2e5 + 10;
char str[N];
int n,m;
void solve(){
    cin >> n >> m;
    cin >> str + 1;
    while(m--){
        int op,l,r;
        cin >> op >> l >> r;
        if(op == 0){
            for(int i=l;i<=r;i++){
                if(str[i] == '0') str[i] = '1';
                else str[i] = '0';
            }
        }else{
            int ans = 0;
            for(int i=l;i<=r;i++){
                if(str[i] == '1') ans ++;
            }
            cout << ans << endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}