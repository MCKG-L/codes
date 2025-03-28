#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<string> alls;
struct Node{
    string a,b;
    int x;
};
vector<Node> adj;
int n;
void solve(){
    string s;
    cin >> s >> n;
    for(int i=0;i<n;i++){
        string a,b;int x;
        cin >> a >> b >> x;
        
        adj.push_back({a,b,x});
        alls.push_back(a);
        alls.push_back(b);
    }
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    auto find = [&](int x) -> int{
        return lower_bound(alls.begin(),alls.end(),x)-alls.begin();
    };

}
int main()
{
    int t = 1;
    while(t--) solve();
    return 0;
}