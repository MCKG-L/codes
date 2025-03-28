/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[3];
    for(int i=0;i<3;i++)cin >> a[i];
    sort(a,a+3);
    if(a[0] + a[1] <= a[2]) cout << "illegal" << endl;
    else cout << "The perimeter is " << a[0] + a[1] + a[2] << endl;
    return 0;
}