/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    double sum = 0;
    for(int i=1;i<=49;i++){
        sum += (2*i-1)*1.0/(2*i+1);
    }
    cout << sum << endl;
    return 0;
}