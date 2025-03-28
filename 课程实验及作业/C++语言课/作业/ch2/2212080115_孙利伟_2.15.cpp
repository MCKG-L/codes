/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double x1,x2,y1,y2,d;
    cout << "Enter x1 and y1: ";cin >> x1 >> y1;
    cout << "Enter x2 and y2: ";cin >> x2 >> y2;
    d = pow(pow(x1-x2,2)+pow(y1-y2,2),0.5);
    cout << "The distance between the two points is " << d << endl;
    return 0;
}