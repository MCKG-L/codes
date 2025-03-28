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
    int x,y;
    cout << "Enter a point: ";cin >> x >> y;
    int s = x * x + y * y;
    if(s <= 100) cout << "in" << endl;
    else cout << "out" << endl;
    return 0;
}