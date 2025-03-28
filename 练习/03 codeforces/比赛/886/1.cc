#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 1e5 + 10;
int prim[N],cnt;
bool st[N];
int p[N];
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void get_prime(int x){
    for(int i=2;i<=x;i++){
        if(!st[i]) prim[cnt++] = i;
        for(int j=0;prim[j]<=x/i;j++){
            st[prim[j]*i] = 1;
            if(i % prim[j] == 0) break;
        }
    }
}
void solve(){
    int a,b,P;
    cin >> a >> b >> P;
    for(int i=1;i<=b;i++) p[i] = i;
    get_prime(b+1);
    for(int i=P;i<=b;i++){
        if(st[i]) continue;
        for(int j=1;j*i<=b;j++) {
            p[find(j*i)] = p[find(i)];
        }
    }
    int ans = 0;
    map<int,int> mp;
    for(int i=a;i<=b;i++){
        mp[find(i)] ++;
    }
    cout << mp.size() << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}