/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int d[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool is_leap(int n){
    if(n % 4 == 0 && n % 100 != 0 || n % 400 == 0){
        return true;
    }
    return false;
}
int main()
{
    int m,y;
    cout << "Enter the year: ";cin >> y;
    cout << "Enter the month: ";cin >> m;
    if(is_leap(y)) d[2] = 29;
    cout << "This month has " << d[m] << " days" << endl;
    return 0;
}