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
    double x1,y1,r1,x2,y2,r2;
    cout << "Enter circle1's  center x-, y-coordinates, and radius: ";
    cin >> x1 >> y1 >> r1;
    cout << "Enter circle2's  center x-, y-coordinates, and radius: ";
    cin >> x2 >> y2 >> r2;
    double dis = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    double d = r1 - r2;
    if(dis <= d) cout << "circle1 is inside circle2" << endl;
    else if(dis > d && dis < r1 + r1) cout << "circle1 overlaps circle2" << endl;
    else if(dis > r1 + r1) cout << "circle1 does not overlaps circle2" << endl;
    return 0;
}