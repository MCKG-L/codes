#include <iostream>
using namespace std;
const int N = 5010;
int pa[N];
int find(int x){
    if(pa[x] != x) pa[x] = find(pa[x]);
    return pa[x];
}
void unite(int a,int b){
    a = find(a);
    b = find(b);
    if(a != b) pa[a] = b;
}
int main()
{
    int n,m,q;
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++) pa[i] = i;
    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        unite(a,b);
    }
    while(q--){
        int a,b;cin >> a >> b;
        if(find(a) != find(b)) cout << "No" << '\n';
        else cout << "Yes" << '\n';
    }
    return 0;
}