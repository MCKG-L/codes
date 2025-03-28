#include <iostream>
#include <set>
#define endl '\n'
using namespace std;
//把需要处理的位置放在容器里 当a[i]<10后把该位置删除
const int N = 2e5 + 10;
int a[N];
int n,q;
set<int> pos;
int func(int x){
    int res = 0;
    while(x){
        res += x % 10;
        x /= 10;
    }
    return res;
}
void solve(){
    cin >> n >> q;
    pos.clear();
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i] >= 10) pos.insert(i);
    }
    // pos.insert(n+1);
    while(q--){
        int op;cin >> op;
        if(op == 1){
            int l,r;
            cin >> l >> r;
            int p = l;
            while(pos.size()){
                auto i = pos.lower_bound(p);
                int it = *i;
                if(i == pos.end() || it > r) break;
                a[it] = func(a[it]);
                if(a[it] < 10) pos.erase(it);
                p = it + 1;
            }
            // while(1){
            //     auto i = pos.lower_bound(p);
            //     if(i == pos.end() || *i > r) break;
            //     int it = *i;
            //     a[it] = func(a[it]);
            //     if(a[it] < 10) pos.erase(it);//i被释放了？
            //     p = it + 1;
            // }
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