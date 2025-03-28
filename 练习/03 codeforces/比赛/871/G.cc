#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
//错！！！
typedef unsigned long long ull;
ull s;
struct Node{
    ull n;
    ull x;//层数
};
const int N = 1e6 + 5;
bool st[N];
void solve(){
    memset(st,false,sizeof st);
    cin >> s;
    ull x = 1;
    while(x * (x + 1) < 2 *  s) x ++;
    // cout << x << endl;
    queue<Node> q;
    q.push({s,x});
    ull ans = 0;
    while(q.size()){
        Node f = q.front();q.pop();
        ull n = f.n,x = f.x;
        // cout << n << "---";
        ans += n * n;
        if(n == (1 + x - 1) * (x - 1) / 2 + 1 && x != 1){
            if(!st[n-x+1]) q.push((Node){n-x+1,x-1}),st[n-x+1] = true;
        }else if(n == (1 + x) * x / 2){
            if(!st[n-x]) q.push((Node){n-x,x-1}),st[n-x] = true;
        }else{
            if(!st[n-x]) q.push((Node){n-x,x-1}),st[n-x] = true;
            if(!st[n-x+1]) q.push((Node){n-x+1,x-1}),st[n-x+1] = true;
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}