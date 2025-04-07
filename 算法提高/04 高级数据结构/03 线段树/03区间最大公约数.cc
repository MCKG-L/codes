#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353ll,inf = 1e9;
const int N = 5e5 + 10;
/* 区间修改 区间查询最大gcd
利用一个序列的gcd与其差分序列的gcd绝对值相等这个性质
一个数列的最大公约数和其差分数列的最大公约数相同
利用差分数组，转化为单点修改，区间查询的问题，可以用线段树维护区间最大公约数
用树状数组维护前缀和
gcd(A1​,A2​,…,An​)​=gcd[gcd(A1​,A2​),gcd(A2​,A3​),…,gcd(An−1​,An​)]
               =gcd[gcd(A1​,A2​−A1​),…,gcd(An−1​,An​−An−1​)]
               =gcd(A1​,A2​−A1​,A3​−A2​,…,An​−An−1​)​
---> gcd[l,r] = gcd(a[l],gcd(dl+1,dl+2,...,dr))
Q l r -> ans = gcd(a[l],gcd([l+1~r]));
*/
template<class info>
struct SegmentTree {
    vector<info>tree;
    int n;
    SegmentTree(int n) {
        this->n = n;
        tree.resize(4 * n + 10);
    }
	SegmentTree() {
    }
	void init(int n){
		this->n = n;
        tree.resize(4 * n + 10);
	}
    void modify(int i, int st, int ed, int pos, const info u) {
        if (st == ed) {
            // tree[i] = u;
			tree[i].sum += u.sum;
			tree[i].d += u.d;
            return;
        }
        int mid = (st + ed) / 2;
        if (pos <= mid)modify(i * 2, st, mid, pos, u);
        if (pos > mid)modify(i * 2 + 1, mid + 1, ed, pos, u);
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    info ask(int i, int st, int ed, int l, int r) {
        if (st >= l && ed <= r) {
            return tree[i];
        }
        int mid = (st + ed) / 2;
        info u=info();
        if (l <= mid && r > mid) {
            u = ask(i * 2, st, mid, l, r) + ask(i * 2 + 1, mid + 1, ed, l, r);
        }
        else if (r <= mid)u = ask(i * 2, st, mid, l, r);
        else if (l > mid)u = ask(i * 2 + 1, mid + 1, ed, l, r);
        return u;
    }
	template<class F>
	int findFirst(int i,int st,int ed,int l,int r,F &&pred){
		if(st>r||ed<l){
			return -1;
		}
		if(st>=l&&ed<=r&&!pred(tree[i])){//从左向右找第一个满足条件的位置;找不到返回-1
			return -1;
		}
		if(st==ed){
			return st;
		}
		int mid=(st+ed)/2;
		int res=findFirst(2*i,st,mid,l,r,pred);
		if(res==-1){
			res=findFirst(2*i+1,mid+1,ed,l,r,pred);
		}
		return res;
	}
	
	template<class F>
	int findLast(int i,int st,int ed,int l,int r,F && pred){
		if(st>r||ed<l){
			return -1;
		}
		
		if(st>=l&&ed<=r&&!pred(tree[i])){//从右向左找第一个满足条件的位置；找不到返回-1
			return -1;
		}
		if(st==ed)return st;
		int mid=(st+ed)/2;
		int res=findLast(2*i+1,mid+1,ed,l,r,pred);
		if(res==-1) {
		    res=findLast(2*i,st,mid,l,r,pred);
		}
		return res;
	}
    info ask(int l, int r) {
		if(l > r) return {0ll,0ll};
        return ask(1, 1, n, l, r);
    }
    void modify(int pos, info u) {
        modify(1, 1, n, pos, u);
    }
	template<class F>
	int findFirst(int l,int r,F &&pred){
		return findFirst(1,1,n,l,r,pred);
	}
	template<class F>
	int findLast(int l,int r,F &&pred){
		return findLast(1,1,n,l,r,pred);
	}
};
struct Info {
    ll d,sum,l,r;
};
Info operator+(Info ls, Info rs){
	Info u = Info();
	u.l = ls.l,u.r = rs.r;
	u.sum = ls.sum + rs.sum;
	u.d = __gcd(ls.d,rs.d);
	return u;
}
int a[N];
int gcd(int a,int b){
	return b ? gcd(b,a%b) : a;
}
void solve(){
	int n,m;
	cin >> n >> m;
	// vector<ll> a(n + 1);
	for(int i=1;i<=n;i++) cin >> a[i];
	SegmentTree<Info> seg(n);
	for(int i=1;i<=n;i++){
		ll d = a[i] - a[i-1];
		seg.modify(i,{d,d,i,i});
	}
	while(m --){
		string op;int l,r;
		cin >> op >> l >> r;
		if(op == "Q"){
			cout << abs(gcd(seg.ask(1,l).sum,seg.ask(l+1,r).d)) << endl;
		}else{
			ll x;cin >> x;
			seg.modify(l,(Info){x,x});
			if(r + 1 <= n) seg.modify(r+1,(Info){-x,-x});
		}
	}
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