#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b == 0){
        x = 1,y = 0;
        return a;
    }
    ll d = exgcd(b,a%b,y,x);
    y -= a / b * x;
    return d;
}
void solve(){
    int n;cin >> n;
    vector<PII> alls;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        alls.push_back({a,b});
    }
    bool ok = true;
    ll a1 = alls[0].first,m1 = alls[0].second;
    for(int i=1;i<n;i++){
        auto [a2,m2] = alls[i];
        ll k1,k2;
        ll d = exgcd(a1,a2,k1,k2);
        if((m2-m1) % d){
            ok = false;
            break;
        }
        k1 *= ( m2 - m1) / d;//真正解 原来是求等于gcd(a1,a2)的解
        ll t = a2 / d;
        k1 = (k1 % t + t) % t;//k1的最小正整数解
        m1 = k1 * a1 + m1;
        a1 = abs(a1 / d * a2);//a1变成最小公倍数
    }
    if(ok){
        cout << (m1 % a1 + a1) % a1 << endl;
    }else{
        cout << -1 << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}