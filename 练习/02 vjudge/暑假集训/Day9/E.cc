#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
vector<vector<int>> cnt_l(N,vector<int>(3));
vector<vector<int>> cnt_r(N,vector<int>(3));
int a[N];
char s[N];
int n;
int mex(int a,int b,int c){
    for(int i=0;i<3;i++){
        if(a != i && b != i && c != i) return i;
    }
    return 3;
}
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> s[i];

    //统计1~i中M位置分别对应a中0、1、2的数目
    for(int i=1;i<n;i++){
        cnt_l[i] = cnt_l[i-1];
        if(s[i] == 'M') cnt_l[i][a[i]]++;
    }
    //统计i~n中X位置分别对应a中0、1、2的数目
    for(int i=n;i>=1;i--){
        cnt_r[i] = cnt_r[i+1];
        if(s[i] == 'X') cnt_r[i][a[i]]++;
    }
    ll ans = 0;
    //枚举所有的E的位置
    for(int i=1;i<=n;i++){
        if(s[i] != 'E') continue;
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                ans += (ll)cnt_l[i][j]*cnt_r[i][k]*mex(j,a[i],k);
            }
        }
    }
    cout << ans << endl;
    return 0;
}