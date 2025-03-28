#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
void solve(){
    int n;cin >> n;
    string s1,s2;
    int cnt = 0;
    char c[2] = {'#','.'};
    int k = 0;
    for(int i=1;i<=2*n;i++){
        s1 += c[k];
        cnt ++;
        if(cnt % 2 == 0) k ^= 1,cnt = 0;
    }
    k = 1;
    cnt = 0;
    for(int i=1;i<=2*n;i++){
        s2 += c[k];
        cnt ++;
        if(cnt % 2 == 0) k ^= 1,cnt = 0;
    }
    for(int i=1;i<=2*n;i++){
        if(((i + 1) / 2 ) % 2 == 1){
            cout << s1 << endl;
        }else{
            cout << s2 << endl;
        }
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