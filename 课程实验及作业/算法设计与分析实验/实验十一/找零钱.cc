#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 0x3f3f3f3f;
int n,m;
vector<int> a;
vector<int> dp_ans;
void find(int n,int m,vector<vector<PII>> &b){
    if(n <= 0 || m <= 0) return;
    PII t = b[n][m];
    int i = t.first,k = t.second;
    m -= a[i] * k;
    while(k --) dp_ans.push_back(a[i]);
    find(i-1,m,b);
}
void solve(){
    cin >> n >> m;int temp = m;
    a.resize(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    //贪心
    vector<int> ans;
    for(int i=n;i>=1;i--){
        int t = m / a[i];
        while(t --) ans.push_back(a[i]);
        m %= a[i];
    }
    m = temp;
    //dp
    vector<vector<int>> dp(n+1,vector<int>(m+1,INF));
    vector<vector<PII>> b(n+1,vector<PII>(m+1));
    for(int i=0;i<=m;i++){
        dp[1][i] = i;
        dp[0][i] = 0;
        b[1][i] = make_pair(1,i);
    }
    for(int i=1;i<=n;i++) dp[i][0] = 0;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k*a[i]<=j;k++){
                if(dp[i][j] > dp[i-1][j-k*a[i]] + k){
                    dp[i][j] = dp[i-1][j-k*a[i]] + k;
                    b[i][j] = make_pair(i,k);
                }
            }
        }
    }
    find(n,m,b);
    auto print = [&](vector<int> ans) -> void{
        cout << temp << "=";
        for(int i=0;i<(int)ans.size()-1;i++) cout << ans[i] << '+';
        cout << ans.back() << endl;
    };
    print(ans);
    print(dp_ans);
}
int main()
{
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}
