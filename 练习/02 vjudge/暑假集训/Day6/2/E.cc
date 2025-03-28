#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int p[N];
map<PII,int> mp;
int n,m,k,q;
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void unite(int a,int b){
    a = find(a),b = find(b);
    p[a] = b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) p[i] = i;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        unite(u,v);
    }
    cin >> k;
    for(int i=1;i<=k;i++){
        int x,y;cin >> x >> y;
        x = find(x),y = find(y);
        mp[{x,y}] ++,mp[{y,x}] ++;
    }
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        a = find(a),b = find(b);
        if(mp.count({a,b}) || mp.count({b,a})){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}