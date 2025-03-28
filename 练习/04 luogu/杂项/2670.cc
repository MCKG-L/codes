#include <iostream>
using namespace std;
int dx[8] = {-1,1,0,0,-1,1,1,-1};
int dy[8] = {0,0,-1,1,-1,-1,1,1};
int a[110][110],ans[110][110];
int main()
{
    int n,m;cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;cin.get(c);
            if(c == '\n'){j--;continue;}
            if(c == '*') a[i][j] = 1;
            else if(c == '?') a[i][j] = 0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<8;k++){
                int x = i + dx[k];
                int y = j + dy[k];
                ans[i][j] += a[x][y];
            }
            if(a[i][j] == 1) cout << char('*');
            else cout << ans[i][j];
        }
        cout << endl;
    } 
    return 0;
}