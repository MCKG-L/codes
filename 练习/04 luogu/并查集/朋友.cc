#include <iostream>
using namespace std;
const int N = 1e4 + 10;
int p[2 * N];
int n,m,P,Q;
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
    cin >> n >> m >> P >> Q;
    for(int i=0;i<2*N;i++){
        p[i] = i;
    }
    while(P--){
        int a,b;
        cin >> a >> b;
        merge(a,b);
    }
    while(Q--){
        int a,b;
        cin >> a >> b;
        merge(-a + N,-b + N);
    }
    int cnt1 = 0,cnt2 = 0;
    for(int i=1;i<=n;i++){
        if(find(i) == find(1)) cnt1 ++;
    }
    for(int i=n+1;i<=2*N;i++){
        if(find(i) == find(N+1)) cnt2 ++;
    }
    cout << min(cnt1,cnt2) << endl;
    return 0;
}