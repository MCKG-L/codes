#include <iostream>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int n,k;
void solve(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int l = 0,r = n-1;
    int cnt = 0;
    while(l < n && cnt < k){
        if(a[l] == a[0]) cnt ++;
        l ++;
    }
    if(cnt == k) l --;
    cnt = 0;
    while(r > 0 && cnt < k){
        if(a[r] == a[n-1]) cnt ++;
        r --;
    }
    if(cnt == k) r ++;
    if(a[0] == a[n-1]){
        if(l < n || r > 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        return;
    }
    if(l == n || r == 0 || l >= r){
        cout << "NO" << endl;
        return;
    }else{
        cout << "YES" << endl;
        return;
    }
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}