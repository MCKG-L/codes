#include <iostream>
using namespace std;
int main()
{
    int n;cin >> n;
    string s;cin >> s;
    for(int i=0;i<n;i++){
        if(s[i] == '('){
            while(s[i] != ')'){
                if(s[i] == ',') s[i] = '.';
                i ++;
            }
        }
    }
    cout << s << endl;
    return 0;
}