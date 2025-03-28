/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int main()
{
    cout << "a       b       pow(a, b)" << endl;
    for(int i=1;i<=5;i++){
        printf("%-5d   %-5d   %-5d\n",i,i+1,(int)pow(i,i+1));
    }
    return 0;
}