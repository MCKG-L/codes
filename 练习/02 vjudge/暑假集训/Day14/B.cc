#include <iostream>
#include <set>
using namespace std;
const int N = 110;
int a[N]; 
int n,d;
void solve(){
    cin >> n >> d;
    for(int i=0;i<n;i++){
        string s;cin >> s;
        for(int i=0;i<d;i++){
            if(s[i] == 'x') a[i] ++;
        }
    }
    int ans = 0,sum = 0;
    for(int i=0;i<d;i++){
        if(!a[i]) sum++;
        else{
            ans = max(ans,sum);
            sum = 0;
        }
    }
    ans = max(ans,sum);
    cout << ans << endl;
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}