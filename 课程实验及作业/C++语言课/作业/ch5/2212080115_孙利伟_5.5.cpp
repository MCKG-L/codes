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
    cout << "Kilograme       Pounds    |" << "     Miles       Kilometers" << endl;
    for(int i=1;i<=199;i++){
        printf("%-16d%-6.1f",i,i*2.2);
        cout << "    |     ";
        printf("%-12d%-7.3f\n",i,i*1.609);
    }
    return 0;
}