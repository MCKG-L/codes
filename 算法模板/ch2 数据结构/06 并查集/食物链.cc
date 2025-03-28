#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 50010;
/*
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5
*/
int n,m;
int p[N],d[N];
int find(int x){
    if(p[x] != x){
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) p[i] = i;
    int ans = 0;
    while(m--){
        int t,x,y;
        cin >> t >> x >> y;
        if(x > n || y > n) ans++;
        else{
            int px = find(x),py = find(y);
            if(t == 1){
                if(px == py && (d[x] - d[y]) % 3) ans++;
                else if(px != py){
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            }
            else{
                if(px == py && (d[x] - d[y] - 1) % 3) ans++;
                else if(px != py){
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}