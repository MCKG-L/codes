#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5010;
int a[N];
long long sum;
void solve(){
    int n;cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    if(a[0] != 1){
        cout << "NO" << endl;
        return;
    }
    sum = 1;
    for(int i=1;i<n;i++){
        if(a[i] > sum){
            cout << "NO" << endl;
            return;
        }
        sum += a[i];
    }
    cout << "YES" << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}