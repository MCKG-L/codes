/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    double i,b,a;
    cout << "Enter balance and interest rate(e.g., 3 for 3%): ";cin >> b >> a;
    i = b * (a / 1200);
    cout << "The interest is " << i << endl;
    return 0;
}