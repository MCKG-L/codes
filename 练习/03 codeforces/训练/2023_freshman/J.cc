#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 60;
int f[N];
void init(){
    // int t = clock();
    f[1] = 1;
    vector<int> a,b;
    a.push_back(1);
    for(int i=1;i<55;i++){
        b.clear();f[i] = a.size();
        for(int j=0;j<a.size();j++){
            int mask = a[j];
            int cnt = 0;
            while(j < a.size() && a[j] == mask) j ++,cnt ++;
            j --;
            b.push_back(cnt);
            b.push_back(mask);
        }
        a = b;
    }
    f[55] = a.size();
    // int t2 = clock();
    // cout << t2 - t << endl;
}
void solve(){
    int x;cin >> x;
    cout << f[x] << endl;
}
signed main()
{
    IOS;int T = 1;init();
    cin >> T;
    while(T--) solve();
    return 0;
}