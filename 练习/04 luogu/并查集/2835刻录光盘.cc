#include <iostream>
using namespace std;
const int N = 210;
/* 这组数据不过
5
2 0
3 0
5 0
3 0
0
*/
int p[N];
int n,ans;
int f[N][N];
int find(int x){
    // if(p[x] != x)p[x] = find(p[x]);
    // return p[x];
    while(p[x] != x)
	x = p[x];
    return p[x];
}
void unite(int a,int b){
	if(!f[a][b]) p[a] = b;
}
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) p[i] = i;
    for(int i=1;i<=n;i++){
        int x;
        while(cin >> x){
            if(x == 0) break;
            f[i][x] = 1;
            unite(x,i);
        }
    }
    for(int i=1;i<=n;i++){
        if(find(i) == i) ans++;
    }
    cout << ans << '\n';
    return 0;
}