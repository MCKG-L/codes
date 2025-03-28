#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int a[N];
ll s[N];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    int l = 1,r = 1;
    int ans = 0;
    while(l <= n && r <= n){
        if(r <= n && s[r]-s[l-1] == m){
            ans ++;
            r ++;
        }else if(r <= n && s[r]-s[l-1] < m){
            r ++;
        }else if(l <= n){
            l ++;
        }
    }
    cout << ans << endl;
    return 0;
}
