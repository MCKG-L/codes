/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int main()
{
    double s1,s2,s3,x1,x2,x3,y1,y2,y3,s,a;
    cout << "Enter the points for a triangle: ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    s1 = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    s2 = sqrt(pow(x1-x3,2)+pow(y1-y3,2));
    s3 = sqrt(pow(x2-x3,2)+pow(y2-y3,2));
    s = (s1 + s2 + s3) / 2;
    a = sqrt(s*(s-s1)*(s-s2)*(s-s3));
    cout << "The area of the triangle is " << a << endl;
    return 0;
}