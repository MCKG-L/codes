#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
//由题知：1~n被完整的划分成了k个子区间
/*
1、发现需要处理的区间段都是关于子区间中点对称的
2、单独考虑每个子区间
3、对于每个子区间 判断每一个对称位置是否需要交换
4、在需要交换的区间端点打上标记，由于两个端点处于对称位置，所以只需要在一端标记 x位置一定是端点之一
5、利用前缀和思想 sum表示该对位置需要交换sum次，sum为偶数不用交换
*/
void solve(){
    int n,k;
    cin >> n >> k;
    string s;cin >> s;s = '*' + s;
    vector<int> L(k),R(k);
    for(int i=0;i<k;i++) cin >> L[i];
    for(int i=0;i<k;i++) cin >> R[i];
    vector<int> cnt(n+1);
    int q;cin >> q;
    for(int i=0;i<q;i++){
        int x;cin >> x;
        cnt[x] ++;
    }
    string ans;
    for(int i=0;i<k;i++){
        int l = L[i],r = R[i];
        int sum = 0;
        string ss = s.substr(l,r-l+1);
        for(int j=l;j<=(l+r)/2;j++){
            sum += cnt[j] + cnt[r-j+l];
            if(sum & 1) swap(ss[j-l],ss[r-j]);
        }
        ans += ss;
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
	int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}