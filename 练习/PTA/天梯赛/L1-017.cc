#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    bool mask = 0;
    string s;cin >> s;
    if(s[0] == '-') mask = 1;
    int cnt = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]-'0' == 2) cnt++;
    }
    double ans = 0;
    int n = s[0] == '-' ? s.size()-1 : s.size();
    ans = 1.0 * cnt / n * 100;
    if(mask) ans *= 1.5;
    if(s.back() % 2 == 0) ans *= 2;
    cout << fixed << setprecision(2) << ans << "%" << endl;
    return 0;
}