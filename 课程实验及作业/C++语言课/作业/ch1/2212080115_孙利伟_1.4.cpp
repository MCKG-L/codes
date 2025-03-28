/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
int main()
{
    cout << "a     a^2     a^3" << endl;
    for(int i=1;i<=4;i++){
        // cout << i << "     " << i*i << "     " << i*i*i << endl;
        printf("%-2d    %-2d      %-2d\n",i,i*i,i*i*i);
    }
    return 0;
}