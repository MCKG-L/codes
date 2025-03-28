/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    int acount;
    cout << "Enter the monthly saving acount: ";cin >> acount;
    double ans = 0;
    for(int i=0;i<6;i++){
        ans = (ans + acount)*(1 + 0.00417);
    }
    cout << "After the sixth month, the acount value is $" << ans << endl;
    return 0;
}