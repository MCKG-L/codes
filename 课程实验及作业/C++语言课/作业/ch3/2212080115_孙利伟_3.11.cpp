/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    double w,c;
    cout << "Enter the weight: ";cin >> w;
    if(w > 50){cout << "The package cannot be shipped" << endl;return 0;}
    if(w <= 1) c = 3.5 * w;
    else if(w <= 3) c = w * 5.5;
    else if(w <= 10) c = 8.5 * w;
    else if(w <= 20) c = 10.5 * w;
    cout << "The cost is " << c << endl;
    return 0;
}