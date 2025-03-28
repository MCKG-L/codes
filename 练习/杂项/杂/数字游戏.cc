#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[5];
bool isprime(ll q){
    bool mask = true;
    for(int i=2;i<=q/i;i++){
        if(q % i == 0){
            mask = false;
            break;
        }
    }
    return mask;
}
int main()
{
    ll q;
    cin >> q;
    if(isprime(q)){
        cout << 1 << '\n' << 0;
    }else{
        int cnt = 0;
        for(ll i=2;i<=sqrt(q);i++){
            while(q % i == 0){
                a[cnt++] = i;
                q /= i;
                if(cnt > 2) break;
            }
            // if(cnt > 2) break;
        }
        if(q != 1) a[cnt++] = q;//最后的因子
        if(cnt >= 3){
            cout << 1 << '\n' << a[0]*a[1];
        }else if(cnt == 2){
            cout << 2 << '\n';
        }
    }
    return 0;
}