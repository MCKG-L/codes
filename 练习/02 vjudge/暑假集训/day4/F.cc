#include <iostream>
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
int p[N],a[N];
/*
每一个数最多被处理三次 当a[i] < 10 时再次处理，不会改变

并查集 i的代表元的含义是：从i开始往后第一个需要处理的位置
*/
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int func(int x){
    int res = 0;
    while(x){
        res += x % 10;
        x /= 10;
    }
    return res;
}
void solve(){
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n+1;i++) p[i] = i;
    while(q--){
        int op;cin >> op;
        if(op == 1){
            int l,r;
            cin >> l >> r;
            for(int i=l;i<=r;i++){
                i = find(i);
                if(i > r) break;
                a[i] = func(a[i]);
                if(a[i] < 10) p[find(i)] = find(i+1);
            }
        }else{
            int x;cin >> x;
            cout << a[x] << endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}