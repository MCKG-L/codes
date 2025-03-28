#include <iostream>
#include <map>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int l[N],r[N],n,m;
char s[N];
map<PII,int> mp;
void solve(){
    mp.clear();
    cin >> n >> m >> s + 1;
    int p = 0;
    for(int i=1;i<=n;i++){
        if(s[i] == '1') l[i] = p;
        else p = i;
    }
    p = n + 1;
    for(int i=n;i>=1;i--){
        if(s[i] == '0') r[i] = p;
        else p = i;
    }
    while(m--){
        int L,R;
        cin >> L >> R;
        if(s[L] == '0') L = r[L];
        if(s[R] == '1') R = l[R];
        if(L >= R) mp[{0,0}] ++;
        else mp[{L,R}] ++;
    }
    cout << mp.size() << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}
