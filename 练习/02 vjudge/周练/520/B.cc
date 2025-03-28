#include <iostream>
using namespace std;
const int N = 2e5 + 10;
long long a[N];
void solve(){
    long long n,k;
    cin >> n >> k;
    bool mask = 0;
    if(k & 1) mask = 1;
    long long max_n = -0x3f3f3f3f,min_n = 0x3f3f3f3f;
    for(int i=0;i<n;i++){
        cin >> a[i];
        max_n = max(max_n,a[i]);
        min_n = min(min_n,a[i]);
    }
    for(int i=0;i<n;i++){
        if(mask){
            cout << -a[i] + max_n << ' ';
        }else{
            cout << a[i] - min_n << ' ';
        }
    }
    cout << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}