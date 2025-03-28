#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll a[N];
void print(int l,int r){
    cout << '?' << ' ';
    cout << r - l + 1 << ' ';
    for(int i=l;i<=r;i++){
        cout << i;
        if(i != r) cout << ' ';
    }
    cout << endl;
}
void m_find(int l,int r){
    while(l < r){
        int mid = (l + r) / 2;
        print(l,mid);
        ll s;cin >> s;
        if(a[mid] - a[l-1] != s){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << "! " << l << endl;
    cout.flush();
}
void solve(){
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    m_find(1,n);
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}