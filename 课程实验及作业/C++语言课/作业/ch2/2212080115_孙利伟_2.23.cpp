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
    double f,i,m,n;
    cout << "Enter invest amount: ";cin >> i;
    cout << "Enter annual interest rate in percentage: ";cin >> m;
    cout << "Enter number of years: ";cin >> n;
    f = i * pow(1+m/100/12,n*12);
    cout << "Accumulated value is $" << f << endl;
    return 0;
}