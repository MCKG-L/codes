#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
void solve(int n){
    if(n == 0) return;
    vector<int> a(n);
    iota(a.begin(),a.end(),1);
    vector<int> ans;
    int p = 0;
    while(p != a.size() - 1){
        ans.push_back(a[p++]);
        a.push_back(a[p++]);
    }
    cout << "Discarded cards:";
    for(int i=0;i<ans.size();i++){
        if(i == 0) cout << " ";
        else cout << ", ";
        cout << ans[i];
    }
    cout << endl;
    cout << "Remaining card: " << a.back() << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("in.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    int T = 1;
    while(cin >> T){
        solve(T);
        if(T == 0) break;
    }
    // for(int i=1;i<=50;i++) cout << i << endl;
    return 0;
}