#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 2010;
bool st[N];
PII p[N];
int n,d;
double dis(PII p1,PII p2){
    int x1 = p1.first,y1 = p1.second;
    int x2 = p2.first,y2 = p2.second;
    return sqrt((y1-y2)*(y1-y2)+(x1-x2)*(x1-x2));
}
void bfs(){
    st[1] = 1;
    queue<int> que;
    que.push(1);
    while(que.size()){
        int k = que.front();que.pop();
        for(int i=1;i<=n;i++){
            if(st[i]) continue;
            if(dis(p[k],p[i]) <= d){
                que.push(i);st[i] = 1;
            }
        }
    }
}
int main()
{
    cin >> n >> d;
    for(int i=1;i<=n;i++){
        int x,y;
        cin >> x >> y;
        p[i] = {x,y};
    }
    bfs();
    for(int i=1;i<=n;i++){
        if(st[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}