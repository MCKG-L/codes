#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e5 + 10;
int n;
struct Seg{
    double x,y1,y2;
    int k;
    bool operator<(const Seg &t)const{
        return x < t.x;
    }
}seg[N*2];
struct Node{
    int l,r;
    int cnt;
    double len;
}tr[N*8];
vector<double> alls;
double find(double x){
    return lower_bound(alls.begin(),alls.end(),x)-alls.begin();
}
void pushup(int u){
    if(tr[u].cnt) tr[u].len = alls[tr[u].r+1]-alls[tr[u].l];
    else if(tr[u].l == tr[u].r){
        tr[u].len = 0;
    }else{
        tr[u].len = tr[u<<1].len + tr[u<<1|1].len;
    }
}
void build(int u,int l,int r){
    tr[u] = {l,r,0,0};
    if(l != r){
        int mid = l + r >> 1;
        build(u<<1,l,r);build(u<<1|1,l,r);
    }
}
void modify(int u,int l,int r,int k){
    if(tr[u].l >= l && tr[u].r <= r){
        tr[u].cnt += k;
        pushup(u);
    }else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u<<1,l,r,k);
        if(r > mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}
void solve(int T){
    alls.clear();
    for(int i=0,j=0;i<n;i++){
        double x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        seg[j ++] = {x1,y1,y2,1};
        seg[j ++] = {x2,y1,y2,-1};
        alls.push_back(y1);
        alls.push_back(y2);
    }
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    build(1,0,alls.size()-2);
    sort(seg,seg+n*2);
    double ans = 0;
    for(int i=0;i<2*n;i++){
        if(i > 0) ans += tr[1].len * (seg[i].x - seg[i-1].x);
        modify(1,find(seg[i].y1),find(seg[i].y2)-1,seg[i].k);
    }
    cout << "Test case #" << T << endl;
    cout << fixed << setprecision(2);
    cout << "Total explored area: " << ans << '\n' << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int k = 1;
    while(cin >> n && n) solve(k ++);
    return 0;
}