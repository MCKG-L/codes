#include <bits/stdc++.h>
// #define int long long
using namespace std;
const int N = 1e6 + 10;
char s[12][12];
int find(int x,int y){
    int dx = min(10-x,x) + 1;
    int dy = min(10-y,y) + 1;
    return min(dx,dy);
}
void solve(){
    int cnt1 = 0,cnt2 = 0;
    for(int i=0;i<11;i++) scanf("%s",s[i]);
    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){
            if(s[i][j] == 'o') cnt1 += find(i,j);
        }
    }
    for(int i=0;i<11;i++) scanf("%s",s[i]);
    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){
            if(s[i][j] == 'o') cnt2 += find(i,j);
        }
    }
    if(cnt1 > cnt2) cout << "Michael win!";
    else cout << "Bad Michael";
}
signed main()
{
    int t = 1;
    // cin >> t;
    while(t--) solve();
}