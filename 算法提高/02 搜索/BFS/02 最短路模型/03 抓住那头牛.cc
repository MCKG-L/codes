#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
int n,f;
bool st[N];
void bfs(){
    queue<PII> que;
    que.push({n,0});
    st[n] = true;
    while(que.size()){
        PII k = que.front();
        que.pop();
        int x = k.first,t = k.second;
        if(x == f){
            cout << t << endl;
            return;
        }
        if(x - 1 >= 0 && !st[x-1]) que.push({x-1,t+1}),st[x-1] = true;
        if(x + 1 < N/2 && !st[x+1]) que.push({x+1,t+1}),st[x+1] = true;
        if(x * 2 < N/2 && !st[x*2]) que.push({x*2,t+1}),st[x*2] = true;
    }
}
int main()
{
    cin >> n >> f;
    bfs();
    return 0;
}