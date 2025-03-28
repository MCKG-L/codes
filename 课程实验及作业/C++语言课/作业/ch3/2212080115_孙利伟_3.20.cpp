/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    double x,y;
    cout << "Enter a point with two coordinates: ";cin >> x >> y;
    if(x >= -1 && x <= 5 && y <= 2.5 && y >= -2.5) cout << "Point(" << x << ", " << y << ") is in the rectangle\n";
    else cout << "Point(" << x << ", " << y << ") is not in the rectangle\n";
    return 0;
}