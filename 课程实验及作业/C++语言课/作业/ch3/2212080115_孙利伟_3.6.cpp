/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int main()
{
    double bmi,feet,height,inches,weight;
    cout << "Enter weight in pounds: ";cin >> weight;
    cout << "Enter feet: ";cin >> feet;
    cout << "Enter inches: ";cin >> inches;
    height = feet * 12 + inches;
    const double K_P_P = 0.45359237;
    const double M_P_I = 0.0254;
    bmi = (weight*K_P_P)/((height*M_P_I)*(height*M_P_I));
    cout << "BMI is " << bmi << endl;
    if(bmi < 18.5) cout << "Underweight" << endl;
    else if(bmi < 25) cout << "Normal" << endl;
    else if(bmi < 30) cout << "Overweight" << endl;
    else cout << "Obese" << endl;
    return 0;
}