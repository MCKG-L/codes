/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int sum = a + b + c;
    int max_n = max(a,max(b,c));
    int min_n = min(a,min(b,c));
    int mid_n = sum - max_n - min_n;
    cout << min_n << ' ' << mid_n << ' ' << max_n;
    return 0;
}