#include <iostream>
#include <cstring>
using namespace std;
const int N = 310;
int d[N][N];
int n,m,t;
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j] = min(d[i][j],max(d[i][k],d[k][j]));
            }
        }
    }
}
int main()
{
    cin >> n >> m >> t;
    memset(d,0x3f,sizeof d);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b],c);
    }
    floyd();
    while(t--){
        int a,b;
        cin >> a >> b;
        if(d[a][b] == 0x3f3f3f3f) cout << -1 << endl;
        else cout << d[a][b] << endl;
    }
    return 0;
}