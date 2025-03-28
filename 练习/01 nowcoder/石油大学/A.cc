#include <iostream>
using namespace std;
int main()
{
    string s = "codeforces";
    int n;cin >> n;
    while(n--){
        string str;cin >> str;
        int ans = 0;
        for(int i=0;i<10;i++){
            if(s[i] != str[i]) ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}