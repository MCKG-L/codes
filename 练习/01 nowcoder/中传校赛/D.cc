#include <iostream>
#include <map>
#include <set>
using namespace std;
map<int,int> mp[3];
set<int> s;
int main()
{
    int n;cin >> n;
    long long sum = 0;
    for(int i=0;i<n;i++){
        char q;int p,m;
        cin >> p >> q >> m;
        sum += m;
        s.insert(p);
        if(q == 'L') mp[0][p] = m;
        else if(q == 'R') mp[1][p] = m;
        else mp[2][p] = m;
    }
    long long ans = 0;
    for(auto i : s){
        int L = mp[0].count(i),R = mp[1].count(i);
        //如果属于颜色i的袜子，既没有左也没有右，就至少要取一只通用袜子
        // if(mp[0].count(i) + mp[1].count(i) == 0) ans++;
        if(!L && !R) ans++;
        else ans += max(mp[1][i],mp[0][i]);
    }
    if(ans == sum){
        cout << -1 << '\n';
    }else{
        cout << ans + 1 << '\n';
    }
    return 0;
}