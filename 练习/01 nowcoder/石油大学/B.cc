#include <iostream>
#include <cstring>
using namespace std;
// const double rate = 0.004;
double ans,sum;
int n,m;
// int a,b,c;
bool vis[20];
struct P{
    int a,b,c;
}p[20];
void dfs(int k,int t){
    if(k == n || t > m){
        ans = max(ans,sum);
        return;
    }
    for(int i=0;i<n;i++){
        double s = 0;
        if(vis[i] == 1) continue;
        if(t + p[i].b > m){
            s = 0;
            // ans = max(ans,sum);
            // continue;
        }
        else{
            s = p[i].a - p[i].a * (t + p[i].b)*0.004 - 50*p[i].c;
            if(s < p[i].a * 0.3) s = p[i].a * 0.3;
        }
        sum += s;
        vis[i] = 1;
        dfs(k+1,t+p[i].b);
        sum -= s;
        vis[i] = 0;
    }
}
void solve(){
    ans = 0;
    sum = 0;
    cin >> n >> m;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        cin >> p[i].a >> p[i].b >> p[i].c;
    }
    dfs(0,0);
    cout << (int)ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}