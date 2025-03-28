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
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8-i;j++) cout << "    ";
        for(int j=1;j<=i;j++) printf("%4d",(int)pow(2,j-1));
        for(int j=i-1;j>=1;j--) printf("%4d",(int)pow(2,j-1));
        cout << endl;
    }
    return 0;
}