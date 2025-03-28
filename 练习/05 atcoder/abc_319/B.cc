#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;cin >> n;
    for(int i=0;i<=n;i++){
        bool f = 0;
        for(int j=1;j<=9;j++){
            if(n % j == 0 && i % (n / j) == 0){
                cout << j;
                f = 1;break;
            }
        }
        if(!f) cout << '-';
    }
    return 0;
}