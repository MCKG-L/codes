#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<string,int> mp;
int main()
{
    int n;cin >> n;
    while(n--){
        map<string,int> temp;
        string s;int k;cin >> k;
        for(int i=0;i<k;i++){
            cin >> s;temp[s]++;
        }
        int n = temp.size() - 1;
        for(auto p : temp){
            mp[p.first] += n;
        }
    }
    int m;cin >> m;
    vector<string> ans;
    while(m--){
        string s;cin >> s;
        if(!mp[s]){
            ans.push_back(s);
            mp[s] = 1;
        }
    }
    if(ans.empty()) cout << "No one is handsome" << endl;
    for(int i=0;i<ans.size();i++){
        cout << ans[i];
        if(i != ans.size()-1) cout << " ";
    }
    return 0;
}