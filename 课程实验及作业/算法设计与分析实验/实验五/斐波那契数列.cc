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
//子问题 求A^n
matrix process(matrix A,int n){
    if(n == 1) return A;
    if(n & 1){
        return multi(A,process(A,n-1));
    }else{
        return process(multi(A,A),n / 2);
    }
}
void solve(){
    int n;cin >> n;
    if(n == 0){
        cout << 0 << endl;
        return;
    }
    //快速幂矩阵
    matrix B(2,vector<int>(2,1));
    B[1][1] = 0;
    matrix ans = process(B,n);
    cout << ans[0][1] << endl;
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t --) solve();
    return 0;
}