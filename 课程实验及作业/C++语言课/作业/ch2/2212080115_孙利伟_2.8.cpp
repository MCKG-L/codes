/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <time.h>
using namespace std;
int main()
{
    int totalSeconds = time(0);
    int currentSecond = totalSeconds % 60;
    int totalMimutes = totalSeconds / 60;
    int currentMimute = totalMimutes % 60;
    int totalHours = totalMimutes / 60;
    int currentHour = totalHours % 24;

    int offset;
    cout << "Enter the time zone offset to GMT: ";
    cin >> offset;
    currentHour = (currentHour + 24 + offset) % 24;
    cout << "The current time is " << currentHour << ":" << currentMimute << ":" << currentSecond << endl;
    return 0;
}