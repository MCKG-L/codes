#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h,w,n;
    cin >> h >> w >> n;
    vector<pair<int,int>> p;
    vector<int> sx,sy;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        p.push_back({x,y});
        sx.push_back(x);
        sy.push_back(y);
    }
    sort(sx.begin(),sx.end());
    sort(sy.begin(),sy.end());
    //去重
    sx.erase(unique(sx.begin(),sx.end()),sx.end());
    sy.erase(unique(sy.begin(),sy.end()),sy.end());
    //对应坐标
    for(int i=0;i<p.size();i++){
        auto [x,y] = p[i];
        cout << lower_bound(sx.begin(),sx.end(),x) - sx.begin() + 1 << " ";
        cout << lower_bound(sy.begin(),sy.end(),y) - sy.begin() + 1 << endl;
    }
    
    return 0;
}