#include <iostream>
using namespace std;
const int N = 100;
int a[N];
int n;
void solve(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        if(i % 2 == 0){
            cout << (a[i] > 0 ? a[i] : -a[i]) << ' ';
        }else{
            cout << (a[i] < 0 ? a[i] : -a[i]) << ' ';
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