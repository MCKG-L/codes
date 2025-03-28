#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int f[N][2];//f[i][j]表示：考虑前i个数并且以第i个数结尾的、f值为j的区间个数
int n;
string s;
int main()
{
    cin >> n >> s;
    s = " " + s;
    long long ans = 0;
    for(int i=1;i<=n;i++){
        if(s[i] == '0'){
            f[i][0] = 1;
            f[i][1] = f[i-1][1] + f[i-1][0];
        }else{
            f[i][0] = f[i-1][1];
            f[i][1] = f[i-1][0] + 1;
        }
        ans += f[i][1];
    }
    cout << ans << endl;
    return 0;
}