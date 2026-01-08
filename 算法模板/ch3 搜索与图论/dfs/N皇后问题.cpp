#include <iostream>
using namespace std;
const int N = 20;
int n;
long long ans;
int a[20];
bool b[20],c[20],d[20];
char g[N][N];
void dfs(int x){
    if(x == n){
        // for(int i=0;i<n;i++){
        //     cout << a[i] << ' ';
        // }
        for(int i=0;i<n;i++){
            puts(g[i]);
        }
        cout << endl;
        ans++;
        return;
    }
    for(int i=0;i<n;i++){
        if(!b[i]&&!c[x+i]&&!d[n+i-x]){
            a[x] = i+1;
            g[x][i] = 'Q';
            b[i] = 1;
            c[x+i] = 1;
            d[n+i-x] = 1;
            dfs(x+1);
            g[x][i] = 'X';
            a[x] = 0;
            b[i] = 0;
            c[i+x] = 0;
            d[n+i-x] = 0;
        }
    }
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            g[i][j] = 'X';
        }
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}