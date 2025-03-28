#include <iostream>
using namespace std;
const int N = 5010;
int p[N];
int n,m,q;
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    cin >> n >> m >> q;
    for(int i=1;i<=N;i++) p[i] = i;
    while(m--){
        int x,y;
        cin >> x >> y;
        p[find(x)] = find(y);
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        if(find(x) == find(y)) puts("Yes");
        else puts("No");
    }
    return 0;
}