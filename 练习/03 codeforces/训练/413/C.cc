#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<int> a,b;
bool is_prime(int n){
    if(n < 2) return false;
    for(int i=2;i<=n/i;i++){
        if(n % i == 0) return false;
    }
    return true;
}
void solve(){
    a.clear(),b.clear();
    for(int i=0;i<3;i++){
        int x;cin >> x;
        if(x % 2 == 0) b.push_back(x);
        else a.push_back(x);
    }
    int n = a.size();
    char ans;
    if(n == 2){
        if(is_prime(a[0]+a[1])) ans = 'R';
        else {
            if(b[0] >= 2 && is_prime(a[0]+b[0]) && is_prime(a[1]+b[0])) ans = 'R';
            else ans = 'P';
        }
    }else if(n == 0) ans = 'R';
    else ans = 'P';
    cout << (char)ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}