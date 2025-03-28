#include <iostream>
using namespace std;
const int N = 30,M = 1e4+10;
int v[N],w[N];
int f[M];
int n,t;
int main()
{
    cin >> n >> t;
    for(int i=1;i<=n;i++){
        cin >> v[i] >> w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=t;j>=w[i];j--){
            f[j] = max(f[j],f[j-w[i]]+v[i]);
        }
    }
    cout << f[t] << endl;
    return 0;
}