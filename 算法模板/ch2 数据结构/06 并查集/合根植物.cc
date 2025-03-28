#include <iostream>
using namespace std;
const int N = 1e6;
int p[N];
int n,m,k;
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void merge(int a,int b){
    a = find(a),b = find(b);
    if(a != b) p[a] = b;
    // if(find(a) != find(b))
    // p[find(a)] = find(b);
}
int main()
{
    cin >> m >> n;
    for(int i=1;i<=m*n;i++){
        p[i] = i;
    }
    cin >> k;
    while(k--){
        int a,b;
        cin >> a >> b;
        merge(a,b);
    }
    int ans = 0;
    for(int i=1;i<=m*n;i++){
        if(find(i) == i) ans++;
    }
    cout << ans << endl;
    return 0;
}