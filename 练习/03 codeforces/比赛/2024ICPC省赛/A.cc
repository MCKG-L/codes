#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 6e5 + 10;
bool dp[2][N];
int a[100];
void solve(){
    int n;cin >> n;
    map<int,int> mp;
    int sum = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        mp[x] ++;
        sum += x;
    }
    int cnt = 0;
    for(auto [x,t] : mp){
        int k = 1;
        while(k <= t){
            a[++cnt] = k * x;
            t -= k;
            k *= 2;
        }
        if(t){
            a[++cnt] = t * x;
        }
    }
    dp[1][a[1]] = dp[1][0] = true;
    for(int i=2;i<=cnt;i++){
        for(int j=0;j<=sum;j++){
            dp[i & 1][j] |= dp[i-1 & 1][j-a[i]] | dp[i-1 & 1][j];
        }
    }
    for(int i=1;i<=sum;i++){
        cout << dp[cnt & 1][i] << ' ';
    }
    cout << endl;
    cout << (dp[cnt & 1][sum/2] ? "YES" : "NO") << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}