#include <iostream>
using namespace std;
const int N = 200;
int p[N];
int n,k;
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void solve(){
    for(int i='a';i<='z';i++){
        p[i] = i;
    }
    cin >> n >> k;
    string s;cin >> s;
    for(int i=0;i<n;i++){
        int j = s[i];
        while(k > 0 && find(j) != 'a'){
            k --;
            p[find(j)] = find(j-1);
            j --;
        }
    }
    string ans = "";
    for(int i=0;i<n;i++){
        ans += find(s[i]);
    }
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}