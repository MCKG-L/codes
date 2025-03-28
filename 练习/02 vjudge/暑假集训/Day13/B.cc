#include <iostream>
using namespace std;
const int N = 31;
int a[N],n;
int ans;
//错！！！
void dfs(int t,int s){
    if(s >= ans) return;
    if(t == n){
        ans = s;
        return;
    }
    if(t == 0){
        int temp = a[t];
        a[t] /= 2;
        dfs(t+1,s+1);
        a[t] = temp;
        dfs(t+1,s);
    }else{
        if(a[t] < a[t-1]) return;
        if(a[t] > a[t-1]){
            dfs(t+1,s);
            if(a[t] / 2 > a[t-1]){
                int temp = a[t];
                a[t] /= 2;
                dfs(t+1,s+1);
                a[t] = temp;
            }
        }
    }
}
void solve(){
    cin >> n;
    ans = 1e9;
    for(int i=0;i<n;i++) cin >> a[i];
    dfs(0,0);
    if(ans == 1e9) ans = -1;
    cout << ans << endl;

}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}