#include <iostream>
using namespace std;
const int N = 1010;
int p[N];
int n,m;
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void merge(int a,int b){
    a = find(a),b = find(b);
    if(a != b) p[a] = b;
}
void solve(){
    for(int i=1;i<=n;i++) p[i] = i;
    while(m--){
        int a,b;
        cin >> a >> b;
        merge(a,b);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(find(i) == i) ans ++;
    }
    cout << ans - 1 << endl;
}
int main()
{
    while(cin >> n >> m){
        if(n == 0) break;
        solve();
    }
    return 0;
}