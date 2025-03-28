#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <set>
#include <queue>
#include <map>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 6;
string a[N],b[N];
int n;
int func(queue<string> &q,unordered_map<string,int> &d1,unordered_map<string,int> &d2,string a[],string b[]){
    int d = d1[q.front()];
    //每次扩展一层
    while(q.size() && d1[q.front()] == d){
        string t = q.front();q.pop();
        for(int i=0;i<t.size();i++){
            for(int j=0;j<n;j++){
                if(t.substr(i,a[j].size()) == a[j]){
                    string s = t.substr(0,i) + b[j] + t.substr(i+a[j].size());
                    if(d2.count(s)) return d1[t] + d2[s] + 1;
                    if(d1.count(s)) continue;
                    d1[s] = d1[t] + 1;
                    q.push(s);
                }
            }
        }
    }
    return 11;
}
int bfs(string A,string B){
    queue<string> q1,q2;
    unordered_map<string,int> d1,d2;
    q1.push(A);q2.push(B);
    d1[A] = 0;d2[B] = 0;
    if(A == B) return 0;
    int dep = 0;
    while(q1.size() && q2.size()){
        dep ++;
        int t = 0;
        if(q1.size() <= q2.size()) t = func(q1,d1,d2,a,b);
        else t = func(q2,d2,d1,b,a);
        if(t <= 10) return t;
        if(dep == 10) return 11;
    }
    return 11;
}
void solve(){
    string A,B;
    cin >> A >> B;
    while(cin >> a[n] >> b[n]) n ++;
    int ans = bfs(A,B);
    if(ans > 10) cout << "NO ANSWER!" << endl;
    else cout << ans << endl;
}
signed main()
{
    IOS;int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
