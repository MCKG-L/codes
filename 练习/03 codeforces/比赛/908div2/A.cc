#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    for(int x=1;x<=20;x++){
        int cnt0 = 0,cnt1 = 0;
        int s0 = 0,s1 = 0;
        for(int i=0;i<n;i++){
            if(s[i] == 'A') s0 ++;
            else s1 ++;
            if(s0 == x){
                cnt0 ++;
                s1 = s0 = 0;
            }
            if(s1 == x){
                cnt1 ++;
                s1 = s0 = 0;
            }
        }
        if(s.back() == 'A' && cnt0 > cnt1){
            cout << "A" << endl;
            return;
        }
        if(s.back() == 'B' && cnt1 > cnt0){
            cout << "B" << endl;
            return;
        }
    }
    cout << "?" << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}