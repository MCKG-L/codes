/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string s[3];
    cout << "Enter the first city: ";getline(cin,s[0]);
    cout << "Enter the second city: ";getline(cin,s[1]);
    cout << "Enter the third city: ";getline(cin,s[2]);
    sort(s,s+3);
    cout << "The three cities in alphabetical order are ";
    for(int i=0;i<3;i++) cout << s[i] << ' ';
    return 0;
}