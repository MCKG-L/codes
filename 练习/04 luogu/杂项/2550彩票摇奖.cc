#include <iostream>
using namespace std;
const int N = 8,MAX = 1001;
int ans[N],a[MAX][N],mask[N];
int main()
{
    int n;cin >> n;
    for(int i=1;i<=7;i++){
        cin >> mask[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=7;j++){
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        cnt = 0;
        for(int j=1;j<=7;j++){
            for(int k=1;k<=7;k++){
                if(a[i][j] == mask[k]){
                    cnt++;
                }
            }
        }
        ans[7-cnt]++;
    }
    for(int i=0;i<7;i++){
        cout << ans[i] << " \0"[i == 6];
    }
    return 0;
}