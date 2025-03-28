/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    int a;
    cout << "Enter a three-digit integer: ";cin >> a;
    if(a/100 == a%10){
        cout << a << " is a palindrome" << endl;
    }else cout << a << " is not a palindrome" << endl;
    return 0;
}
