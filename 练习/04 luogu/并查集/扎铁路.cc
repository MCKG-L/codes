#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 151,M = 5010;
struct Node{
    int a,b;
}e[M];
int p[N];
int n,m;
vector<pair<int,int>> ans;
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void merge(int a,int b){
    a = find(a),b = find(b);
    if(a != b) p[a] = b;
}
void func(int t){
    for(int i=1;i<=n;i++) p[i] = i;
    for(int i=0;i<m;i++){
        if(i == t) continue;
        merge(e[i].a,e[i].b);
    }
    int a = min(e[t].a,e[t].b), b = max(e[t].a,e[t].b);
    if(find(a) != find(b)) ans.push_back({a,b});
}
int main()
{
    cin >> n >> m;
    for(int i=0;i<m;i++) cin >> e[i].a >> e[i].b;
    for(int i=0;i<m;i++){
        func(i);
    }
    sort(ans.begin(),ans.end());
    for(auto i : ans){
        cout << i.first << ' ' << i.second << endl;
    }
    return 0;
}