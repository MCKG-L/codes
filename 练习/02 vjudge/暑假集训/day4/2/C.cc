#include <iostream>
using namespace std;
const int N = 2010;
int a[N],n;
void solve(){
    cin >> n;
    string s;cin >> s;
    int cnt = 0;
    for(int i=0;i<n/2;i++){
        if(s[i] != s[n-i-1]) cnt ++;
        else{
            break;
        }
    }
    cout << n - cnt * 2 << endl;
}
int main()
{
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}