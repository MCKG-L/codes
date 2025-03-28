#include <iostream>
#include <algorithm>
using namespace std;
//O(sqrt(n)) 
bool is_prime(int n){
    if(n < 2) return false;
    for(int i=2;i<=n/i;i++){//防止溢出
        if(n % i == 0) return false;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    if(is_prime(n)) puts("Yes");
    else puts("No");
    return 0;
}