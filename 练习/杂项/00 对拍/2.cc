#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
void solve(int n){
    if(n == 0) return;
    queue<int> q;
    for(int i=1;i<=n;i++) q.push(i);
    cout << "Discarded cards:";
    while(q.size() > 1){
        if(q.size() == n) cout << " " << q.front();
        else cout << ", " << q.front();
        q.pop();q.push(q.front());
        q.pop();
    }
    cout << "\n" << "Remaining card: " << q.front() << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("in.txt","r",stdin);
    freopen("out2.txt","w",stdout);
    int T = 1;
    while(cin >> T){
        solve(T);
        if(T == 0) break;
    }
    return 0;
}