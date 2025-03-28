#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool cmp(pair<int,int> p1,pair<int,int> p2){
    if(p1.second != p2.second) return p1.second > p2.second;
    else return p1.first > p2.first;
}
int main()
{
    int n;cin >> n;
    map<int,int> mp;
    while(n--){
        int k;cin >> k;
        for(int i=0;i<k;i++){
            int id;cin >> id;
            mp[id]++;
        }
    }
    vector<pair<int,int>> ans;
    for(auto i : mp){
        ans.push_back(i);
    }
    sort(ans.begin(),ans.end(),cmp);
    cout << ans[0].first << " " << ans[0].second << endl;
    return 0;
}