/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    int f = 1;
    double sum1 = 0,sum2 = 0;
    for(int i=0;i<6;i++){
        sum1 += f*1.0/(2*i+1);
        f *= -1;
    }
    f = 1;
    for(int i=0;i<7;i++){
        sum2 += f*1.0/(2*i+1);
        f *= -1;
    }
    cout << 4 * sum1 << endl;
    cout << 4 * sum2 << endl;
}