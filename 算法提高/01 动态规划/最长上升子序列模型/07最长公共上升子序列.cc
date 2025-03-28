#include <iostream>
using namespace std;
const int N = 3010;
int n,a[N],b[N],f[N][N];
//f[i][j]表示a中前i个数，b中前j个数并且以b[j]结尾的LCIS长度
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    
    for(int i=1;i<=n;i++){
        int maxv = 1;
        for(int j=1;j<=n;j++){
            f[i][j] = f[i-1][j];
            // if(a[i] != b[j]) continue;
            // for(int k=0;k<j;k++){
            //     if(b[k] < a[i]) f[i][j] = max(f[i][j],f[i][k]+1);
            // }
            if(a[i] == b[j]) f[i][j] = max(f[i][j],maxv);
            if(b[j] < a[i]) maxv = max(maxv,f[i][j]+1);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) ans = max(ans,f[n][i]);
    cout << ans << endl;
    return 0;
}