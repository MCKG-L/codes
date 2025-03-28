#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> PII;
const int N = 21;
int a[N],n;
void solve(){
    cin >> n;
    int ma = -21,mi = 21;
    int p1 = 0,p2 = 0,cnt = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i] < 0) cnt ++;
        if(a[i] > ma) ma = a[i],p1 = i;
        if(a[i] < mi) mi = a[i],p2 = i;
    }
    if(ma <= 0){
        cout << n - 1 << endl;
        for(int i=n-1;i>=1;i--) cout << i << ' ' << i + 1 << endl;
        return;
    }
    if(mi >= 0){
        cout << n - 1 << endl;
        for(int i=2;i<=n;i++){
            cout << i << ' ' << i - 1 << endl;
        }
        return;
    }
    vector<PII> ans;
    if(cnt <= 7){
        while(ma < 21){
            ans.push_back({p1,p1});
            ma *= 2;
        }
        for(int i=1;i<=n;i++){
            if(a[i] < 0) ans.push_back({i,p1});
        }
        for(int i=2;i<=n;i++) ans.push_back({i,i-1});
        cout << ans.size() << endl;
        for(auto i : ans) cout << i.first << ' ' << i.second << endl;
        return;
    }
    if(cnt > 12){
        while(mi > -21){
            mi *= 2;
            ans.push_back({p2,p2});
        }
        for(int i=1;i<=n;i++){
            if(a[i] > 0) ans.push_back({i,p2});
        }
        for(int i=n-1;i>=1;i--) ans.push_back({i,i+1});
        cout << ans.size() << endl;
        for(auto i : ans) cout << i.first << ' ' << i.second << endl;
        return;
    }
    if(ma + mi >= 0){
        for(int i=1;i<=n;i++){
            if(a[i] < 0) ans.push_back({i,p1});
        }
        for(int i=2;i<=n;i++) ans.push_back({i,i-1});
        cout << ans.size() << endl;
        for(auto i : ans) cout << i.first << ' ' << i.second << endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(a[i] > 0) ans.push_back({i,p2});
    }
    for(int i=n-1;i>=1;i--) ans.push_back({i,i+1});
    cout << ans.size() << endl;
    for(auto i : ans) cout << i.first << ' ' << i.second << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}