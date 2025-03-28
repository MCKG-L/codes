#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
vector<string> a,b;
map<string,int> mp1,mp2,mp;
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string s;cin >> s;
        if(mp1.count(s)) continue;
        mp1[s] ++;
        a.push_back(s);
    }
    for(int i=0;i<m;i++){
        string s;cin >> s;
        if(mp2.count(s)) continue;
        mp2[s] ++;
        b.push_back(s);
    }
    vector<string> ans;
    for(int i=0;i<a.size()||i<b.size();i++){
        if(i < a.size() && !mp.count(a[i])){
            ans.push_back(a[i]);
            mp[a[i]] ++;
        }
        if(i < b.size() && !mp.count(b[i])){
            ans.push_back(b[i]);
            mp[b[i]] ++;
        }
    }
    for(auto i : ans){
        cout << i << '\n';
    }
    return 0;
}