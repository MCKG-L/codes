

# 杂项
```cpp
run.bat (r ans)
@echo off
set FILENAME=%1.cpp
set EXENAME=%1.exe
echo compile %FILENAME% ...
g++ "%FILENAME%" -o "%EXENAME%"
if %errorlevel% equ 0 (
    echo runnig %EXENAME% ...
    "%EXENAME%"
) else (
    echo 
)
/*
  a^b=a+b-2*(a&b);
  当n&m!=m时C(n,m)为偶数。
  当n&m==m时C(n,m)为奇数
*/
设 f(x, y) 为x到y的所有整数的异或值
f(1, n)=
   n      n % 4 == 0
   1      n % 4 == 1
   n +1   n % 4 == 2
   0      n % 4 == 3
(p-1)!%p==0如果p为合数(除了4)
(p-1)!%p==-1%p 如何p为质数
       1^3+2^3+...+n^3=[n(n+1)/2]^2
	   1^2+2^2+...+n^2=n(n+1)(2n+1)/6
        错位排序递推公式: F(n)=(n-1)(F(n-1)+F(n-2)), F(1)=0,F(2)=1。
		(将n个数放到n个位置每个位置对应的下标和当前数不一样的排列数)

        就是问这个序列最少可以划分为多少个非递增序列，根据Dilworth定理，我们只需求最长上升子序列的长度就是答案。

	  第二类斯特林数 求n个不同的小球放到m个相同的盒子的方案数
	  预处理0(nm);
	  s(n,m)=s(n-1,m-1)+m*s(n-1,m);
	  int dp[100][100];
	  dp[0][0]=1;
	  for(int i=1;i<=100;i++){
		 for(int j=1;j<=i;j++){
			 dp[i][j]=dp[i-1][j-1]+j*dp[i-1][j];
		 }
	  }
      dp[0][i]=1;
      dp[i][j]=dp[i-1][j]+dp[i][j-1];//

	int x = 13;
	for (int s = x; s; s = x & (s - 1)) {
		cout << s << "\n";
	}
	枚举子集，如x=13(1101) 输出1101,1001,0101,1000,0001,0100,1100，(七个)
	(不知道什么原理)
mt19937_64 rnd(time(0)) 随机生成64为整数 
无向图重定向 必须联通（或许是ed=sqrt(n)???)
ed=(2*m+n-1)/n;
vector<vector<int>>rg(n+1);
	int ed=10;
	queue<int>q;
	for(int i=1; i<=n; i++) {
		if(d[i]<=ed) {
			q.push(i);
		}
	}
	while(q.size()) {
		int u=q.front();
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto it:g[u]) {
			if(vis[it])continue;
			rg[u].push_back(it);
			if(--d[it]<=ed) {
				q.push(it);
			}
		}
}

(x , y)转化成 ({x + y}/2 , {x - y }/2 后 
, 求切比雪夫距离等价于求曼哈顿距离.
(x , y) 转化成 (x + y , x - y) 后
，求曼哈顿距离等价于求切比雪夫距离.
int bitcnt(int x) {return __builtin_popcountll(x); }
int lowbit(int x) { return x & -x; }
int lowbitpos(int x) { return __builtin_ffsll(x);}
int bitmod(int x) { return __builtin_parityll(x); }

```
# 组合等式
1、第二类斯特林数 求n个不同的小球放到m个相同的盒子的方案数
 s(n,m)= $\frac{1}{m!}\sum_{k=0}^{k=m}(-1)^{k}C_{m}^{k}(m-k)^{n}$


2、
$$
\sum_{j=0}^{A} C_i^j = \sum_{j=0}^{A} C_{i-1}^{j-1} + C_{i-1}^j = \left(2 \times \sum_{j=0}^{A} C_{i-1}^j \right) - C_{i-1}^A
$$

设 $ f_i = \sum_{j=0}^{A} C_i^j $。

由上述定义可得递推关系式：

$ f_i = 2 \times f_{i-1} - C_{i-1}^A $


3、$\sum_{i=q}^{n}C_{i}^{q}=C_{n+1}^{q+1}$

4、
$ (-1)^m C_{n-1}^{m} = \sum_{i=0}^{m} (-1)^i \ C_{n}^{i} $

5、
$ \sum_{i=0}^{n} \ C{n}^{i} \cdot i = n \cdot 2^{n-1} $

6、
 $ \sum_{i=0}^{n} \ C{n}^{i} \cdot i^2 = n(n+1) \cdot 2^{n-2} $

7、
$ (x + y)^n = \sum_{i=0}^{n} \ C{n}^{i} x^i y^{n-i} $
# ST表		

```cpp
求区间最大值，求区间最小值，求区间&，求区间|，求区间gcd。				
示例区间最大值。		
template<class T>
struct rmq {
	int n;
	vector<T>a;
	vector<array<T, 21>>f;
	function<T(T, T)>func;
	rmq() {};
	vector<int>len;
	void work(vector<T>a,function<T(T, T)>func_) {
		this->a = a;
		this->func = func_;
		n = a.size();
		f.assign(n+1, {});
		len.resize(n + 1);
		len[1] = 0;
		for (int i = 2; i <= n; i++)len[i] = len[i / 2] + 1;
		for (int i = 1; i <= n; i++)f[i][0] = a[i-1];
		const int lg = log2(n);
		for (int j = 1; j <= lg; j++) {
			for (int i = 1; i + (1 << (j)) - 1 <= n; i++) {
				f[i][j] = func(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
			}
		}
		return;
	}
	T ask(int l, int r) {
		return func(f[l][len[r - l + 1]], f[r - (1 << len[r - l + 1]) + 1][len[r - l + 1]]);
	}
};	
		
```				


# 二维前缀和
```cpp
for(int i=1;i<=n;i++)				
    for(int j=1;j<=m;j++)				
        sum[i][j]=arr[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];	
    auto get=[&](int x1,int y1,int x2,int y2){
		//右下角x2  y2 左上角 x1 y1
		return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
	};
    
arr[x1][y1] += c;
arr[x1][y2+1] -=c;
arr[x2+1][y1] -=c;
arr[x2+1][y2+1] += c;
```				
# 虚树
```cpp
    auto bvt = [&](vector<int> key)
    {
        sort(key.begin(), key.end(), [&](int x, int y)
             { return dfn[x] < dfn[y]; });
        vector<int> a;
        for (int i = 0; i < (int)key.size() - 1; ++i)
        {
            a.push_back(key[i]);
            a.push_back(LCA(key[i], key[i + 1]).first);
        }
        a.push_back(key.back());
        sort(a.begin(), a.end(), [&](int x, int y)
             { return dfn[x] < dfn[y]; });
        a.erase(unique(a.begin(), a.end()), a.end());
        vector<pair<int, int>> ask;
        for (int i = 0; i < (int)a.size() - 1; i++)
        {
            int lc = LCA(a[i], a[i + 1]).first;
            ask.push_back({lc, a[i + 1]});
        }
        return ask;
    };


```
# 树上公共祖先（lca			
```cpp
ll LCA(ll u, ll v) {
	if(dis[u] < dis[v]) swap(u, v);
	per(i, 18, 0) if(dis[fa[u][i]] >= dis[v]) u = fa[u][i];
	if(u == v) return u;
	per(i, 18, 0) if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}

struct  HLD {
    int n;
    vector<int>sz, top, de, fa, id, seq,son,dfn;
    vector<vector<int>>g;
    int cur=0;
    int cnt=0;
    HLD(int n) {
        this->n = n;
        sz.resize(n + 1);
        top.resize(n + 1);
        fa.resize(n + 1);
        de.resize(n + 1);
        dfn.resize(n+1);
        id.resize(n + 1);
        seq.resize(n + 1);
        son.resize(n + 1);
        g.assign(n + 1, {});
    }
    void add(int x, int y) {
        g[x].push_back(y);
    };
    void dfs1(int u,int f) {
        sz[u] = 1;
        int maxx = 0;
        fa[u] = f;
        dfn[u]=++cnt;
        de[u] = de[f] + 1;
        for (auto it : g[u]) {
            if (it == f)continue;
            dfs1(it, u);
            sz[u] += sz[it];
            if (sz[it] > maxx) {
                son[u] = it;
                maxx = sz[it];
            }
        }
    }
    void dfs2(int u, int f, int tp) {
        id[u] = ++cur;
        top[u] = tp;
        seq[cur] = u;
        if (son[u])dfs2(son[u],u,tp);
        for (auto it: g[u]) {
            if (it == f||it==son[u])continue;
            dfs2(it, u, it);
        }
    };
    void work(int root) {
        dfs1(root,0);
        dfs2(root,0,root);
    }
    int lca(int x, int y) {
        while (top[x] != top[y]) {
            if (de[top[x]] < de[top[y]])swap(x, y);
            x = fa[top[x]];
        }
        return de[x] < de[y] ? x : y;
    }
    int dis(int x, int y) {
        return de[x] + de[y] - 2 * de[lca(x, y)];
    }
	bool isson(int x,int y){
		return dfn[x]>=dfn[y]&&dfn[y]+sz[y]-1>=dfn[x];
	}
    int jump(int u, int k) {
        if (de[u] <= k) return -1;
        int d = de[u] - k;
        while (de[top[u]] > d) {
            u = fa[top[u]];
        }
        return seq[id[u] - (de[u] - d)];
    }
};

注意st表
struct HLD{
     vector<vector<int>>g;
     vector<int>dfn,de,seq;
     rmq<pair<int,int>>q;
    int n=0;
    int cnt=0;
    HLD(int n){
        this->n=n;
        g.resize(n+10);
        dfn.resize(2*n+10);
        de.resize(n+10);
        seq.resize(2*n+10);
    }
    void add(int x,int y){
        g[x].push_back(y);
    }
    void dfs(int u,int f,int d){
        dfn[u]=++cnt;seq[cnt]=u;
        de[u]=d;
        for(auto it:g[u]){
            if(it==f)continue;
            dfs(it,u,d+1);
            seq[++cnt]=u;
        }
    }
    void work(int rt){
        dfs(rt,-1,1);
        vector<pair<int,int>>a;
        for(int i=1;i<=2*n-1;i++){
            a.push_back({de[seq[i]],seq[i]});
        }
        q.work(a,[&](auto x,auto y){
            return min(x,y);
        });
    }
    int ask(int a,int b){
        int l=dfn[a];int r=dfn[b];
        if(l>r)swap(l,r);
        return q.ask(l,r).second;
    }
};
```		
# 二进制gcd		
```cpp
int gcd(int a, int b) {
  if(b==0) return abs(a);
  if(a==0) return abs(b);
  int az = __builtin_ctzll(a);
  int bz = __builtin_ctzll(b);
  int z = std::min(az, bz);
  a >>= az, b >>= bz;
  while (a != b) {
    int diff = b - a;
    az = __builtin_ctzll(diff);
    b = b < a ? b : a;
    a = abs(diff) >> az;
  }
  return a << z;
}
```
# exgcd
```cpp
// 要求c%gcd(a,b)==0才成立
// 这里求的是x的最小正整数 且  if(a<0||b<0)gcd(a,b)<0
void exgcd(int a, int b, int &gd, int &x, int &y) {
  if (!b) {
    x = 1;
    y = 0;
    gd = a;
    return;
  }
  exgcd(b, a % b, gd, y, x);
  y -= a / b * x;
}

```
# 值域预处理gcd
```cpp
struct Rangegcd{
vector<int> prime, minp;
vector<bool> book; // 这里面的实际存的的bit类型
void initprime(int n) {
  book.resize(n + 10);
  minp.resize(n + 10);
  for (int i = 2; i <= n; i++) {
    if (!book[i]) {
      prime.push_back(i);
      minp[i] = i;
    }
    for (auto &p : prime) {
      if (1ll*i * p > n)
        break;
      book[i * p] = 1;
      minp[i * p] = p;
      if (i % p == 0)
        break;
    }
  }
}
vector<vector<int>>g;
vector<array<int,3>>ff;
int v;
void init(int n){
     v=sqrt(n);v++;
     initprime(n);
     ff.resize(n+1);
     g.resize(v+1);
     for(int i=0;i<=v;i++)g[i].resize(v+1);
    for(int i=0;i<=v;i++)g[0][i]=g[i][0]=i;
    for(int i=1;i<=v;i++){
        for(int j=1;j<=i;j++){
            g[i][j]=g[j][i]=g[i-j][j];
        }
    }
    for(int i=1;i<=n;i++){
        if(!book[i]){
            ff[i][0]=ff[i][1]=1;ff[i][2]=i;
        }
        else{
            int p=minp[i];
            for(int j=0;j<=2;j++)ff[i][j]=ff[i/p][j];
            ff[i][0]*=p;
            if(ff[i][0]>ff[i][1])swap(ff[i][0],ff[i][1]);
            if(ff[i][1]>ff[i][2])swap(ff[i][1],ff[i][2]);
        }
    }
 }
 int mgg(int x,int &y){
     int d=(x>v)?(y%x==0?x:1):g[x][y%x];
     y/=d;
     return d;
 }
 int gcd(int x,int y){
    return mgg(ff[x][0],y)*mgg(ff[x][1],y)*mgg(ff[x][2],y);
 }
}rangegcd;

```
# 大质数分解
```cpp
mt19937_64 rng(time(0));
struct Factor{
using f64=long double;
//mt19937_64 rng(time(0));
f64 iv;
int m;
void setmod(int mod) {
  m = mod;
  iv = (f64)1 / m;
}
 int gcd(int a, int b) {
  if(b==0) return abs(a);
  if(a==0) return abs(b);
  int az = __builtin_ctzll(a);
  int bz = __builtin_ctzll(b);
  int z = std::min(az, bz);
  a >>= az, b >>= bz;
  while (a != b) {
    int diff = b - a;
    az = __builtin_ctzll(diff);
    b = b < a ? b : a;
    a = abs(diff) >> az;
  }
  return a << z;
}
int mul(int a, int b) {
  int r = a * b - (int)(a * iv * b - 0.5) * m;
  return r < m ? r : r - m;
}
int add(int a, int b) { return a += b, a >= m ? a - m : a; }
int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1)
      ans = mul(ans, a);
    a = mul(a, a);
    b >>= 1;
  }
  return ans;
}
bool isprime(int n) {
  if (n <= 2 || (!(n & 1)))
    return n == 2;
  int t = __builtin_ctzll(n - 1);
  int u = (n - 1) >> t;
  setmod(n);
  for (int i = 0; i < 8; i++) {
    int v = qpow(rng() % (n - 2) + 2, u);
    if (v == 1 || v == n - 1)
      continue;
    for (int j = 1; j <= t; j++) {
      v = mul(v, v);
      if (v == n - 1)
        break;
      if (j == t)
        return false;
    }
  }
  return true;
}
int rho(int n) {
  if (!(n & 1))
    return 2;
  if (n % 3 == 0)
    return 3;
  if (n % 5 == 0)
    return 5;
  if (n % 7 == 0)
    return 7;
  int s = 0, t = 0, c = rng() % (n - 1) + 1;
  for (int i = 1;; i <<= 1) {
    int v = 1;
    s = t;
    for (int j = 1; j <= i; j++) {
      t = mul(t, t);
      t = add(t, c);
      v = mul(v, abs(t - s));
      if (j == i || ((j & 127) == 0)) {
        int d = gcd(n, v);
        if (d > 1)
          return d;
      }
    }
  }
  return 0;
}
vector<int> getprime(int n) {
  vector<int> ans;
  auto f = [&](auto f, int n) {
    if (n == 1)
      return;
    if (isprime(n))
      return ans.push_back(n), void();
    int m = rho(n);
    f(f, m);
    f(f, n / m);
  };
  f(f, n);
  sort(begin(ans), end(ans));
  return ans;
}
}factor;

```

