#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> PII;
const int N = 110;
char a[N][N];
int n,m;
vector<PII> ans;
bool func(int x,int y){
    int nx = x + 8,ny = y + 8;
    bool f = true;
    for(int i=x;i<=x+3;i++){
        for(int j=y;j<=y+3;j++){
            if(i == x + 3){
                if(a[i][j] != '.') return false;
            }else
            if(j == y + 3){
                if(a[i][j] != '.') return false;
            }else{
                if(a[i][j] != '#') return false;
            }
        }
    }
    for(int i=nx;i>=nx-3;i--){
        for(int j=ny;j>=ny-3;j--){
            if(i == nx - 3){
                if(a[i][j] != '.') return false;
            }else if(j == ny - 3){
                if(a[i][j] != '.') return false;
            }else{
                if(a[i][j] != '#') return false;
            }
        }
    }
    return true;
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i] + 1;
    for(int i=1;i<=n-8;i++){
        for(int j=1;j<=m-8;j++){
            if(func(i,j)) ans.push_back({i,j});
        }
    }
    for(auto i : ans){
        cout << i.first << ' ' << i.second << endl;
    }
    return 0;
}