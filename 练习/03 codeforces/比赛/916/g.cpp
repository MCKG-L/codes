#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int mod = 998244353;
mt19937_64 rnd(998244353);
int get(){
    int x = 0;
    while(x == 0) x = rnd();
    return x;
}
void solve(){
    int n;cin >> n;
    int m = n * 2;
    vector<int> color(m + 10),pos(m + 10,-1),hash(n + 1);
    for(int i=0;i<m;i++){
        cin >> color[i];
    }
    for(int i=1;i<=n;i++){
        hash[i] = get();
    }
    map<int,int> mp;
    mp[0] = -1;
    auto cal = [&](int l,int r)->int{
        // cout << l << ' ' << r << endl;
        int res = 0;
        while(l <= r){
            // cout << "pos:" << pos[l] << endl;
            if(pos[l] != -1){
                l = pos[l] + 1;
            }else{
                res ++;
                l ++;
            }
        } 
        return res;
    };
    int cur = 0,ans = 1LL,siz = 0;
    for(int i=0;i<m;i++){
        cur ^= hash[color[i]];
        if(cur == 0){ //找到右边界
            siz ++;
            ans = ans * cal(mp[0]+1,i) % mod;
            mp.clear();
        }else if(mp.count(cur)){
            pos[mp[cur]+1] = i;
        }
        mp[cur] = i;
    }
    cout << siz << ' ' << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}