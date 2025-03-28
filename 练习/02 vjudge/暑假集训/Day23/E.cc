#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
struct Node{
    int x,id;
    int ans;
}a[N];
int n;
void solve(){
    cin >> n;
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> a[i].x;
        a[i].id = i;
        sum += a[i].x;
    }
    sort(a,a+n,[&](Node p1,Node p2){return p1.x < p2.x;});
    for(int i=0;i<n;i++){
        if(i == 0) a[i].ans = sum - n * (a[i].x-1);
        else a[i].ans = a[i-1].ans + (a[i].x-a[i-1].x)*(2*i-n);
    }
    sort(a,a+n,[&](Node p1,Node p2){return p1.id < p2.id;});
    for(int i=0;i<n;i++) cout << a[i].ans << ' ';
    cout << endl;
}
signed main()
{
    IOS;int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
