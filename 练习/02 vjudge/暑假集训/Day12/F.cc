#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
/*
枚举x以得到gcd(x,a*b)，则y = k * a*b/gcd,将y映射到可能的最大值: y = y * (d / y)
直接枚举可能的gcd,x = kk * gcd 直接将x映射到可能的最大值 x = x * (c / x)
*/
ll a,b,c,d;
ll x,y;
void solve(){
    vector<int> p1,p2;
    cin >> a >> b >> c >> d;
    for(int i=1;i<=a/i;i++){
        if(a % i == 0){
            p1.push_back(i);
            p1.push_back(a/i);
        }
    }
    for(int i=1;i<=b/i;i++){
        if(b % i == 0){
            p2.push_back(i);
            p2.push_back(b/i);
        }
    }
    for(ll d1 : p1){
        for(ll d2 : p2){
            x = d1 * d2;
            y = a * b / x;
            x = c / x * x;
            y = d / y * y;
            if(x > a && x <= c && y > b && y <= d){
                cout << x << ' ' << y << endl;
                return;
            }
        }
    }
    cout << -1 << ' ' << -1 << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}