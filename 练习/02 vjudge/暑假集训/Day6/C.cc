#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
const int N = 2010;
struct Node{
    int x,y;
}a[N];
int n,d;
bool st[N];
void bfs(){
    queue<int> que;
    que.push(0);
    // st[0] = 1;
    while(que.size()){
        int t = que.front();que.pop();
        for(int i=0;i<n;i++){
            if(st[i]) continue;
            double dis = sqrt(pow(a[t].x-a[i].x,2)+pow(a[t].y-a[i].y,2));
            if(dis <= d){
                st[i] = 1;
                que.push(i);
            }
        }
    }
}
int main()
{
    cin >> n >> d;
    for(int i=0;i<n;i++){
        cin >> a[i].x >> a[i].y;
    }
    bfs();
    for(int i=0;i<n;i++){
        if(st[i]) puts("Yes");
        else puts("No");
    }
    return 0;
}