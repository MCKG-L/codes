#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010,M = 100010;
struct node{
    int a,b,t;
}e[M];
int p[N];
int n,m,ans;
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void unite(int a,int b){
    a = find(a),b = find(b);
    if(a != b)ans--,p[a] = b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) p[i] = i;
    for(int i=0;i<m;i++){
        cin >> e[i].a >> e[i].b >> e[i].t;
    }
    ans = n;
    sort(e,e+m,[&](node p1,node p2){return p1.t < p2.t;});
    bool mask = 1;
    for(int i=0;i<m;i++){
        unite(e[i].a,e[i].b);
        if(ans == 1){
            cout << e[i].t << '\n';mask = 0;
            break;
        }
    }
    if(mask) cout << -1 << '\n';
    return 0;
}