#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int N = 2e4+10;
int p[N];
int n,m,k;
// vector<pair<string,int>> v(N);
map<string,int> mp;
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void unite(int a,int b){
    a = find(a),b = find(b);
    if(a != b) p[a] = b;
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) p[i] = i;
    for(int i=1;i<=n;i++){
        string s;cin >> s;
        mp.insert(make_pair(s,i));
    }
    for(int i=0;i<m;i++){
        string a,b;cin >> a >> b;
        unite(mp[a],mp[b]);
    }
    cin >> k;
    while(k--){
        string a,b;
        cin >> a >> b;
        if(find(mp[a]) != find(mp[b]))  cout << "No." << '\n';
        else cout << "Yes." << '\n';
    }
    return 0;
}