#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int n){
    if(n == 1) return false;
    if(n == 2 || n == 3) return true;
    for(int i=2;i<=n/i;i++){
        if(n % i == 0) return false;
    }
    return true;
}
int main()
{
    int n;cin >> n;
    while(n--){
        int x;cin >> x;
        if(isprime(x)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}