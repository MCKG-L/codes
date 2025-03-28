#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int st[N];
void solve(){
    memset(st,-1,sizeof st);
    int x;cin >> x;
    st[x] = 0;
    int k = 0;
    for(int i=1;i<=999;i++){
        cout << '+' << ' ' << 1 << endl;
        k ++;
        cin >> x;
        if(st[x] != -1){
            cout << '!' << ' ' << k << endl;
            return;
        }
        st[x] = k;
    }
    for(int i=0;i<1000;i++){
        cout << '+' << ' ' << 1000 << endl;
        k += 1000;
        cin >> x;
        if(st[x] != -1){
            cout << '!' << ' ' << k - st[x] << endl;
            return;
        }
        st[x] = k;
    }
}
int main()
{
    int t = 1;
    while(t--) solve();
    return 0;
}