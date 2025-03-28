#include <iostream>
using namespace std;
bool isprime(int n){
    if(n == 1) return false;
    else if(n == 2 || n == 3) return true;
    bool ans = true;
    for(int i=2;i*i<=n;i++){
        if(n % i == 0){
            ans = false;
            break;
        }
    }
    return ans;
}
int main()
{
    int n;cin >> n;
    int mask = 1;
    int t = n;
    while(t>9){
        mask *= 10;
        t /= 10;
    }
    int ans = 0;
    while(n){
        ans += (n % 10) * mask;
        mask /= 10;
        n /= 10;
    }
    if(isprime(n) && isprime(ans)){
        cout << "yes";
    }else {
        cout << "no";
    }
    return 0;
}