#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int ans[N][N];
int main()
{
    int n;cin >> n;
    int x = 1,y = 0,i = 1;
    int mask = 0;
    while(i <= n * n){
        if(mask%4 == 0){
            y++;
            if(ans[x][y] == 0 && y <= n){
                ans[x][y] = i++;
            }else{
                mask++;
                y--;
            }
        }
        if(mask%4 == 1){
            x++;
            if(ans[x][y] == 0 && x <= n){
                ans[x][y] = i++;
            }else{
                mask++;
                x--;
            }
        }
        if(mask%4 == 2){
            y--;
            if(ans[x][y] == 0 && y > 0){
                ans[x][y] = i++;
            }else{
                mask++;
                y++;
            }
        }
        if(mask%4 == 3){
            x--;
            if(ans[x][y] == 0 && x > 0){
                ans[x][y] = i++;
            }else{
                mask++;
                x++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           printf("%3d",ans[i][j]);
        }
        cout << endl;
    }
    return 0;
}