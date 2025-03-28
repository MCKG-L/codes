#include <bits/stdc++.h>
using namespace std;
/*
离散化做法
*/
int m_rank(vector<int> &s,int x){
    return lower_bound(s.begin(),s.end(),x) - s.begin() + 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h,w,n;
    cin >> h >> w >> n;
    vector<int> sx,sy;
    vector<pair<int,int>> p;//pai是数对
    int x,y;
    for(int i=1;i<=n;i++){
        cin >> x >> y;
        sx.push_back(x);
        sy.push_back(y);
        p.push_back({x,y});//用大括号
    }
    sort(sx.begin(),sx.end());
    sort(sy.begin(),sy.end());
    sx.erase(unique(sx.begin(),sx.end()),sx.end());
    sy.erase(unique(sy.begin(),sy.end()),sy.end());
    for(int i=0;i<n;i++){
        auto [x,y] = p[i];//结构化绑定 c++17
        cout << m_rank(sx,x) << " " << m_rank(sy,y) << '\n';
    }
    return 0;
}