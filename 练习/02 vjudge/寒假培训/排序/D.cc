#include <bits/stdc++.h>
using namespace std;
bool cmp(string s1,string s2){
    return s1 + s2 > s2 + s1;
}
void solve(){
    int n;
    cin >> n;
    string s[n];
    for(int i=0;i<n;i++) cin >> s[i];
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++){
        cout << s[i];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}