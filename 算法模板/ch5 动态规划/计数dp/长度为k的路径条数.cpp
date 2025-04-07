#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int mod = 1e9 + 7,inf = 1e18;
/*
给一张有向简单图，给出邻接矩阵，求长度为 K 的路径条数，答案对 109+7 取模。

邻接矩阵的k次幂结果a[i][j]表示某个点到(i,j)点路径长度为k的路径条数
矩阵快速莫求邻接矩阵的K次幂，即可得到答案
*/
int matlen;
struct mat {
    using i64 = long long;
    i64 a[60][60];
    mat(){
        memset(a,0,sizeof(a));
    }
	mat operator*(mat x) {
        mat ans=mat(); 
        for(int i=1;i<=matlen;i++){
            for(int j=1;j<=matlen;j++){
                for(int k=1;k<=matlen;k++){
                    ans.a[i][j]+=a[i][k]*x.a[k][j]%mod;
                    ans.a[i][j]%=mod;
                }
            }
        }
        return ans;
 	}
    mat operator^(int b){
        mat ans=mat();
        for(int i=1;i<=matlen;i++){
            ans.a[i][i]=1;
        }
        mat base=*this;
        while(b){
            if(b&1)ans=ans*base;
            b>>=1; base=base*base;
        }
        return ans;
    }
};
void solve(){
	int n,k;cin >> n >> k;
	matlen = n;
	mat m = mat();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> m.a[i][j];
		}
	}
	m = m ^ k;
	int ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans = (ans + m.a[i][j]) % mod;
		}
	}
	cout << ans << endl;
}	
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
	#ifdef LOCAL
		freopen("D:\\Others\\desktop\\text.in","r",stdin);
	#endif
    // cin >> T;
    while(T --) solve();
    return 0;
}