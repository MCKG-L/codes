/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    int w1,w2;
    double p1,p2;
    cout << "Enter weight and price for package1: ";
    cin >> w1 >> p1;
    cout << "Enter weight and price for package2: ";
    cin >> w2 >> p2;
    double f1 = p1 / w1;
    double f2 = p2 / w2;
    if(f1 == f2) puts("Two packages have the save price");
    else if(f1 < f2) puts("Package 1 has a better price");
    else puts("Package2 has a better price");
    return 0;
}