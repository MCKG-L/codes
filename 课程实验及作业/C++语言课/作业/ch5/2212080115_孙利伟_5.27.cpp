/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    int n;cin >> n;
    double sum = 0;
    double k = 1.0;
    for(int i=1;i<=n;i++){
        sum += k/(2*i-1);
        k *= -1;
    }
    cout << 4*sum << endl;
    return 0;
}