#include <iostream>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
int a[N],n,q;
void solve(){
    ll s1 = 0,s2 = 0;
    ll sum = 0;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i] & 1) s1 ++;
        else s2 ++;
        sum += a[i];
    }
    while(q--){
        int op,x;
        cin >> op >> x;
        if(op == 0){
            sum += s2 * x;
            if(x & 1) s1 += s2,s2 = 0;
            cout << sum << endl;
        }else{
            sum += s1 * x;
            if(x & 1) s2 += s1,s1 = 0;
            cout << sum << endl;
        }
    }
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}