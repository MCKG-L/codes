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
    cout << "Kilograme       Pounds" << endl;
    for(int i=1;i<=199;i++){
        printf("%-16d%.1f\n",i,i*2.2);
    }
    return 0;
}