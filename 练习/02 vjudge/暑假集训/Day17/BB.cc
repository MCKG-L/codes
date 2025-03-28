#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 3e5 + 10;
int n,k;
vector<PII> a;
void solve(){
    a.clear();
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        x %= k;
        if(x == 0) x = k;
        a.push_back({x,i});
    }
    sort(a.begin(),a.end(),[&](PII p1,PII p2){
        if(p1.first != p2.first ) return p1.first > p2.first;
        return p1.second < p2.second;
    });
    for(auto i : a){
        cout << i.second << ' ';
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}