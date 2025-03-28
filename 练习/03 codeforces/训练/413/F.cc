#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;
int n,m;
map<int,string> mp;
vector<vector<int>> v;
vector<int> st;
void bfs(){
    queue<int> que;
    que.push(m);
    while(que.size()){
        int p = que.front();que.pop();
        for(int i : v[p]){
            if(st[i] <= 100) que.push(i);
            st[i] ++;
        }
    }
}
void solve(){
    cin >> n >> m;
    mp.clear();
    v.clear();v.resize(n+1);
    st.clear();st.resize(n+1);
    for(int i=1;i<=n;i++){
        string s;cin >> s;
        mp[i] = s;
    }
    for(int i=1;i<=n;i++){
        int k;cin >> k;
        while(k--){
            int x;cin >> x;
            v[i].push_back(x);
        }
    }
    bfs();
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(st[i] > 100) ans.push_back(i);
    }
    if(ans.size() == 0){
        cout << "No one is disturbed!" << endl;
    }else{
        cout << ans.size() << endl;
        for(int i=0;i<ans.size();i++){
            cout << mp[ans[i]] << ' ';
        }
        cout << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}