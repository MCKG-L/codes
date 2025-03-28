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
    double sum = 0,p = 10000;
    for(int i=0;i<10;i++){
        sum += p;
        p *= 1.05;
    }
    cout << sum << endl;
    p = 1000;
    double ans[15];
    for(int i=0;i<10;i++){
        sum = 0,p = 1000*pow(1.05,i);
        for(int j=0;j<4;j++){
            sum += p;
            p *= 1.05;
        }
        ans[i] = sum;
    }
    for(int i=0;i<10;i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}