#include <iostream>
using namespace std;
//并查集 + 01背包
const int N = 10010;
int p[N],dp[N],c[N],d[N];
int n,m,w;
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void unite(int a,int b){
    a = find(a),b = find(b);
    if(a != b) p[a] = b;
}
int main()
{
    cin >> n >> m >> w;
    for(int i=1;i<=n;i++) p[i] = i;
    for(int i=1;i<=n;i++){
        cin >> c[i] >> d[i];
    }
    for(int i=1;i<=m;i++){
        int a,b;cin >> a >> b;
        unite(a,b);
    }
    for(int i=1;i<=n;i++){
        if(p[i] != i){
            c[find(i)] += c[i],c[i] = 0;
            d[find(i)] += d[i],d[i] = 0;
        }
    }
    //dp
    for(int i=1;i<=n;i++){
        for(int j=w;j>=c[i];j--){
            dp[j] = max(dp[j],dp[j-c[i]]+d[i]);
        }
    }
    cout << dp[w] << '\n';
    return 0;
}