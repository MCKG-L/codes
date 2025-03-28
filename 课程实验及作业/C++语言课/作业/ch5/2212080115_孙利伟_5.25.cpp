/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    int n = 500000;
    double sum = 0;
    for(int i=1;i<=n;i++){
        sum += 1.0/i;
    }
    printf("%.18f\n",sum);
    sum = 0;
    for(int i=n;i>=1;i--){
        sum += 1.0/i;
    }
    printf("%.18f\n",sum);
    return 0;
}