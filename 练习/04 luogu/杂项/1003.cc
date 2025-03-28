#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5+2;
struct P{
    int sx,sy,x,y;
};
vector<P> a(N);
int n,fx,fy;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        int sx,sy,x,y;
        cin >> sx >> sy >> x >> y;
        a[i] = {sx,sy,x,y};
    }
    cin >> fx >> fy;
    for(int i=n-1;i>=0;i--){
        int sx = a[i].sx,sy = a[i].sy;
        int x = a[i].x,y = a[i].y;
        if(sx <= fx && sx + x >= fx && sy <= fy && sy+y >= fy){
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}