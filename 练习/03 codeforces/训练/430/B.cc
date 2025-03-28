#include <iostream>
using namespace std;
int main()
{
    string str;cin >> str;
    bool flag = 0;
    if(str.size() < 3){
        cout << str;
        return 0;
    }
    cout << str[0] << str[1];
    for(int i=2;i<str.size();i++){
        if(str[i-2] == 'c' &&str[i-1] == 'j' && str[i] == 'b'){
            flag ^= 1;
        }
        cout << str[i];
        if(flag) cout << ',',flag ^= 1;
    }
    return 0;
}