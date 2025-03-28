#include <iostream>
using namespace std;
const int N = 1e4 + 10;
int p[N],c[N],d[N],dp[N];
int n,m,w;
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void merge(int a,int b){
    a = find(a),b = find(b);
    if(a != b) p[a] = b;
}
int main()
{
    cin >> n >> m >> w;
    for(int i=1;i<=n;i++){
        p[i] = i;
        cin >> c[i] >> d[i];
    }
    while(m--){
        int a,b;
        cin >> a >> b;
        merge(a,b);
    }
    //同一个集合的元集中在代表元上
    for(int i=1;i<=n;i++){
        if(p[i] != i){
            c[find(i)] += c[i],c[i] = 0;
            d[find(i)] += d[i],d[i] = 0;
        }
    }
    //01背包
    for(int i=1;i<=n;i++){
        for(int j=w;j>=c[i];j--){
            dp[j] = max(dp[j],dp[j-c[i]] + d[i]);
        }
    }
    cout << dp[w] << endl;
    return 0;
}