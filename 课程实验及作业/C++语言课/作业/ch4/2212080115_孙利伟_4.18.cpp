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
    char c[3];
    for(int i=0;i<3;i++){
        int pos = rand() % 26;
        c[i] = 'A' + pos;
    }
    for(int i=0;i<3;i++){
        cout << c[i];
    }
    return 0;
}