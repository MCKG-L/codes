#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> PII;
int n,m;
vector<int> a;
void solve(){
    cin >> n >> m;
    a.resize(m + 1);
    int ed;
    for(int i=1;i<=m;i++) cin >> a[i];
    cin >> ed;
    if(ed > n){
        cout << "No Solution" << endl;
        return;
    }
   vector<int> ans;
    for(int i=1,j=0;i<=m;i++){
        if(a[i] > n){
            cout << "No Solution" << endl;
            return;
        }
        int t = n;
        for(j=i;j<=m;j++){
            t -= a[j];
            if(t < 0){
                break;
            }
        }
        ans.push_back(j - 1);
        i = j - 1;
    }
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << ' ';
    cout << endl;
}
int main()
{
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}