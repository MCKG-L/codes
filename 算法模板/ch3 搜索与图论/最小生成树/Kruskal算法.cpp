#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
/*
1、先将所有边按照权重从小到大排序 快排
2、枚举每条边a--b,权重为c,
如果a,b不连通，将这条边加到集合中 用并查集维护集合
*/
const int N = 100010;
int n,m;
int p[N];
struct E{
    int a,b,w;
    bool operator< (const E &W)const{
        return w < W.w;
    }
}e[N];
int res,cnt;
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        e[i] = {a,b,w};
    }
    for(int i=1;i<=n;i++) p[i] = i;
    sort(e,e+m);
    for(int i=0;i<m;i++){
        int a = e[i].a,b = e[i].b,w = e[i].w;
        a = find(a),b = find(b);
        if(a != b){
            p[a] = b;
            res += w;
            cnt++;
        }
    }
    if(cnt < n - 1) puts("impossible!");
    else cout << res << endl;
    return 0;
}
