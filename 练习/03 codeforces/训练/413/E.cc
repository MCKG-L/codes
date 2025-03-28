#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;
//错！！！
unordered_map<int,char> mp = {{0,'a'},{1,'W'},{2,'Y'}},p = {{0,'K'},{1,'B'},{2,'T'}};
void solve(){
    string s;cin >> s;
    vector<char> ans;
    for(int i=0;i<s.size();i++){
        if(s[i] == '0'){
            int k = i;bool flag = false;
            while(s[i] == '0' && i % 4 != 3) i++;
            if(i % 4 != 3){
                flag = true;
                ans.push_back('0');
                ans.push_back(s[i]);
                ans.push_back(p[i%4]);
            }else if(flag){
                ans.push_back(p[k%4]);
            }else ans.push_back(mp[ans.size()-k-1]);
        }else{
            ans.push_back(s[i]);
            ans.push_back(p[i%4]);
            if(i % 4 == 3) ans.push_back(mp[ans.size()-i-1]);
        }
    }
    ans.pop_back();
    for(int i=0;i<ans.size();i++) cout << ans[i];
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;cin >> t;cin.get();
    while(t--) solve();
    return 0;
}