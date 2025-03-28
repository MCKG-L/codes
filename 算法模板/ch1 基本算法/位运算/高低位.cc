#include <iostream>
using namespace std;
int main()
{
    // int a = (2 << 29) + 5;
    // int b = a << 16;
    // int c = b >> 16;
    // int d = a >> 16;
    // cout << n << ' ' << (n << 16) << ' ' << ((n << 16) >> 16);
    // for(int i=31;i>=0;i--){
    //     cout << (a >> i & 1);
    // }
    // cout << endl;
    // for(int i=31;i>=0;i--){
    //     cout << (b >> i & 1);
    // }
    // cout << endl;
    // for(int i=31;i>=0;i--){
    //     cout << (c >> i & 1);
    // }
    // cout << endl;
    // for(int i=31;i>=0;i--){
    //     cout << (d >> i & 1);
    // }
    // cout << endl;
    // cout << (1 << 1 & b);
    unsigned int n;
    n = (1 << 31) - 1;
    cout << ((n << 16) + (n >> 16));
    return 0;
}