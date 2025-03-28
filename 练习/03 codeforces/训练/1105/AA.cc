#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
map<char,int> mp = {{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9},{'A',10},
{'B',11},{'C',12},{'D',13},{'E',14},{'F',15}};
void solve(){
    string A,B,S;
    cin >> A >> B >> S;
    for(int X=16;X>1;X--){
        int a = 0,b = 0,s = 0;
        for(int i=0;A[i];i++) a = a * X + mp[A[i]];
        for(int i=0;B[i];i++) b = b * X + mp[B[i]];
        for(int i=0;S[i];i++) s = s * X + mp[S[i]];
        if(a + b == s){
            cout << X << endl;
            return;
        }
    }

}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}