# 组合数
```cpp
struct Comb{
vector<int>f,fac,inv;
int ksm(int a,int b){
     int ans=1;
     a%=mod;
     while(b){
        if(b&1)ans=ans*a%mod;
        b>>=1;a=a*a%mod;
     }
     return ans;
}
void initC(int n) {
  f.resize(n + 10);
  fac.resize(n + 10);
  f[0] = fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = f[i - 1] * i;
  }
  fac[n] = ksm(f[n], mod - 2);
  for (int i = n - 1; i >= 1; i--) {
    fac[i] = fac[i + 1] * (i + 1) % mod;
  }
}
void initinv(int n) {
  inv.resize(n + 10);
  inv[1] = 1;
  for (int i = 2; i <= n; i++) {
    inv[i] = mod - (mod / i * inv[mod % i]) % mod;
  }
}
int C(int n, int m) {
  assert(n>=0);
  if (n < m)
    return 0;
  return f[n] * fac[m] % mod * fac[n - m] % mod;
}
 int Lucas(int n, int m) {
  if (m == 0)
    return 1; // mod*logp(m)*log2(mod)  mod为素数1e5以内大致
  return (C(n % mod, m % mod) * Lucas(n / mod, m / mod)) % mod;
}

}comb;
```
# 莫队			
```cpp		
const int N = 1e6;				
struct node {				
	int l, r;			
}arr[N];				
int be[N];				
bool cmp(struct node a, struct node b) {				
	if (be[a.l] != be[b.l])return a.l < b.l;			
	if (be[a.l] % 2 == 1)return a.r < b.r;			
	return a.r > b.r;			
    //奇偶优化				
}				
signed main() {				
	int n, m; cin >> n >> m;			
	int bk = sqrt(n);
	for (int i = 1; i <= n; i++) {			
		be[i] = (i - 1) / bk + 1;		
	}			
	sort(arr + 1, arr + 1 + m, cmp);			
	auto del = [&](int x) {};			
	auto add = [&](int x) {};			
	int l = 1; int r = 0;			
    //注意先add再del先扩展，再收缩，防止RE。				
	for (int i = 1; i <= m; i++) {			
		while (arr[i].r > r)add(++r);		
		while (arr[i].l < l)add(--l);		
		while (arr[i].r < r)del(r--);		
		while (arr[i].l > l)del(l++);		
	};	
}

```

# 回滚莫队(只增)
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int be[N];
struct node
{
    int l, r, id;
    bool operator<(struct node a)
    {
        if (be[l] != be[a.l])
            return be[l] < be[a.l];
        return r < a.r;
    }
} arr[N];
void slove()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> arr[i].l >> arr[i].r;
        arr[i].id = i;
    }
    int bk = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        be[i] = (i + bk - 1) / bk;
    }
    sort(arr + 1, arr + 1 + q);
    array<int, 3> ans = {0, 0, (int)1e9};
    auto temp = ans;
    int l = bk + 1;
    int r = bk;
    vector<int> cnt(n + 10);
    auto add = [&](int i)
    {
        int x = a[i];
        ans[0] -= (cnt[x] * (cnt[x] - 1)) / 2 * x;
        ++cnt[x];
        ans[0] += (cnt[x] * (cnt[x] - 1)) / 2 * x;
        int now = (cnt[x] * (cnt[x] - 1)) / 2 * x;
        if (now > ans[1])
        {
            ans[1] = now;
            ans[2] = x;
        }
        else if (now == ans[1])
        {
            ans[2] = min(ans[2], x);
        }
    };
    auto del = [&](int i)
    {
        --cnt[a[i]];
    };
    vector<array<int, 2>> sum(q + 10);
    for (int i = 1; i <= q; i++)
    {

                if (be[arr[i].l] >= be[l])
        {
            ans = temp;
            for (int j = l; j <= r; j++)
                del(j);
            r = be[arr[i].l] * bk;
            l = r + 1;
        }

        if (be[arr[i].l] == be[arr[i].r])
        {
            for (int j = arr[i].l; j <= arr[i].r; j++)
            {
                add(j);
            }
            sum[arr[i].id] = {ans[0], ans[2]};
            for (int j = arr[i].l; j <= arr[i].r; j++)
            {
                del(j);
            }
            ans = temp;
            continue;
        }
        while (r < arr[i].r)
        {
            add(++r);
        }
        auto t = ans;
        for (int j = arr[i].l; j < l; j++)
            add(j);
        sum[arr[i].id] = {ans[0], ans[2]};
        for (int j = arr[i].l; j < l; j++)
            del(j);
        ans = t;
    }
    for (int i = 1; i <= q; i++)
    {
        cout << sum[i][0] << " " << sum[i][1] << "\n";
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    mt19937_64 rng(time(0));
    std::cout.tie(0);
    slove();
    return 0;
}

```
# 带修莫队
```cpp

#include <bits/stdc++.h>
using namespace std;
#define int long long
long long asksize;
const int N = 1e6 + 10;
int pos[N];
int pre[N];
int a[N];
struct askuery
{
    int id, t, l, r;
    bool operator<(const askuery &b) const
    {
        return (pos[l] < pos[b.l]) || (pos[l] == pos[b.l] && pos[r] < pos[b.r]) ||
               (pos[l] == pos[b.l] && pos[r] == pos[b.r] && t < b.t);
    }
} ask[N];
struct operation
{
    int p, v, t;
} mo[N];
int vis[N];
signed main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    int cnt1 = 0;
    int cnt2 = 0;
    asksize = pow(n, 0.67);
    for (int i = 1; i <= n; i++)
        cin >> a[i], pre[i] = a[i];
    for (int i = 1; i <= N; i++)
    {
        pos[i] = (i - 1) / asksize;
    }
    for (int i = 1; i <= q; i++)
    {
        char op;
        cin >> op;
        if (op == 'Q')
        {
            int l, r;
            cin >> l >> r;
            ++cnt1;
            ask[cnt1] = {cnt1, cnt2, l, r};
        }
        else
        {
            int x, v;
            cin >> x >> v;
            ++cnt2;
            mo[cnt2].p = x;
            mo[cnt2].v = pre[x];
            pre[x] = mo[cnt2].t = v;
        }
    }
    sort(ask + 1, ask + cnt1 + 1);
    int sum = 0;
    auto add = [&](int i)
    {
        if (++vis[a[i]] == 1)
            sum++;
    };
    auto del = [&](int i)
    {
        if (--vis[a[i]] == 0)
            sum--;
    };
    auto modify = [&](int i, int v, int l, int r)
    {
        if (i >= l && i <= r)
        {
            del(i);
            a[i] = v;
            add(i);
        }
        else
            a[i] = v;
    };
    vector<int> ans(q + 10);

    int l = 1;
    int r = 0;
    int last = 0;
    for (int i = 1; i <= cnt1; i++)
    {
        while (ask[i].r > r)
            add(++r);
        while (ask[i].l < l)
            add(--l);
        while (ask[i].r < r)
            del(r--);
        while (ask[i].l > l)
            del(l++);
        while (last + 1 <= ask[i].t)
        {
            last++;
            modify(mo[last].p, mo[last].t, ask[i].l, ask[i].r);
        }
        while (last > ask[i].t)
        {
            modify(mo[last].p, mo[last].v, ask[i].l, ask[i].r);
            last--;
        }
        ans[ask[i].id] = sum;
    }
    for (int i = 1; i <= cnt1; i++)
    {
        cout << ans[i] << "\n";
    }
}
```

# 树上莫队
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
long long qsize;
const int N = 2e5 + 10;
int pos[N];
struct query
{
    int now, t, l, r;
    int ad = 0;
    bool operator<(const query &b) const
    {
        return (pos[l] < pos[b.l]) || (pos[l] == pos[b.l] && pos[r] < pos[b.r]) ||
               (pos[l] == pos[b.l] && pos[r] == pos[b.r] && t < b.t);
    }
} q[N];
struct operation
{
    int p, v, t;
} mo[N];
int val[N];
int w[N];
int a[N];
int f[N][21];
int de[N];
int pre[N];
int now[N];
int st[N];
int ed[N];
int sum[N];
int cnt[N];
int vis[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int qq;
    cin >> qq;
    int cnt1 = 0;
    int cnt2 = 0;
    qsize = 2500;
    for (int i = 1; i <= m; i++)
        cin >> val[i];
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i], pre[i] = a[i];
    int idx = 0;
    auto dfs = [&](auto dfs, int u, int fa) -> void
    {
        f[u][0] = fa;
        for (int i = 1; i <= 20; i++)
            f[u][i] = f[f[u][i - 1]][i - 1];
        de[u] = de[fa] + 1;
        st[u] = ++idx;
        now[idx] = u;
        for (auto it : g[u])
        {
            if (it == fa)
                continue;
            dfs(dfs, it, u);
        }
        ed[u] = ++idx;
        now[idx] = u;
    };
    dfs(dfs, 1, 0);
    for (int i = 1; i <= idx; i++)
    {
        pos[i] = (i - 1) / qsize;
    }
    auto lca = [&](int x, int y)
    {
        if (de[x] < de[y])
            swap(x, y);
        for (int i = 20; i >= 0; i--)
        {
            if (de[f[x][i]] >= de[y])
                x = f[x][i];
        }
        if (x == y)
            return x;
        for (int i = 20; i >= 0; i--)
        {
            if (f[x][i] != f[y][i])
            {
                x = f[x][i];
                y = f[y][i];
            }
        }
        return f[x][0];
    };
    for (int i = 1; i <= qq; i++)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
        {
            ++cnt1;
            if (st[x] > st[y])
                swap(x, y);
            int lc = lca(x, y);
            if (lc == x)
                q[cnt1] = {cnt1, cnt2, st[x], st[y], 0};
            else
                q[cnt1] = {cnt1, cnt2, ed[x], st[y], lc};
        }
        else
        {
            ++cnt2;
            mo[cnt2].p = x;
            mo[cnt2].v = pre[x];
            pre[x] = mo[cnt2].t = y;
        }
    }
    sort(q + 1, q + cnt1 + 1);
    int ans = 0;
    auto add = [&](int i)
    {
        int x = a[i];
        if (vis[i] == 0)
        {
            ++cnt[x];
            ans += w[cnt[x]] * val[x];
        }
        else
        {
            ans -= w[cnt[x]] * val[x];
            --cnt[x];
        }
        vis[i] ^= 1;
    };
    auto modify = [&](int i, int v)
    {
        if (vis[i])
        {   //如果节点i为1那么说明访问过 所以 他会增加一个cnt的值
            ans -= w[cnt[a[i]]] * val[a[i]];
            cnt[a[i]]--;
            a[i] = v;
            cnt[a[i]]++;
            ans += w[cnt[a[i]]] * val[a[i]];
        }
        else
            a[i] = v; //否则我们不需要考虑节点i在不在区间内部
    };
    int l = 1, r = 0, last = 0;
    for (int i = 1; i <= cnt1; i++)
    {

        while (q[i].r > r)
            add(now[++r]);
        while (q[i].l < l)
            add(now[--l]);
        while (q[i].r < r)
            add(now[r--]);
        while (q[i].l > l)
            add(now[l++]);
        while (last + 1 <= q[i].t)
        {
            last++;
            modify(mo[last].p, mo[last].t);
        }
        while (last > q[i].t)
        {
            modify(mo[last].p, mo[last].v);
            last--;
        }
        int lc = q[i].ad;
        if (lc)
        {
            add(lc);
            sum[q[i].now] = ans;
            add(lc);
        }
        else
            sum[q[i].now] = ans;
    }
    for (int i = 1; i <= cnt1; i++)
    {
        cout << sum[i] << "\n";
    }
}
```
# 分块
```cpp
    int n; cin >> n;
	vector<int>le(n + 10);
	vector<int>ri(n + 10);
	vector<int>nowbk(n + 10);
	int bk = sqrt(n);
	for (int i = 1; i <= n; i++) {
		int cnt = (i - 1) / bk + 1;
		le[i] = (cnt - 1) * bk + 1;//  当前下标所在块的左边界下标
		ri[i] = min(n, cnt * bk);  //  当前下标所在快的右边界下标
		nowbk[i] = cnt;
	}
	auto get = [&](int st, int ed) {
		if (nowbk[st] == nowbk[ed]) {
			for(int i=st;i<=ed;i++){
				
			}
			return;
		}
		for (int i = st; i <= ri[st]; i++) {

		}
		
		for (int i = nowbk[st] + 1; i <= nowbk[ed] - 1; i++) {
			int stpos = (i - 1) * bk + 1; int edpos = min(n, i * bk);//当前块的区间左边界下标和区间右边界下标
		}
		for (int i = le[ed]; i <= ed; i++) {
			
		}
		return ;
	};
   

```	
							
			
				
				
# 约数和			
				
