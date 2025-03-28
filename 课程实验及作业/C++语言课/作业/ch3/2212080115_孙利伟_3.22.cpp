/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    double a,b,c,d,e,f;
    double x1,x2,x3,x4,y1,y2,y3,y4;
    cout << "Enter x1, y1, x2, y2, x3, y3, x4, y4: ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    a = y1-y2,b = x2-x1,c = y3-y4;
    d = x4-x3,e = (y1-y2)*x1-(x1-x2)*y1,f = (y3-y4)*x3-(x3-x4)*y3;
    if(a*d == b*c) cout << "The two lines are parallel" << endl;
    else{
        double x,y;
        x = (e*d-b*f)/(a*d-b*c);
        y = (a*f-e*c)/(a*d-b*c);
        cout << "The intersecting point is at (" << x << ", " << y << ")" << endl;
    }
    return 0;
}