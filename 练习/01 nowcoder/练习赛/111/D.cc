#include <iostream>
#define int long long
using namespace std;
int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x = 1,y = 0;
        return a;
    }
    int d = exgcd(b,a%b,y,x);
    y -= (a / b) * x;
    return d;
}
signed main()
{
    int t;cin >> t;
    while(t--){
        int a,b,n,L,R;
        cin >> a >> b >> n >> L >> R;
        int x,y;
        int d = exgcd(a,b,x,y);
        if(n % d){
            cout << "NO" << endl;
        }else{
            int p = b / d;
            x = x * n / d;
            x = (x + p) % p;
            int l,r;
            if(L < x) l = 0;
            else{
                l = (L - x + p -1) / p;
            }
            if(R < x) r = -1;
            else{
                r = (R - x) / p;
            }
            if(l > r) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
    return 0;
}