对于对于一个数N，可以被分解质因数为				
N=$p1^{a_1}$*$p2^{a_2}$*$p3^{a_3}$*$p4^{a_4}$.....$pn^{a_n}$				
				
N的约数个数为($a_1$+1)*($a_2$+1)*($a_3$+1)....*($a_n$+1)				
				
				
N的约数和为 ($p1^{0}$+$p1^{1}$+$p1^{2}$...$p1^{a1}$)($p2^{0}$+$p2^{1}$+$p2^{2}$...$p2^{a2}$)				
($p3^{0}$+$p3^{1}$+$p3^{2}$...$p3^{a3}$)....				
($pn^{0}$+$pn^{1}$+$pn^{2}$...$pn^{an}$)				
				
				
```cpp
求（1-n)每一个数约数的个数				
const int N = 1e7;				
int d[N];				
int book[N];				
int arr[N];				
int num[N];				
int cnt;				
void f() {				
    d[1] = 1;				
    for (int i = 2; i <= 1e6; i++) {				
        if (!book[i]) {				
            arr[++cnt] = i, d[i] = 2, num[i] = 1;				
        }				
        for (int j = 1; j <= cnt && 1ll * i * arr[j] <= 1e6; j++) {				
            book[i * arr[j]] = 1;				
            if (i % arr[j] == 0) {				
                num[i * arr[j]] = num[i] + 1;				
                d[i * arr[j]] =d[i]/(num[i]+1)*(num[i * arr[j]] + 1);				
                break;				
            }				
            num[i * arr[j]] = 1;				
            d[i * arr[j]] = d[i]*d[arr[j]];				
        }				
    }				
}				
				
				
```				
				
```cpp		
求(1-n)每一个数所有约数的和				
const int N = 1e5 + 5;				
bool book[N];				
int arr[N];				
long long sp[N], sum[N];				
int cnt;				
void f()				
{   cnt = 0;				
    sp[1] = 1;				
    sum[1] = 1;				
    for (int i = 2; i < N; ++i)				
    {				
        if (!book[i])				
        {				
            arr[cnt++] = i;				
            sp[i] = i + 1;				
            sum[i] = i + 1;				
        }				
        for (int j = 0; j < cnt && i *arr[j] < N; ++j)				
        {				
            book[i * arr[j]] = 1;				
            if (!(i % arr[j]))				
            {				
                sp[i * arr[j]] = sp[i] * arr[j] + 1;				
                sum[i * arr[j]] = sum[i] / sp[i] * sp[i * arr[j]];				
                break;				
            }				
            sum[i * arr[j]] = sum[i] * sum[arr[j]];				
            sp[i * arr[j]] = 1 + arr[j];				
        }				
    }				
}				
```				
# bsgs(exgsbs)
对于gsbs
给定 $a$, $b$, $p$，求最小非负整数 $x$，满足 $a^x \mod p = b \mod p$。
条件gcd(a,p)=1 (a>=1,b>=1,p>=1)

对于exgsbs 要求 (a>=1,b>=1,p>=1)
 ```cpp
int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
        return x = 1, y = 0, a;
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int inv(int v, int p)
{
    int x, y;
    exgcd(v, p, x, y);
    return (x % p + p) % p;
}
int bsgs(int a, int p, int b)
{
    a %= p, b %= p;
    if (b == 1 || p == 1)
        return 0;
    map<int, int> mp;
    int B = ceil(sqrt(p));
    ll s = 1;
    for (int i = 0; i < B; i++, s = s * a % p)
    {
        if (s == b)
            return i;
        mp[s * b % p] = i;
    }
    ll t = s;
    for (int i = 1; i <= B + 1; i++, s = s * t % p)
        if (mp.count(s))
            return i * B - mp[s];
    return -1;
}
int exbsgs(int a, int p, int b)
{
    a %= p, b %= p;
    if (b == 1 || p == 1)
        return 0;
    int cnt = 0;
    int s = 1;
    while (1)
    {
        int d = __gcd(a, p);
        if (d == 1)
            break;
        if (b % d)
            return -1;
        b /= d, p /= d;
        cnt++, s = s * (a / d) % p;
        if (s == b)
            return cnt;
    }
    b = inv(s, p) * b % p;
    ll ret = bsgs(a, p, b);
    return ret == -1 ? -1 : ret + cnt;
}

 ```
# 欧拉函数				
  				
 $\phi$(n)=n*$\prod_{i=1}^{s}(1-\frac{1}{p_i})$				
				
				
 $p_i$为第i个质因子				
$\phi(n)$表示所有小于等于n的和n互质的正整数数量				
 $\sum_{d|n}\phi(d)$=n				
对于一个长度为n的数列a我们可以求				
$\sum_{i=1}^{n}\sum_{j=1}^n\gcd (a_{i},a_{j})$				
				
(反演)等价$\sum_{i=1}^{n}\sum_{j=1}^{n}\sum_{d|a_{i}}\sum_{d|a_{j}}\phi(d)$				
## 性质				
1、若p为质数，φ(p)=p-1				
				
解释：这个显然1~p-1都与p互质，除了p。				
				
2、若p为质数，对于p^k,有φ(p^k)=p^k-p^(k-1)				
				
解释：在范围内，与p^k不互质的数，显然与p^k的gcd是p，那么只要那个数可以*p并且不超过范围，这个*p后的数与n^p不互质，显然1~p^(k-1)都可以*p不超过范围，那么就有p^(k-1)个数与p^k不互质.				
				
3、当n>2是，与n互质的数总是成对存在，如gcd(a,n)=1,则gcd(n-a,n)=1。				
				
解释：我们假设gcd(n-a,n)=m(m!=1),则有n=p*m,n-a=q*m,那么有a=(p-q)*m,则有a与n有公约数m，与gcd(n,a)=1矛盾，得证。				
				
4、因此，n>2时，φ(n)是偶数,而且小于等于n的数中，与n互质的数的总和为：φ(n) * n / 2 (n>1即可)。	
$$
\text{若 } \gcd(a, m) = 1, \text{ 则满足 } a^{\varphi(m)} \equiv 1 \pmod{m}
$$			
 $$让上面这个式子成立的最小正整数一定是\varphi(m)的因子。如果a,m不互质显然不成立$$
$$
a^c \equiv 
\begin{cases} 
a^{c \mod \varphi(m)} & \text{if } \gcd(a, m) = 1 \\
a^{c \mod \varphi(m)} + \varphi(m) & \text{if } \gcd(a, m) \neq 1, c < \varphi(m) \\
a^{(c \mod \varphi(m)) + \varphi(m)} & \text{if } \gcd(a, m) \neq 1, c \geq \varphi(m)
\end{cases}
$$				
```cpp		
质数筛求欧拉函数				
const int N = 1e7;				
int arr[N];				
int book[N];				
int phi[N];				
int cnt;				
	phi[1] = 1;			
	for (int i = 2; i <= 1e6; i++) {			
		if (!book[i])arr[++cnt] = i, phi[i] = i - 1;		
		for (int j = 1; j <= cnt && 1ll * i * arr[j] <= 1e6; j++) {		
			book[i * arr[j]] = 1;	
			if (i % arr[j] == 0) {	
				phi[i * arr[j]] = arr[j] * phi[i];
				break;
			}	
			phi[i * arr[j]] = phi[i] * phi[arr[j]];	
		}		
}		
int phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            res = res / i * (i - 1);
        }
    }
    if (n > 1) {
        res = res / n * (n - 1);
    }
    return res;
}
```				
# 莫比乌斯函数
```cpp
int arr[N];
int book[N];
int mu[N];
void f() {
	int cnt = 0;
	mu[1] = 1;
	for (int i = 2; i <= 1e6; i++) {
		if (!book[i])arr[++cnt] = i,mu[i]=-1;
		for (int j = 1; j <= cnt && i * arr[j] <=1e6; j++) {
			book[i * arr[j]] = 1;
			if (i % arr[j] == 0) {
				mu[i * arr[j]] = 0;
				break;
			}
			mu[i * arr[j]] = -mu[i];
		}
	}
}

```
# 链式向前星建图				
```cpp			
const int N = 1e6;				
int h[N], nex[N], v[N], w[N];				
int idx;				
int dis[N];				
void add(int x, int y, int s) {				
	v[++idx] = y; w[idx] = s;			
	nex[idx] = h[x];			
	h[x] = idx;			
}				
    queue<int>q				
	q.push(1);			
	dis[1] = 0;			
	while (q.size()) {			
		int u = q.front(); q.pop();		
		for (int i = h[u]; i; i = nex[i]) {		
			int j = v[i];	
			if (dis[j] < dis[u] + w[i]) {	
				dis[j] = dis[u] + w[i];
				q.push(j);
			}	
		}		
	}			
				
```				
				
# 矩阵快速幂	
例一		
斐波那契数列
 $ f(n)=f(n-1)+f(n-2))$

$\begin{bmatrix} F(N+1) & F(N)  \end{bmatrix}$=$\begin{bmatrix} F(N) & F(N-1)  \end{bmatrix}$X
$\begin{bmatrix} 1 & 1\\1 & 0  \end{bmatrix}$

$\begin{bmatrix} F(N+1) & F(N)  \end{bmatrix}$=$\begin{bmatrix} F(1) & F(0)  \end{bmatrix}$X $\begin{bmatrix} 1 & 1\\
1 & 0 \end{bmatrix}^n$
例二


$f(n)$=$\begin{cases} 1 \\ 2 \\ f(n-1)+2f(n-2)+n^3\end{cases} $









$\begin{bmatrix} f(n)\\ f(n-1)\\ n^3 \\n^2\\n\\1 \end{bmatrix}$ =$\begin{bmatrix} 1&2&1&3&3&1\\1&0&0&0&0&0\\0&0&1&3&3&1\\0&0&0&1&2&1\\0&0&0&0&1&1\\0&0&0&0&0&1 \end{bmatrix}$=$\begin{bmatrix} f(n-1)\\ f(n-2)\\ (n-1)^3 \\(n-1)^2\\n-1\\1 \end{bmatrix}$




```cpp
int matlen;
struct mat {
    using i64 = long long;
    i64 a[22][22];
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
```

