#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin >> n;
    string maxs,s;
    int maxn = 1;
    for(int i=0;i<n;i++){
        cin >> s;
        if(maxs.size()==s.size()&&s>maxs||s.size()>maxs.size()){
            maxs = s;
            maxn = i + 1;
        }
    }
    cout << maxn << '\n' << maxs;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}