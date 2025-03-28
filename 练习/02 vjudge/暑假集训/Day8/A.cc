#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
const int N = 100;
vector<pair<int,int>> p;
int a[N],b[N];
void solve(){
    p.clear();
    int n,t;
    cin >> n >> t;
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i] += i;
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    for(int i=0;i<n;i++){
        if(a[i] <= t){
            p.push_back({b[i],i+1});
        }
    }
    if(p.size() == 0){
        cout << -1 << endl;
        return;
    }
    sort(p.begin(),p.end());
    cout << p.back().second << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}