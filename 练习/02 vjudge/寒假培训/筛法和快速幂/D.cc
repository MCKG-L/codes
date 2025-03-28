#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4;
ll mask[N],q;
int cnt;
void devide(ll n){
    int len = (ll)sqrt(n);
    int a,flag = 0;
    ll temp = n;
    for(int i=2;i<=len;i++){
        if(n % i == 0){
            a = i;
            flag = 1;
            break;
        }
    }
    if(flag){
        flag = 0;
        for(int i=a;i<=n;i++){
            while(n % i == 0){
                mask[cnt++] = i;
                n /= i;
                //卡1234567891 * 2
                if(cnt == 1 && temp % mask[0] == 0){
                    int l = sqrt(n);
                    for(int j=2;j<=l;j++){
                        if(n % j == 0){
                            flag = 1;
                        }
                    }
                    if(flag == 0){
                        cnt = 2;
                        return;
                    }else{
                        continue;
                    }
                }
                //卡12345678910
                if(cnt == 2 && temp % (mask[0]*mask[1]) == 0 && n!=1){
                    cnt = 3;
                    return;
                }
            }
            
        }
    }
    
}
int main()
{
    cin >> q;
    devide(q);
    for(int i=0;i<cnt;i++){
        cout << mask[i] << " ";
    }
    cout << cnt << endl;
    if(cnt == 0){
        cout << 1 << '\n' << 0;
    }else if(cnt > 2){
        cout << 1 << '\n' << mask[0]*mask[1];
    }else{
        cout << 2;
    }
    return 0;
}