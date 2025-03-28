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
    double a,b,c;
    cout << "Enter a, b, c: ";cin >> a >> b >> c;
    if(a == 0){
        if(b == 0){
            if(c != 0) cout << "The equation has no real roots";
            else cout << "The equation has infinitely many roots";
        }else{
        	double r = -1 * c / b;
            cout << "The root is " << r;
        }
    }else{
        double d = sqrt(b*b-4*a*c);
        if(d > 0){
            double r1 = (-1*b+d)/(2*a),r2 = (-1*b-d)/(2*a);
            cout << "The roots are " << r1 << " ans " << r2;
        }else if(d == 0){
        	double r = -1 * b /(2*a);
            cout << "The root is " << r;
        }else{
            cout << "The equation has no real roots";
        }
    }
    return 0;
}