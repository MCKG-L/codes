#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 30;
vector<int> p[N];
int m_find(int l,int r,int x){
    int max_n = 0;
    for(int i=1;i<=26;i++){
        if(i == x) continue;
        int x = lower_bound(p[i].begin(),p[i].end(),l)-p[i].begin();
        int y = lower_bound(p[i].begin(),p[i].end(),r)-p[i].begin()-1;
        max_n = max(max_n,y-x+1);
    }
    return max_n;
}
void solve(){
    for(int i=0;i<N;i++) p[i].clear();
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        p[x].push_back(i);
    }
    for(int i=1;i<=26;i++) sort(p[i].begin(),p[i].end());
    int max_n = 0;
    for(int i=1;i<=26;i++){
        max_n = max(max_n,(int)p[i].size());
        int l = 0,r = p[i].size()-1;
        while(l < r){
            int g = m_find(p[i][l],p[i][r],i);
            max_n = max(max_n,2*(l+1)+g);
            l++,r--;
        }
    }
    cout << max_n << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}