/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of year: ";cin >> n;
    int t = n * 365 * 24 * 3600;
    int ans = 312032486;
    ans += t / 7;
    ans -= t / 13;
    ans += t / 45;
    cout << "The population in " << n << "years is ";
    cout << ans << endl;
    return 0;
}