#include <iostream>
using namespace std;
int main()
{
    string s;cin >> s;
    if(s.size() <= 3){
        cout << s << endl;
    }else{
        for(int i=0;i<s.size();i++){
            if(i < 3) cout << s[i];
            else cout << '0';
        }
        cout << endl;
    }
    return 0;
}