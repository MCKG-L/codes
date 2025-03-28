#include <iostream>
#include <cstring>
using namespace std;
int cnt[26];
void solve(){
    memset(cnt,0,sizeof cnt);
    int n;cin >> n;
    for(int i=0;i<n;i++){
        char c;cin >> c;
        cnt[c-'a']++;
    }
    for(int i=25;i>=0;i--){
        if(cnt[i]){
            cout << i + 1 << endl;
            break;
        }
    }
    
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}