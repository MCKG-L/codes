#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
const int N = 2e5 + 10;
void print(int l,int r){
    cout << "? " << (r-l+1) << ' ';
    for(int i=l;i<=r;i++){
        cout << i;
        if(i != r) cout << ' ';
    }
    cout << endl;
}
void solve(){
    int n;cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    int l = 1,r = n;
    while(l < r){
        int mid = l + r >> 1;
        print(l,mid);
        int s;cin >> s;
        if(a[mid] - a[l-1] != s) r = mid;
        else l = mid + 1;
    }
    cout << "! " << l << endl;
    cout.flush();
}
signed main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}