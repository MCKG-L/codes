#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 1e5 + 10;
/*
对蓝星而言，任何一个有效的数字，其从左到右每一位上的数字奇偶性都必须是交替出现的
蓝桥星的数字序列从 10 开始，依次为 10,12,14,16,18,21,23,25,27,29,30,…
求第n个数字是什么？
数位dp + 二分
*/
int dp[30][2][2][2];
int len;
string s;
void solve(){
    int n;cin >> n;
    //lim表示是否最为开头，flag表示是否有最高位限制
    //开头往往限制比较特殊，需要单独判断
    auto dfs = [&](auto dfs,int pos,int lim,int flag,int st)->int{
        if(pos == len + 1){
            return 1;
        }
        if(dp[pos][lim][flag][st] != -1){
            return dp[pos][lim][flag][st];
        }
        int num = s[pos] - '0';
        if(flag == 0) num = 9;
        int ans = 0;
        for(int i=0;i<=num;i++){
            if(lim == 1){
                ans += dfs(dfs,pos+1,lim & (i == 0),flag & (i == num),i % 2);
            }else{
                if(i % 2 != st){
                    ans += dfs(dfs,pos+1,lim & (i == 0),flag & (i == num),i % 2);
                }
            }
        }
        return dp[pos][lim][flag][st] = ans;
    };
    auto check = [&](int x)->int{
        s = to_string(x);
        len = s.size();
        s = " " + s;
        memset(dp,-1,sizeof dp);
        return dfs(dfs,1,1,1,0) - 10;
    };
    int l = 1,r = 1e18;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid) >= n) r = mid - 1;
        else l = mid + 1;
    }
    cout << l << endl;
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
