#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
typedef pair<int,int> PII;
using ll = long long;
int p[N],cnt;
bool st[N];
void get_primes(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]) p[cnt++] = i;
        for(int j=0;p[j]<=n/i;j++){
            st[p[j]*i] = 1;
            if(i % p[j] == 0) break;
        }
    }
}
int ans;
void process(int x){
    if(x <= 4){
        if(x == 4) ans ++;
        return;
    }
    //从前往后找到第一对
    for(int i=0;i<cnt&&p[i]*2<=x;i++){
        if(!st[x-p[i]]){
            // cout << p[i] << ' ' << x-p[i] << endl;
            ans ++;
            process(x-p[i]*2);
            break;
        }
    }
}
void solve(){
    //78498个素数
    int x;cin >> x;
    get_primes(x);
    process(x);
    cout << ans << endl;
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t --) solve();
    return 0;
}