#include <iostream>
using namespace std;
int main()
{
    string s = "codeforces";
    int t = 1;
    cin >> t;
    while(t--){
        char c;cin >> c;
        if(s.find(c) != string::npos) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}