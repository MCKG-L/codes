#include <iostream>
using namespace std;
int main()
{
    string s;cin >> s;
    int sum = 0,cnt = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'O') cnt++,sum+=cnt;
        else cnt = 0;
    }
    cout << sum << endl;
    return 0;
}