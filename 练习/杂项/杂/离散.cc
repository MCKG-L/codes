#include <iostream>
#include <algorithm>
#include <vector>
#define VPII vector<pair<int,int>>
#define VII vector<int>
using namespace std;
int main()
{
    int h,w,n;
    VPII p;
    VII sx,sy;
    cin >> h >> w >> n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        sx.push_back(x);
        sy.push_back(y);
        p.push_back({x,y});
    }
    sort(sx.begin(),sx.end());
    sort(sy.begin(),sy.end());
    sx.erase(unique(sx.begin(),sx.end()),sx.end());
    sy.erase(unique(sy.begin(),sy.end()),sy.end());
    for(int i=0;i<n;i++){
        int x = p[i].first;
        int y = p[i].second;
        cout << lower_bound(sx.begin(),sx.end(),x) - sx.begin() + 1 << " ";
        cout << lower_bound(sy.begin(),sy.end(),y) - sy.begin() + 1 << endl;
    }
    return 0;
}
