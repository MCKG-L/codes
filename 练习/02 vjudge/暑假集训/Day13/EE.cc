#include <iostream>
using namespace std;
const int N = 26;
int p[N];
int n,k;
void solve(){
    for(int i=0;i<26;i++){
        p[i] = 0;
    }
    cin >> n >> k;
    string s;cin >> s;
    for(int i=0;i<n;i++){
        int j = s[i];
        while(!p[j-'a'] && k && j>'a'){
            p[j-'a'] ++;
            k --,j --;
        }
    }
    string ans = "";
    for(int i=0;i<n;i++){
        char c = s[i];
        while(p[c-'a']) c --;
        ans += c;
    }
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}