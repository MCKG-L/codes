/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cout << "Enter two integers: ";cin >> a >> b;
    if(a % b == 0) cout << a << " is divesible by " << b;
    else cout << a << " is not divisible by " << b;
    return 0; 
}