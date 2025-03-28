#include <iostream>
#include <vector>
using namespace std;
int n;
bool func(string s){
    for(int i=0;i<n/2;i++){
        if(s[i] != s[n-i-1]) return false;
    }
    return true;
}
void solve(){
    vector<string> p;
    string s;cin >> n;
    for(int i=0;i<2*(n-1);i++){
        cin >> s;
        if(s.size() == n - 1) p.push_back(s);
    }
    // cout << p[0] << ' ' << p[1] << endl;
    int k = n - 2;
    string ans;
    if(p[0].substr(1) == p[1].substr(0,k)){
        ans = p[0] + p[1][k];
    }else if(p[1].substr(1) == p[0].substr(0,k)){
        ans = p[1] + p[0][k];
    }
    // cout << ans << endl;
    if(func(ans)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}