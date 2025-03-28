#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
struct node{
    int num,x;
}a[N];
bool cmp(node p1,node p2){
    if(p1.x == p2.x){
        return p1.num < p2.num;
    }else return p1.x > p2.x;
}
void solve(){
    int n,m;
    cin >> n >> m;
    int b[n] = {};
    for(int i=0;i<n;i++){
        cin >> a[i].num >> a[i].x;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        b[i] = a[n-i-1].x;
    }
    int mask = a[(int)(m*1.5)-1].x;
    int cnt =  n - (lower_bound(b,b+n,mask)- b);
    cout << mask << " " << cnt << '\n';
    for(int i=0;i<cnt;i++){
        cout << a[i].num << " " << a[i].x << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}