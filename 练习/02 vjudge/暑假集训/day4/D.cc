#include <iostream>
#include <map>
#include <cstring>
using namespace std;
const int N = 2e5 + 10;
char a[N];
int l[N],r[N];
void solve(){
    int n;cin >> n;
    memset(l,0,sizeof l);
    memset(r,0,sizeof r);
    for(int i=1;i<=n;i++) cin >> a[i];
    map<char,int> mp;
    for(int i=1;i<=n;i++){
        if(!mp.count(a[i])){
            l[i] = l[i-1] + 1;
        }else{
            l[i] = l[i-1];
        }
        mp[a[i]] ++;
    }
    mp.clear();
    for(int i=n;i>=1;i--){
        if(!mp.count(a[i])){
            r[i] = r[i+1] + 1;
        }else{
            r[i] = r[i+1];
        }
        mp[a[i]]++;
    }
    int ans = 0;
    for(int i=1;i<n;i++){
        ans = max(ans,l[i]+r[i+1]);
    }
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}