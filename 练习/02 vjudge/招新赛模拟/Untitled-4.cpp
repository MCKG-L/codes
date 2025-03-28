#include <bits/stdc++.h>
using namespace std;
#define  enl          '\n'
#define  int          long long
#define  sz(s)        (int)s.size()
#define  all(v)       (v).begin(),(v).end()

mt19937 rng (chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename A, typename B> ostream& operator<< (ostream &cout, pair<A, B> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; }
template <typename A, typename B> istream& operator>> (istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template <typename A> ostream& operator<< (ostream &cout, vector<A> const &v) {cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";}
template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

const long long mod = 1e9+7;
const long long inf = 1e18;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m));
    cin>>a;

    function<int(int,int)>dfs = [&](int x,int y) {
        if(x < 0 or x >= n or y < 0 or y >= m or a[x][y] == 0) return 0LL;
        int res = a[x][y];
        a[x][y] = 0;
        for(int i=0;i<4;i++) res += dfs(x+dx[i],y+dy[i]);
        return res;
    };

    int ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            amax(ans,dfs(i,j));
        }
    }

    cout<<ans<<enl;
} 

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases = 1;
    cin>>testcases;
    while(testcases--) solve();
    return 0;
}