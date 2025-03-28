#include <iostream>
#include <vector>
using namespace std;
void solve(){
    vector<int> ans;
    int a,b;
    cin >> a >> b;
    int cnt = 0;
    while(1){
        int ra = a % b;
        int rb = b;
        cnt ++;
        ans.push_back(a/b);
        a = rb,b = ra;
        if(!b) break;
    }
    cout << cnt - 1 << ' ';
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
}
int main()
{
    int t;cin >> t;
    while(t--)solve();
    return 0;
}