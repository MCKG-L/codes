#include <bits/stdc++.h>
using namespace std;
void solve(){
    int y,m;
    cin >> y >> m;
    bool mask = false;
    if(y%4==0&&y%100!=0||y%400==0){
        mask = true;
    }
    if(m == 1 || m == 3 || m == 5 || m == 8 || m == 10 || m == 12){
        cout << 31;
    }else if(m == 2){
        cout << (mask ? 29 : 28);
    }else{
        cout << 30;
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}