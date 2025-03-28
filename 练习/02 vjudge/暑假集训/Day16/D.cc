#include <iostream>
#include <set>
#define int long long
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll a[N];
int n;
set<int> s;
void solve(){
    s.clear();
    cin >> n;
    for(int i=1;i<=n;i++) s.insert(i);
    int cnt = 0,p = 0;
    for(int i=1;i<=n-1;i++){
        cin >> a[i];
        int x = a[i] - a[i-1];
        if(x < 0 || x >  n){
            cnt ++;p = x;
        }else{
            if(s.find(x) == s.end()){
                p = x;cnt ++;
            }else s.erase(s.find(x));
        }
    }
    if(cnt >= 2){
        cout << "NO" << endl;
        return;
    }
    if(cnt == 0){
        cout << "YES" << endl;
        return;
    }
    if(cnt == 1){
        int a = *s.begin(),b = *prev(s.end());
        if(p == a + b){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
signed main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}