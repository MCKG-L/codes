#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 1e4 + 10;
int n,c1,c2;
void solve(){
    cin >> n >> c1 >> c2;
    int tot = 0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];tot += a[i];
    }
    int sum = 0,ans = 0;
    vector<bool> st(n + 1),m;
    function<void(int u)> dfs = [&](int u)-> void{
        if(u >= n){
            if(sum > ans){
                m = st;
                ans = sum;
            }
            return;
        }
        for(int i=0;i<n;i++){
            if(st[i]) continue;
            if(sum + a[i] <= c1){
                st[i] = true;
                sum += a[i];
                dfs(u + 1);
                st[i] = false;
                sum -= a[i];
            }else{
                dfs(u + 1);
            }
        }
    };
    dfs(0);
    if(tot - ans > c2){
        cout << "No Solution" << endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(m[i]) cout << i + 1 << ' ';
    }
    cout << endl;
    for(int i=0;i<n;i++){
        if(!m[i]) cout << i + 1 << ' ';
    }
    cout << endl;
}
int main()
{
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}