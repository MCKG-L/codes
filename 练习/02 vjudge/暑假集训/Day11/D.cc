#include <iostream>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int n;
void solve(){
    int n;cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int cnt = 0;
    for(int i=0,j=0;i<n;i++){
        if(i == 0){
            while(j < n && a[j] == a[i]) j++;
            if(a[j] > a[i] || j == n) cnt++;
            i = j - 1;
        }else{
            if(a[i-1] <= a[i]) continue;
            j = i;
            while(j < n && a[j] == a[i]) j++;
            if(a[j] > a[i] || j == n){
                cnt ++;
            }
            i = j - 1;
        }
    }
    if(cnt == 1) puts("YES");
    else puts("NO"); 
}
int main(){
    int t;cin >> t;
    while(t--) solve();
    return 0;
}