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
    cout << "Enter a dicimal value (0 to 15): ";cin >> n;
    if(n >= 0 && n <= 9) cout << n;
    else if(n > 9 && n < 16) cout << char('A' + n - 10);
    else cout << n << " is an unvalid input" << endl;
    return 0;
}