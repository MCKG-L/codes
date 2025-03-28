#include <iostream>
using namespace std;
const int N = 10000;
int p[2*N+10];
int n,m,pp,q;
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
    cin >> n >> m >> pp >> q;
    for(int i=1;i<=2*N;i++){
        p[i] = i;
    }
    for(int i=0;i<pp+q;i++){
        int a,b;cin >> a >> b;
        if(a < 0 && b < 0) a = -1*a+N,b = -1*b+N;
        unite(a,b);
    }
    int k=0,l=0;
    for(int i=1;i<=n;i++){
        if(find(i) == find(1)) k++;
    }
    for(int i=1+N;i<=2*N;i++){
        if(find(i) == find(1+N)) l++;
    }
    cout << min(l,k) << '\n';
    return 0;
}
