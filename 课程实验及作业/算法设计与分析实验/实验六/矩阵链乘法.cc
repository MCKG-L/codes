#include <iostream>
#include <vector>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 1010,INF = 0x3f3f3f3f;
/*
5
30 35 15 5 10 20
11875
*/
bool f;
void find(int l,int r,vector<vector<int>> &path){
    // if(l == r){
    //     cout << "A" << l;
    //     return;
    // }
    // int t = path[l][r];
    // if(t - l4554 >= 1){
    //     cout << "(";
    //     find(l,t,path);
    //     cout << ")";
    // }else{
    //     find(l,t,path);
    // }
    // if(r-t-1>=1){
    //     cout << "(";
    //     find(t+1,r,path);
    //     cout << ")";
    // }else{
    //     find(t+1,r,path);
    // }
    if(l == r){
        cout << "A" << l;
        return;
    }
    if(f){
        cout << "(";
        find(l,path[l][r],path);
        find(path[l][r]+1,r,path);
        cout << ")";
    }else{
        f = 1;
        find(l,path[l][r],path);
        find(path[l][r]+1,r,path);
    }
}
void solve(){
    int n;cin >> n;
    vector<int> a(n+10);
    vector<vector<int> > dp(n+10,vector<int>(n+10,INF));
    vector<vector<int> > path(n+10,vector<int>(n+10,0));
    for(int i=0;i<=n;i++){
        cin >> a[i];
        dp[i][i] = 0;
        path[i][i] = i;
    }
    //区间DP
    //枚举长度
    for(int len=2;len<=n;len++){
        //枚举左端点
        for(int i=1;i<=n-len+1;i++){
            int j = i + len - 1;
            for(int k=i;k<j;k++){
                int t = dp[i][k] + dp[k+1][j] + a[i-1] * a[k] * a[j];
                if(t < dp[i][j]){
                    dp[i][j] = t;
                    path[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][n] << endl;
    find(1,n,path);
}
signed main()
{
    int T = 1;
    while(T --) solve();
    return 0;
}