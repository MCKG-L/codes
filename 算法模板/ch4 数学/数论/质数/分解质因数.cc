#include <iostream>
#include <algorithm>
using namespace std;
//O(sqrt(n)) 
void divide(int n){
    for(int i=2;i<=n/i;i++){
        if(n % i == 0){
            int s = 0;
            while(n % i == 0) s++,n /= i;
            cout << i << ':' << s << endl;
        }
    }
    //最多只有一个大于sqrt(n) 的质因子
    if(n > 1) cout << n << ':' << 1 << endl;
}
int main()
{
    int n;cin >> n;
    divide(n);
    return 0;
}