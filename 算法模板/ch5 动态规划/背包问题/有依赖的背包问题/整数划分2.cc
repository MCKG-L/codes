#include <iostream>
using namespace std;
/*
第二种思考方式：
f[i][j]表示总和为i，个数为j的总方案数
状态划分：方案中最小值为1、方案中最小值大于1
则 f[i][j] = f[i-1][j-1] + f[i-j][j]
*/
const int N = 1010,mod = 1e9 + 7;
int n;
int f[N][N];
int main()
{
    cin >> n;
    f[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            f[i][j] = (f[i-1][j-1] + f[i-j][j]) % mod;
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) ans += f[n][i];
    cout << ans << endl;
    return 0;
}