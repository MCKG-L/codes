/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    double x1,x2,y1,y2;
    cout << "Enter the coordinates for two points: ";
    cin >> x1 >> y1 >> x2 >> y2;
    double m = (y2-y1)/(x2-x1);
    double b = y1 - m*x1;
    cout << "The line equation for two points (" << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ") is "
    << "y = ";
    if(m != 1) cout << m << " x ";
    else cout << " x";
    if(b != 0) cout << (b > 0 ? '+' : '\0') << b;
    return 0;
}