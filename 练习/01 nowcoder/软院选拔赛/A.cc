#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned long long ll;
ll solve(string s){
    ll a = 0;
    ll ans = 0;
    for(char i : s){
        if(i == 'b'){
            if(a < 2) continue;
            ans += a * (a-1)/2;
        }
        else if(i == 'a') a++;
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    cout << max(solve("a"+s),solve(s+"b")) << endl;
    return 0;
}