#include <iostream>
#include <stack>
#define endl '\n'
using namespace std;
const int N = 1e5 + 10;
//超时~~~ 需要用二分答案！
struct Node{
    int a,b;
    int l,r;
}p[N];
int n,m,q;
int a[N];
void solve(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int l,r;
        cin >> l >> r;
        p[i] = {r-l+1,0,l,r};
    }
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i=0;i<q;i++){
        ans ++;
        for(int j=0;j<m;j++){
            if(a[i] >= p[j].l && a[i] <= p[j].r){
                p[j].a --;p[j].b ++;
            }
            if(p[j].a < p[j].b){
                cout << ans << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}