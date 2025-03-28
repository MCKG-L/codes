#include <iostream>
using namespace std;
bool func(string s){
    if(s.size() != 3) return false;
    if(s[0]=='2'&&s[1]=='5'&&s[2]=='0'){
        return true;
    }
    return false;
}
int main()
{
    int k=0;bool mask=1;string s;
    int ans = 0;
    while(cin >> s){
        k++;
        if(func(s) && mask){
            ans = k;
            mask = 0;
        }
    }
    cout << ans << endl;
    return 0;
}