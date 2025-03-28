#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<string> a;
unordered_map<int,char> mp = {{2,'T'},{3,'B'},{4,'K'}},p = {{1,'W'},{2,'Y'}};
void solve(){
    string s;cin >> s;
    a.clear();
    int n = s.size();
    while(n){
        if(n % 4 != 0){
            a.push_back(s.substr(0,n%4));
            s = s.substr(n%4);
            n -= n % 4;
        }else{
            a.push_back(s.substr(0,4));
            s = s.substr(4);
            n -= 4;
        }
        // cout << s << endl;
    }
    string ans = "";
    // for(int i=0;i<a.size();i++) cout << a[i] << endl;
    if(a.size() == 1 && a[0] == "0") ans += '0';
    for(int i=0;i<a.size();i++){
        string s = a[i];
        for(int j=0;j<s.size();j++){
            if(s[j]!='0'){
                ans += s[j];
                if(j != s.size()-1) ans += mp[s.size()-j];
            }
            else{
                int k = j;
                while(j<s.size() && s[j]=='0') j++;
                if(j == s.size()){
                    if(k == 0) continue;
                    if(i != a.size()-1) ans+=p[a.size()-i-1];
                }else{
                    ans += '0';
                    j--;
                }
            }
            if(i != a.size()-1 && j == s.size()-1) ans += p[a.size()-i-1];
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