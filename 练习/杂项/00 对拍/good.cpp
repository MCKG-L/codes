#include<iostream>
#include<cstring>
#define int long long
using namespace std;
int n,num[25],dp[25][2][10];
int dfs(int len,int top,int maxn){
	if(len==1) return top?min(maxn,num[1]+1):maxn;
	if(dp[len][top][maxn]) return dp[len][top][maxn];
	if(!maxn){
		int an=0;int mm=(top?num[len]:9);
		for(int i=0;i<=mm;i++){
			maxn=i;
			an+=dfs(len-1,(i==num[len])&&top,maxn); 
		}
		dp[len][top][0]=an;
		return an;
	}
	int an=0,mm=(top?num[len]:9);
	for(int i=0;i<=min(maxn-1,mm);i++){
		an+=dfs(len-1,(i==num[len])&&top,maxn);
	}
	dp[len][top][maxn]=an;return an;
}
int work(int x){
	memset(dp,0,sizeof(dp));n=0;
	while(x) num[++n]=x%10,x/=10;
	int an=dfs(n,1,0);
	return an;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int L,R;
	cin>>L>>R;
	cerr << work(R) << ' ' << work(L-1) << endl;
	cout<<work(R)-work(L-1); 
	return 0;
}