# scc
```cpp
struct scc{
   vector<int>dfn,vis,low,st;
   vector<int>cnt;
   int n;
   int sz=0;
   int idx=0;
   vector<vector<int>>g;
   vector<int>id;
   scc(){
   }
   int size(){
      return sz;
   }
   scc(int n){
      this->n=n;
      g.resize(n+10);
      cnt.resize(n+10);
      dfn.resize(n+10);
      low.resize(n+10);
      vis.resize(n+10);
      id.resize(n+10);
   }
   void add(int x,int y){
       g[x].push_back(y);
   }
   void dfs(int u,int f){
     if(dfn[u])return;
     dfn[u]=low[u]=++idx;
	 vis[u]=1;
     st.push_back(u);
     for(auto it:g[u]){
		 if(it==f)continue; //如果求无向图割边加上这一句
          if(!dfn[it]){
               dfs(it,u);
               low[u]=min(low[u],low[it]);
          }
          else if(vis[it]) {
               low[u]=min(low[u],dfn[it]);
          }
     }
     if(dfn[u]==low[u]){
          sz++;
          while(1){
            int temp=st.back();st.pop_back();
            id[temp]=sz;
            cnt[sz]++;
			   vis[temp]=0;
               if(temp==u)break;
          }
     }
   }
   void work(int root){
       dfs(root,-1);
   }
   vector<vector<int>>newg(){
      vector<vector<int>>rg(n+10);
      map<pair<int,int>,int>mp;
      for(int i=1;i<=n;i++){
          for(auto it:g[i]){
             if(id[it]==id[i])continue;
             if(mp.count({id[i],id[it]}))continue;
             rg[id[i]].push_back(id[it]);
             mp[{id[i],id[it]}]=1;
          }
      }
      return rg;
   }
};
struct Tarjan
{ // 下面都是无向图中
	// incblock 去掉这个点增加的联通块个数。(如果他是孤立点联通快个数反而会减少) (孤立点不算割点)
	vector<int> low, dfn, stk, incblock, h, v, nex, vis;
	vector<int> bri; // 	是不是桥
	vector<int> cut; // 是不是割点
	int idx = 0, total = 0, top = 0;
	void init(int n, int m)
	{
		h.resize(n + 10, -1);
		v.resize(m + 10);
		nex.resize(m + 10, -1);
		bri.resize(m + 10);
		vis.resize(n + 10);
		low.resize(n + 10);
		dfn.resize(n + 10);
		stk.resize(n + 10);
		cut.resize(n + 10);
		incblock.resize(n + 10);
	}
	void add(int x, int y)
	{
		v[total] = y;
		nex[total] = h[x];
		h[x] = total++;
	}
	void work(int u, int fa)
	{
		low[u] = dfn[u] = ++idx;
		stk[top++] = u;
		vis[u] = 1;
		int son = 0;

		for (int i = h[u]; i != -1; i = nex[i])
		{
			int j = v[i];
			if (j == fa)
				continue;
			if (!dfn[j])
			{
				son++;
				work(j, u);
				if (low[u] > low[j])
					low[u] = low[j];
				if (low[j] > dfn[u])
				{
					bri[i] = 1;
					bri[i ^ 1] = 1;
				}
				if (u != fa && low[j] >= dfn[u])
				{
					cut[u] = 1;
					incblock[u]++;
				}
			}
			else if (low[u] > dfn[j])
			{
				low[u] = dfn[j];
			}
		}
		if (u == fa && son > 1)
		{
			cut[u] = 1;
		}
		if (u == fa)
		{
			incblock[u] = son - 1;
		}
		vis[u] = false;
		top--;
	}
} tar;
```
# 懒标记线段树
```cpp
template<class Info, class Tag>
struct  segmenttree {
    int n;
    vector<Info> info;
    vector<Tag> tag;
    void init(int n){
        this->n = n;
        tag.resize(4 * n + 10);
        info.resize(4 * n + 10);
    }
    segmenttree(int n) {
        init(n);
    }
    segmenttree(){

    }
    void up(int i) {
        info[i] = info[2 *i] + info[2 * i+ 1];
    }
    void apply(int i, const Tag& v) {
        info[i].apply(v);
        tag[i].apply(v);
    }
    void down(int i) {
        apply(2 * i, tag[i]);
        apply(2 * i + 1, tag[i]);
        tag[i] = Tag();
    }
    void modify(int i, int pos,int st, int ed, const Info& v) {
        if (st == ed) {
            info[i] = v; return;
        }
        int mid = (st + ed) / 2;
        down(i);
        if (pos <= mid)modify(i * 2, pos, st, mid, v);
        if (pos > mid)modify(i * 2 + 1, pos, mid + 1, ed, v);
        up(i);
    }
    void modify(int pos, const Info& v) {
        modify(1, pos, 1, n, v);
    }
    Info ask(int i, int l, int r, int st, int ed) {
        if (st >= l && ed <= r)
            return info[i];
        int mid = (st + ed) / 2;
        Info u1 = Info();
        Info u2 = Info();
        down(i);
        if (l <= mid)
            u1 = ask(i * 2, l, r, st, mid);
        if (r > mid)
            u2 = ask(i * 2 + 1, l, r, mid + 1, ed);
        return u1+u2;
    }
    Info ask(int l, int r) {
        return ask(1, l, r, 1, n);
    }
    void rangemodify(int i, int l, int r, int st, int ed, const Tag& v) {
        if (st >= l && ed <= r) {
            apply(i, v); return;
        }
        int mid = (st + ed) / 2;
        down(i);
        if (l <= mid)rangemodify(i * 2, l, r, st, mid, v);
        if (r > mid)rangemodify(i * 2 + 1, l, r, mid + 1, ed, v);
        up(i);
     }
    void rangemodify(int l, int r, const Tag& v) {
        rangemodify(1, l, r, 1, n, v);
    }
};
struct Tag {
    void apply(Tag t){

    }
};

struct Info {
    void apply(Tag t) {

    }
};
Info operator+(Info ls, Info rs) {
    Info u;
	
    return u;
}
```

# 线段树
```cpp
template <class Info>
struct segmenttree
{
    vector<Info> info;
    int n;
    void init(int n)
    {
        this->n = n;
        info.resize(4 * n + 10);
    }
    segmenttree(int n)
    {
        this->n = n;
        info.resize(4 * n + 10);
    }
    segmenttree()
    {
    }
    void modify(int i, int st, int ed, int pos, const Info &u)
    {
        if (st == ed)
        {
            info[i] = u;
            return;
        }
        int mid = (st + ed) / 2;
        if (pos <= mid)
            modify(i * 2, st, mid, pos, u);
        if (pos > mid)
            modify(i * 2 + 1, mid + 1, ed, pos, u);
        info[i] = info[i * 2] + info[i * 2 + 1];
    }
    Info ask(int i, int st, int ed, int l, int r)
    {
        if (st >= l && ed <= r)
        {
            return info[i];
        }
        int mid = (st + ed) / 2;
        Info u1 = Info();
        Info u2 = Info();
        down(i);
        if (l <= mid)
            u1 = ask(i * 2, l, r, st, mid);
        if (r > mid)
            u2 = ask(i * 2 + 1, l, r, mid + 1, ed);
        return u1+u2;
    }
    template <class F>
    int findFirst(int i, int st, int ed, int l, int r, F &&pred)
    {
        if (st > r || ed < l)
        {
            return -1;
        }
        if (st >= l && ed <= r && !pred(info[i]))
        {
            return -1;
        }
        if (st == ed)
        {
            return st;
        }
        int mid = (st + ed) / 2;
        int res = findFirst(2 * i, st, mid, l, r, pred);
        if (res == -1)
        {
            res = findFirst(2 * i + 1, mid + 1, ed, l, r, pred);
        }
        return res;
    }

    template <class F>
    int findLast(int i, int st, int ed, int l, int r, F &&pred)
    {
        if (st > r || ed < l)
        {
            return -1;
        }
        if (st >= l && ed <= r && !pred(info[i]))
        {
            return -1;
        }
        if (st == ed)
            return st;
        int mid = (st + ed) / 2;
        int res = findLast(2 * i + 1, mid + 1, ed, l, r, pred);
        if (res == -1)
        {
            res = findLast(2 * i, st, mid, l, r, pred);
        }
        return res;
    }
    Info ask(int l, int r)
    {
        return ask(1, 1, n, l, r);
    }
    void modify(int pos, Info u)
    {
        modify(1, 1, n, pos, u);
    }
    template <class F>
    int findFirst(int l, int r, F &&pred)
    {
        return findFirst(1, 1, n, l, r, pred); // 从左向右找第一个满足条件的位置;找不到返回-1
    }
    template <class F>
    int findLast(int l, int r, F &&pred)
    {
        return findLast(1, 1, n, l, r, pred); // 从右向左找第一个满足条件的位置；找不到返回-1
    }
};
struct Info
{
};
Info operator+(Info ls, Info rs)
{
    Info u = Info();
    return u;
}
```
# 李超树

```cpp
struct line
{
    int k, b, flag;
};
struct litree
{
    int n;
    vector<line> info;
    litree()
    {
    }
    litree(int n)
    {
        init(n);
    }
    void init(int n)
    {
        this->n = n;
        info.resize(4 * (n + 1) + 10);
    }
    int f(line now, int x)
    {
        return now.k * x + now.b;
    }
    void add(int i, int l, int r, int st, int ed, line now)
    {
        int mid = (l + r) / 2;
        if (l >= st && r <= ed)
        {
            if (info[i].flag == 0)
            {
                info[i] = now;
                return;
            }
            if (f(now, l) <= f(info[i], l) && f(now, r) <= f(info[i], r))
            { // 改反
                info[i] = now;
                return;
            }
            if (f(now, l) >= f(info[i], l) && f(now, r) >= f(info[i], r))
            { // 改反
                return;
            }
            if (l == r)
                return;
            // 当前为求最小值
            if (f(now, mid) <= f(info[i], mid))
            { // 若求最大修改为>=
                swap(info[i], now);
            }
            if ((now.b - info[i].b) * 1.0 / (info[i].k - now.k) <= mid)
            {
                add(i * 2, l, mid, st, ed, now);
            }
            else
            {
                add(i * 2 + 1, mid + 1, r, st, ed, now);
            }
            return;
        }
        if (st <= mid)
            add(i * 2, l, mid, st, ed, now);
        if (ed > mid)
            add(i * 2 + 1, mid + 1, r, st, ed, now);
    }
    int ask(int i, int l, int r, int pos)
    {
        int ans = 1e15;
        if (info[i].flag == 1)
        {
            ans = f(info[i], pos);
        }
        if (l == r)
        {
            return ans;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            ans = min(ans, ask(i * 2, l, mid, pos));
        if (pos > mid)
            ans = min(ans, ask(i * 2 + 1, mid + 1, r, pos));
        return ans;
    }
    void add(line now)
    {
        add(1, 1, n, 1, n, now);
    }
    int ask(int pos)
    {
        return ask(1, 1, n, pos);
    }
};



```
# 树链刨分(+上方线段树)
```cpp
vector<int> fa(n + 10), sz(n + 10), top(n + 10), id(n + 10), de(n + 10), son(n + 10);
int idx = 0;
auto dfs1 = [&](auto dfs1, int u, int f) -> void
{
    fa[u] = f;
    de[u] = de[f] + 1;
    sz[u] = 1;
    int maxx = 0;
    for (auto it : g[u])
    {
        if (it == f)
            continue;
        dfs1(dfs1, it, u);
        sz[u] += sz[it];
        if (sz[it] > maxx)
        {
            maxx = sz[it];
            son[u] = it;
        }
    }
};
auto dfs2 = [&](auto dfs2, int u, int f) -> void
{
    top[u] = f;
    id[u] = ++idx;
    if (son[u])
        dfs2(dfs2, son[u], f);
    for (auto it : g[u])
    {
        if (it == fa[u] || it == son[u])
            continue;
        dfs2(dfs2, it, it);
    }
};
dfs1(dfs1, 1, 0);
dfs2(dfs2, 1, 1);
// 随便放的一个函数格式
auto add = [&](int x, int y, int k)
{
    while (top[x] != top[y])
    {
        if (de[top[x]] < de[top[y]])
            swap(x, y);
        seg.modify(id[top[x]], id[x], tag{k});
        x = fa[top[x]];
    }
    if (de[x] < de[y])
        swap(x, y);
    seg.modify(id[y], id[x], tag{k});
};

```
# 扫描线(未离散化)(abc 346 G)
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5;
struct node
{
    int l, r, sum, len;
} tree[N * 4];
void build(int i, int l, int r)
{
    tree[i].l = l;
    tree[i].r = r;
    if (l == r)
        return;
    int mid = (l + r) / 2;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid + 1, r);
    ;
}
void pushup(int i)
{
    if (tree[i].sum >= 1)
        tree[i].len = tree[i].r + 1 - tree[i].l;
    else
    {
        if (tree[i].l != tree[i].r)
            tree[i].len = tree[i * 2].len + tree[i * 2 + 1].len;
        else
            tree[i].len = 0;
    }
}
void change(int i, int l, int r, int f)
{
    if (tree[i].l >= l && tree[i].r <= r)
    {
        tree[i].sum += f;
        pushup(i);
        return;
    }
    int mid = (tree[i].l + tree[i].r) / 2;
    if (l <= mid)
        change(i * 2, l, r, f);
    if (r > mid)
        change(i * 2 + 1, l, r, f);
    pushup(i);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    map<int, int> mp;
    vector<int> pre(n + 10);
    for (int i = 1; i <= n; i++)
    {
        if (mp.count(a[i]))
        {
            pre[i] = mp[a[i]] + 1;
        }
        else
            pre[i] = 1;
        mp[a[i]] = i;
    }
    mp.clear();
    vector<int> suf(n + 10);
    for (int i = n; i >= 1; i--)
    {
        if (mp.count(a[i]))
            suf[i] = mp[a[i]] - 1;
        else
            suf[i] = n;
        mp[a[i]] = i;
    }
    vector<array<int, 4>> st(1);
    for (int i = 1; i <= n; i++)
    {
        int y1 = i;
        int y2 = suf[i];
        st.push_back({pre[i], y1, y2 + 1, 1});
        st.push_back({i + 1, y1, y2 + 1, -1});
    }
    sort(st.begin() + 1, st.begin() + 1 + 2 * n, [&](auto x, auto y)
         { return x[0] < y[0]; });
    int ans = 0;
    build(1, 1, n);
    for (int i = 1; i <= 2 * n; i++)
    {
        ans += (st[i][0] - st[i - 1][0]) * tree[1].len;
        change(1, st[i][1], st[i][2] - 1, st[i][3]);
    }
    cout << ans << "\n";
    return 0;
}
```
# 扫描线(离散化)洛谷原题代码
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> pos;
int s;
const int N = 1e5 * 4;
struct node
{
    int l, r, sum, len;
} tree[810000];
void build(int i, int l, int r)
{
    tree[i].l = l;
    tree[i].r = r;
    if (l == r)
        return;
    int mid = (l + r) / 2;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid + 1, r);
}
void pushup(int i)
{
    if (tree[i].sum >= 1)
        tree[i].len = pos[tree[i].r] - pos[tree[i].l - 1];
    else
    {
        if (tree[i].l != tree[i].r)
            tree[i].len = tree[i * 2].len + tree[i * 2 + 1].len;
        else
            tree[i].len = 0;
    }
}
void change(int i, int l, int r, int f)
{
    if (tree[i].l >= l && tree[i].r <= r)
    {
        tree[i].sum += f;
        pushup(i);
        return;
    }
    int mid = (tree[i].l + tree[i].r) / 2;
    if (l <= mid)
        change(i * 2, l, r, f);
    if (r > mid)
        change(i * 2 + 1, l, r, f);
    pushup(i);
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<array<int, 4>> st(1);
    for (int i = 1; i <= n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        st.push_back({x1, y1, y2, 1});
        st.push_back({x2, y1, y2, -1});
        pos.push_back(y1);
        pos.push_back(y2);
    }
    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());
    int len = pos.size();
    auto find = [&](int x)
    {
        return lower_bound(pos.begin(), pos.end(), x) - pos.begin() + 1;
    };
    sort(st.begin() + 1, st.begin() + 1 + 2 * n, [&](auto x, auto y)
         { return x[0] < y[0]; });
    build(1, 1, len);
    int ans = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        s++;
        int x = find(st[i][1]);
        int y = find(st[i][2]);
        ans += (st[i][0] - st[i - 1][0]) * tree[1].len;
        change(1, x, y - 1, st[i][3]);
    }
    cout << ans << "\n";
    return 0;
}
```
# 树状数组


