#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
int a[201][201];
int ne1[4][2] = {1,0,0,1,-1,0,0,-1,};
int ne2[4][2] = {-1,0,0,-1,1,0,0,1,};
bool st[210][210];
void solve(){
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    vector<int> ans1,ans2;
    int cnt = 0,k1 = 0,k2 = 0;
    int x1 = 0,y1 = 1,x2 = n + 1,y2 = n;
    while(cnt < n * n){
        x1 += ne1[k1%4][0],y1 += ne1[k1%4][1];
        if(x1 > n || x1 <= 0 || y1 > n || y1 <= 0 || st[x1][y1]){
            x1 -= ne1[k1%4][0],y1 -= ne1[k1%4][1];
            k1 ++;
        }else{
            ans1.push_back(a[x1][y1]);
            st[x1][y1] = 1;cnt ++;
        }
        x2 += ne2[k2%4][0],y2 += ne2[k2%4][1];
        if(x2 <= 0 || x2 > n || y2 <= 0 || y2 > n || st[x2][y2]){
            x2 -= ne2[k2%4][0],y2 -= ne2[k2%4][1];
            k2 ++;
        }else{
            ans2.push_back(a[x2][y2]);
            st[x2][y2] = 1;cnt ++;
        }
    }
    for(auto i : ans1) cout << i << ' ';
    cout << endl;
    for(auto i : ans2) cout << i << ' ';
    cout << endl;
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}