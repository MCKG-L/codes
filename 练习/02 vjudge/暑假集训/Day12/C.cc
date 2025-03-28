#include <iostream>
#include <vector>
using namespace std;
vector<int>p1,p2;
void solve(){
    p1.clear();p2.clear();
    int n;char c;
    string s;
    cin >> n >> c >>  s;
    for(int i=0;i<n;i++){
        if(s[i] == c) p1.push_back(i);
        if(s[i] == 'g') p2.push_back(i);
    }
    int ans = 0;
    int l1 = p1.size(),l2 = p2.size();
    for(int i=0;i<l1;i++){
        if(p1[i] > p2[l2-1]){
            int pos = p2[0];
            ans = max(ans,n+pos-p1[i]);
        }else{
            int pos = *lower_bound(p2.begin(),p2.end(),p1[i]);
            // cout << pos << "---" << endl;
            ans = max(ans,pos-p1[i]);
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}