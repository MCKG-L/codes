#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
//贪心 队列
//一个数最多操作三次就可以变成1
void solve(){
    int n;cin >> n;
    priority_queue<int> q1,q2;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        q1.push(x);
    }
    for(int i=0;i<n;i++){
        int x;cin >> x;
        q2.push(x);
    }
    int ans = 0;
    while(q1.size() && q2.size()){
        int a = q1.top(),b = q2.top();
        if(a != b){
            ans ++;
            if(a > b){
                q1.pop();
                q1.push(to_string(a).size());
            }else{
                q2.pop();
                q2.push(to_string(b).size());
            }
        }else{
            q1.pop();
            q2.pop();
        }
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}