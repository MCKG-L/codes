#include <iostream>
using namespace std;
void solve(){
    int n;cin >> n;
    int x = 0,y = 0;
    // int ans = 0;
    bool flag = 1;
    for(int i=0;i<n;i++){
        char c;cin >> c;

        if(c == 'U') y ++;
        if(c == 'R') x ++;
        if(c == 'L') x --;
        if(c == 'D') y --;
        if(x == 1 && y == 1){
            flag = 0;
        }
    }
    if(!flag) puts("YES");
    else puts("NO");
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;   
}