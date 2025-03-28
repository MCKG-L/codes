/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    double v0,v1,t;
    cout << "Enter v0, v1, and t: ";
    cin >> v0 >> v1 >> t;
    double a = (v1-v0)/t;
    cout << "The average acceleration is  " << a << endl;
    return 0;
}