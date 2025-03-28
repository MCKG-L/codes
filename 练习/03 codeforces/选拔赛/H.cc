#include <iostream>
#include <unordered_map>
#include <cstring>
#include <string>
using namespace std;
unordered_map<string,string> mp = {{"chimasu","tte"},{"rimasu","tte"},{"mimasu","nde"},{"bimasu","nde"},{"nimasu","nde"},
{"kimasu","ite"},{"gimasu","ide"},{"shimasu","shite"}};
void solve(){
    string s;cin >> s;
    if(s == "ikimasu"){
        cout << "itte" << endl;
        return;
    }
    int n = s.size();
    string ss = s.substr(n-7,7);
    // cout << ss << "-----" << endl;
    if(mp.count(ss)){
        cout << s.substr(0,n-7) << mp[ss] << endl;
        return;
    }
    ss = s.substr(n-6,6);
    if(mp.count(ss)){
        cout << s.substr(0,n-6) << mp[ss] << endl;
    }
}
int main()
{
    int t;cin >> t;
    while(t--)solve();
    return 0;
}