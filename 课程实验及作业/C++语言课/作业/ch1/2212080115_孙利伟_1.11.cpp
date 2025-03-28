/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    int t = 5 * 365 * 24 * 3600;
    int ans = 312032486;
    ans += t / 7;
    ans -= t / 13;
    ans += t / 45;
    cout << ans << endl;
    return 0;
}