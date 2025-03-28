#include <iostream>
using namespace std;
//分别枚举每一个位置
int main()
{
    string s;cin >> s;
    int b = 0,g = 0;
    for(int i=0;i<s.size()-2;i++){
        if(s[i] == 'b' || s[i+1] == 'o' || s[i+2] == 'y') b++;
    }
    for(int i=0;i<s.size()-3;i++){
        if(s[i] == 'g' || s[i+1] == 'i' || s[i+2] == 'r' || s[i+3] == 'l') g++;
    }
    cout << b << '\n' << g << endl;
    return 0;
}