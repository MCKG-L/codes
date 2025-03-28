#include <iostream>
using namespace std;
int main()
{
    string s;
    while(cin >> s){
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += ((1 << (n-i)) - 1) * (s[i]-'0');
        }
        cout << ans << endl;
    }
    return 0;
}