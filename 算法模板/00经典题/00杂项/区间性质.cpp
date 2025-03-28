#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  1e6 + 10,inf = 3e18;
/*
给出n个区间[L1,R1]、[L2,R2]...[Ln,Rn],从左到右，如果当前分数在区间范围内，则分数加一
有q次询问，问当初始分数是x时，经过这b个区间之后，分数是多少？

该问题有个性质：对于当前的区间[L,R],如果能从该区间拿到加分，则初始分数一定满足在一个连续区间中
可以使用二分找到这个区间的左右端点
维护初始分数是x 
*/
struct Fenwick{
    std::vector<int> tr;
    int n;
    Fenwick(int n){
        this->n = n;
        tr.resize(n+1,0);
    }
    void add(int x,int c){
        for(int i=x;i<=n;i+=i&-i) tr[i] += c;
    }
    int ask(int x){
        int ans = 0;
        for(int i=x;i>=1;i-=i&-i) ans += tr[i];
        return ans;
    }
    int ask(int l,int r){
        return ask(r) - ask(l-1);
    }
};
void solve(){
    int n;cin >> n;
    Fenwick fenwick(5e5+10);
    for(int i=1;i<=n;i++){
        int L,R;cin >> L >> R;
        int l = 1,r = L;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(mid + fenwick.ask(mid) >= L) r = mid - 1;
            else l = mid + 1;
        }
        int p1 = l;
        l = 1,r = R;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(mid + fenwick.ask(mid) <= R) l = mid + 1;
            else r = mid - 1;
        }
        fenwick.add(p1,1),fenwick.add(r+1,-1);
    }
    int q;cin >> q;
    while(q --){
        int x;cin >> x;
        cout << x + fenwick.ask(x) << endl;
    }
} 
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}