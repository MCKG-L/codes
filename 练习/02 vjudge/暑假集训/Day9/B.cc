#include <iostream>
#include <map>
using namespace std;
map<string ,int> mp;
const int N = 105;
string a[N],b[N];
int cost[N];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++) cin >> b[i];
    int d = 0;
    cin >> d;
    for(int i=1;i<=m;i++){
        cin >> cost[i];
        mp[b[i]] = cost[i];
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(mp.count(a[i])){
            ans += mp[a[i]];
        }else{
            ans += d;
        }
    }
    cout << ans << endl;
    return 0;
}