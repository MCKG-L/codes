/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double f,i,m;
    cout << "Enter the amount of water in kilograms: ";cin >> m;
    cout << "Enter thr initial temperature: ";cin >> i;
    cout << "Enter thr final temperature: ";cin >> f;
    double q = 4184 * m * (f - i);
    cout << fixed << "The energy needed is " << q << endl;
    return 0;
}