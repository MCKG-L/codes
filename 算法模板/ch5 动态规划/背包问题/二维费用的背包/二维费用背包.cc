#include <iostream>
using namespace std;

/*
限制增加了一个重量
背包的最大容量是V，最大承受重量是M
每一个物品只能使用一次，物品的体积是v，重量是m，价值是w
求装出的最大价值
*/
const int N = 110;
int n,v,m;
int f[N][N];
int main()
{
    cin >> n >> v >> m;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        for(int j=v;j>=a;j--){
            for(int k=m;k>=b;k--){
                f[j][k] = max(f[j][k],f[j-a][k-b]+c);
            }
        }
    }
    cout << f[v][m] << endl;
    return 0;
}
