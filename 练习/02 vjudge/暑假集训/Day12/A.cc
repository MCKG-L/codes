#include <iostream>
#include <map>
using namespace std;
const int N = 55;
map<int,char> mp;
int a[N];
string s;
int n;
void solve(){
    mp.clear();
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    cin >> s;
    for(int i=0;i<n;i++){
        if(mp.count(a[i])){
            if(mp[a[i]] != s[i]){
                cout << "NO" << endl;
                return;
            }
        }
        mp[a[i]] = s[i];
    }

    cout << "YES" << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}