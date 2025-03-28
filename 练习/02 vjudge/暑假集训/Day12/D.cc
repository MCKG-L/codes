#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
vector<int> p;
int cnt[N],n;
void solve(){
    p.clear();
    cin >> n;
    int s = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        while(x && x % 2 == 0){
            s ++;
            x /= 2;
        }
    }
    if(s >= n){
        cout << 0 << endl;
        return;
    }
    int t = n - s;
    for(int i=1;i<=n;i++){
        if(cnt[i]) p.push_back(cnt[i]);
    }
    sort(p.begin(),p.end(),[&](int a,int b){return a > b;});
    for(int i=0,l=p.size();i<l;i++){
        t -= p[i];
        if(t <= 0){
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    for(int i=1;i<=N-5;i++){
        if(i % 2 == 0){
            cnt[i] = cnt[i>>1] + 1;
        }
    }
    // for(int i=1;i<=100;i++){
    //     cout << cnt[i] << ' ';
    // }
    int t;cin >> t;
    while(t--) solve();
    return 0;
}