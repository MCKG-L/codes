/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
int main()
{
    srand(time(0));
    int mask = rand() % 2;
    int ans;
    cout << "Enter your answer: ";cin >> ans;
    if(ans == mask) cout << "you are correct!";
    else cout << "you are wrong!";
    return 0;
}