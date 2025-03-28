#include <iostream>
using namespace std;
const int N = 1010;
int a[N][N];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int n,m;
int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;cin >> c;
            a[i][j] = c - '0';
        }
    }
    int ans = 0;
    bool flag = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == 1 || a[i][j] == 2) continue;
            int cnt = 0;
            for(int k=0;k<4;k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(x < 0 || x >= n || y < 0 || y >= m) continue;
                if(a[x][y] == 1) cnt ++;
                if(a[x][y] == 2){
                    cnt = 0;
                    break;
                }
            }
            if(cnt == 3) ans ++,flag = true;
        }
    }
    if(flag){
        cout << "YES" << endl;
        cout << ans << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}