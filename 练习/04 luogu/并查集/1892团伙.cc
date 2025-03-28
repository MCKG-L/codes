#include <iostream>
using namespace std;
//并查集 + 反集
const int N = 2010;
int p[N];
int n,m;
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
    for(int i=1;i<=2*n;i++) p[i] = i;
    while(m--){
        char op[2];int a,b;
        cin >> op >> a >> b;
        if(op[0] == 'F') unite(a,b);
        else unite(n+a,b),unite(n+b,a);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(find(i)==i) ans++;
    }
    cout << ans << endl;
    return 0;
}