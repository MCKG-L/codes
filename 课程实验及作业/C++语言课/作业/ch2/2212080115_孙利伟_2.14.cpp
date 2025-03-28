/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    double pounds,inches,BMI,m,kg;
    cout << "Enter the weight in pounds: ";cin >> pounds;
    cout << "Enter height in inches: ";cin >> inches;
    m = inches * 0.0254;
    kg = pounds * 0.45359237;
    BMI = kg / (m * m);
    cout << "BMI is " << BMI << endl;
    return 0;
}