/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    double d,m,p;
    cout << "Enter the friving distance: ";cin >> d;
    cout << "Enter miles per gallon: ";cin >> m;
    cout << "Enter price per gallon: ";cin >> p;
    cout << "The cost of driving is $" << (d/m*p) << endl;
    return 0;
}