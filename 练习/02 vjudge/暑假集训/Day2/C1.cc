#include <iostream>
#include <map>
using namespace std;
void solve(){
    map<char,int> pos;
    int n;cin >> n;
    bool mask = 1;
    for(int i=0;i<n;i++){
        char c;cin >> c;
        if(pos.count(c) && (i - pos[c]) & 1){
            mask = 0;
        }
        pos[c] = i;
    }
    if(mask) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}