#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int a[N],b[N];
int n;
void solve(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i],b[i] = a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(a[i] % 2 == 0 && b[i] % 2){
            cout << "NO" << endl;
            return;
        }
        if(a[i] % 2 && b[i] % 2 == 0){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}