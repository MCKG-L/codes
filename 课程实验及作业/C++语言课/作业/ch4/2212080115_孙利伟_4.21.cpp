/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <map>
using namespace std;
map<char,string> mp = {{'1',"Freshman"},{'2',"sophomore"},{'3',"Junior"},{'4',"Senior"},
{'M',"Mathematics"},{'C',"Computer Science"},{'I',"Information Technology"}};
int main()
{
    string s;
    cout << "Enter two characters: ";cin >> s;
    if(!mp.count(s[0])){
        cout << "Invalid major code" << endl;
        return 0;
    }
    if(!mp.count(s[1])){
        cout << "Invalid status code" << endl;
        return 0;
    }
    cout << mp[s[0]] << ' ' << mp[s[1]] << endl;
    return 0;
}