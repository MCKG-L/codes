/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <map>
using namespace std;
map<int,string> mp{{0,"false"},{1,"true"}};
int main()
{
    bool mask1,mask2,mask3;
    int n;
    cout << "Enter an integer: ";cin >> n;
    if(n % 5 == 0 && n % 6 == 0) mask1 = 1;else mask1 = 0;
    if(n % 5 == 0 || n % 6 == 0 ) mask2 = 1;else mask2 = 0;
    if((n % 5 == 0 && n % 6 != 0) || (n % 5 != 0 && n % 6 == 0)) mask3 = 1;else mask3 = 0;
    cout << "Is " << n << " divisible by 5 and 6? " << mp[mask1] << endl;
    cout << "Is " << n << " divisible by 5 or 6? " << mp[mask2] << endl;
    cout << "Is " << n << " divisible by 5 or 6, but not both? " << mp[mask3] << endl;
    return 0;
}