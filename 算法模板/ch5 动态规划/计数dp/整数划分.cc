#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
/*
整数划分：n = n1 + n2 + n3 + ... + nk (n1 <= n2 <= n3 <= ... <= nk)

看成完全背包问题：从1~n中选数，满足和为n

f[i][j] = f[i-1][j] + f[i-1][j-i] + f[i-1][j-2i] + ... + f[i-1][j-si]
f[i][j-i] = f[i-1][j-i] + f[i-1][j-2i] + ... + f[i-1][j-si];
则 f[i][j] = f[i-1][j] + f[i][j-i]
优化：f[j] = f[j] + f[j-i]
*/
const int N = 1010;
int f[N];
int n;
int main()
{
    cin >> n;
    f[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            f[j] = (f[j] + f[j-i]) % mod;
        }
    }
    cout << f[n] << endl;
    return 0;
}