/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int a,b,s,n;
int main()
{
    int x;
    while(cin >> x){
        if(x == 0) break;
        n++;s+=x;
        if(x > 0)a++;else b++;
    }
    cout << "Enter an integer, the inputs ends if it is 0: ";
    cout << "The number of positive is " << a << endl;
    cout << "The number of negative is " << b << endl;
    cout << "The total is " << s << endl;
    cout << "The average is " << 1.0*s/n << endl;
    return 0;
}