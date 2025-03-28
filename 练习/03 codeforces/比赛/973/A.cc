#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a < b && b < c){
        cout << "STAIR" << endl;
    }else if(a < b && c < b){
        cout << "PEAK" << endl;
    }else{
        cout << "NONE" << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t --) solve();
    return 0;
}