```cpp
struct fenwick
{
    using i64 = long long;
    vector<i64> c;
    int n;
    int lg2;
    fenwick(int n)
    {
        c.resize(n + 1);
        lg2 = log2(n) + 1;
        this->n = n;
    }
    void clear(int i)
    {
        while (i <= n)
        {
            c[i] = 0;
            i += i & -i;
        }
    }
    void add(int i, i64 x)
    {
        while (i <= n)
        {
            c[i] += x;
            i += i & -i;
        }
    }
    i64 sum1(int i)
    {
        i64 sum = 0;
        while (i)
        {
            sum += c[i];
            i -= i & -i;
        }
        return sum;
    }
    i64 getsum(int l, int r)
    {
        return sum1(r) - sum1(l - 1);
    }
    int kth(i64 k)
    { // 求第K小的数是多少// 如 1 3 3 4 第二小的数是3,第三小数是3
        i64 now = 0;
        i64 sum = 0;
        for (int i = lg2; i >= 0; i--)
        {
            if (now + (1 << i) <= n && sum + c[now + (1 << i)] < k)
            {
                sum += c[now + (1 << i)];
                now += (1 << i);
            }
        }
        return now + 1;
    }
};
```

# 线性基
```cpp
struct xorbase
{
    vector<int> base;
    int iszero = 0;
    xorbase()
    {
        base.resize(70);
    }
    int insert(int x)
    {
        for (int i = 60; i >= 0; i--)
        {
            if (x >> i & 1)
            {
                if (base[i])
                    x ^= base[i];
                else
                {
                    base[i] = x;
                    return 1ll;
                }
            }
        }
        iszero = 1;
        return 0ll;
    }
    int getmax()
    {
        int ans = 0;
        for (int i = 60; i >= 0; i--)
        {
            ans = max(ans, ans ^ base[i]);
        }
        return ans;
    }
    void work()
    {
        for (int i = 0; i <= 60; i++)
        {
            for (int j = i - 1; j >= 0; j--)
                if (base[i] & (1ll << j))
                    base[i] ^= base[j];
        }
    }
    int kth(int k) // 求的是去重后的第k小 这里我们不算空集所以可能异或不出来0
    {
        k -= iszero;
        if (k == 0)
            return 0;
        int ans = 0;
        for (int i = 0; i <= 60; i++)
        {
            if (base[i])
            {
                if (k & 1)
                {
                    ans ^= base[i];
                }
                k >>= 1;
            }
        }
        if (k != 0)
            return -1; // 总的异或种类小于k；
        return ans;
    }
    int all()
    {
        int cnt = 0;
        for (int i = 0; i <= 60; i++)
        {
            if (base[i])
                cnt++;
        }
        return (1ll << cnt) - (iszero ^ 1);
    }
};

struct Ji
{
    int p[31], pos[31];
    void insert(int j, int x)
    {
        for (int i = 30, val = x; i >= 0; --i)
            if (val & (1 << i))
            {
                if (!p[i])
                {
                    p[i] = val, pos[i] = j;
                    return;
                }
                if (pos[i] < j)
                {
                    swap(pos[i], j);
                    swap(val, p[i]);
                }
                val ^= p[i];
            }
    }
    int qry(int l)
    {
        int ans = 0;
        for (int i = 30; i >= 0; --i)
            if (p[i] && pos[i] >= l)
                ans = max(ans, ans ^ p[i]);
        return ans;
    }
} ;
```

# 单调队列
```cpp
struct moqueue
{
    using i64 = int;
    vector<pair<i64, i64>> mx;
    vector<pair<i64, i64>> mn;
    int l1 = 1, r1 = 0, l2 = 1, r2 = 0;
    int n, k;
    int i = 0;
    moqueue(int n)
    {
        // 这里的k表示的是队列中维护的序列长度
        this->n = n;
        mx.resize(n + 10);
        mn.resize(n + 10);
    }
    void set(int k)
    {
        this->k = k;
    }
    void add(i64 x)
    {
        i++;
        while (l1 <= r1 && i - mx[l1].first >= k)
            l1++;
        while (r1 >= l1 && mx[r1].second <= x)
            r1--;
        mx[++r1] = {i, x};
        while (l2 <= r2 && i - mn[l2].first >= k)
            l2++;
        while (r2 >= l2 && mn[r2].second >= x)
            r2--;
        mn[++r2] = {i, x};
    }
    i64 max()
    {
        while (l1 <= r1 && i - mx[l1].first >= k)
            l1++;
        if (l1 > r1)
            return -1e9;
        return mx[l1].second;
    }
    i64 min()
    {
        while (l2 <= r2 && i - mn[l2].first >= k)
            l2++;
        if (l2 > r2)
            return 1e9;
        return mn[l2].second;
    }
};
```

 # ntt
 ```cpp
vector<int> NTT(vector<int> a, vector<int> b)
{
    int s = a.size() + b.size() - 1;
    int len = 1;
    while (len < a.size() + b.size())
        len *= 2;
    a.resize(len);
    b.resize(len);
    const int mod = 998244353;
    int n = a.size();
    int m = b.size();
    const int lg = log2(n);
    auto ksm = [&](int a, int b)
    {
        int ans = 1;
        while (b)
        {
            if (b & 1)
                ans = ans * a % mod;
            b >>= 1;
            a = a * a % mod;
        }
        return ans;
    };
    auto ntt = [&](vector<int> &a, int f)
    {
        for (int i = 0; i < n; i++)
        {
            int ans = 0;
            int cnt = 0;
            for (int j = lg - 1; j >= 0; j--)
            {
                if (i >> j & 1)
                    ans += (1 << cnt);
                cnt++;
            }
            if (i <= ans)
                swap(a[i], a[ans]);
        }
        for (int len = 2; len <= n; len *= 2)
        {
            int gn = ksm(3, (mod - 1) / len);
            if (f)
                gn = ksm(3, mod - 1 - (mod - 1) / len);
            for (int i = 0; i < n; i += len)
            {
                int w = 1;
                for (int j = i; j < i + len / 2; j++)
                {
                    int y = w * a[j + len / 2] % mod;
                    int x = a[j];
                    a[j] = (x + y) > mod ? x + y - mod : x + y;
                    a[j + len / 2] = (x - y + mod) > mod ? x - y : x - y + mod;
                    w = w * gn % mod;
                }
            }
        }
    };
    ntt(a, 0);
    ntt(b, 0);
    for (int i = 0; i < n; i++)
        a[i] = a[i] * b[i] % mod;
    ntt(a, 1);
    int inv = ksm(n, mod - 2);
    for (int i = 0; i < n; i++)
        a[i] = a[i] * inv % mod;
    while (a.size() > s)
        a.pop_back();
    return a;
}
模数     原根 
104857601     3
167772161     3
469762049     3
998244353     3
79164837199873 5 
2748779069441 3
39582418599937 5
1337006139375617 3
1231453023109121 3
3799912185593857 5
31525197391593473 3
180143985094819841 6
 ```
# fft
```cpp
vector<int> FFT(vector<int> a1, vector<int> b1)
{
    #define comp complex<double>
    const double PI = acos(-1);
    vector<comp> a(a1.size()), b(b1.size());
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = a1[i];
    }
    for (int i = 0; i < b.size(); i++)
    {
        b[i] = b1[i];
    }
    int s = a.size() + b.size() - 1;
    int lim = 1;
    int l = 0;
    while (lim < s + 1)
        lim *= 2, l++;
    vector<int> r(lim);
    a.resize(lim);
    b.resize(lim);
    for (int i = 0; i < lim; i++)
    {
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    }
    auto fft = [&](vector<comp> &a, int type)
    {
        for (int i = 0; i < lim; i++)
            if (i < r[i])
                swap(a[i], a[r[i]]);
        for (int i = 1; i < lim; i <<= 1)
        {
            comp x(cos(PI / i), type * sin(PI / i));
            for (int j = 0; j < lim; j += (i << 1))
            {
                comp y(1, 0);
                for (int k = 0; k < i; k++, y *= x)
                {
                    comp p = a[j + k], q = y * a[j + k + i];
                    a[j + k] = p + q;
                    a[j + k + i] = p - q;
                }
            }
        }
    };
    fft(a, 1);
    fft(b, 1);
    for (int i = 0; i < lim; i++)
        a[i] *= b[i];
    fft(a, -1);
    while (a.size() > s)
        a.pop_back();
    vector<int> ans;
    for (auto it : a)
    {
        ans.push_back((int)(0.5 + it.real() / lim));
    }
    return ans;
}

```

# 主席树
```cpp
struct Ptr
{
    vector<int> ls, rs, sum, root;
    int idx = 0, size = 0, n = 0, range = 0;
    void init(vector<int> a, int size, int range)
    { // 动态开点
        this->n = a.size();
        this->range = range;
        this->size = size;

        root.resize(n + 1);
        ls.resize(size + 5);
        rs.resize(size + 5);
        sum.resize(size + 5);

        a.insert(a.begin(), 0);
        for (int i = 1; i <= n; i++)
            root[i] = insert(root[i - 1], 1, range, a[i]);
    }
    Ptr(vector<int> a, int size, int range)
    {
        // 动态开点
        init(a, size, range);
    }
    int insert(int pre, int l, int r, int pos)
    {
        int rt = ++idx;
        ls[rt] = ls[pre];
        rs[rt] = rs[pre];
        sum[rt] = sum[pre];
        sum[rt]++;
        if (l == r)
            return rt;
        int mid = (l + r) / 2;
        if (pos <= mid)
            ls[rt] = insert(ls[pre], l, mid, pos);
        else
            rs[rt] = insert(rs[pre], mid + 1, r, pos);
        return rt;
    };
    int kth(int pre, int now, int l, int r, int k)
    {
        if (l == r)
        {
            return l;
        }
        int mid = (l + r) / 2;
        int ans = sum[ls[now]] - sum[ls[pre]];
        if (k <= ans)
            return kth(ls[pre], ls[now], l, mid, k);
        else
            return kth(rs[pre], rs[now], mid + 1, r, k - ans);
    };
    int kth(int l, int r, int k)
    {
        return kth(root[l - 1], root[r], 1, range, k);
    }
    int rangecnt(int pre, int now, int st, int ed, int l, int r)
    {
        if (!sum[now])
            return 0;
        if (st >= l && ed <= r)
        {
            return sum[now] - sum[pre];
        }
        int ans = 0;
        int mid = (st + ed) / 2;
        if (l <= mid)
            ans += rangecnt(ls[pre], ls[now], st, mid, l, r);
        if (r > mid)
            ans += rangecnt(rs[pre], rs[now], mid + 1, ed, l, r);
        return ans;
    }
    int rangecnt(int l, int r, int v1, int v2)
    {
        return rangecnt(root[l - 1], root[r], 1, range, v1, v2);
    }
};
```


# 并查集
```cpp
struct DSU
{
    vector<int> f, siz;
    DSU() {}
    DSU(int n)
    {
        init(n);
    }
    void init(int n)
    {
        f.resize(n + 1);
        iota(f.begin() + 1, f.begin() + 1 + n, 1);
        siz.assign(n + 1, 1);
    }
    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x)
    {
        return siz[find(x)];
    }
};

struct DSU
{
    vector<int> f, fv;
    int find(int x)
    {
        if (f[x] == x)
            return x;
        int xx = find(f[x]);
        fv[x] ^= fv[f[x]];
        f[x] = xx;
        return xx;
    }
    DSU(int n)
    {
        f.resize(n + 10);
        fv.resize(n + 10);
        for (int i = 1; i <= n; i++)
            f[i] = i;
    }
    int merge(int x, int y, int w)
    {
        int u = x;
        int v = y;
        x = find(x);
        y = find(y);
        if (x == y)
        {
            if ((fv[u] ^ fv[v] ^ w) == 0)
                return 1;
            else
                return -1;
        }
        f[x] = y;
        fv[x] = fv[u] ^ fv[v] ^ w;
        return 2;
    }
};
```
# 带权并查集
```cpp
int find(int x){
    if(f[x]==x)return x;
    int now=f[x];
    f[x]=find(f[x]);
    val[x]+=val[now];
    return f[x];
};
void slove(){
   for(int i=1;i<=n;i++)f[i]=i,val[i]=0;
   for(int i=1;i<n;i++){
      int a,b,c;cin>>a>>b;
      int x=find(a);int y=find(b);
      // 他们之间的权值为1
      val[y]+=val[a]+1;
      f[y]=x;
   }
}
```
# 可撤销并查集
```cpp
struct DSU{
    int n;
	vector<int>f,sz,s;
	DSU(){
	}
	DSU(int n){
		f.resize(n+1);
		sz.resize(n+1,1);
		for(int i=1;i<=n;i++)f[i]=i;
	}
    int find(int x){return f[x] == x? x : find(f[x]);}
    void merge(int x, int y){
        x = find(x), y = find(y);
        if(x == y){
            st.push_back(-1);
            return;
        }
		if(sz[x]>sz[y])swap(x,y);
		s.push_back(x);
		f[x] = y; 
		sz[y] += sz[x];
    }
    void del(){
		if(s.size()){
			int x=s.back();
            if(x==-1){
                st.pop_back();return;
            }
			sz[f[x]]-=sz[x];
			f[x]=x;
			s.pop_back();
		}
    }
};

```
# 马拉车
```cpp
 vector<int> mach(string s)
{
    string t = "#";
    for (int i = 1; i < s.size(); i++)
    {
        t += s[i];
        t += '#';
    }
    int n = t.size();
    vector<int> r(n + 1);
    for (int i = 0, j = 0; i < n; i++)
    {
        if (2 * j - i >= 0 && j + r[j] > i)
        {
            r[i] = min(r[2 * j - i], j + r[j] - i);
        }
        while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]])
        {
            r[i] += 1;
        }
        if (i + r[i] > j + r[j])
        {
            j = i;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        r[i] = r[i - 1] - 1;
    }
    return r;
}
```

