/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    double t;
    cin >> t;
    if(t < 30) cout << "too cold" << endl;
    else if(t > 100) cout << "too hot" << endl;
    else cout << "just right" << endl;
    return 0;
}