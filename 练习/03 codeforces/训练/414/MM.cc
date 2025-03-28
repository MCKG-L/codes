#include <iostream>
#include <vector>
using namespace std;
void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> ans(n);
    int x = 1;
    for(int i=0;i<n;i+=2){
        ans[i] = x;ans[i+1] = -x;
        x ++;
    }
    if(n & 1) ans[n-1] = k;
    else ans[0] += k;
    for(int i : ans){
        cout << i << ' ';
    }
    cout << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}