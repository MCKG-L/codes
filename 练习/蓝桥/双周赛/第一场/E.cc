#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef unsigned long long ULL;
const int N = 2e6 + 10,P = 131;
ULL h[N],p[N];
char s[N],t[N];
int n;
//字符串哈希
ULL get(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}
void solve(){
    cin >> n;
    cin >> s + 1 >> t + 1;
    for(int i=1;i<=n;i++){
        // if(s[i] >= 'a' && s[i] <= 'z'){
        //     s[i] -= 32;
        // }else s[i] += 32;
        /*
        观察大写字母和小写字母的ASII码 发现大写字母的二进制第6位都是0
        小写字母的二进制第6位都是1 大小写字母偏移量32的二进制恰好位0010 0000
        可以发现 大写字母的ASCII码值和32进行按位异或 可以得到其对应小写字母的ASCII码
        同样发现 小写字母的ASCII码值和32进行按位异或 可以得到其对应大写字母的ASCII码
        */
        s[i] ^= 32;
        s[i+n] = s[i];
    }
    p[0] = 1;
    for(int i=1;i<=n*2;i++){
        p[i] = p[i-1] * P;
        h[i] = h[i-1] * P + s[i];
    }
    ULL ht = 0;
    for(int i=1;i<=n;i++){
        ht = ht * P + t[i];
    }
    int ans = n;
    for(int i=1;i<=n;i++){
        if(get(i,i+n-1) == ht){
            ans = min(ans,min(i-1,n-i+1));
        }
    }
    if(ans == n) cout << "No" << endl;
    else cout << "Yes\n" << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}