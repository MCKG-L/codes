#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 1e6 + 10;
vector<int> primes;
bool st[N];
void get_primes(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]) primes.push_back(i);
        for(int j=0;primes[j]<=n/i;j++){
            st[primes[j]*i] = 1;
            if(i % primes[j] == 0) break;
        }
    }
}
/*
1 
9 1
1 3
*/
void solve(){
    int n0,q;cin >> n0 >> q;
    int k = primes.size();
    vector<int> p0(k),p;
    int n = n0,sum = 1,sum0 = 1;
    int t = n0;
    for(int i=0;i<k;i++){
        int P = primes[i];
        if(P > t) break;
        if(t % P) continue;
        int cnt = 0;
        while(t % P == 0) cnt ++,t /= P;
        p0[i] = cnt;
        sum0 *= (p0[i] + 1);
    }
    p = p0,sum = sum0;
    while(q--){
        int op;cin >> op;
        if(op == 2){
            n = n0;
            p = p0,sum = sum0;
        }else{
            int x;cin >> x;
            t = x;
            for(int i=0;i<k;i++){
                int P = primes[i];
                if(P > t) break;
                if(t % P) continue;
                int cnt = 0;
                while(t % P == 0) t /= P,cnt ++;
                sum /= (p[i] + 1);
                p[i] += cnt;
                sum *= (p[i] + 1);
            }
            bool ok = 1;t = sum;
            for(int i=0;i<k;i++){
                int P = primes[i];
                if(P > t) break;
                if(t % P) continue;
                int cnt = 0;
                while(t % P == 0) t /= P,cnt ++;
                if(cnt > p[i]){
                    ok = 0;
                    break;
                }
            }
            if(ok) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}
signed main()
{
    IOS;int T = 1;
    cin >> T;get_primes(N);
    while(T--) solve();
    return 0;
}