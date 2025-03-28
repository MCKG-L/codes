/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<char,int> mp{{'a',4},{'b',3},{'c',2},{'d',1},{'e',0}};
    char ch,t;
    cout << "Enter a letter grade: ";cin >> ch;t = ch;
    if(ch >= 'A' && ch <= 'Z') ch += 32;
    cout << "The numberic value for grade " << char(t) << " is " << mp[ch] << endl;
    return 0;
}