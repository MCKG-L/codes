#include <iostream>
#include <cstring>
using namespace std;
const int N = 1010;
int p[N];
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
    int n,m;
    while(cin >> n >> m){
        if(n == 0) break;
        for(int i=1;i<=n;i++) p[i] = i;
        for(int i=0;i<m;i++){
            int a,b;cin >> a >> b;
            unite(a,b);
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(find(i) == i) ans++;
        }
        cout << ans - 1 << '\n';
    }
    return 0;
}