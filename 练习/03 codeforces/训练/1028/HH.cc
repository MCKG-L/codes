#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
int a[201][201];
bool st[210][210];
void solve(){
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    vector<int> ans1,ans2;
    int x = 1,y = 1,xx = n,yy = n;
    int cnt = 0;
    while(cnt < n * n){
        while(x <= n && !st[x][y]){
            ans1.push_back(a[x][y]);
            st[x][y] = 1;cnt ++;
            x ++;
        }y ++;x --;
        while(xx >= 1 && !st[xx][yy]){
            ans2.push_back(a[xx][yy]);
            st[xx][yy] = 1;cnt ++;
            xx --;
        }yy --; xx ++;
        while(y <= n && !st[x][y]){
            ans1.push_back(a[x][y]);
            st[x][y] = 1;cnt ++;
            y ++;
        }
        x --;y --;
        while(yy >= 1 && !st[xx][yy]){
            ans2.push_back(a[xx][yy]);
            st[xx][yy] = 1;cnt ++;
            yy --;
        }xx ++;yy ++;
        while(x >= 1 && !st[x][y]){
            ans1.push_back(a[x][y]);
            st[x][y] = 1;cnt ++;
            x --;
        }y --;x ++;
        while(xx <= n && !st[xx][yy]){
            ans2.push_back(a[xx][yy]);
            st[xx][yy] = 1;cnt ++;
            xx ++;
        }yy ++;xx --;
        while(y >= 1 && !st[x][y]){
            ans1.push_back(a[x][y]);
            st[x][y] = 1;cnt ++;
            y --;
        }x ++;y ++;
        while(yy <= n && !st[xx][yy]){
            ans2.push_back(a[xx][yy]);
            st[xx][yy] = 1;cnt ++;
            yy ++;
        }xx --;yy --;
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
    while(T--) solve();
    return 0;
}