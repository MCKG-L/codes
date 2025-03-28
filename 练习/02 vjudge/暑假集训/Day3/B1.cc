#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int i = 3,j = 2;
    j *=  i -= (i ++);
    cout << j << ' ' << i << endl;
    i = 3,j = 3;
    j *= i -= ( ++ i);
    cout << j << ' ' << i << endl;
    return 0;
}