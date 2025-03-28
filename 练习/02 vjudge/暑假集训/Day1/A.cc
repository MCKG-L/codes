#include <iostream>
using namespace std;
int main()
{
    int t;cin >> t;
    string a = "codeforces";
    while(t--){
        string s;
        cin >> s;
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] != a[i]) ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}