#include <iostream>
using namespace std;
/*
情形1：有多组问题，需要多次计算组合数
预处理出组合数
求C(a,b) % p (p = 1e9+7)
递推式：C(a,b) = C(a-1,b) + C(a-1,b-1)
可以预处理出所有可能用到的C(a,b)
b <= a <= 2000
*/
const int N = 2010,mod = 1e9 + 7;
int c[N][N];
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            if(!j) c[i][j] = 1;
            else c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
        }
    }
}
int main()
{
    init();
    int n;cin >> n;
    while(n--){
        int a,b;
        cin >> a >> b;
        cout << c[a][b] << endl;
    }
    return 0;
}