#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
#define endl '\n'
using namespace std;
//枚举经过的每一个格子 记录经过的每个格子的状态
const int N = 25001;
unordered_map<string,int> p = {{"DL",0},{"DR",1},{"UL",2},{"UR",3}};
int sx,sy,fx,fy,n,m;
string op;
void solve(){
    cin >> n >> m >> sx >> sy >> fx >> fy >> op;
    bool st[n+1][m+1][4];
    memset(st,false,sizeof st);
    if(sx == fx && sy == fy){
        cout << 0 << endl;
        return;
    }
    int dx = (op[0] == 'U' ? -1 : 1);
    int dy = (op[1] == 'L' ? -1 : 1);
    int x = sx,y = sy;
    int ans = 0;
    while(1){
        if(st[x][y][p[op]]) break;
        st[x][y][p[op]] = true;
        if(x == fx && y == fy){
            cout << ans << endl;
            return;
        }
        x += dx;y += dy;
        bool f1 = x > n || x < 1;
        bool f2 = y > m || y < 1;
        if(f1 || f2){
        	x -= dx,y -= dy;
        	if(f1) dx *= -1;if(f2) dy *= -1;
            string s = "";
            if(dx == 1) s += 'D';else s += 'U';
            if(dy == 1) s += 'R';else s += 'L';
            ans ++;op = s;
        }
    }
    cout << -1 << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}