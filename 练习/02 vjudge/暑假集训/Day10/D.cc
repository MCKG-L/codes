#include <iostream>
#include <map>
using namespace std;
typedef pair<int,int> PII;
map<PII,int> mp;
int n,T,m;
int ans;
bool st[15];
void dfs(PII p,int t){
    if(t == T){
        ans ++;
        return;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(st[i] || st[j]) continue;
            if(i == 0 && j == 0) continue;
            if(mp.count({i,j})) continue;
            st[i] = st[j] = true;
            dfs({i,j},t+1);
            st[i] = st[j] = false;
        }
    }
}
int main()
{
    cin >> n >> T >> m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        mp[{a,b}] = mp[{b,a}] = 1;
    }
    dfs({0,0},0);
    cout << ans << endl;
    return 0;
}