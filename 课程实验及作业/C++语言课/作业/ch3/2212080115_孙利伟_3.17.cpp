/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double t1,t2,v;bool mask = 0;
    cout << "Enter the temperature in Fahrenheit: ";cin >> t1;
    cout << "Enter the wind speed in miles per hour: ";cin >> v;
    if(v < 2) cout << "The wind speed is invalid\n",mask = 1;
    if(t1 < -58 || t1 > 41) cout << "The temperature is invalid\n",mask = 1;
    if(mask) return 0;
    t2 = 35.74 + 0.6215 * t1 - 35.75 * pow(v,0.16) + 0.4275 * t1 * (v,0.16);
    cout << "The wind chill index is " << t2 << endl;
    return 0;
}