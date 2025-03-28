/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
int main()
{
    srand(time(0));
    int a,b,c;
    a = rand() % 100;
    b = rand() % 100;
    c = rand() % 100;
    cout << a << " + " << b << " + " << c << " = " << " ? ";
    int ans = 0;
    cin >> ans;
    if(ans == a + b + c) cout << "You are correct!" << endl;
    else cout << "You are wrong!" << endl;
    return 0;
}