#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353ll,inf = 1e18;
class Solution {
    public:
        int sumSubarrayMins(vector<int>& arr) {
            int n = arr.size(),mod = 1e9 + 7;
            vector<int> stk(n + 1);int top = 0;
            vector<int> L(n + 1);
            for(int i=0;i<n;i++){
                while(top && arr[stk[top]] >= arr[i]) top --;
                if(top) L[i] = stk[top];
                else L[i] = 0;
                stk[++top] = i;
            }
            top = 0;
            int ans = 0;
            for(int i=n-1;i>=0;i--){
                while(top && arr[stk[top]] >= arr[i]) top --;
                int r = top ? stk[top] : n - 1;
                cerr << L[i] << ' ' << r << endl;
                ans = (ans + 1LL * (i - L[i] + 1) * (r - i + 1) * arr[i]) % mod;
            }
            return ans;
        }
    };
void solve(){
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}