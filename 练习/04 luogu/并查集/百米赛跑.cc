#include <iostream>
#include <map>
using namespace std;
const int N = 1e4 + 10;
int p[N];
int n,m,k;
map<string,int> mp;
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void merge(int a,int b){
    a = find(a),b = find(b);
    if(a != b) p[a] = b;
}
int main()
{
    cin >> n >> m;
    string s;
    for(int i=1;i<=n;i++){
        p[i] = i;
        cin >> s;
        mp[s] = i;
    }
    while(m--){
        string a,b;
        cin >> a >> b;
        merge(mp[a],mp[b]);
    }
    cin >> k;
    while(k--){
        string a,b;
        cin >> a >> b;
        if(find(mp[a]) == find(mp[b])) puts("Yes.");
        else puts("No.");
    }
    return 0;
}
