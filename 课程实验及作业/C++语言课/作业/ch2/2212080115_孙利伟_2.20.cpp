/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    double x1,x2,y1,y2,k;
    cout << "Enter thr coordinates for tow points: ";
    cin >> x1 >> y1 >> x2 >> y2;
    k = (y2-y1)/(x2-x1);
    cout << "The slop for the line that connects tow points (" << x1 << ", " << y1 << ") and (";
    cout << x2 << ", " << y2 << ") is " << k << endl;
    return 0;
}