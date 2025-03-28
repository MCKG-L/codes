/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <cmath>
using namespace std;
const double pi = acos(-1);
int main()
{
    double l,r;
    cout << "Enter the radius ans length of a cylinder: ";
    cin >> r >> l;
    double a,v;
    a = pi * r * r;
    v = a * l;
    cout << "The area is " << a << endl;
    cout << "The volum is " << v << endl;
    return 0;
}