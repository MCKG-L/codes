#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
typedef pair<int,int> PII;
int a,b;
void solve(){
    int x1,y1,x2,y2;
    cin >> a >> b;
    cin >> x1 >> y1 >> x2 >> y2;
    int dx[] = {a,a,-a,-a,b,b,-b,-b};
    int dy[] = {b,-b,b,-b,a,-a,a,-a};
    map<PII,int> mp,mp2;
    for(int i=0;i<8;i++){
        int nx = x1 + dx[i];
        int ny = y1 + dy[i];
        mp[{nx,ny}] ++;
    }
    int cnt = 0;
    
    for(int i=0;i<8;i++){
        int nx = x2 + dx[i];
        int ny = y2 + dy[i];
        mp2[{nx,ny}] ++;
    }
    for(auto [x,y] : mp){
        if(mp2.count(x)) cnt ++;
    }
    cout << cnt << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}