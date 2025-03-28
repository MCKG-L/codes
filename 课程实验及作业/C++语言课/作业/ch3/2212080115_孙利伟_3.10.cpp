/*
姓名：孙利伟
学号：2212080115
班级：二班
*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int main()
{
    srand(time(0));
    int a = rand() % 100;
    int b = rand() % 100;
    cout << "What is " << a << " + " << b << " ? ";
    int ans = 0;cin >> ans;
    if(ans == a + b) cout << "You are correct!" << endl;
    else{
        cout << "Your answer is wrong\n";
        cout << a << " + " << b << " should be " << a + b << endl;
    }
    return 0;
}