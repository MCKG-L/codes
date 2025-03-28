#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    cout << a.size() << endl;
    for(auto i=a.begin();i!=a.end();i++){
        cout << *i << " \0"[i==prev(a.end())];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}