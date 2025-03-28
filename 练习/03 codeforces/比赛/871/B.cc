#include <iostream>
using namespace std;
const int N = 105;
int a[N];
int n;
void solve(){
    cin >> n;
    int ans = 0;
    int s = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(x == 0) s ++;
        else{
            ans = max(ans,s);
            s = 0;
        }
    }
    cout << max(ans,s) << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}