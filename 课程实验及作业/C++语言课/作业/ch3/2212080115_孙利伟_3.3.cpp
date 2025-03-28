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
    cin >> a >> b >> c >> d >> e >> f;
    if(a*d == b*c) cout << "The equation has no solution" << endl;
    else{
        double x,y;
        x = (e*d-b*f)/(a*d-b*c);
        y = (a*f-e*c)/(a*d-b*c);
        cout << "x is " << x << " and y is " << y << endl;
    }
    return 0;
}