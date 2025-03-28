#include <iostream>
#include <map>
using namespace std;
int main()
{
    string n;cin >> n;
    map<int,int> mp;
    for(auto s : n){
        mp[s-'0']++;
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        cout << it->first << ":" << it->second << endl;
    }
    return 0;
}