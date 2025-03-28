#include <iostream>
#include <cmath>
using namespace std;
bool is_prime(int n){
    if(n == 2 || n == 3) return 1;
    for(int i=2;i<=n/i;i++){
        if(n % i == 0){
            return 0;
        }
    }
    return true;
}
int main()
{
    int n;cin >> n;
    if(is_prime(n)){
        cout << 1 << endl << n;
        return 0;
    }
    int ans = 0,st = 0;;
    for(int i=2;i<=sqrt(n);i++){
        if(n % i == 0){
            int temp = n,cnt = 0,k = i;
            while(temp % k == 0) cnt++,temp/=k,k++;
            if(cnt > ans){
                st = i;
                ans = cnt;
            }
        }
    }
    cout << ans << endl;
    for(int i=st;i<st+ans;i++){
        cout << i << (i < st + ans - 1 ? '*' : '\0');
    }
    cout << endl;
    return 0;
}