# 哈希
```cpp
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
```


	
# 单哈希(自然溢出)
```cpp
struct Hash
{
    using ull = unsigned long long;
    vector<ull> base;
    vector<ull> h;
    ull p = 131;
    Hash(string s)
    {
        int n = s.size() - 1;
        base.resize(n + 10);
        h.resize(n + 10);
        base[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            base[i] = base[i - 1] * p;
            h[i] = h[i - 1] * p + s[i];
        }
    }
    ull get(int l, int r)
    {
        assert(l <= r);
        return h[r] - h[l - 1] * base[r - l + 1];
    }
};
```
# 单哈希(取模)
```cpp
struct Hashmod
{
    using ll = long long;
    vector<ll> base;
    vector<ll> h;
    ll p = 131;
    const ll mod = 1e9 + 7;
    Hashmod(string s)
    {
        int n = s.size() - 1;
        base.resize(n + 10);
        h.resize(n + 10);
        base[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            base[i] = base[i - 1] * p % mod;
            h[i] = (h[i - 1] * p + s[i]) % mod;
        }
    }
    ll get(int l, int r)
    {
        assert(l <= r);
        return ((h[r] - h[l - 1] * base[r - l + 1]) % mod + mod) % mod;
    }
};

```


# 双哈希
```cpp
struct Hash
{
    using i64 = long long;
    using ui64 = unsigned long long;
    vector<ui64> h1;
    vector<ui64> h2;
    vector<ui64> p;
    vector<i64> p1;
    vector<i64> h11;
    vector<i64> h22;
    int base = 131;
    const i64 mod = 1e9 + 7;
    int base1 = 11311;
    vector<int> st = {
        13, 13231, 1313, 13131, 1221, 13331, 13341,
        1331, 11, 1221, 134531, 1144, 131};
    Hash(string s, int n)
    {
        h1.resize(n + 10);
        h2.resize(n + 10);
        p.resize(n + 10);
        h11.resize(n + 10);
        h22.resize(n + 10);
        p1.resize(n + 10);
        p[0] = 1;
        p1[0] = 1;
        int x, y;
        while (1)
        {
            x = rnd() % 13;
            y = rnd() % 13;
            x = abs(x);
            y = abs(y);
            if (x == y)
                continue;
            break;
        }
        base = st[x];
        base1 = st[y];
        for (int i = 1; i <= n; i++)
        {
            p[i] = p[i - 1] * base;
            p1[i] = p1[i - 1] * base1;
            p1[i] %= mod;
        }
        for (int i = 1; i <= n; i++)
        {
            h1[i] = h1[i - 1] * base + s[i];
            h11[i] = h11[i - 1] * base1 + s[i];
            h11[i] %= mod;
        }
        for (int i = n; i >= 1; i--)
        {
            h2[i] = h2[i + 1] * base + s[i];
            h22[i] = h22[i + 1] * base1 + s[i];
            h22[i] %= mod;
        }
    }
    pair<ui64, ui64> get(int l, int r)
    {
        return {h1[r] - h1[l - 1] * p[r - l + 1], ((h11[r] - h11[l - 1] * p1[r - l + 1] % mod) % mod + mod) % mod};
    }
    pair<ui64, ui64> getflip(int l, int r)
    {
        return {h2[l] - h2[r + 1] * p[r - l + 1], ((h22[l] - h22[r + 1] * p1[r - l + 1] % mod) % mod + mod) % mod};
        ;
    }
};
```



# 后缀数组
```cpp
struct sufarr
{
    vector<int> rank, sa, tp, cnt, lcp, len;
    vector<array<int, 21>> f;
    int n;
    sufarr(string s)
    {
        // 下标从1开始
        this->n = s.size() - 1;
        rank.resize(n + 2);
        sa.resize(n + 2);
        tp.resize(n + 2);
        cnt.resize(n + 2);
        lcp.resize(n + 2);
        for (int i = 1; i <= n; i++)
            sa[i] = i;
        sort(sa.begin() + 1, sa.begin() + 1 + n, [&](int x, int y)
             { return s[x] < s[y]; });
        for (int i = 1; i <= n; i++)
        {
            rank[sa[i]] = rank[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
        }
        auto sort = [&]()
        {
            for (int i = 1; i <= n; i++)
                cnt[i] = 0;
            for (int i = 1; i <= n; i++)
                cnt[rank[i]]++;
            for (int i = 1; i <= n; i++)
                cnt[i] += cnt[i - 1];
            for (int i = n; i >= 1; i--)
                sa[cnt[rank[tp[i]]]--] = tp[i];
        };
        for (int w = 1; w <= n; w *= 2)
        {
            int p = 0;
            for (int i = 1; i <= w; i++)
                tp[++p] = n - i + 1;
            for (int i = 1; i <= n; i++)
                if (sa[i] > w)
                    tp[++p] = sa[i] - w;
            sort();
            swap(rank, tp);
            rank[sa[1]] = 1;
            for (int i = 2; i <= n; i++)
            {
                int x = sa[i - 1] + w;
                if (x > n)
                    x = -1;
                else
                    x = tp[sa[i - 1] + w];
                int y = sa[i] + w;
                if (y > n)
                    y = -1;
                else
                    y = tp[sa[i] + w];
                rank[sa[i]] = rank[sa[i - 1]] + !(tp[sa[i - 1]] == tp[sa[i]] && x == y);
            }
        }
        int k = 0;
        for (int i = 1; i <= n; i++)
        {
            if (k >= 1)
                k--;
            int j = sa[rank[i] - 1];
            while (i + k <= n && j + k <= n && s[i + k] == s[j + k])
                k++;
            lcp[rank[i]] = k;
        }
    }
    void work()
    {
        f.assign(n + 1, {});
        len.resize(n + 1);
        len[1] = 0;
        for (int i = 2; i <= n; i++)
            len[i] = len[i / 2] + 1;
        for (int i = 1; i <= n; i++)
            f[i][0] = lcp[i];
        const int lg = log2(n);
        for (int j = 1; j <= lg; j++)
        {
            for (int i = 1; i + (1 << (j)) - 1 <= n; i++)
            {
                f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int getlcp(int l, int r)
    {
        if (l > r)
            swap(l, r);
        l++;
        return min(f[l][len[r - l + 1]], f[r - (1 << len[r - l + 1]) + 1][len[r - l + 1]]);
    }
};

```


