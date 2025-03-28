/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
using namespace std;
int gcd(int a,int b){
    if(b == 0) return 0;
    while(b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int a,b;
    cin >> a >> b;
    cout << gcd(a,b) << endl;
    return 0;
}