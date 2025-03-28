//F
//The Way to The Terminal Station…
#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#define int long long
using namespace std;
const int maxn=1e5+10;
const int mod=998244353;
set<int>p,q;
int vis[maxn],sum[maxn];//vis[i] 表示的是每一份的第 i 天是否必须出勤，sum[i] 表示的是因子 i 的贡献。
 
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
 
signed main()
{
	int n=read();
	string s;
	cin>>s;
	s='%'+s;
	//预处理出 n 的所有因子
	for(int i=1;i<n;i++)
	{
		if(n%i==0)p.insert(i);
	}
	//枚举所有的因子，考虑每个因子的贡献。
	int ans=0;
	for(int v:p)
	{
		for(int i=1;i<=v;i++)vis[i]=0;
		for(int i=1;i<=n;i++)
		{
			int t=i%v;
			if(t==0)t=v;
			if(s[i]=='.')vis[t]=1;
		}
		sum[v]=1;
		for(int i=1;i<=v;i++)
		{
			if(!vis[i])(sum[v]*=2)%=mod;
		}
        //容斥，计算每个因子单独的贡献。
		for(int vv:p)
		{
			if(vv==v)break;
			if(v%vv==0)sum[v]=(sum[v]-sum[vv]+mod)%mod;
		}
		(ans+=sum[v])%=mod;
	}
	cout<<ans<<'\n';
	return 0;
}