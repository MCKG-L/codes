#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,string>p1,pair<int,string>p2){
    if(p2.second.size() == p1.second.size()){
        return p1.second < p2.second;
    }else return p1.second.size() < p2.second.size();
}
void solve(){  
    int n;cin >> n;
    vector<pair<int,string>> a;
    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        a.push_back({i+1,s});
    }
    sort(a.begin(),a.end(),cmp);
    //cout.setf(ios::fixed,ios::floatfield);//不适用科学计数法
    //cout << a[n-1].first << '\n' << setprecision(0) << a[n-1].second;//控制小数位
    cout << a[n-1].first << '\n' << a[n-1].second;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
