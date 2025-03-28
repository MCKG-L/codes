#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,b;cin >> n >> b;
    int a[n],sum = 0;;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n,[&](int x,int y){return x > y;});
    for(int i=0;i<n;i++){
        sum += a[i];
        if(sum >= b){
            cout << i +1;
            return;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}