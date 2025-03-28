#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#define IOS ios::sync_with_stdio(false);cout.tie(nullptr),cout.tie(nullptr)
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
int n;
const int N = 1e5 + 10;
int a[N],ans;
void quick_sort(int a[],int l,int r){
    if(l >= r) return;
    int x = a[l],i = l - 1,j = r + 1;
    while(i < j){
        do i++;while(a[i] < x);
        do j--;while(a[j] > x);
        if(i < j) swap(a[i],a[j]),ans ++;
    }
    quick_sort(a,l,j);
    quick_sort(a,j+1,r);
}
void solve(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    quick_sort(a,0,n-1);
    cout << ans << endl;
}
signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}