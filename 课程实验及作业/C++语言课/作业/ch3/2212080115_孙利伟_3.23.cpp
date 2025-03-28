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
    cout << "Enter a point's x- and y- coordinates: ";
    cin >> x >> y;
    if(x + 2*y - 200 <= 0) cout << "The point is in the triangle" << endl;
    else cout << "The point is not in the triangle" << endl;
    return 0;
}