# Z函数

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int vis[300];
#define int long long
vector<int> ex(string s)
{
    int n = s.size();
    s = " " + s;
    vector<int> z(n + 10);
    int l = 1;
    int r = 0;
    for (int i = 2; i <= n; i++)
    {
        if (i <= r)
            z[i] = min(z[i - l + 1], r - i + 1);
        while (i + z[i] <= n && s[i + z[i]] == s[1 + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            r = i + z[i] - 1, l = i;
    }
    z[1] = n;
    // z[i]表示从s串i下标开始的后缀和s串能匹配的最长的前缀长度
    return z;
}
void slove()
{
    string s, t;
    cin >> t >> s;
    int n = s.size();
    vector<int> tz = ex(s);
    int m = t.size();
    s = " " + s;
    t = " " + t;
    vector<int> z(m + 10);
    int l = 1;
    int r = 0;
    for (int i = 1; i <= m; i++)
    {
        if (i <= r)
            z[i] = min({tz[i - l + 1], r - i + 1});
        while (i + z[i] <= m && 1 + z[i] <= n && t[i + z[i]] == s[1 + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    // z[i]表示从t串i下标开始的后缀和s串能匹配的最长的前缀长度
}
```
# kmp
```cpp
using i64 = long long;
mt19937_64 rnd(time(0));
auto kmp = [&](string s)
{
    int n = s.size();
    s = " " + s;
    vector<int> nex(n + 10);
    int i = 1;
    int j = 0;
    while (i <= n)
    {
        while (j && s[i] != s[j])
            j = nex[j];
        nex[++i] = ++j;
    }
    return nex;
};
s : ababac
 nex : 0 1 1 2 3 4 int p = k + 1;
t是要被匹配的串也就是用kmp传参的串
    charnow为我们枚举的串的当前的字符 while (p != 0 && t[p] != charnow) p = nex[p];
如果匹配成功那么这时候显然p值为t的长度 
void getborder(string a)
{
    auto kmp = [&](string s)
    {
        int n = s.size() - 1;
        vector<int> nex(n + 10);
        int i = 1;
        int j = 0;
        while (i <= n)
        {
            while (j && s[i] != s[j])
                j = nex[j];
            nex[++i] = ++j;
        }
        return nex;
    };
    // 所有的border可以组成Logn个等差序列
    //  pos为每个等差序列的右端点，num为这个等差序列的数量,d为差值
    vector<int> nex = kmp(a);
    int n = a.size() - 1;
    vector<int> d(n + 10), pos(n + 10);
    vector<int> num(n + 10);
    int p = n + 1;
    int cnt = 0;
    while (1)
    {
        if (nex[p] >= 2)
        {
            ++cnt;
            if (2 * (nex[p] - 1) >= p - 1)
            {
                d[cnt] = p - 1 - (nex[p] - 1);
                pos[cnt] = (nex[p] - 1);
                int f = (p - 1) % d[cnt] + d[cnt];
                num[cnt] = (nex[p] - 1 - f) / d[cnt] + 1;
                assert((nex[p] - 1 - f) % d[cnt] == 0);
                p = f + 1;
            }
            else
            {
                d[cnt] = (nex[p] - 1);
                pos[cnt] = (nex[p] - 1);
                num[cnt] = 1;
                p = nex[p];
            }
        }
        else
            break;
    }
}
```


# min_25
```cpp
int ksm(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        b>>=1;a=a*a%mod;
    }
    return ans;
}
struct Min_25{
    vector<int>id1,id2,book,arr,sum,w;
    vector<int>g1,g2;
    vector<int>sum1,sum2;
    int sqrn=0,cnt=0,m=0,n=0;
    int getid(int x){
    if(x<=sqrn)return id1[x];
    else {
          return id2[n/x];
       }
     }
    int f(int x){
       x%=mod;
       return (x*x%mod-x)%mod;
    }
    void init(int n){
        sqrn=sqrt(n+0.5);
        this->n=n;
        book.resize(sqrn+10);
        arr.resize(sqrn+10);
        id1.resize(2*sqrn+10);
        id2.resize(2*sqrn+10);
        w.resize(2*sqrn+10);

        g1.resize(2*sqrn+10);
        g2.resize(2*sqrn+10);
        sum1.resize(2*sqrn+10);
        sum2.resize(2*sqrn+10);
        for(int i=2;i<=sqrn;i++){
            if(!book[i])arr[++cnt]=i;
            for(int j=1;j<=cnt&&i*arr[j]<=sqrn;j++){
                book[i*arr[j]]=1;
                if(i%arr[j]==0)break;
            }
        }
        arr[cnt+1]=1e9;
        cnt=1;
        while(arr[cnt]*arr[cnt]<=n)cnt++;
        cnt--;
        int r=1;
        for(int l=1;l<=n;l=r+1){
        r=n/(n/l);
        w[++m]=n/l;

        if(n/l<=sqrn){
            id1[n/l]=m;
        }
        else {
            id2[n/(n/l)]=m;
        }
       }
       auto initmg=[&](){
            int inv6=ksm(6,mod-2);
            int inv2=ksm(2,mod-2);
            for(int i=1;i<=m;i++){
                 g1[i]=w[i]%mod*(w[i]%mod+1)%mod*(2*w[i]%mod+1)%mod*inv6%mod-1;
                 g2[i]=w[i]%mod*(w[i]%mod+1)%mod*inv2%mod-1;
            }
            for(int i=1;i<=cnt;i++){
                sum1[i]=sum1[i-1]+arr[i]*arr[i]%mod;
                sum2[i]=sum2[i-1]+arr[i]%mod;
                sum1[i]%=mod;sum2[i]%=mod;
            }
       };
       initmg();
       // sum g 记得预处理sum 和 g
        for(int i=1;i<=cnt;i++){
        for(int j=1;j<=m&&arr[i]*arr[i]<=w[j];j++){
            int x=getid(w[j]/arr[i]);
            g1[j]=(g1[j]-arr[i]*arr[i]%mod*(g1[x]-sum1[i-1])%mod)%mod;
            g2[j]=(g2[j]-arr[i]*(g2[x]-sum2[i-1])%mod)%mod;
        }
      }
    }
     int S(int n,int j){
        int ans=g1[getid(n)]-sum1[j-1]-g2[getid(n)]+sum2[j-1];
        ans%=mod;
        for(int i=j;arr[i]*arr[i]<=n;i++){
            for(int t=arr[i];t*arr[i]<=n;t=t*arr[i]){
                ans+=S(n/t,i+1)*f(t)%mod+f(t*arr[i]);
                ans%=mod;
            }
        }
        if(ans<0)ans+=mod;
        return ans;
    };
}min25;
```

# 最大流
```cpp
所谓闭合子图就是给定一个有向图，从中选择一些点组成一个点集V。对于V中任意一个点，其后续节点都仍然在V中。比如：
最大权闭合子图的权值等于所有正权点之和减去最小割。(可以直接记结论，比赛也没人让你证明结论 Orz )
对于一般的图来说：首先建立源点s和汇点t，将源点s与所有权值为正的点相连，容量为权值；将所有权值为负的点与汇点t相连，容量为权值的绝对值；

权值为0的点不做处理；同时将原来的边容量设置为无穷大
template <class T>
struct MaxFlow
{
    struct _Edge
    {
        int to;
        T cap;
        _Edge(int to, T cap) : to(to), cap(cap) {}
    };
    int n;
    std::vector<_Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<int> cur, h;
    MaxFlow() {}
    MaxFlow(int n)
    {
        init(n);
    }
    void init(int n)
    {
        this->n = n;
        e.clear();
        g.assign(n, {});
        cur.resize(n);
        h.resize(n);
    }
    bool bfs(int s, int t)
    {
        h.assign(n, -1);
        std::queue<int> que;
        h[s] = 0;
        que.push(s);
        while (!que.empty())
        {
            const int u = que.front();
            que.pop();
            for (int i : g[u])
            {
                auto [v, c] = e[i];
                if (c > 0 && h[v] == -1)
                {
                    h[v] = h[u] + 1;
                    if (v == t)
                    {
                        return true;
                    }
                    que.push(v);
                }
            }
        }
        return false;
    }
    T dfs(int u, int t, T f)
    {
        if (u == t)
        {
            return f;
        }
        auto r = f;
        for (int &i = cur[u]; i < (int)g[u].size(); ++i)
        {
            const int j = g[u][i];
            auto [v, c] = e[j];
            if (c > 0 && h[v] == h[u] + 1)
            {
                auto a = dfs(v, t, std::min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0)
                {
                    return f;
                }
            }
        }
        return f - r;
    }
    void addEdge(int u, int v, T c)
    {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    T flow(int s, int t)
    {
        T ans = 0;
        while (bfs(s, t))
        {
            cur.assign(n, 0);
            ans += dfs(s, t, std::numeric_limits<T>::max());
        }
        return ans;
    }
    std::vector<bool> minCut()
    {
        std::vector<bool> c(n);
        for (int i = 0; i < n; i++)
        {
            c[i] = (h[i] != -1);
        }
        return c;
    }
    struct Edge
    {
        int from;
        int to;
        T cap;
        T flow;
    };
    std::vector<Edge> edges()
    {
        std::vector<Edge> a;
        for (int i = 0; i < e.size(); i += 2)
        {
            Edge x;
            x.from = e[i + 1].to;
            x.to = e[i].to;
            x.cap = e[i].cap + e[i + 1].cap;
            x.flow = e[i + 1].cap;
            a.push_back(x);
        }
        return a;
    }
};
```

# 最小费用最大流
```cpp
//原始对偶算法 模板
template<class T>
struct MinCostFlow {
    struct _Edge {
        int to;
        T cap;
        T cost;
        _Edge(int to_, T cap_, T cost_) : to(to_), cap(cap_), cost(cost_) {}
    };
    int n;
    std::vector<_Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<T> h, dis;
    std::vector<int> pre;
    bool dijkstra(int s, int t) {
        dis.assign(n, std::numeric_limits<T>::max());
        pre.assign(n, -1);
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> que;
        dis[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            T d = que.top().first;
            int u = que.top().second;
            que.pop();
            if (dis[u] != d) {
                continue;
            }
            for (int i : g[u]) {
                int v = e[i].to;
                T cap = e[i].cap;
                T cost = e[i].cost;
                if (cap > 0 && dis[v] > d + h[u] - h[v] + cost) {
                    dis[v] = d + h[u] - h[v] + cost;
                    pre[v] = i;
                    que.emplace(dis[v], v);
                }
            }
        }
        return dis[t] != std::numeric_limits<T>::max();
    }
    MinCostFlow() {}
    MinCostFlow(int n_) {
        init(n_);
    }
    void init(int n_) {
        n = n_;
        e.clear();
        g.assign(n, {});
    }
    void addEdge(int u, int v, T cap, T cost) {
        g[u].push_back(e.size());
        e.emplace_back(v, cap, cost);
        g[v].push_back(e.size());
        e.emplace_back(u, 0, -cost);
    }
    //最小费用最大流
    std::pair<T, T> flow(int s, int t) {
        T flow = 0;
        T cost = 0;
        h.assign(n, 0);
        while (dijkstra(s, t)) {
            //维护势能
            for (int i = 0; i < n; ++i) {
                h[i] += dis[i];
            }
            //找到增广路上的最大流
            T aug = std::numeric_limits<int>::max();
            for (int i = t; i != s; i = e[pre[i] ^ 1].to) {
                aug = std::min(aug, e[pre[i]].cap);
            }
            //更新残留网
            for (int i = t; i != s; i = e[pre[i] ^ 1].to) {
                e[pre[i]].cap -= aug;
                e[pre[i] ^ 1].cap += aug;
            }
            flow += aug;
            cost += aug * h[t];//h[s]始终等于0,dis[t] += h[t] - 0
        }
        return std::make_pair(flow, cost);
    }
    struct Edge {
        int from;
        int to;
        T cap;
        T cost;
        T flow;
    };
    //返回每条边的流量情况
    std::vector<Edge> edges() {
        std::vector<Edge> a;
        for (int i = 0; i < e.size(); i += 2) {
            Edge x;
            x.from = e[i + 1].to;
            x.to = e[i].to;
            x.cap = e[i].cap + e[i + 1].cap;
            x.cost = e[i].cost;
            x.flow = e[i + 1].cap;
            a.push_back(x);
        }
        return a;
    }
};
```
# 判断日期
```CPP
const int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int daysInMonth(int y, int m) {
    return d[m - 1] + (isLeap(y) && m == 2);
}

int getDay(int y, int m, int d) {
    int ans = 0;
    for (int i = 1970; i < y; i++) {
        ans += 365 + isLeap(i);
    }
    for (int i = 1; i < m; i++) {
        ans += daysInMonth(y, i);
    }
    ans += d;
    return (ans + 2) % 7 + 1;
}
```
# 计算几何
```cpp
template<class T>
struct Point {
    T x;
    T y;
    Point(const T &x_ = 0, const T &y_ = 0) : x(x_), y(y_) {}
     
    template<class U>
    operator Point<U>() {
        return Point<U>(U(x), U(y));
    }
    Point &operator+=(const Point &p) & {
        x += p.x;
        y += p.y;
        return *this;
    }
    Point &operator-=(const Point &p) & {
        x -= p.x;
        y -= p.y;
        return *this;
    }
    Point &operator*=(const T &v) & {
        x *= v;
        y *= v;
        return *this;
    }
    Point &operator/=(const T &v) & {
        x /= v;
        y /= v;
        return *this;
    }
    Point operator-() const {
        return Point(-x, -y);
    }
    friend Point operator+(Point a, const Point &b) {
        return a += b;
    }
    friend Point operator-(Point a, const Point &b) {
        return a -= b;
    }
    friend Point operator*(Point a, const T &b) {
        return a *= b;
    }
    friend Point operator/(Point a, const T &b) {
        return a /= b;
    }
    friend Point operator*(const T &a, Point b) {
        return b *= a;
    }
    friend bool operator==(const Point &a, const Point &b) {
        return a.x == b.x && a.y == b.y;
    }
    friend std::istream &operator>>(std::istream &is, Point &p) {
        return is >> p.x >> p.y;
    }
    friend std::ostream &operator<<(std::ostream &os, const Point &p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};
 
template<class T>
struct Line {
    Point<T> a;
    Point<T> b;
    Line(const Point<T> &a_ = Point<T>(), const Point<T> &b_ = Point<T>()) : a(a_), b(b_) {}
};
 
template<class T>
T dot(const Point<T> &a, const Point<T> &b) {
    return a.x * b.x + a.y * b.y;
}
template<class T>
T cross(const Point<T> &a, const Point<T> &b) {
    return a.x * b.y - a.y * b.x;
}
template<class T>
T square(const Point<T> &p) {
    return dot(p, p);
}
 
template<class T>
double length(const Point<T> &p) {
    return std::sqrt(square(p));
}
 
template<class T>
double length(const Line<T> &l) {
    return length(l.a - l.b);
}
 
template<class T>
Point<T> normalize(const Point<T> &p) {
    return p / length(p);
}
 
template<class T>
bool parallel(const Line<T> &l1, const Line<T> &l2) {
    return cross(l1.b - l1.a, l2.b - l2.a) == 0;
}
template<class T>
double distance(const Point<T> &a, const Point<T> &b) {
    return length(a - b);
}
template<class T>
double distancePL(const Point<T> &p, const Line<T> &l) {
    return std::abs(cross(l.a - l.b, l.a - p)) / length(l);
}
template<class T>
double distancePS(const Point<T> &p, const Line<T> &l) {
    if (dot(p - l.a, l.b - l.a) < 0) {
        return distance(p, l.a);
    }
    if (dot(p - l.b, l.a - l.b) < 0) {
        return distance(p, l.b);
    }
    return distancePL(p, l);
}
template<class T>
double distanceSS(const Line<T> &l1, const Line<T> &l2) {
    if (std::get<0>(segmentIntersection(l1, l2)) != 0) {
        return 0.0;
    }
    return std::min({distancePS(l1.a, l2), distancePS(l1.b, l2), distancePS(l2.a, l1), distancePS(l2.b, l1)});
}
template<class T>
Point<T> rotate(const Point<T> &a) {
    return Point(-a.y, a.x);
}
template<class T>
int sgn(const Point<T> &a) {
    return a.y > 0 || (a.y == 0 && a.x > 0) ? 1 : -1;
}
template<class T>
bool pointOnLineLeft(const Point<T> &p, const Line<T> &l) {
    return cross(l.b - l.a, p - l.a) > 0;
}
template<class T>
Point<T> lineIntersection(const Line<T> &l1, const Line<T> &l2) {
    return l1.a + (l1.b - l1.a) * (cross(l2.b - l2.a, l1.a - l2.a) / cross(l2.b - l2.a, l1.a - l1.b));
}
 
template<class T>
bool pointOnSegment(const Point<T> &p, const Line<T> &l) {
    return cross(p - l.a, l.b - l.a) == 0 && std::min(l.a.x, l.b.x) <= p.x && p.x <= std::max(l.a.x, l.b.x)
        && std::min(l.a.y, l.b.y) <= p.y && p.y <= std::max(l.a.y, l.b.y);
}

template<class T>
bool pointInPolygon(const Point<T> &a, const std::vector<Point<T>> &p) {
    int n = p.size();
    for (int i = 0; i < n; i++) {
        if (pointOnSegment(a, Line(p[i], p[(i + 1) % n]))) {
            return true;
        }
    }
    int t = 0;
    for (int i = 0; i < n; i++) {
        auto u = p[i];
        auto v = p[(i + 1) % n];
        if (u.x < a.x && v.x >= a.x && pointOnLineLeft(a, Line(v, u))) {
            t ^= 1;
        }
        if (u.x >= a.x && v.x < a.x && pointOnLineLeft(a, Line(u, v))) {
            t ^= 1;
        }
    }
     
    return t == 1;
}
// 0 : not intersect
// 1 : strictly intersect
// 2 : overlap
// 3 : intersect at endpoint
template<class T>
std::tuple<int, Point<T>, Point<T>> segmentIntersection(const Line<T> &l1, const Line<T> &l2) {
    if (std::max(l1.a.x, l1.b.x) < std::min(l2.a.x, l2.b.x)) {
        return {0, Point<T>(), Point<T>()};
    }
    if (std::min(l1.a.x, l1.b.x) > std::max(l2.a.x, l2.b.x)) {
        return {0, Point<T>(), Point<T>()};
    }
    if (std::max(l1.a.y, l1.b.y) < std::min(l2.a.y, l2.b.y)) {
        return {0, Point<T>(), Point<T>()};
    }
    if (std::min(l1.a.y, l1.b.y) > std::max(l2.a.y, l2.b.y)) {
        return {0, Point<T>(), Point<T>()};
    }
    if (cross(l1.b - l1.a, l2.b - l2.a) == 0) {
        if (cross(l1.b - l1.a, l2.a - l1.a) != 0) {
            return {0, Point<T>(), Point<T>()};
        } else {
            auto maxx1 = std::max(l1.a.x, l1.b.x);
            auto minx1 = std::min(l1.a.x, l1.b.x);
            auto maxy1 = std::max(l1.a.y, l1.b.y);
            auto miny1 = std::min(l1.a.y, l1.b.y);
            auto maxx2 = std::max(l2.a.x, l2.b.x);
            auto minx2 = std::min(l2.a.x, l2.b.x);
            auto maxy2 = std::max(l2.a.y, l2.b.y);
            auto miny2 = std::min(l2.a.y, l2.b.y);
            Point<T> p1(std::max(minx1, minx2), std::max(miny1, miny2));
            Point<T> p2(std::min(maxx1, maxx2), std::min(maxy1, maxy2));
            if (!pointOnSegment(p1, l1)) {
                std::swap(p1.y, p2.y);
            }
            if (p1 == p2) {
                return {3, p1, p2};
            } else {
                return {2, p1, p2};
            }
        }
    }
    auto cp1 = cross(l2.a - l1.a, l2.b - l1.a);
    auto cp2 = cross(l2.a - l1.b, l2.b - l1.b);
    auto cp3 = cross(l1.a - l2.a, l1.b - l2.a);
    auto cp4 = cross(l1.a - l2.b, l1.b - l2.b);
    if ((cp1 > 0 && cp2 > 0) || (cp1 < 0 && cp2 < 0) || (cp3 > 0 && cp4 > 0) || (cp3 < 0 && cp4 < 0)) {
        return {0, Point<T>(), Point<T>()};
    }
    Point p = lineIntersection(l1, l2);
    if (cp1 != 0 && cp2 != 0 && cp3 != 0 && cp4 != 0) {
        return {1, p, p};
    } else {
        return {3, p, p};
    }
}
 template<class T>
std::vector<Point<T>> getHull(std::vector<Point<T>> p) {
    std::vector<Point<T>> h, l;
    std::sort(p.begin(), p.end(), [&](auto a, auto b) {
        if (a.x != b.x) {
            return a.x < b.x;
        } else {
            return a.y < b.y;
        }
    });
    p.erase(std::unique(p.begin(), p.end()), p.end());
    if (p.size() <= 1) {
        return p;
    }
    for (auto a : p) {
        while (h.size() > 1 && cross(a - h.back(), a - h[h.size() - 2]) <= 0) {
            h.pop_back();
        }
        while (l.size() > 1 && cross(a - l.back(), a - l[l.size() - 2]) >= 0) {
            l.pop_back();
        }
        l.push_back(a);
        h.push_back(a);
    }
    l.pop_back();
    std::reverse(h.begin(), h.end());
    h.pop_back();
    l.insert(l.end(), h.begin(), h.end());
    return l;
}
template<class T>
double hullDiameter(vector<Point<T>>b){
    std::vector<Point<T>> d;
    int m=b.size();
    d.reserve(2 * m);
    for (int i = 0; i < m; i++) {
        int j = i == m - 1 ? 0 : i + 1;
        d.push_back(b[j] - b[i]);
        d.push_back(b[i] - b[j]);
    }
    sort(d.begin(), d.end(),
    [&](const auto &a, const auto &b) {
            if (sgn(a) != sgn(b)) {
                return sgn(a) == 1;
            }
            return cross(a, b) > 0;
     });
    b.resize(2 * m);
    Point<T> u {};
    for (int i = 0; i < 2 * m; i++) {
        b[i] = u;
        u += d[i];
    }
    double ans = 0;
    for (int i = 0; i < m; i++) {
        ans = max(ans,distance(b[i],b[i+m]));
    }
    return ans/2;
}
template<class T>
double getAreaPolygon(vector<Point<T>>b){
    int n=b.size();
    double ans=0;
    for(int i = 0;i < n ;i++){
        int j =(i+1)%n;
        ans+=cross(b[i],b[j]);
    }
    ans/=2;
    return ans;
}
```
# LCT
```cpp
struct LCT {
  int ch[N][2], fa[N], tag[N];
  void clear(int x) {
    ch[x][0] = ch[x][1] = fa[x] = tag[x] =0;
  }
  int getch(int x) { return ch[fa[x]][1] == x; }
  int isroot(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }

  void update(int x) {
    if (!isroot(x)) update(fa[x]);
    pushdown(x);
  }
  void print(int x) {
    if (!x) return;
    pushdown(x);
    print(ch[x][0]);
    printf("%d ", x);
    print(ch[x][1]);
  }
  void rotate(int x) {
    int y = fa[x], z = fa[y], chx = getch(x), chy = getch(y);
    fa[x] = z;
    if (!isroot(y)) ch[z][chy] = x;
    ch[y][chx] = ch[x][chx ^ 1];
    fa[ch[x][chx ^ 1]] = y;
    ch[x][chx ^ 1] = y;
    fa[y] = x;
    up(y);
    up(x);
    if (z) up(z);
  }
  void splay(int x) {
    update(x);
    up(x);
    for (int f = fa[x]; f = fa[x], !isroot(x); rotate(x))
      if (!isroot(f)) rotate(getch(x) == getch(f) ? f : x);
  }
  void access(int x) {
    for (int f = 0; x; f = x, x = fa[x]) splay(x), ch[x][1] = f, up(x);
  }
  void makeroot(int x) {
    access(x);
    splay(x);
    tag[x] ^= 1;
    swap(ch[x][0], ch[x][1]);
  }
  int find(int x) {
    access(x);
    splay(x);
    while (ch[x][0]) x = ch[x][0];
    splay(x);
    return x;
  }
  void link(int x, int y) {
      makeroot(x);
      fa[x] = y;
  }
  void cut(int x, int y) {
    makeroot(x);
    access(y);
    splay(y);
    ch[y][0] = fa[x] = 0;
    up(y);
  }
  void split(int x,int y){
       makeroot(x);
       access(y);
       splay(y);
  }
  #define ls ch[x][0]
  #define rs ch[x][1]
  
  void pushdown(int x) {
    if (tag[x]) {
      if (ch[x][0]) {
         tag[ch[x][0]] ^= 1, swap(ch[ch[x][0]][0], ch[ch[x][0]][1]);
      }
      if (ch[x][1]){
         tag[ch[x][1]] ^= 1, swap(ch[ch[x][1]][0], ch[ch[x][1]][1]);
      }
      tag[x] = 0;
    }
  }
  void up(int x) {
    if (!x) return;
    
  }
  #undef ls
  #undef rs
} st;
```
# 笛卡尔
```cpp
vector<pair<int, int>> getcart(vector<int> a)
{
    int n = a.size();
    vector<pair<int, int>> ans(n + 10);
    a.insert(a.begin(), 0);
    vector<int> st;
    for (int i = 1; i <= n; i++)
    {
        int last = 0;
        while (st.size() && a[st.back()] > a[i])
        {
            last = st.back();
            st.pop_back();
        }
        if (st.size())
        {
            ans[st.back()].second = i;
        }
        if (last)
        {
            ans[i].first = last;
        }
        st.push_back(i);
    }
    ans[0].first = ans[0].second = st[0]; // 根节点 现在为最小值为根节点
    return ans;
}
```
# 筛素数个数(1e11)
```cpp
ll f[N], g[N], n;
void init()
{
    ll i, j, m;
    for (m = 1; m * m <= n; ++m)
        f[m] = n / m - 1;
    for (i = 1; i <= m; ++i)
        g[i] = i - 1;
    for (i = 2; i <= m; ++i)
    {
        if (g[i] == g[i - 1])
            continue;
        for (j = 1; j <= min(m - 1, n / i / i); ++j)
        {
            if (i * j < m)
                f[j] -= f[i * j] - g[i - 1];
            else
                f[j] -= g[n / i / j] - g[i - 1];
        }
        for (j = m; j >= i * i; --j)
            g[j] -= g[j / i] - g[i - 1];
    }
    // f[i]表示[2,n/i]范围内的素数个数注意f只有sqrt(n)的长度
    // 所以f[1]表示n以内的素数个数
}
```
# 背包
```cpp
vector<bool> subset_sum(const vector<int> &a, int s)
{
    if (s == 0)
        return vector<bool>(a.size(), false);
    int n = a.size();
    int mx = *max_element(a.begin(), a.end());
    int b = 0, sb = 0;
    while (b < n && a[b] + sb <= s)
        sb += a[b++];
    if (b == n && sb < s)
        return {};
    int offset = s - mx + 1;
    vector<int> dp(mx * 2, -1);
    vector<vector<int>> pre(n, vector<int>(mx * 2, -1));
    dp[sb - offset] = b;
    for (int i = b; i < n; i++)
    {
        vector<int> ndp(dp);
        vector<int> &prei = pre[i];
        for (int j = mx - 1; j >= 0; j--)
        {
            if (ndp[j + a[i]] < ndp[j])
            {
                prei[j + a[i]] = -2;
                ndp[j + a[i]] = ndp[j];
            }
        }
        for (int j = mx * 2 - 1; j >= mx; j--)
        {
            for (int k = ndp[j] - 1; k >= max(dp[j], 0); k--)
            {
                if (ndp[j - a[k]] < k)
                {
                    prei[j - a[k]] = k;
                    ndp[j - a[k]] = k;
                }
            }
        }
        swap(dp, ndp);
    }
    if (dp[mx - 1] == -1)
        return {};
    vector<bool> res(n, false);
    int i = n - 1, j = mx - 1;
    while (i >= b)
    {
        int p = pre[i][j];
        if (p == -2)
        {
            res[i] = !res[i];
            j -= a[i];
            i--;
        }
        else if (p == -1)
            i--;
        else
        {
            res[p] = !res[p];
            j += a[p];
        }
    }
    while (i >= 0)
    {
        res[i] = !res[i];
        i--;
    }
    return res;
}
```

# 手写哈希map
```cpp

//开在堆区，否则爆栈
template <typename T, typename V,int N>
struct htb
{
    int h[N], to[N], idx = 0;
    int sz = 0;
    T k[N];
    V w[N];
    static int hashx(unsigned long long v)
    {
        v ^= v << 13;
        v ^= v >> 7;
        return (v ^ (v << 17)) % N;
    }
    bool count(T x)
    {
        for (int i = h[hashx(x)]; i; i = to[i])
        {
            if (k[i] == x)
                return true;
        }
        return false;
    }
    V &operator[](T x)
    {
        int &p = h[hashx(x)];
        for (int i = p; i; i = to[i])
        {
            if (k[i] == x)
                return w[i];
        }
        k[++idx] = x;
        to[idx] = p;
        w[p = idx] = 0;
        sz++;
        return w[idx];
    }
    bool erase(T x)
    {
        int prev = 0;
        for (int i = h[hashx(x)]; i; i = to[i])
        {
            if (k[i] == x)
            {
                if (prev == 0)
                    h[hashx(x)] = to[i];
                else
                    to[prev] = to[i];
                sz--;
                return true;
            }
            prev = i;
            i = to[i];
        }
        return false;
    }
    void clear()
    {
        while (idx)
            h[hashx(k[idx--])] = 0;
        sz = idx = 0;
    }
    int size() { return sz; }
};



template <typename T, typename V, int N>
struct htb
{
    int h[N], to[N], idx = 0;
    int sz = 0;
    T k[N];
    V w[N];
    int pre[N + 3], nxt[N + 3];
    int tail = N + 1;
    static int hashx(unsigned long long v)
    {
        v ^= v << 13;
        v ^= v >> 7;
        return (v ^ (v << 17)) % N;
    }
    void ins(int x)
    {

        nxt[tail] = x;
        pre[x] = tail;
        tail = x;
    }
    void del(int x)
    {
        if (x == tail)
        {
            nxt[pre[x]] = 0;
            tail = pre[x];
        }
        else
        {
            pre[nxt[x]] = pre[x];
            nxt[pre[x]] = nxt[x];
        }
        pre[x] = nxt[x] = 0;
    }
    bool count(T x)
    {
        for (int i = h[hashx(x)]; i; i = to[i])
        {
            if (k[i] == x)
                return true;
        }
        return false;
    }
    V &operator[](T x)
    {
        int &p = h[hashx(x)];
        int ff = 0;
        for (int i = p; i; i = to[i])
        {
            ff = 1;
            if (k[i] == x)
                return w[i];
        }
        k[++idx] = x;
        to[idx] = p;
        w[p = idx] = 0;
        if (ff == 0)
        {
            ins(hashx(x) + 1); // 链表
        }
        sz++;
        return w[idx];
    }
    bool erase(T x)
    {
        int prev = 0;
        for (int i = h[hashx(x)]; i; i = to[i])
        {
            if (k[i] == x)
            {
                if (prev == 0)
                    h[hashx(x)] = to[i];
                else
                    to[prev] = to[i];
                sz--;
                if (h[hashx(x)] == 0)  // 链表
                    del(hashx(x) + 1); // 链表
                return true;
            }
            prev = i;
            i = to[i];
        }
        return false;
    }
    void clear()
    {
        while (idx)
            h[hashx(k[idx--])] = 0;
        sz = idx = 0;
    }
    int size() { return sz; }
    vector<int> getall()
    {
        vector<int> ans;
        for (int i = nxt[N + 1]; i; i = nxt[i])
        {
            for (int j = h[i - 1]; j; j = to[j])
            {
                ans.push_back(k[j]);
            }
        }
        return ans;
    }
};
```


# py

```.cpp
import itertools
from itertools import combinations,permutations
from collections import defaultdict
from more_itertools  import distinct_permutations,distinct_combinations
from collections import deque
from heapq import heappush,heappop
import sys
from more_itertools.more import distinct_permutations
from decimal import Decimal,getcontext
input=lambda :sys.stdin.readline().strip("\n\r")
arr=[1,1,2,3]
for  x in distinct_combinations(arr,2):
    print(x)
print("#########")
for x in combinations(arr,2):
    print(x)

print("#########")
for x in distinct_permutations(arr):
    print(x)

print("#########")
for x in permutations(arr):
    print(x)
dic=dict()
dic['2']=1
print(dic.get('2',None))
print(dic.get('1',None))
getcontext().prec = 450
a=Decimal(2)
b=Decimal(3)
print(a/b)
print(str(a/b))
#ord 函数可以将一个字符转换成其对应的 ASCII 码值，而 chr 函数则是将一个数字（ASCII 码值）转换成对应的字符。
print(ord('a'))
```