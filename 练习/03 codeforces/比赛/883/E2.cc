#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
set<int> mp;
//1 + k^1 + k^2 + ... + k^p (p >= 2, k >= 2)
/*
发现当p >= 3时，k <= 1000000 ，可以预处理出所有满足 k>=2 && p >= 3的所有n
同时 p == 2时的部分情况也可以预处理
如果没有找到，则一定属于p == 2的情况 需要解方程 1 + k + k^2 == n
*/
void init(){
    //预处理
    for(int k=2;k<=1000000;k++){
        int s = k + 1;
        int t = k * k;
        for(int p=2;p<=63;p++){
            s = s + t;
            if(s > 1e18) break;
            mp.insert(s);
            if(t > (int)(1e18)/k) break;
            t *= k;
        }
    }
}
void solve(){
    int n;cin >> n;
    if(n < 7){
        cout << "NO" << endl;
        return;
    }
    int d = 4 * n - 3;
    int sd = sqrt(d);
    int p = -1;
    if(sd * sd == d) p = sd;
    else if((sd + 1)*(sd + 1) == d) p = sd + 1;
    if(p != -1 && (p-1)%2 == 0 && (p-1)/2 > 1){
        cout << "YES" << endl;
        return;
    }
    if(mp.count(n)) cout << "YES" << endl;
    else cout << "NO" << endl;
}
signed main()
{
    IOS;int T = 1;
    init();
    cin >> T;
    while(T--) solve();
    return 0;
}