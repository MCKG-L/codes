#include <iostream>
using namespace std;
void solve(){
    // int n;cin >> n;
    string s;cin >> s;
    char c = '0';
    for(int i=0;i<s.size();i++){
        if(s[i] == '?'){
            s[i] = c;
        }else{
            c = s[i];
        }
    }
    cout << s << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}