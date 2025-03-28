#include <iostream>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int p[N],n;
void solve(){
    cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        p[x] = i;
    }
    //枚举mex的可能取值1~n
    //mex值为k的区间，一定包含元素0~k-1
    int l = p[0],r = p[0];//记录0~k-1中数的最左位置和最右位置
    ll ans = 0;p[n] = n;
    for(int i=1;i<=n;i++){
        l = min(l,p[i-1]);
        r = max(r,p[i-1]);
        int pos = p[i],len = 2 * i;
        if(pos >= l && pos <= r) continue;//该区间的mex不可能为i
        if(pos < l){
            for(int j=l;j>pos && r-j+1<=len;j--){
                int R = min(n-1,j+len-1);
                ans += R - r + 1;
            }
        }else if(pos > r){
            for(int j=r;j<pos&&j-l+1<=len;j++){
                int L = max(0,j-len+1);
                ans += l - L + 1;
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}