#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int b = 211;
    cout << a << ' ' << b << endl;
    a ^= b ^= a ^= b;
    cout << a << ' ' << b << endl;
    return 0;

}