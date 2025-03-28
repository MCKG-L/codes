/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int,string> mp{{0,"sunday"},{1,"Monday"},{2,"Tuesday"},{3,"Wednesday"},{4,"Thursday"},{5,"Friday"},{6,"Saturday"}};
int main()
{
    int n,d;
    cout << "Enter today's day: ";cin >> n;
    cout << "Enter the number of days elapsed since today: ";cin >> d;
    int x = (n + d) % 7;
    cout << "Today is " << mp[n] << " and the future day is " << mp[x] << endl;
    return 0;
}