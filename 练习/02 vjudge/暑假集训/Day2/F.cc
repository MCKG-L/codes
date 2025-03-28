#include <iostream>
#include <queue>
using namespace std;
int n,m,si,sj,fi,fj;
//超时！！！
struct Node{
    int x,y;
    string op;
    int t;
};
bool check(int x,int y,string op){
	if(op == "DR"){
		if(fj == fi + y - x && fi >= x) return true;
	}
	if(op == "DL"){
		if(fj == x + y - fi && fi >= x) return true;
	}
	if(op == "UL"){
		if(fj == fi + y - x && fi <= x) return true;
	}
	if(op == "UR"){
		if(fj == x + y - fi && fi <= x) return true;
	}
    return false;
}
bool bfs(string op){
    queue<Node> que;
    if(si == 1 && sj == 1){
    	int t = 1;
    	if(check(si,sj,op)){
    		cout << 0 << endl;
    		return true;
		}
		if(op == "DR") t = 0;
		que.push({si,sj,"DR",t});
	}else if(si == 1 && sj == m){
		int t = 1;
    	if(check(si,sj,op)){
    		cout << 0 << endl;
    		return true;
		}
		if(op == "DL") t = 0;
		que.push({si,sj,"DL",t});
	}
	else if(si == n && sj == 1){
		int t = 1;
    	if(check(si,sj,op)){
    		cout << 0 << endl;
    		return true;
		}
		if(op == "UR") t = 0;
		que.push({si,sj,"UR",t});
	}
	else if(si == n && sj == m){
		int t = 1;
    	if(check(si,sj,op)){
    		cout << 0 << endl;
    		return true;
		}
		if(op == "UL") t = 0;
		que.push({si,sj,"UL",t});
	}else que.push({si,sj,op,0});
	
    while(que.size()){
        Node f = que.front();que.pop();
        int x = f.x,y = f.y;
        string s;
        int nx,ny;
        string ss = f.op;
        if(ss == "B") break;
        if(check(x,y,ss)){
            cout << f.t << endl;
            return true;
        }
        if(ss == "DL"){
            nx = x + y - 1;
            ny = x + y - n;
            if(nx >= 1 && nx <= n) s = "DR",ny = 1;
            else if(ny >= 1 && ny <= m) s = "UL",nx = n;
            if(nx == n && ny == 1) s = "B";
        }
        if(ss == "UL"){
           nx = x - y + 1;
            ny = y - x + 1;
            if(nx >= 1 && nx <= n) s = "UR",ny = 1;
            else if(ny >= 1 && ny <= m) s = "DL",nx = 1;
            if(nx == 1 && ny == 1) s = "B";
        }
        if(ss == "UR"){
             nx = x + y - m;
              ny = x + y - 1;
            if(nx >= 1 && nx <= n) s = "UL",ny = m;
            else if(ny >= 1 && ny <= m) s = "DR",nx = 1;
            if(nx == 1 && ny == m) s = "B";
        }
        if(ss == "DR"){
              nx = x - y + m;
              ny = y - x + n;
            if(nx >= 1 && nx <= n) s = "DL",ny = m;
            else if(ny >= 1 && ny <= m) s = "UR",nx = n;
            if(nx == n && ny == m) s = "B";
        }
        que.push({nx,ny,s,f.t + 1});
    }
    return false;
}
void solve(){
	string op;
    cin >> n >> m >> si >> sj >> fi >> fj >> op;
    if(!bfs(op)) cout << -1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}