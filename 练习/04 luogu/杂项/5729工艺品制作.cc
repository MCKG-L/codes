#include <iostream>
using namespace std;
const int N = 21;
int a[N][N][N];
int main()
{
    int w,x,h;
    cin >> w >> x >> h;
    int q;cin >> q;
    while(q--){
        int x1,x2,y1,y2,z1,z2;
        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                for(int k=z1;k<=z2;k++){
                    a[i][j][k] = 1;
                }
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=w;i++){
        for(int j=1;j<=x;j++){
            for(int k=1;k<=h;k++){
                if(a[i][j][k] == 0){
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}