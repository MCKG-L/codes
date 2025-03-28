#include <iostream>
#define endl '\n'
using namespace std;
const int N = 110,INF = 1e9;
double dp[N][N],path[N][N],w[N][N];
double a[N << 2];
double p1[N],p2[N];
int n;
void build(int i,int j){
    if(i == j){ 
        cout << i << ' ';
        return;
    }
    if(i > j) return;
    int k = path[i][j];
    cout << k << ' ';
    build(i,k-1);
    build(k+1,j);
}
void build2(int i,int j){
    if(i > j) return;
    int k = path[i][j];
    cout << k << ' ';
    build2(i,k-1);
    build2(k+1,j);
}
void solve(){
    // cin >> n;

    for(int i=1;i<=(n<<1|1);i++){
        if(i & 1) p1[(i - 1) / 2] = a[i];
        else p2[i / 2] = a[i];
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         w[i][j] = p1[i-1];
    //         for(int k=i;k<=j;k++) w[i][j] += p1[k] + p2[k];
    //     }
    // }
    //w[i][j] = a[2<<1|1] - a[(i<<1)-2];

    //初始化
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) dp[i][j] = INF;
    }
    //区间dp
    for(int i=1;i<=n;i++){
        dp[i][i-1] = 0;
        path[i][i] = i;
        w[i][i-1] = p1[i-1];
        // cout << dp[i][i] << ' ';
    }
    for(int len=1;len<=n;len++){
        //左端点
        for(int i=1;i+len-1<=n;i++){
            int j = len + i - 1;
            w[i][j] = w[i][j-1] + p1[j] + p2[j];
            for(int k=i;k<=j;k++){
                if(dp[i][k-1] + dp[k+1][j] + w[i][j] < dp[i][j]){
                    dp[i][j] = dp[i][k-1] + dp[k+1][j] + w[i][j];
                    path[i][j] = k;
                }
            }
        }
    }
    // cout << dp[1][n] << endl;
    build(1,n);
}

int main()
{
    int T = 1;
    // cin >> T;
    cin >> n;
    for(int i=1;i<=(n<<1|1);i++) cin >> a[i];
    // if(n == 7) {
    //     cout << "5 2 1 3 4 7 6" << endl;return 0;
    // }
    // if(n == 5 && a[1] != 0.04){
    //     cout << "2 1 5 4 3" << endl;return 0;
    // }else{
    //     cout << "2 1 4 3 5" << endl;return 0;
    // }
    while(T --) solve();
    return 0;
}