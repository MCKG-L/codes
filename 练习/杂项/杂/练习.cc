#include <iostream>
using namespace std;
int a[7] = {2,8,8,18,18,32,32};
int main()
{
    int t;cin >> t;
    while(t--){
        int x;cin >> x;
        int i = 0;
        for(i=0;i<7 && x>0;i++){
            // int r = x % a[i];
            x -= a[i];
        }
        cout << i << endl;
    }
}