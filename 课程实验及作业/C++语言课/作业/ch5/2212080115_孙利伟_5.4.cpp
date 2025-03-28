/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    cout << "Miles       Kilometers" << endl;
    for(int i=1;i<=10;i++){
        printf("%-12d%.3f\n",i,i*1.609);
    }
    return 0;
}