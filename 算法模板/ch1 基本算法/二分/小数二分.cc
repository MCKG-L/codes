#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
//求一个数的平方根
double m_binary(double x){
    double l = 0,r = x;
    while(r -l > 1e-8){
        double mid = (l + r) / 2;
        if(mid*mid >= x) r = mid;
        else l = mid;
    }
    return l;
}
int main()
{
    double n;cin >> n;
    cout << sqrt(n) << endl;
    cout << m_binary(n) << endl;
    return 0;
}