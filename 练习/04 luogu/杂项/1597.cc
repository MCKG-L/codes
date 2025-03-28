#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int ans[3] = {};
    int pos = 0;
    for(int i=0;i<s.size();i++){
        if(i % 5 == 0) pos = s[i] - 'a';
        else if(i == 3){
            if(s[i] >= '0' && s[i] <= '9') ans[pos] = s[i]-'0';
            else {
                int p = s[i] - 'a';
                ans[pos] = ans[p];
            }
        }
    }
    for(int i=0;i<3;i++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}