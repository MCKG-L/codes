#include <iostream>
using namespace std;
const int N = 110,M = 10010;
int n,m;
int f[M];
int main()
{
    cin >> n >> m;
    f[0] = 1;
    for(int i=1;i<=n;i++){
        int v;cin >> v;
        for(int j=m;j>=v;j--){
            f[j] += f[j-v];
        }
    }
    cout << f[m] << endl;
    return 0;
}