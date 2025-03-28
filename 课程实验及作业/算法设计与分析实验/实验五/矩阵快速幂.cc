#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> PII;
using ll = long long;
using matrix = vector<vector<int>>;
const int N = 2e5 + 10;
const int mod = 10000;
matrix multi(matrix A,matrix B){
    matrix C(2,vector<int>(2,0));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                C[i][j] += A[i][k] * B[k][j];
            }
            C[i][j] %= mod;
        }
    }
    return C;
}
matrix qmi(int k){
    //单位矩阵
    matrix ans(2,vector<int>(2,1));
    ans[0][1] = ans[1][0] = 0;

    //快速幂矩阵
    matrix A(2,vector<int>(2,1));
    A[1][1] = 0;

    while(k){
        if(k & 1) ans = multi(A,ans);
        k >>= 1;
        A = multi(A,A);
    }
    return ans;
}
void solve(){
    int n;cin >> n;
    matrix ans = qmi(n);
    cout << ans[0][1] << endl;
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t --) solve();
    return 0;
}