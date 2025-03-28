#include <iostream>
using namespace std;
void solve(){
    string s;
    cin >> s;
    int a = 1;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i] == '0') a *= 10;
        else {
            cout << (10 - (s[i]-'0')) * a << endl;
            return;
        }
    }
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}