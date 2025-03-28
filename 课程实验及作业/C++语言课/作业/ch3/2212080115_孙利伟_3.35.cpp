/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    string s;
    cout << "Enter the first 9 digits od an ISBN as integer: ";cin >> s;
    int sum = 0;
    for(int i=0;i<9;i++){
        sum += (s[i]-'0')*(i+1);
    }
    if(sum % 11 < 10) s += sum%11+'0';
    else s += 'X';
    cout << "The ISBN-10 number is " << s << endl;
    return 0;
}