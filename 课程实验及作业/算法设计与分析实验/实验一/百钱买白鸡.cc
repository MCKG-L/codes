#include <iostream>
using namespace std;
int main()
{
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            int x = 100 - i - j;
            if(x % 3) continue;
            if(5 * i + 3 * j + x / 3 == 100){
                cout << i << ' ' << j << ' ' << x << endl;
            }
        }
    }
    return 0;
}