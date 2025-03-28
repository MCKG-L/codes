/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string,int> mp = {{"Jan",31},{"Feb",28},{"Mar",31},{"Apri",30},{"May",31},{"Jun",30},{"Jul",31},{"Aug",31},{"Sep",30},
{"Oct",31},{"Nov",30},{"Dec",31}};
int main()
{
    int y;
    string s;
    cout << "Enter a year: ";cin >> y;
    cout << "Enter a month: ";cin >> s;
    int is_leap = false;
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0) is_leap = true;
    if(is_leap && s == "Feb") cout << s << " " << y << " has " << mp[s]+1 << " days" << endl;
    else if(mp.count(s)) cout << s << " " << y << " has " << mp[s] << " days" << endl;
    else cout << s << " is not a correct onth name" << endl;
    return 0;
}