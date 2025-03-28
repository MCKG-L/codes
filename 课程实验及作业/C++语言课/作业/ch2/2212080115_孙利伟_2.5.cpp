/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    double s,g,r,t;
    cout << "Enter the subtotal ans a gratuity rate: ";
    cin >> s >> r;
    g = s * r / 100;
    t = s + g;
    cout << "The gratuity is $" << g << " and total is $" << t << endl;
    return 0;
}