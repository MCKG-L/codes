#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct point{
    int x,y,cnt;
}a[N];
//cnt记录了每个点出现的次序，坐标作为一个整体，应该用结构体数组。
int main()
{
    int m,k,n;
    cin >> m >> k >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].x >> a[i].y;
        a[i].cnt = i;
    }
    sort(a+1,a+n+1,[&](point p1,point p2){return p1.x < p2.x;});
    int mask = 1,i=1;
    while(a[i].x != 0){
        while(a[i].x == a[i+1].x) a[i++].x = mask;
        a[i++].x = mask++;
    }
    sort(a+1,a+1+n,[&](point p1,point p2){return p1.y < p2.y;});
    mask = i = 1;
    while(a[i].y != 0){
        while(a[i].y == a[i+1].y) a[i++].y = mask;
        a[i++].y = mask++;
    }
    sort(a+1,a+1+n,[&](point p1,point p2){return p1.cnt < p2.cnt;});
    for(int i=1;i<=n;i++){
        cout << a[i].x << " " << a[i].y << endl;
    }
    return 0;
}