#include <iostream>
#include <map>
using namespace std;
map<int,int> mp;
int n,m,p,q;
int find(int x){
    if(mp[x] != x) mp[x] = find(mp[x]);
    return mp[x];
}
void unite(int a,int b){
    a = find(a),b = find(b);
    if(a != b) mp[a] = b;
}
int main()
{
    cin >> n >> m >> p >> q;
    for(int i=-1*m;i<=n;i++) mp[i] = i;
    for(int i=0;i<p+q;i++){
        int a,b;cin >> a >> b;
        unite(a,b);
    }
    int k=0,l=0;
    for(int i=-1*m;i<=-1;i++){
        if(find(i) == find(-1)) k++;
    }
    for(int i=1;i<=n;i++){
        if(find(i) == find(1)) l++;
    }
    cout << min(l,k) << '\n';
    return 0;
}