#include <iostream>
using namespace std;

int main()
{
    int n;cin >> n;
    string s = "codeforces";
    for(int i=0;i<n;i++){
        char c;cin >> c;
        bool flag = 1;
        for(int j=0;j<s.size();j++){
            if(s[j] == c){
                cout << "YES" << endl;
                flag = 0;
                break;
            }
        }
        if(flag) cout << "NO" << endl;
    }
    return 0;
}