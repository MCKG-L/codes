/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    double v,a,l;
    cout << "Enter speed ans acceleration: ";cin >> v >> a;
    l = v * v /(2 * a);
    cout << "The minimum runway length for this airplane is " << l << endl;
    return 0;
}