#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  3e5 + 10;
vector<int> g[N];
int n;
int get(vector<int> &a){ //a是x的所有索引集合，求不含x的子区间个数
    ll res = 0;
    int sz = a.size();
    if(sz == 0){
        return n * (n + 1) / 2;
    }
    int len = a[0] - 1;
    res += len * (len + 1) / 2;
    for(int i=1;i<sz;i++){
        len = a[i] - a[i-1] - 1;
        res += len * (len + 1) / 2;
    }
    len = n - a.back();
    res += len * (len + 1) / 2;
    return res;
}
int get2(vector<int> &a,vector<int> &b){//同时不包含x和x-1
    vector<int> c;
    // if(a.size() == 0 || b.size() == 0) return 0;
    int i = 0,j = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]) c.push_back(a[i++]);
        else c.push_back(b[j++]);
    }
    while(i < a.size()) c.push_back(a[i++]);
    while(j < b.size()) c.push_back(b[j++]);
    return get(c);
}
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        g[x].push_back(i);
    }
    ll ans = 0;
    //枚举需要选择以i为左端点的区间数量
    // for(int i=1;i<=n+1;i++){
    //     cout << i << ": " <<  get(g[i]) << ' ';
    //     cout << get2(g[i-1],g[i]) << endl;
    // }
    for(int i=1;i<=n;i++){ //包含i-1不包含i的集合数目
        ans += get(g[i]); //不包含i的集合数目
        ans -= get2(g[i-1],g[i]);//不包含i也不包含i-1的数目
    }
    ans += n * (n + 1) / 2 - get(g[n]);//包含i不包含i-1的集合数目
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}