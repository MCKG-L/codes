#include <iostream>
using namespace std;
char ans[2010],mask[2010];
void solve(){
    int n,a,b;
    cin >> n >> a >> b;
    for(int i=0;i<a;i++){
        if(i >= b) mask[i] = 'a' + b - 1;
        else mask[i] = 'a' + i;
    }
    // for(int i=0;i<a;i++) cout << mask[i];
    // cout << "---" << endl;
    for(int i=0;i<n;i++){
        ans[i] = mask[i%a];
    }
    for(int i=0;i<n;i++) cout << ans[i];
    cout << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}