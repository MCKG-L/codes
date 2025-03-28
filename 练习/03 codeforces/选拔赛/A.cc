#include <iostream>
using namespace std;
void solve(){
    int k;cin >> k;
    int cnt = 0;
    for(int i=1;i<=6;i++){
        for(int j=i;j<=6;j++){
            if(i + j == k)cnt++;
        }
    }
    cout << cnt << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}