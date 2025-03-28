#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 155,M = 5010;
int p[N];
int n,m;
struct edge{
    int a,b;
}e[M];
vector<pair<int,int>> ans;
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void unite(int a,int b){
    a = find(a),b = find(b);
    if(a != b) p[a] = b;
}
void func(int t){
    for(int i=1;i<=n;i++) p[i] = i;
    for(int i=0;i<m;i++){
        if(i == t) continue;
        int a = e[i].a,b = e[i].b;
        unite(a,b);
    }
    int a = e[t].a,b = e[t].b;
    if(find(a) != find(b)) ans.push_back({min(a,b),max(a,b)});
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> e[i].a >> e[i].b;
    }
    for(int i=0;i<m;i++){
        func(i);
    }
    sort(ans.begin(),ans.end());
    for(auto i : ans) cout << i.first << ' ' << i.second << '\n';
    return 0;
}