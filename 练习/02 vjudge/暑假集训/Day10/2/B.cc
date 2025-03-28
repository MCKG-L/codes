#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 110;
map<int,int> p[N];
int a[N];
bool check(int i,int j){
    if(p[j].size() < p[i].size()) return 0;
    for(auto &[x,y] : p[i]){
        if(!p[j].count(x)) return 0;
    }
    return 1;
}
void solve(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        int c;cin >> c;
        for(int j=0;j<c;j++){
            int x;cin >> x;
            p[i][x] ++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i] < a[j]) continue;
            if(!check(i,j)) continue;
            if(a[i] == a[j]){
                if(p[j].size() > p[i].size()){
                    cout << "Yes" << endl;
                    return;
                }
            }else{
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}