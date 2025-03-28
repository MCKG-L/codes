#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int l[N],r[N],a[N];
void solve(){
    int n;
    cin >> n;
    memset(l,0,(n+10)*4);
    memset(r,0,(n+10)*4);
    for(int i=1;i<=n;i++) cin >> a[i];
    int p1=0,p2=0;bool f = true;
    for(int i=n;i>=1;i--){
        r[i] = r[i+1];
        if(a[i] == 0) r[i]++;
    }
    for(int i=1;i<=n;i++){
        if(a[i] == 0 && f) p1 = i,f = false;
        if(a[i] == 1) p2 = i;
        l[i] = l[i-1];
        if(a[i] == 1) l[i]++;
    }
    // cout << "___" << p1 << ' ' << p2 << endl;
    long long ans = 0;
    //p0 不换
    for(int i=1;i<=n;i++){
        if(a[i] == 1){
            ans += r[i+1];
        }
    }
    //p1 左边第一个0换为1
    ll sum = 0;
    for(int i=1;i<=n;i++){
        if(i == p1) sum += r[i+1];
        if(p1 && i < p1 && a[i] == 1){
            sum += max(0,r[i+1] - 1);
        }else if(a[i] == 1){
            sum += r[i+1];
        }
    }
    ans = max(ans,sum);
    //p2
    sum = 0;
    for(int i=1;i<=n;i++){
        if(p2 && i < p2 && a[i] == 1) sum += r[i+1] + 1;
        else if(a[i] == 1 && i != p2) sum += r[i+1];
    }
    ans = max(ans,sum);
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}