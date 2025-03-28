#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#define INF 0x7f7f7f7f
const int MAXN=3005;
int n,m,ans;
struct node
{
	int to,cost,limit;
	bool operator<(const node& a)const
	{
		return cost>a.cost;//方向别反了
	}
};
vector<node> edge[MAXN];
int dis[MAXN],limit[MAXN];
bool visit[MAXN];

void input(void)
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b,x;
		cin>>a>>b>>x>>limit[i];
		edge[a].push_back(node{b,x,limit[i]});//无向图
		edge[b].push_back(node{a,x,limit[i]});
	}
}

int dijkstra(const int limit)
{
	priority_queue<node> q;//记得清空
	memset(visit,false,sizeof(visit));
	memset(dis,INF,sizeof(dis));
	dis[1]=0;
	q.push(node{1,0,limit});
	while(!q.empty())//模板
	{
		const int u=q.top().to;
		q.pop();
		if(visit[u])
		 continue;
		visit[u]=true;
		for(auto v:edge[u])
		 if(v.limit>=limit && dis[v.to]>dis[u]+v.cost)
		 {//注意限制
		 	dis[v.to]=dis[u]+v.cost;
		 	q.push(node{v.to,dis[v.to],limit});
		 }
	}
	return dis[n];
}

int main()
{
	input();
	for(int i=1;i<=m;i++)//枚举 m 次而非 n 次
	 ans=max(ans,limit[i]*int(1e6)/dijkstra(limit[i]));//更新答案
	cout<<ans<<endl;
	return 0;
}