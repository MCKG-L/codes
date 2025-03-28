#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int f[N];
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
int vis[N];
int main(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++){
         int x,y;cin>>x>>y;
         vis[x]++;vis[y]++;
         if(find(x)==find(y))continue;
         f[find(x)]=find(y);
    }
    vector<pair<int,int>>st(n+10);
    for(int i=1;i<=n;i++){
        st[find(i)].first++;
        st[find(i)].second+=vis[i];
    }
    vector<int>v;
    int ans=0;
    for(int i=1;i<=n;i++){
        int x=st[i].first;int y=st[i].second;
        if(x==0)continue;
        v.push_back(x);
        ans+=(x*(x-1)-y)/2;
    }
    sort(v.begin(),v.end());
    if(ans==0){
        cout<<v[0]*v[1]<<"\n";
    }
    else {
        cout<<ans<<"\n";
    }


    return 0;
}