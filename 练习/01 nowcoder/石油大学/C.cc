#include <iostream>
#include <vector>
#include <map>
#include <cmath>
typedef long long ll;
using namespace std;
const int N = 2e5+10;
vector<int> p[N];
void divide(int x,int i){
    for(int k=2;k<=sqrt(x);k++){
        if(x % k == 0){
            p[i].push_back(k);
            while(x % k == 0) x /= k;
        }
    }
    if(x > 1) p[i].push_back(x);
}

void solve(){
    map<int,int> pos;
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        p[i].resize(0);
        divide(x,i);
    }
    long long ans = 0;
    //这里i,j要用long long,否则乘法运算过程中会溢出
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<p[i].size();j++){
            if(!pos[p[i][j]]) ans += (n-i+1)*i,pos[p[i][j]] = i;
            else ans += (i-pos[p[i][j]])*(n-i+1),pos[p[i][j]] = i;
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}