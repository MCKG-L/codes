/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    long long m,y,d,t;
    cout << "Enter the number of minuts: ";
    cin >> m;
    t = m;
    y = m / (365*24*60);
    m = m % (365*24*60);
    d = m / (24*60);
    cout << t << " minuts is approximately " << y << " years and " << d << " days" << endl;
    return 0;
}