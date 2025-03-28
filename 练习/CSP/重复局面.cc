#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n;cin >> n;
    map<string,int> mp;
    for(int i=0;i<n;i++){
        string s;
        for(int j=0;j<8;j++){
            string ss;cin >> ss;
            s += ss;
        }
        mp[s] ++;
        cout << mp[s] << endl;   
    }
    return 0;
}