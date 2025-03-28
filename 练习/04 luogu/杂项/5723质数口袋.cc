#include <iostream>
using namespace std;
int main()
{
    int L;
    cin >> L;
    int cnt = 0,sum = 0,i = 2;
    while(sum < L){
        bool mask = true;
        for(int j=2;j*j<=i;j++){
            if(i % j == 0){
                mask = false;
                break;
            }
        }
        if(mask){
            sum += i;
            if(sum <= L){
                cout << i << endl;
                cnt ++;
            }
        }
        i++;
    }
    cout << cnt;
    return 0;
}