#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
/*
对a[i]求前缀异或和，得到sum[i] = b1 ^ bi+1 --> bi+1 = sum[i] ^ b1
所以求出b1,即可求出合理的数组b sum[i]全部已知可求

考虑b1的每一位，由于b数组是一个[0,n)的序列，所以目标数组的每一位中1的个数总和是固定的
题目保证一定存在解，先假设该位为0，则需要判断对应b数组，和目标数组中1的个数
如果不同，说明该位一定不是0，即为1

最终求出的x就是b1，然后可以依次求出bi+1
*/
void solve(){
    int n;cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<n;i++){
        cin >> a[i];
        a[i] ^= a[i-1];
    }
    int x = 0;
    for(int i=0;i<20;i++){
        int cnt1 = 0,cnt2 = 0;
        //0~n-1
        for(int j=0;j<n;j++){
            int d = j >> i & 1;
            cnt1 += d;
        }
        //a[i]
        for(int j=1;j<n;j++){
            int d = a[j] >> i & 1;
            cnt2 += d;
        }
        if(cnt1 != cnt2) x |= 1 << i;
    }
    cout << x << ' ';
    for(int i=1;i<n;i++) cout << (a[i] ^ x) << ' ';
    cout << endl;
}
signed main()
{
    IOS;
	int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}