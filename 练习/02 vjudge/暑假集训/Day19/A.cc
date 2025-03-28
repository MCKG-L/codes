#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int n;
void solve(){
    cin >> n;
    int cnt = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i] == i + 1) cnt ++;
    }
    cout << (cnt + 1) / 2 << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}